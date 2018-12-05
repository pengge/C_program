//*****************************************************************************
//
// Microsoft Windows Media
// Copyright (C) Microsoft Corporation. All rights reserved.
//
// FileName:            AudioPlay.cpp
//
// Abstract:            Implementation of the CAudioPlay class.
//
//*****************************************************************************

#include "stdafx.h"
#include <stdio.h> 
#include <string.h>
#include "AudioPlay.h"
#include "asferr.h"
#include "nserror.h"
#include "mmreg.h"
#include "TagDefine.h"

#ifdef SUPPORT_DRM

#include "DRM.h"

CDRM objDRM;    // to handle protected content

#endif

//#include "BroadConvertDlg.h"

class CBroadConvertDlg;
//------------------------------------------------------------------------------
// Name: CAudioPlay::CAudioPlay()
// Desc: Constructor.
//------------------------------------------------------------------------------
CAudioPlay::CAudioPlay()
{	
    m_cRef              = 1;

#ifdef SUPPORT_DRM
	m_bProcessingDRMOps = FALSE;
#endif

    m_bClosed           = TRUE;
    m_bIsSeekable       = FALSE;
    m_bIsBroadcast      = FALSE;
	m_bEOF				= FALSE;
    m_dwAudioOutputNum  = 0xFFFFFFFF;
	m_dwThreadID		= 0;
	m_hAsyncEvent		= INVALID_HANDLE_VALUE;
	m_hrAsync			= S_OK;
	//m_hWaveOut			= NULL;
	m_pReader			= NULL;
    m_pHeaderInfo       = NULL;
	m_cHeadersLeft		= 0;
	m_pwszURL			= NULL;
	memset(m_SaveURLA, 0x00, sizeof(m_SaveURLA));
	memset(m_SaveURLB, 0x00, sizeof(m_SaveURLB));
	memset(m_SaveURLC, 0x00, sizeof(m_SaveURLC));
	m_cnsFileDuration	= 0;
	m_pWfx              = NULL;	
	m_pSrcWfx			= NULL;
	m_pMidWfx			= NULL;
	m_pDstWfx			= NULL;
	nFileNo				= 1;
	nFileByte			= 0;	

	dwWriteThreadID = 0;
	hWriteThread = NULL;
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::~CAudioPlay()
// Desc: Destructor.
//------------------------------------------------------------------------------
CAudioPlay::~CAudioPlay()
{
	Exit();
	CoUninitialize();
}

CAudioPlay::CDataStack::CDataStack ()
{
	m_buffer = NULL;
	m_length = 0;
}

CAudioPlay::CDataStack::~CDataStack ()
{
	delete[] m_buffer;
}

void CAudioPlay::CDataStack::Append (const char* data, int len)
{
	if (data == NULL || len <= 0) return;

	m_sync.Enter ();
	if (m_length == 0)
	{
		m_buffer = new char[len];
		memcpy(m_buffer, data, len);
		m_length = len;
	}
	else
	{
		//	backup old buffer (temporarily)
		char* oldbuff = new char[m_length];
		memcpy(oldbuff, m_buffer, m_length);

		//	create a new buffer that holds the old one PLUS the new stuff
		delete[] m_buffer;
		m_buffer = new char[m_length + len];

		//	copy old buffer and new data into the new (bigger) buffer
		memcpy(m_buffer, oldbuff, m_length);
		memcpy(&m_buffer[m_length], data, len);

		//	store the new length of the data
		m_length += len;

		//	do clean-up
		delete[] oldbuff;
	}
	m_sync.Leave ();
}

int CAudioPlay::CDataStack::Remove (char* data, int len)
{
	memset(data, 0, len);

	m_sync.Enter ();
	//	if the buffer is empty, don't remove anything
	if (m_length == 0)
	{
		m_sync.Leave ();
		return 0;
	}

	//	determine how much we will actually copy
	int remlen = len;
	if (remlen > m_length)
		remlen = m_length;

	//	backup old buffer (temporarily)
	char* oldbuff = new char[m_length];
	memcpy(oldbuff, m_buffer, m_length);

	//	copy part of buffer (or all) to 'data'
	memcpy(data, oldbuff, remlen);

	//	create a new buffer that holds the old one MINUS the removed stuff
	delete[] m_buffer;
	if (m_length - remlen <= 0)
	{
		m_buffer = NULL;
		m_length = 0;
	}
	else
	{
		m_buffer = new char[m_length - remlen];

		//	remove the part that has been copied from the buffer
		memcpy(m_buffer, &oldbuff[remlen], m_length - remlen);

		//	store the new length of the data
		m_length -= remlen;
	}

	//	do clean-up
	delete[] oldbuff;

	m_sync.Leave ();
	return remlen;
}

int CAudioPlay::CDataStack::Length ()
{
	long length;

	m_sync.Enter ();
	length = m_length;
	m_sync.Leave ();

	return length;
}

void CAudioPlay::CDataStack::RemoveAll ()
{

	m_sync.Enter ();

	if (m_length == 0)
	{
		m_sync.Leave ();
		return;
	}

	if (m_buffer != NULL)
	{
		delete[] m_buffer;
	}
	m_length = 0;
	
	m_sync.Leave ();	
}
//------------------------------------------------------------------------------
// Name: CAudioPlay::QueryInterface()
// Desc: IUnknown method.
//------------------------------------------------------------------------------
HRESULT STDMETHODCALLTYPE CAudioPlay::QueryInterface( /* [in] */ REFIID riid,
                                                      /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject ) 
{
    if( ( IID_IWMReaderCallback == riid ) ||
        ( IID_IUnknown == riid ) )
    {
        *ppvObject = static_cast< IWMReaderCallback* >( this );
        AddRef();
        return( S_OK );
    }

    *ppvObject = NULL;
    return( E_NOINTERFACE );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::AddRef()
// Desc: IUnknown method.
//------------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE CAudioPlay::AddRef()
{
    return( InterlockedIncrement( &m_cRef ) );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Release()
// Desc: IUnknown method.
//------------------------------------------------------------------------------
ULONG STDMETHODCALLTYPE CAudioPlay::Release()
{
    if( 0 == InterlockedDecrement( &m_cRef ) )
    {
        delete this;
        return( 0 );
    }

    return( m_cRef );
}

//----------------------------------------------------------------
// 函数功能:  IWMReaderCallback 方法，用来处理状态标识
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//----------------------------------------------------------------
HRESULT CAudioPlay::OnStatus( /* [in] */ WMT_STATUS Status,
							  /* [in] */ HRESULT hr,
							  /* [in] */ WMT_ATTR_DATATYPE dwType,
							  /* [in] */ BYTE __RPC_FAR *pValue,
							  /* [in] */ void __RPC_FAR *pvContext ) 
{
	//-----------------------
    // Step1: 定义变量
    //-----------------------

	//--------------------------------------
    // Step2: 检测reader对象发送的重要消息
    //--------------------------------------
	switch( Status )
	{
	
	//--------------------------------------
    // Step2.1: reader已经打开文件
    //--------------------------------------
	case WMT_OPENED:

#ifdef SUPPORT_DRM
		//
		// Set the event if DRM operation is not going on
		//
		if( !m_bProcessingDRMOps )
#endif	
        {
            SetAsyncEvent( hr );
        }
			
		break;

	//--------------------------------------
    // Step2.2: 开始回放打开的文件
    //--------------------------------------
	case WMT_STARTED:

		m_bEOF = FALSE;
		if (pParDlg != NULL)
		{
			pParDlg->SetCurrentStatus( PLAY );
		}
		
		break;

	//--------------------------------------
    // Step2.3: reader已经关闭文件
    //--------------------------------------
	case WMT_CLOSED:

		SetAsyncEvent( hr );
		break;


	//--------------------------------------
    // Step2.4: 前面播放的reader已经停止
    //--------------------------------------
	case WMT_STOPPED:
		
		SetAsyncEvent( hr );
		pParDlg->SetCurrentStatus( STOP );
		break;
	

	//--------------------------------------
    // Step2.5: 发送错误或已结束
    //--------------------------------------
	case WMT_ERROR:
	case WMT_EOF:
	case WMT_MISSING_CODEC:
		
		m_bEOF = TRUE;
		
		//---------------------------------------------
		// Step2.5.1: 当没有buffer供回放使用则停止回放
		//---------------------------------------------
		if( 0 == m_cHeadersLeft )
		{
			pParDlg->SetCurrentStatus( STOP );
		}

		break;
	
	
	//----------------------------
    // Step2.6: reader开始缓冲
    //----------------------------
	case WMT_BUFFERING_START:
		
		pParDlg->SetCurrentStatus( BUFFERING );
		break;


	//----------------------------
    // Step2.7: reader缓冲完毕
    //----------------------------
	case WMT_BUFFERING_STOP:

		pParDlg->SetCurrentStatus( PLAY );
		break;

	case WMT_LOCATING:
		break;

    //
    // License and DRM related messages
    //
	//-------------------------------
    // Step2.8: 有关许可和DRM的消息
    //-------------------------------
	case WMT_NO_RIGHTS:
	case WMT_NO_RIGHTS_EX:
	case WMT_NEEDS_INDIVIDUALIZATION:
	case WMT_LICENSEURL_SIGNATURE_STATE:

#ifdef SUPPORT_DRM
		m_bProcessingDRMOps = TRUE;
#endif
    
    case WMT_ACQUIRE_LICENSE:
	case WMT_INDIVIDUALIZE:

#ifdef SUPPORT_DRM
		objDRM.OnDRMStatus( Status, hr, dwType, pValue, pvContext );
#endif
		break;

	default:
		break;
	}

//	SAFE_ARRAYDELETE( pValue );
	SAFE_ARRAYDELETE( pvContext );
	
	return( S_OK );
}


//---------------------------------------------------------------
// 函数功能:  IWMReaderCallback 方法，用来处理样本
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//----------------------------------------------------------------
HRESULT CAudioPlay::OnSample( /* [in] */ DWORD dwOutputNum,
							  /* [in] */ QWORD cnsSampleTime,
							  /* [in] */ QWORD cnsSampleDuration,
							  /* [in] */ DWORD dwFlags,
							  /* [in] */ INSSBuffer __RPC_FAR *pSample,
							  /* [in] */ void __RPC_FAR *pvContext )
{
	
	//-----------------------
    // Step1: 定义变量
    //-----------------------
	BYTE        *pData = NULL;	
	BYTE		*pDstMidData = NULL;
	BYTE		*pDstData = NULL;
	DWORD       cbData = 0;	
	DWORD		dwSrcBytes = 0 ;
	DWORD		dwDstMidSamples = 0 ;
	DWORD		dwDstMidBytes = 0 ;
	DWORD		dwDstBytes = 0 ;
	HRESULT     hr = S_OK;
    MMRESULT    mmr = 0;	
	HACMDRIVER	had = NULL;
	HACMSTREAM	hstrPcm = NULL;
	HACMSTREAM	hstrDst = NULL;
	ACMSTREAMHEADER astrhdrDst;	
	ACMSTREAMHEADER astrhdrPcm;
			
	int			nMaxByte = 0;

	//--------------------------------------------------------------------------
    // Step2: 检查输出编号是否与存储的相符。应为我们只存储第一个相符的音频输出，
	//			所以其他的输出，不管其类型是什么，都将忽略
    //--------------------------------------------------------------------------
    if( dwOutputNum != m_dwAudioOutputNum )
    {
        return( S_OK );
    }

	//--------------------------------------
    // Step2: 从buffer对象中获取样本数据
    //--------------------------------------
	hr = pSample->GetBufferAndLength( &pData, &cbData );	
    if( FAILED( hr ) )
	{
		return( hr );
	}

	//-----------------------------------------------------------------------------
    // Step3: 此方法内其余的代码，将使用Windows	Multimedia wave处理函数播放内容
	// Step3.1 为数据头和数据分配内存,拷贝数据
    //-----------------------------------------------------------------------------
		
	do
    {
		//---------------------------------------------------------------------------------------
		// Step3.2: 将源媒体转换为CODEC支持的PCM格式，
		//			我们使用任何一个可以完成PCM到PCM转换的驱动
		// Step3.2.1 打开转换流
		//---------------------------------------------------------------------------------------
		mmr = acmStreamOpen(&hstrPcm,
							NULL, // any driver
							m_pSrcWfx, // source format
							m_pMidWfx, // destination format
							NULL, // no filter
							NULL, // no callback
							0, // instance data (not used)
							ACM_STREAMOPENF_NONREALTIME); // flags
		if (mmr) 
		{				
			pParDlg->InsertLog("Failed to open a stream to do PCM to PCM conversion\n");
			hr = HRESULT_FROM_WIN32( GetLastError() ) ;
			goto HappenError;
		}

		//------------------------------------------
		// Step3.3: 为转换结果分配一个buffer
		//------------------------------------------
		dwSrcBytes = cbData ;
		dwDstMidSamples = cbData  / m_pSrcWfx->wBitsPerSample *8 * m_pMidWfx->nSamplesPerSec / m_pSrcWfx->nSamplesPerSec;
		dwDstMidBytes = dwDstMidSamples * m_pMidWfx->wBitsPerSample / 8;
		pDstMidData = new BYTE [dwDstMidBytes];

	#ifdef _DEBUG		
		memset(pDstMidData, 0, dwDstMidBytes);
	#endif

		
		//--------------------------
		// Step3.2.2: 填充转换信息
		//--------------------------		
		memset(&astrhdrPcm, 0, sizeof(astrhdrPcm));
		astrhdrPcm.cbStruct = sizeof(astrhdrPcm);
		//astrhdrPcm.pbSrc = (unsigned char*)pwh->lpData;// the source data to convert
		astrhdrPcm.pbSrc = pData;
		astrhdrPcm.cbSrcLength = cbData;
		astrhdrPcm.pbDst = pDstMidData;
		astrhdrPcm.cbDstLength = dwDstMidBytes;

		//--------------------------
		// Step3.2.3: 准备转换头
		//--------------------------
		mmr = acmStreamPrepareHeader(hstrPcm, &astrhdrPcm, 0); 
		if (mmr) 
		{
			pParDlg->InsertLog("Failed acmStreamPrepareHeader\n");			
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}

		//--------------------------
		// Step3.2.4: 转换数据
		//--------------------------
		mmr = acmStreamConvert(hstrPcm, &astrhdrPcm, 0);
		if (mmr) 
		{
			pParDlg->InsertLog("Failed to do PCM to PCM conversion\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}		
	
		//--------------------------------------------
		// Step3.3: 将数据从中间PCM格式转换为最终格式
		// Step3.3.1: 打开驱动
		//--------------------------------------------
		mmr = acmDriverOpen(&had, hadid, 0);
		if (mmr) 
		{
			pParDlg->InsertLog("Failed to open driver\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}

	
		//--------------------------------------------------------------------------
		// Step3.3.2:	打开转换流，注意必须使用ACM_STREAMOPENF_NONREALTIME 标志，
		//				如果不使用此标志，有些压缩软件将报告512号错误。
		//--------------------------------------------------------------------------
		mmr = acmStreamOpen(&hstrDst,
							had, // driver handle
							m_pMidWfx, // source format
							m_pDstWfx, // destination format
							NULL, // no filter
							NULL, // no callback
							0, // instance data (not used)
							ACM_STREAMOPENF_NONREALTIME); // flags
		if (mmr) 
		{
			pParDlg->InsertLog("Failed to open a stream to do PCM to driver format conversion\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}

		
		//--------------------------------------------------------------------------
		// Step3.3.3:	为转换结果分配一个buffer.根据平均比特率加一些冗余，
		//				计算输出缓冲区的大小。IMA_ADPCM驱动在没有附加空间
		//				时进行转换将失败。
		//--------------------------------------------------------------------------
		dwDstBytes = m_pDstWfx->nAvgBytesPerSec * dwDstMidSamples / m_pMidWfx->nSamplesPerSec;
		dwDstBytes =  dwDstBytes;//* 3 / 2; // add a little room
		pDstData = new BYTE [dwDstBytes];

	#ifdef _DEBUG		
		memset(pDstData, 0, dwDstBytes);
	#endif

		//---------------------------------
		// Step3.3.4:	填充转换信息
		//---------------------------------
		memset(&astrhdrDst, 0, sizeof(astrhdrDst));
		astrhdrDst.cbStruct = sizeof(astrhdrDst);
		astrhdrDst.pbSrc = pDstMidData; // the source data to convert
		astrhdrDst.cbSrcLength = astrhdrPcm.cbDstLengthUsed ;//dwDst1Bytes;
		astrhdrDst.pbDst = pDstData;
		astrhdrDst.cbDstLength = dwDstBytes;

		//---------------------------------
		// Step3.3.5:	准备信息头
		//---------------------------------
		mmr = acmStreamPrepareHeader(hstrDst, &astrhdrDst, 0);
		if (mmr) 
		{			
			pParDlg->InsertLog("Failed acmStreamPrepareHeader\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}

		//---------------------------------
		// Step3.3.5:	转换数据
		//---------------------------------
		mmr = acmStreamConvert(hstrDst, &astrhdrDst, 0);
		if (mmr) 
		{
			pParDlg->InsertLog("Failed to do PCM to driver format conversion\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}	

		

		//--------------------------------------
		// Step3.3.7:	将转换后的数据写入文件
		//--------------------------------------
		m_sync.Enter();
		m_AudioData.Append((const char*)astrhdrDst.pbDst, astrhdrDst.cbDstLengthUsed);
		m_sync.Leave();
		
		
		mmr = acmStreamUnprepareHeader(hstrPcm, &astrhdrPcm, 0);
		if (mmr) 
		{
			pParDlg->InsertLog("Failed to acmStreamUnprepareHeader\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}
		//--------------------------
		// Step3.2.5: 关闭转换流
		//--------------------------
		acmStreamClose(hstrPcm, 0);

		mmr = acmStreamUnprepareHeader(hstrDst, &astrhdrDst, 0);
		if (mmr) 
		{
			pParDlg->InsertLog("Failed to acmStreamUnprepareHeader\n");
			hr = HRESULT_FROM_WIN32( GetLastError() );
			goto HappenError;
		}
		//---------------------------------
		// Step3.3.6:	关闭转换流和驱动
		//---------------------------------
		mmr = acmStreamClose(hstrDst, 0);
		mmr = acmDriverClose(had, 0);
		mmr = 0;

		//Sleep(10);

		//--------------------------------------------
		// Step3.4: 判断是否需要回放，需要则回放数据
		//--------------------------------------------
			

		//--------------------------------------------
		// Step3.5: 设置播放的百分比
		//--------------------------------------------
		if( m_bIsBroadcast )
		{
			pParDlg->SetTime( cnsSampleTime, 0 );
		}
        else
		{
			pParDlg->SetTime( cnsSampleTime, m_cnsFileDuration );
		}

		SAFE_ARRAYDELETE( pDstMidData );
		SAFE_ARRAYDELETE( pDstData );
		
    }
    while( FALSE );
	
	
	//--------------------------------------------
	// Step4: 如果失败，停止播放
	//--------------------------------------------	
	if( MMSYSERR_NOERROR != mmr )
	{           	
		pParDlg->InsertLog( "Wave function failed" );
		SendMessage((HWND)pParDlg, WM_COMMAND, IDC_STOP, 0);
	}

	SAFE_ARRAYDELETE( pDstMidData );	
	SAFE_ARRAYDELETE( pDstData );
	return ( S_OK );

HappenError:	

	mmr = acmStreamUnprepareHeader(hstrPcm, &astrhdrPcm, 0);
	if (mmr) 
	{
		pParDlg->InsertLog("Failed to acmStreamUnprepareHeader\n");
		hr = HRESULT_FROM_WIN32( GetLastError() );
		goto HappenError;
	}
	//--------------------------
	// Step3.2.5: 关闭转换流
	//--------------------------
	acmStreamClose(hstrPcm, 0);

	mmr = acmStreamUnprepareHeader(hstrDst, &astrhdrDst, 0);
	if (mmr) 
	{
		pParDlg->InsertLog("Failed to acmStreamUnprepareHeader\n");
		hr = HRESULT_FROM_WIN32( GetLastError() );
		goto HappenError;
	}
	//---------------------------------
	// Step3.3.6:	关闭转换流和驱动
	//---------------------------------
	mmr = acmStreamClose(hstrDst, 0);
	mmr = acmDriverClose(had, 0);
	mmr = 0;
	SAFE_ARRAYDELETE( pDstMidData );	
	SAFE_ARRAYDELETE( pDstData );
	return( S_OK );
}


//////////////////////////////////////////////////////////////////////////////////
// 函数功能:  初始化音频播放器
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//////////////////////////////////////////////////////////////////////////////////
HRESULT CAudioPlay::Init()
{
	//-----------------------
    // Step1: 定义变量
    //-----------------------
	HRESULT hr = S_OK;	
	
	//-----------------------
    // Step2: 初始化运行环境
    //-----------------------
	do
	{
		//----------------------------
		// Step2.1: 初始化COM运行环境
		//----------------------------
        hr = CoInitialize( NULL );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "CoInitialize failed" ) );
			pParDlg->InsertLog( m_tszErrMsg );			
			break;
		}
		
		//--------------------------------------------------------------
		// Step2.2: 创建异步调用事件.当此类中的代码以异步方式调用，
		//			它将等待此事件重置后，恢复进程.
		//--------------------------------------------------------------
		m_hAsyncEvent = CreateEvent( NULL, FALSE, FALSE, NULL );
		if( NULL == m_hAsyncEvent )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not create the event" ) );
			pParDlg->InsertLog( m_tszErrMsg );
			hr = E_FAIL;
			break;
		}

       	//------------------------------------------
		// Step2.3: 创建读对象，只请求回放功能
		//------------------------------------------
        hr = WMCreateReader( NULL, WMT_RIGHT_PLAYBACK, &m_pReader );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not create Reader" ) );
			pParDlg->InsertLog( m_tszErrMsg );			
			break;
		}		
	}
	while( FALSE );

	//-----------------------
    // Step3: 处理结果
    //-----------------------
	if( FAILED( hr ) )
	{
        wsprintf( m_tszErrMsg, _T("%s (hr=%#X)"), m_tszErrMsg, hr );
		pParDlg->InsertLog( m_tszErrMsg );		
		Exit();
	}	

	return( hr );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Exit()
// Desc: Cleanup.
//------------------------------------------------------------------------------
HRESULT CAudioPlay::Exit()
{
    SAFE_RELEASE( m_pHeaderInfo );
	SAFE_RELEASE( m_pReader );

	/*if( NULL != m_hWaveOut )
    {
        waveOutClose( m_hWaveOut );
		m_hWaveOut = NULL;
    }*/

	if( NULL != m_hAsyncEvent )
	{
		CloseHandle( m_hAsyncEvent );
		m_hAsyncEvent = NULL;
	}

	SAFE_ARRAYDELETE( m_pwszURL );
	SAFE_ARRAYDELETE( m_pWfx );
    
	return( S_OK );
}


//---------------------------------------------------------------
// 函数功能:  打开文件
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//----------------------------------------------------------------
HRESULT CAudioPlay::Open( LPCWSTR pwszUrl, LPCWSTR pwszSaveUrlA, LPCWSTR pwszSaveUrlB, LPCWSTR pwszSaveUrlC, BOOL bPlayBack)
{
	//-----------------------
    // Step1: 定义变量
    //-----------------------
    const INT MAX_ERROR_LENGTH = 256;
	HRESULT hr = S_OK;
	
	//------------------------------------------------------------
    // Step2: 检查输入参数是否不为NULL，并且reader已经初始化
    //------------------------------------------------------------
	if( NULL == pwszUrl )
    {
		return( E_INVALIDARG );
    }

	if( NULL == pwszSaveUrlA )
    {
		return( E_INVALIDARG );
    }

	if( NULL == pwszSaveUrlB )
    {
		return( E_INVALIDARG );
    }

	if( NULL == m_pReader )
    {
		return( E_UNEXPECTED );
    }

	//------------------------------------------------------------
    // Step3: 
    //------------------------------------------------------------
	do
	{
        ZeroMemory( m_tszErrMsg, MAX_ERROR_LENGTH );
		ResetEvent( m_hAsyncEvent );
	
		//-------------------------------------------
		// Step3.1: 关闭以前打开的文件，并删除旧文件 
		//-------------------------------------------
		Close();
		SAFE_ARRAYDELETE( m_pwszURL );
		
		//----------------------------------------
		// Step3.2: 设置新文件名
		//----------------------------------------
		m_pwszURL = new WCHAR[ wcslen( pwszUrl ) + 1 ];
		if( NULL == m_pwszURL )
		{
			hr = HRESULT_FROM_WIN32( GetLastError() );
			_tcscpy( m_tszErrMsg, _T( "Insufficient memory" ) );
			pParDlg->InsertLog( m_tszErrMsg ); 
			break;
		}
		wcscpy( m_pwszURL, pwszUrl );

		memset(m_SaveURLA, 0x00, sizeof(m_SaveURLA));
		memset(m_SaveURLB, 0x00, sizeof(m_SaveURLB));
		memset(m_SaveURLC, 0x00, sizeof(m_SaveURLC));
		memcpy(m_SaveURLA, pwszSaveUrlA, wcslen( pwszSaveUrlA ));
		memcpy(m_SaveURLB, pwszSaveUrlB, wcslen( pwszSaveUrlB ));
		memcpy(m_SaveURLC, pwszSaveUrlC, wcslen( pwszSaveUrlC ));
		remove(m_SaveURLA);
		remove(m_SaveURLB);
		remove(m_SaveURLC);

#ifdef SUPPORT_DRM

		hr = objDRM.Init( this, m_pReader, m_pwszURL );
		if( FAILED( hr ) )
        {
			break;
		}
		
		m_bProcessingDRMOps = FALSE;
#endif

		//-------------------------------------------------------------
		// Step3.3: 用reader对象打开文件。此方法同时设置reader的状态
		//-------------------------------------------------------------
        hr = m_pReader->Open( pwszUrl, this, NULL );		
		if( FAILED( hr ) )
        {
            _tcscpy( m_tszErrMsg, _T( "Could not open the specified file" ) );
			break;
		}
		

		//-------------------------------------------------------------------
		// Step3.4: 等待打开调用结束。当reader完成时，会调用OnStatus回调函数
		//-------------------------------------------------------------------
		WaitForEvent( m_hAsyncEvent );
		
#ifdef SUPPORT_DRM

		if( ( NS_S_DRM_ACQUIRE_CANCELLED == m_hrAsync ) || 
			( NS_E_DRM_INDIVIDUALIZATION_INCOMPLETE == m_hrAsync ) )
		{
			//--------------------------------------
			// DRM操作已经被取消,因此文件还未打开
			//--------------------------------------
			hr = m_hrAsync;
			return( hr );
		}

        //-----------------------------------
		// Step3.5: 查询许可失败的原因
		//-----------------------------------
        BOOL fAcquiringLicenseNonSilently = FALSE;
        if( 7 == objDRM.GetLastDRMVersion() &&
            ( NS_E_DRM_LICENSE_NOTACQUIRED == m_hrAsync || 
              NS_E_DRM_LICENSE_STORE_ERROR == m_hrAsync ) )
        {
            fAcquiringLicenseNonSilently = TRUE;
            hr = objDRM.AcquireLastV7LicenseNonSilently();
            if ( FAILED( hr ) )
            {
                return hr;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        // Check to see if the license is being acquired non-silently
        ////////////////////////////////////////////////////////////////////////////////
		if( NS_E_DRM_NO_RIGHTS == m_hrAsync || // All DRMv1 licenses are gotten non-silently
            fAcquiringLicenseNonSilently )
		{
			////////////////////////////////////////////////////////////////////////////////
			// The license for this file is being acquired non-silently,
			// and it cannot be played until the license is acquired.
			////////////////////////////////////////////////////////////////////////////////
			MessageBox( NULL, _T( "After acquiring the license, re-open the file." ), ERROR_DIALOG_TITLE, MB_OK );

			SetCurrentStatus( CLOSED );
			SetCurrentStatus( READY );
			hr = m_hrAsync;
			return( hr );
		}
#endif

        ////////////////////////////////////////////////////////////////////////////////
        // Check the HRESULT reported by the reader object to the OnStatus 
		//  callback. Most errors in opening files will be reported this way.
		////////////////////////////////////////////////////////////////////////////////
        if( FAILED( m_hrAsync ) )
		{
			hr = m_hrAsync;

			_tcscpy( m_tszErrMsg, _T( "Could not open the specified file" ) );
			break;
		}
		
        
        SAFE_RELEASE( m_pHeaderInfo );
		hr = m_pReader->QueryInterface( IID_IWMHeaderInfo, ( VOID ** )&m_pHeaderInfo );
		if( FAILED (hr) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not QI for IWMHeaderInfo" ) );
			break;
		}

/*		hr = RetrieveAndDisplayAttributes();
		if( FAILED( hr ) )
		{
			break;
		}*/
		
		////////////////////////////////////////////////////////////////////////////////
		// Set the audio ouput number for the current file. 
        // Only the first audio output is retrieved, regardless of the 
		//  number of audio outputs in the file.
		////////////////////////////////////////////////////////////////////////////////
		hr = GetAudioOutput();
		if( FAILED( hr ) )
		{
			break;
		}
	}
	while( FALSE );

	
	if( FAILED( hr ) )
	{
		Close();

		if( _tcslen( m_tszErrMsg ) > 0 )
		{
            wsprintf( m_tszErrMsg, _T("%s (hr=%#X)"), m_tszErrMsg, hr );
			//MessageBox( NULL, m_tszErrMsg, ERROR_DIALOG_TITLE, MB_OK );
		}
	}


	m_bPlayBack = bPlayBack;
	return( hr );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Close()
// Desc: Closes the file.
//------------------------------------------------------------------------------
HRESULT CAudioPlay::Close()
{
	HRESULT hr = S_OK;

	if( NULL != m_pReader )
	{
		hr = m_pReader->Close();
	    if( FAILED ( hr ) )
	    {
		    return( hr );
	    }
	}
	
    
	////////////////////////////////////////////////////////////////////////////////
    // Wait for the reader to deliver a WMT_CLOSED event to the OnStatus
	//  callback.
	////////////////////////////////////////////////////////////////////////////////
    WaitForEvent( m_hAsyncEvent );
	
    ////////////////////////////////////////////////////////////////////////////////
    // Close the wave output device.
    ////////////////////////////////////////////////////////////////////////////////
	/*if( m_hWaveOut )
	{
		if( MMSYSERR_NOERROR != waveOutReset( m_hWaveOut ) )
		{
			return( E_FAIL );
		}

		if( MMSYSERR_NOERROR != waveOutClose( m_hWaveOut ) )
		{
			return( E_FAIL );
		}

		m_hWaveOut = NULL;
	}*/
	
	return( S_OK );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Start()
// Desc: Configures output device and starts reader.
//------------------------------------------------------------------------------
HRESULT CAudioPlay::Start( QWORD cnsStart )
{
	HRESULT hr = S_OK;
	
    ////////////////////////////////////////////////////////////////////////////////
    // Ensure that a reader object has been instantiated.
    ////////////////////////////////////////////////////////////////////////////////
    if( NULL == m_pReader )
    {
        return( E_UNEXPECTED );
    }

	hWriteThread = CreateThread (NULL,
								0,
								(LPTHREAD_START_ROUTINE) WriteAudioThread,
								this,
								0,
								(LPDWORD) &dwWriteThreadID);

	if (hWriteThread == NULL)
	{
		return FALSE;
	}

    ////////////////////////////////////////////////////////////////////////////////
    // Configure the wave output device.
    ////////////////////////////////////////////////////////////////////////////////
	/*if( NULL != m_hWaveOut )
	{
		if( MMSYSERR_NOERROR != waveOutReset( m_hWaveOut ) )
		{
			return( E_FAIL );
		}
	}
	else
	{
			
		if (m_bPlayBack)
		{
			MMRESULT mmr = waveOutOpen( &m_hWaveOut,
										WAVE_MAPPER,
										m_pWfx,
										( DWORD )WaveProc,
										( DWORD )this,
										CALLBACK_FUNCTION );	


			if ( MMSYSERR_ALLOCATED == mmr)
			{
				pParDlg->InsertLog( "MMSYSERR_ALLOCATED" );
			}
			else if ( MMSYSERR_BADDEVICEID == mmr)
			{
				pParDlg->InsertLog( "MMSYSERR_BADDEVICEID" );			
			}
			else if ( MMSYSERR_NODRIVER == mmr)
			{
				pParDlg->InsertLog( "MMSYSERR_NODRIVER" );
			}
			else if ( MMSYSERR_NOMEM == mmr)
			{
				pParDlg->InsertLog( "MMSYSERR_NOMEM" );
			}
			else if ( WAVERR_BADFORMAT == mmr)
			{
				pParDlg->InsertLog( "WAVERR_BADFORMAT" );
			}
			else if ( WAVERR_SYNC == mmr)
			{
				pParDlg->InsertLog( "WAVERR_SYNC" );
			}

			if( MMSYSERR_NOERROR != mmr )
			{
				return( E_FAIL );
			}
		}

        ////////////////////////////////////////////////////////////////////////////////
        // Use another thread for wave output.
        ////////////////////////////////////////////////////////////////////////////////
		HANDLE hThread = CreateThread( NULL, 0, OnWaveOutThread,
									   ( LPVOID )this, NULL, &m_dwThreadID );

		if( NULL == hThread )
		{
			return( HRESULT_FROM_WIN32( GetLastError() ) );
		}
		else
		{
			////////////////////////////////////////////////////////////////////////////////
			// Close the thread handle, as it's no longer required in this thread.
			////////////////////////////////////////////////////////////////////////////////
			CloseHandle( hThread );
		}
	}*/

	return( m_pReader->Start( cnsStart, 0, 1.0, NULL ) );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Stop()
// Desc: Stops the reader.
//------------------------------------------------------------------------------
HRESULT CAudioPlay::Stop()
{
	HRESULT hr = S_OK;   
	
    if( NULL == m_pReader )
    {
        return( E_UNEXPECTED );
    }

	Sleep (10);
	WaitForSingleObject (hWriteThread, 5000);
	
	DWORD dwExitCode;
	GetExitCodeThread (hWriteThread, &dwExitCode);
	if (dwExitCode == STILL_ACTIVE)
	{
		//	wait for the event to be set and then reset
		//WaitForSingleObject (m_event, 2000);
		//ResetEvent (m_event);

		//	if still active, we might have a dead-lock
		//	might be caused by the callback fct
		TerminateThread (hWriteThread, 0);
	}
	hWriteThread = NULL;

#ifdef SUPPORT_DRM
	////////////////////////////////////////////////////////////////////////////////
	// Cancel current DRM operation, if any.
	////////////////////////////////////////////////////////////////////////////////
	hr = objDRM.Cancel();
	if( FAILED( hr ) )
	{
		////////////////////////////////////////////////////////////////////////////////
		// The cancellation of the DRM operation has failed.
		////////////////////////////////////////////////////////////////////////////////
		return( hr );
    }
    
    if( S_OK == hr )
    {
	    ////////////////////////////////////////////////////////////////////////////////
	    // Since the DRM operation has been successfully canceled, the file is not yet opened.
	    // So no need to stop.
	    ////////////////////////////////////////////////////////////////////////////////
	    SetCurrentStatus( CLOSED );
	    SetCurrentStatus( READY );
	    return( hr );
    }
#endif

	

	hr = m_pReader->Stop();
	if( FAILED( hr ) )
	{
		return( hr );
	}
		
	////////////////////////////////////////////////////////////////////////////////
	// Reset the wave output device
	////////////////////////////////////////////////////////////////////////////////
	/*if( NULL != m_hWaveOut )
	{
		if( MMSYSERR_NOERROR != waveOutReset( m_hWaveOut ) )
		{
			return( E_FAIL );
		}
		
        ////////////////////////////////////////////////////////////////////////////////
		// Wait for all audio headers to be unprepared.
        ////////////////////////////////////////////////////////////////////////////////
		WaitForEvent( m_hAsyncEvent );
	}*/
	
	pParDlg->SetCurrentStatus( CLOSED );
	pParDlg->SetCurrentStatus( READY );
    return( S_OK );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Pause()
// Desc: Pauses the reader and the output device.
//------------------------------------------------------------------------------
HRESULT CAudioPlay::Pause()
{
    ////////////////////////////////////////////////////////////////////////////////
    // Sanity check
    ////////////////////////////////////////////////////////////////////////////////
    if( NULL == m_pReader )
    {
        return( E_UNEXPECTED );
    }

	/*if( NULL != m_hWaveOut )
	{
		////////////////////////////////////////////////////////////////////////////////
		// Pause the wave output device
		////////////////////////////////////////////////////////////////////////////////
		if( MMSYSERR_NOERROR != waveOutPause( m_hWaveOut ) )
		{
			return( E_FAIL );
		}
	}*/

	return( m_pReader->Pause() );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::Resume()
// Desc: Resumes after pause.
//------------------------------------------------------------------------------
HRESULT CAudioPlay::Resume()
{
    ////////////////////////////////////////////////////////////////////////////////
    // Sanity check
    ////////////////////////////////////////////////////////////////////////////////
    if( NULL == m_pReader )
    {
        return( E_UNEXPECTED );
    }

	/*if( NULL != m_hWaveOut )
	{
		////////////////////////////////////////////////////////////////////////////////
		// Resume the wave output device
		////////////////////////////////////////////////////////////////////////////////
		if( MMSYSERR_NOERROR != waveOutRestart( m_hWaveOut ) )
		{
			return( E_FAIL );
		}
	}*/

	return( m_pReader->Resume() );
}


//------------------------------------------------------------------------------
// Name: CAudioPlay::ReopenReader()
// Desc: Opens reader after DRM operations.
//------------------------------------------------------------------------------

#ifdef SUPPORT_DRM

HRESULT CAudioPlay::ReopenReader( void *pvContext )
{
	if( NULL == m_pReader )
	{
        return( E_UNEXPECTED );
    }

	m_bProcessingDRMOps = FALSE;
	return m_pReader->Open( m_pwszURL, this, pvContext );
}
#endif

//------------------------------------------------------------------------------
// Name: CAudioPlay::SetAsyncEvent()
// Desc: This method sets the asynchronous event. When an asynchronous method
//  is called in the other methods of this class, execution of that thread waits
//  for the asynchronous event to be set.
//------------------------------------------------------------------------------
void CAudioPlay::SetAsyncEvent( HRESULT hrAsync )
{
	m_hrAsync = hrAsync;
	SetEvent( m_hAsyncEvent );
}


//////////////////////////////////////////////////////////////////////////////////
// 函数功能:  获取广播长度
// 输入参数: 
// 输出参数:
// 返回值  :
//				QWORD				-- 广播长度
// 备    注:
//////////////////////////////////////////////////////////////////////////////////
QWORD CAudioPlay::GetFileDuration()
{
	return( m_cnsFileDuration );
}


//---------------------------------------------------------------
// 函数功能:  获取是否可遍历属性
// 输入参数: 
// 输出参数:
// 返回值  :
//				BOOL				-- 是否可遍历
// 备    注:
//----------------------------------------------------------------
BOOL CAudioPlay::IsSeekable()
{
	return( m_bIsSeekable );
}


//////////////////////////////////////////////////////////////////////////////////
// 函数功能:  获取广播属性
// 输入参数: 
// 输出参数:
// 返回值  :
//				BOOL				-- 是否是广播
// 备    注:
//////////////////////////////////////////////////////////////////////////////////
BOOL CAudioPlay::IsBroadcast()
{
	return( m_bIsBroadcast );
}

//---------------------------------------------------------------
// 函数功能:  启动处理WaveOut消息的线程
// 输入参数: 
// 输出参数:
// 返回值  :
//				DWORD				-- 操作结果
// 备    注:
//----------------------------------------------------------------
DWORD WINAPI CAudioPlay::OnWaveOutThread( LPVOID lpParameter )
{
	//-----------------------
    // Step1: 定义变量
    //-----------------------
	CAudioPlay* pThis = ( CAudioPlay* )lpParameter;

	//--------------------------------------------------
    // Step2: 重定向到CAudioPlay类的静态处理函数
    //--------------------------------------------------
	pThis->OnWaveOutMsg();

	return( 0 );
}


//------------------------------------------------------------------------------
// Name: CAudioPlay::WaveProc()
// Desc: Callback passed to waveOutOpen.
//------------------------------------------------------------------------------
void CALLBACK CAudioPlay::WaveProc( HWAVEOUT hwo,
									UINT uMsg, 
									DWORD dwInstance,
									DWORD dwParam1,
									DWORD dwParam2 )
{
	CAudioPlay* pThis = ( CAudioPlay* )dwInstance;
	
	////////////////////////////////////////////////////////////////////////////////
	// Redirect the processing to a different thread
	////////////////////////////////////////////////////////////////////////////////
	PostThreadMessage( pThis->m_dwThreadID, uMsg, dwParam1, dwParam2 );
}

void CAudioPlay::OnWriteAudioMsg()
{
}

//---------------------------------------------------------------
// 函数功能:  WaveOut消息处理
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//----------------------------------------------------------------
void CAudioPlay::OnWaveOutMsg()
{
	//-----------------------
    // Step1: 定义变量
    //-----------------------
	HRESULT     hr = S_OK;
    LPWAVEHDR   pwh = NULL;
    MMRESULT    mmr = MMSYSERR_NOERROR;
	MSG         uMsg;

	//------------------------
    // Step2: 创建消息队列
    //------------------------
	PeekMessage( &uMsg, NULL, WM_USER, WM_USER, PM_NOREMOVE );

	//------------------------------------------
    // Step3: 消息队列已经创建了，我们来取消息
    //------------------------------------------
    while( 0 != GetMessage( &uMsg, NULL, 0, 0 ) )
    {
        switch( uMsg.message )
        {
		case WOM_DONE:
			//------------------------------------------
			// Step3.1: 重置wave header, 因为已经播放
			//------------------------------------------
			pwh = ( LPWAVEHDR )uMsg.wParam;

			/*mmr = waveOutUnprepareHeader( m_hWaveOut, pwh, sizeof( WAVEHDR ) );

			if( MMSYSERR_NOERROR == mmr )
			{
				InterlockedDecrement( &m_cHeadersLeft );
			}
			else if( WHDR_ENDLOOP == mmr )
            {
                SetEvent( m_hAsyncEvent );
            }
			else
			{
              	//------------------------------------------
				// Step3.1.1 发生错误时停止播放
				//------------------------------------------
				SendMessage((HWND)pParDlg, WM_COMMAND, IDC_STOP, 0);
				pParDlg->InsertLog( "Wave function (waveOutUnprepareHeader) failed" );
			}

           	//------------------------------------------
			// Step3.2 如果没有空闲的缓冲区停止
			//------------------------------------------
			if( m_bEOF && ( 0 == m_cHeadersLeft ) )
			{
				pParDlg->SetCurrentStatus( STOP );
			}*/

			SAFE_ARRAYDELETE(pwh);

            break;			

		case WOM_CLOSE:

			PostQuitMessage( 0 );
			break;
		}
	}

    return;
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::WaitForEvent()
// Desc: Waits for the specified event to be signaled. 
//       The maximum wait time is msMaxWaitTime.
//------------------------------------------------------------------------------
void CAudioPlay::WaitForEvent( HANDLE hEvent, DWORD msMaxWaitTime )
{
    DWORD   i;
	MSG     msg;

    for( i = 0; i < msMaxWaitTime; i += 10 )
    {
        if( PeekMessage( &msg, ( HWND ) NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }

        if( WAIT_TIMEOUT != WaitForSingleObject( hEvent, 10 ) )
        {
            break;
        }
    }
    
	return;
}


//////////////////////////////////////////////////////////////////////////////////
// 函数功能:  获取第一个音频输出的wave格式
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//////////////////////////////////////////////////////////////////////////////////
HRESULT CAudioPlay::GetAudioOutput()
{
	//---------------------
    // Step1: 定义变量
    //---------------------
	WORD					wFormatTag	= WAVE_FORMAT_ALAW; 
	DWORD                   cOutputs	= 0;
    DWORD                   i			= 0;	
	ULONG                   cbType		= 0;
	HRESULT                 hr			= S_OK;
    IWMOutputMediaProps*    pProps		= NULL;
	WM_MEDIA_TYPE*          pMediaType	= NULL;
	WAVEFORMATEX*			pwfDrv		= NULL;	
	WAVEFORMATEX*			pwfPCM		= NULL;
	char					temp[1024];

    //------------------------
    // Step2: 数据有效性验证
    //------------------------
    if( NULL == m_pReader )
    {
        return( E_UNEXPECTED );
    }

	//-------------------------------------------------------
    // Step3: 获取音频输出的格式,目前只处理第一个音频输出
    //-------------------------------------------------------
	do
	{
        //------------------------------------
        // Step3.1 查询媒体个数
        //------------------------------------
        hr = m_pReader->GetOutputCount( &cOutputs );
		if( FAILED( hr ) )
		{			
			_tcscpy( m_tszErrMsg, _T( "Could not get output count" ) );
			break;
		}

		//------------------------------------------------------------------------------
		// Step3.2 查询第一个音频输出
		// Note: 目前只处理第一个音频输出,如果此处多于一个音频输出,将选择第一个        
		//------------------------------------------------------------------------------
		for( i = 0; i < cOutputs; i++ )
		{
			//---------------------------
			// Step3.2.1 初始化变量        
			//---------------------------
			SAFE_RELEASE( pProps );
			SAFE_ARRAYDELETE( pMediaType );

			//-----------------------------------
			// Step3.2.2 查询媒体属性     
			//-----------------------------------
			hr = m_pReader->GetOutputProps( i, &pProps );
			if( FAILED( hr ) )
			{
				_tcscpy( m_tszErrMsg, _T( "Could not get output props" ) );
				break;
			}

            //----------------------------------------------------
            // Step3.2.3 查询媒体属性的长度,并为变量分配空间
            //----------------------------------------------------
			hr = pProps->GetMediaType( NULL, &cbType );
			if( FAILED( hr ) )
			{
				_tcscpy( m_tszErrMsg, _T( "Could not query for the space needed for media type" ) );
				break;
			}

			pMediaType = ( WM_MEDIA_TYPE* ) new BYTE[ cbType ];
			if( NULL == pMediaType )
			{
				hr = HRESULT_FROM_WIN32( GetLastError() ) ;
    			_tcscpy( m_tszErrMsg, _T( "Insufficient memory" ) );
				break;
			}

            //--------------------------------
            // Step3.2.4 查询媒体属性
            //--------------------------------
			hr = pProps->GetMediaType( pMediaType, &cbType );
			if( FAILED( hr ) )
			{
				_tcscpy( m_tszErrMsg, _T( "Could not get media type" ) );
				break;
			}
			
			//-----------------------------------------------------------
            // Step3.2.5 判断媒体属性是否为音频,并且其格式是否为音频格式,
			//			 符合将其存储
            //-----------------------------------------------------------
			if(( WMMEDIATYPE_Audio == pMediaType->majortype )
				&& (pMediaType->formattype == WMFORMAT_WaveFormatEx))				
            {
				//------------------------------------
				// Step3.4 存储此输出的音频格式
				//------------------------------------
				m_dwAudioOutputNum = i;

				SAFE_ARRAYDELETE( m_pWfx );      

				m_pWfx = ( WAVEFORMATEX * )new BYTE[ pMediaType->cbFormat ];
				if( NULL == m_pWfx )
				{
					hr = HRESULT_FROM_WIN32( GetLastError() ) ;
    				_tcscpy( m_tszErrMsg, _T( "Insufficient memory" ) );
					break;
				}
				CopyMemory( m_pWfx, pMediaType->pbFormat, pMediaType->cbFormat );

				SAFE_ARRAYDELETE( m_pSrcWfx ); 	
				m_pSrcWfx = ( WAVEFORMATEX * )new BYTE[ pMediaType->cbFormat ];
				if( NULL == m_pSrcWfx )
				{
					hr = HRESULT_FROM_WIN32( GetLastError() ) ;
    				_tcscpy( m_tszErrMsg, _T( "Insufficient memory" ) );
					break;
				}
				CopyMemory( m_pSrcWfx, pMediaType->pbFormat, pMediaType->cbFormat );
				break;
            }
		}
		
		SAFE_RELEASE( pProps );
		SAFE_ARRAYDELETE( pMediaType );

		if( FAILED( hr ) )
		{
			break;
		}

		//-----------------------------------------------
		// Step3.3 在此媒体文件中未发现音频输出,则返回		       
		//-----------------------------------------------
		if( i == cOutputs )
		{			
			hr = E_UNEXPECTED;
			_tcscpy( m_tszErrMsg, _T( "Could not find an audio stream in the specified file" ) );
			break;
		}
        
		//------------------------------------
        // Step3.5 查询支持指定格式的驱动
        //------------------------------------
		wFormatTag = WAVE_FORMAT_ALAW;
		hadid = find_driver( wFormatTag );
		if (hadid == NULL) 
		{
			hr = HRESULT_FROM_WIN32( GetLastError() ) ;
			_tcscpy( m_tszErrMsg, _T( "not find driver" ) );
			break;
		}
		
		//------------------------------------------------------
        // Step3.6 获得格式的详细描述
		// 注意：这只是一个给定格式签的第一种或是最可能的格式
        //------------------------------------------------------
		pwfDrv = get_driver_format(hadid, wFormatTag);
		if (pwfDrv == NULL) 
		{
			hr = HRESULT_FROM_WIN32( GetLastError() ) ;
			_tcscpy( m_tszErrMsg, _T( "get_driver_format error" ) );
			break;
		}
		SAFE_ARRAYDELETE( m_pDstWfx );
		m_pDstWfx = ( WAVEFORMATEX * )new BYTE[ sizeof(WAVEFORMATEX) ];
		if( NULL == m_pDstWfx )
		{
			hr = HRESULT_FROM_WIN32( GetLastError() ) ;
    		_tcscpy( m_tszErrMsg, _T( "Insufficient memory" ) );
			break;
		}
		CopyMemory( m_pDstWfx, pwfDrv, sizeof(WAVEFORMATEX) );

		memset(temp, 0x00, sizeof(temp));
		sprintf(temp, "Driver format: %u bits, %lu samples per second\n",
			 pwfDrv->wBitsPerSample, pwfDrv->nSamplesPerSec);
		pParDlg->InsertLog( temp );

		
		//---------------------------------------------------------
        // Step3.7 获取驱动程序所支持的PCM格式
		// 注意：我们只是选取第一支持的PCM格式但不一定是最好的选择
        //---------------------------------------------------------
		pwfPCM = get_driver_format( hadid, WAVE_FORMAT_PCM );
		if (pwfPCM == NULL) 
		{        
			hr = HRESULT_FROM_WIN32( GetLastError() ) ;
			_tcscpy( m_tszErrMsg, _T( "get_driver_format(PCM) error" ) );
			break;
		}   
		SAFE_ARRAYDELETE( m_pMidWfx );
		m_pMidWfx = ( WAVEFORMATEX * )new BYTE[ sizeof(WAVEFORMATEX) ];
		if( NULL == m_pMidWfx )
		{
			hr = HRESULT_FROM_WIN32( GetLastError() ) ;
    		_tcscpy( m_tszErrMsg, _T( "Insufficient memory" ) );
			break;
		}
		CopyMemory( m_pMidWfx, pwfPCM, sizeof(WAVEFORMATEX) );

		memset(temp, 0x00, sizeof(temp));
		sprintf(temp, "PCM format: %u bits, %lu samples per second\n",
			 pwfPCM->wBitsPerSample, pwfPCM->nSamplesPerSec);
		pParDlg->InsertLog( temp ); 		

		SAFE_ARRAYDELETE( pwfPCM );
		SAFE_ARRAYDELETE( pwfDrv );
				
	}
	while( FALSE );
	
	//-------------------------------
    // Step4: 释放资源,返回结果
    //-------------------------------
	SAFE_ARRAYDELETE( pwfPCM );
	SAFE_ARRAYDELETE( pwfDrv );
	SAFE_ARRAYDELETE( pMediaType );
	SAFE_RELEASE( pProps );
	SAFE_ARRAYDELETE( m_pWfx );	

	if( FAILED( hr ) )
	{
        wsprintf( m_tszErrMsg, _T("%s (hr=%#X)"), m_tszErrMsg, hr );		
	}

	return( hr );
}

//------------------------------------------------------------------------------
// Name: CAudioPlay::RetrieveAndDisplayAttributes()
// Desc: Retrieves and displays title, author, copyright and duration info.
//       Retrieves Seekable and Broadcast attributes
//------------------------------------------------------------------------------
HRESULT CAudioPlay::RetrieveAndDisplayAttributes()
{
	BYTE*   pbValue = NULL;
	HRESULT hr = S_OK;	
	WCHAR   wszNoData[] = L"No Data";

	do
	{
		////////////////////////////////////////////////////////////////////////////////
		// Get attribute "Title"
		////////////////////////////////////////////////////////////////////////////////
		hr = GetHeaderAttribute( g_wszWMTitle, &pbValue );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not get the Title attribute" ) );
			break;
		}
		
		if( NULL != pbValue )
		{
			pParDlg->SetItemText( IDC_CLIP, ( LPWSTR )pbValue );
			SAFE_ARRAYDELETE( pbValue );
        }
		else
		{
			pParDlg->SetItemText( IDC_CLIP, wszNoData );
		}
		
		////////////////////////////////////////////////////////////////////////////////
		// Get attribute "Author"
		////////////////////////////////////////////////////////////////////////////////
		hr = GetHeaderAttribute( g_wszWMAuthor, &pbValue );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not get the Author attribute" ) );
			break;
		}

		if( NULL != pbValue )
		{
			pParDlg->SetItemText( IDC_AUTHOR, ( LPWSTR )pbValue  );
			SAFE_ARRAYDELETE( pbValue );
		}
		else
		{
			pParDlg->SetItemText( IDC_AUTHOR, wszNoData );
		}

		////////////////////////////////////////////////////////////////////////////////
		// Get attribute "Copyright"
		////////////////////////////////////////////////////////////////////////////////
		hr = GetHeaderAttribute( g_wszWMCopyright, &pbValue );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not get the Copyright attribute" ) );
			break;
		}

		if( NULL != pbValue )
		{
			pParDlg->SetItemText( IDC_COPYRIGHT, ( LPWSTR )pbValue  );
			SAFE_ARRAYDELETE( pbValue );
		}
		else
		{
			pParDlg->SetItemText( IDC_COPYRIGHT, wszNoData );
		}
		
		////////////////////////////////////////////////////////////////////////////////
		// Get attribute "Duration"
		////////////////////////////////////////////////////////////////////////////////
		hr = GetHeaderAttribute( g_wszWMDuration, &pbValue );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not get the Duration attribute" ) );
			break;
		}

        if( NULL != pbValue )
        {
            m_cnsFileDuration = *( QWORD* )pbValue;
			//SAFE_ARRAYDELETE( pbValue );
        }
        else
        {
            m_cnsFileDuration = 0;
        }

		pParDlg->SetTime( 0, m_cnsFileDuration );

        ////////////////////////////////////////////////////////////////////////////////
        // Retrieve Seekable attribute
        ////////////////////////////////////////////////////////////////////////////////
		hr = GetHeaderAttribute( g_wszWMSeekable, &pbValue );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not get the Seekable attribute" ) );
			break;
		}

		if( NULL != pbValue )
		{
            m_bIsSeekable = *( BOOL* )pbValue;
        }
        else
        {
            m_bIsSeekable = FALSE;
        }
        
        ////////////////////////////////////////////////////////////////////////////////
        // Retrieve Broadcast attribute
        ////////////////////////////////////////////////////////////////////////////////
		hr = GetHeaderAttribute( g_wszWMBroadcast, &pbValue );
		if( FAILED( hr ) )
		{
			_tcscpy( m_tszErrMsg, _T( "Could not get the Broadcast attribute" ) );
			break;
		}

		if( NULL != pbValue )
		{
            m_bIsBroadcast = *( BOOL* )pbValue;
        }
        else
        {
            m_bIsBroadcast = FALSE;
        }
   	}
	while (FALSE );
		
	if( FAILED( hr ) )
	{
        wsprintf( m_tszErrMsg, _T("%s (hr=%#X)"), m_tszErrMsg, hr );
		//MessageBox( NULL, m_tszErrMsg, ERROR_DIALOG_TITLE, MB_OK );
	}

	return( hr );
}


//////////////////////////////////////////////////////////////////////////////////
// 函数功能:  获取指定头属性值
// 输入参数: 
// 输出参数:
// 返回值  :
//				HRESULT				-- 操作结果
// 备    注:
//////////////////////////////////////////////////////////////////////////////////
HRESULT CAudioPlay::GetHeaderAttribute( LPCWSTR pwszName, BYTE** ppbValue )
{
	BYTE                *pbValue = NULL;
	HRESULT             hr = S_OK;
	WMT_ATTR_DATATYPE   wmtType;
	WORD                wStreamNum = 0;
    WORD                cbLength = 0;

    //--------------------
    // Step1: 有效性验证
    //--------------------
    if( NULL == m_pHeaderInfo )
    {
        return( E_UNEXPECTED );
    }

    if( NULL == ppbValue )
    {
        return( E_INVALIDARG );
    }

	//-------------------------------------
	// Step2: 获取为指定属性分配的字节数
	//-------------------------------------
	hr = m_pHeaderInfo->GetAttributeByName( &wStreamNum,
										    pwszName,
										    &wmtType,
										    NULL,
										    &cbLength );
	if( FAILED( hr ) && ( ASF_E_NOTFOUND != hr ) )
	{
		return( hr );
	}

    //-----------------------------------------------------
    // Step2.1: 如果未查找到属性，则返回，且属性值置为NULL
    //-----------------------------------------------------
	if( ASF_E_NOTFOUND == hr )
	{
        *ppbValue = NULL;
		return( S_OK );
	}

	//--------------------------------------------
	// Step3: 分配属性值的存储空间，并获取实际值
	//--------------------------------------------
	pbValue = new BYTE[ cbLength ];
	if( NULL == pbValue )
	{
		return( HRESULT_FROM_WIN32( GetLastError() ) );
	}

	hr = m_pHeaderInfo->GetAttributeByName( &wStreamNum,
										    pwszName,
										    &wmtType,
										    pbValue,
										    &cbLength );

	//--------------------------------------------
	// Step4: 将值赋给输出参数，并释放资源
	//--------------------------------------------
	*ppbValue = pbValue;
	//SAFE_ARRAYDELETE( pbValue );	

	return( S_OK );
}


CSync::CSync ()
{
	m_sync = CreateMutex (NULL, false, NULL);
	if (m_sync == NULL)
	{
		//throw CError (1001);
	}
}

CSync::~CSync()
{
	if (m_sync != NULL)
	{
		CloseHandle (m_sync);
		m_sync = NULL;
	}
}

void CSync::Enter () const
{
	WaitForSingleObject (m_sync, INFINITE);
}

void CSync::Leave () const
{
	ReleaseMutex (m_sync);
}




int CAudioPlay::WriteAudioThread(void *pThis)
{
	return ((CAudioPlay*) (pThis))->WriteAudioWait ();
}

int CAudioPlay::WriteAudioWait()
{
	const int MAX_WRITE_NUM = 10240;
	int nMaxByte = 0; 
	int iAudioDataCount = 0;
	CFile		file;

	HRESULT		hr = S_OK;
	char	buffer[MAX_WRITE_NUM];
	int		iBufferLen = 0;
	

	while (true)
	{
		m_sync.Enter ();
		iAudioDataCount = m_AudioData.Length();
		m_sync.Leave ();
		
		if (iAudioDataCount > 0)
		{		
			memset(buffer, 0x00, sizeof(buffer));
			if (iAudioDataCount > 10240)
			{
				iBufferLen = 10240;
			}
			else
			{
				iBufferLen = iAudioDataCount;
			}
			m_sync.Enter ();
			m_AudioData.Remove(buffer, iBufferLen);
			m_sync.Leave ();

			try
			{			
				nMaxByte = m_pDstWfx->nAvgBytesPerSec * MAXFILERECSECOND;
				if (nFileByte >= nMaxByte)
				{
					nFileByte = 0;
					if (nFileNo == 1)
					{
						nFileNo = 2;
						if( !file.Open( m_SaveURLB, 
							CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone |  CFile::typeBinary, 
							NULL ) )
						{
							hr = E_FAIL;
						}
					}
					else if (nFileNo == 2)
					{
						nFileNo = 3;					
						if( !file.Open( m_SaveURLC, 
							CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone |  CFile::typeBinary, 
							NULL ) )
						{
							hr = E_FAIL;
						}
					}
					else 
					{
						nFileNo = 1;					
						if( !file.Open( m_SaveURLA, 
							CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone |  CFile::typeBinary, 
							NULL ) )
						{
							hr = E_FAIL;
						}
					}
				}
				else
				{
					if (nFileNo == 1)
					{
						if( !file.Open( m_SaveURLA, 
							CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyNone |  CFile::typeBinary, 
							NULL ) )
						{
							hr = E_FAIL;
						}
					}
					else if (nFileNo == 2)
					{
						if( !file.Open( m_SaveURLB, 
							CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyNone |  CFile::typeBinary, 
							NULL ) )
						{
							hr = E_FAIL;
						}		
					}
					else
					{
						if( !file.Open( m_SaveURLC, 
							CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyNone |  CFile::typeBinary, 
							NULL ) )
						{
							hr = E_FAIL;
						}		
					}
				}
				
				if ( hr == S_OK )
				{
					file.SeekToEnd();	

					//file.Write(astrhdrDst.pbDst, astrhdrDst.cbDstLengthUsed);
					file.Write( buffer, iBufferLen );
					file.Close(); 
					//nFileByte += astrhdrDst.cbDstLengthUsed;
					nFileByte += iBufferLen;
				}
			}
			catch(...)
			{
				
			}
		}
		Sleep(10);
	}

	return 0;
}
