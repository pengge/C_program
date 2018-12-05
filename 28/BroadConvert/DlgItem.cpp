// DlgItem.cpp : implementation file
//

#include "stdafx.h"
#include "BroadConvert.h"
#include "DlgItem.h"
#include <Commdlg.h>
#include <commctrl.h>
#include <stdio.h>
#include "AudioPlay.h"
#include "TagDefine.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgItem property page

IMPLEMENT_DYNCREATE(CDlgItem, CPropertyPage)

CDlgItem::CDlgItem() : CPropertyPage(CDlgItem::IDD)
{
	//{{AFX_DATA_INIT(CDlgItem)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDlgItem::~CDlgItem()
{
//	KillTimer( 200 );
	if( NULL != g_pAudioplay )
	{
		g_pAudioplay->Exit();
		g_pAudioplay->Release();
	}

	if (hHeap != NULL)
	{
		HeapDestroy(hHeap);
	}
}

void CDlgItem::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgItem)
	DDX_Control(pDX, IDC_EDIT_DESFILEC, m_editDesFileC);
	DDX_Control(pDX, IDC_CHECK_PLAYBACK, m_CheckPlay);
	DDX_Control(pDX, IDC_EDIT_DESFILEB, m_editDesFileB);
	DDX_Control(pDX, IDC_EDIT_DESFILEA, m_editDesFileA);
	DDX_Control(pDX, IDC_PLAY, m_ButPlay);
	DDX_Control(pDX, IDC_STATUS, m_editStatus);
	DDX_Control(pDX, IDC_DURATION, m_editDuration);	
	DDX_Control(pDX, IDC_EDIT_SOURCE, m_editSource);
	DDX_Control(pDX, IDC_SLIDER, m_ctrlSlider);
	DDX_Control(pDX, IDC_STOP, m_ButStop);
	DDX_Control(pDX, IDC_PAUSE, m_ButPause);
	DDX_Control(pDX, IDC_OPEN, m_ButOpen);
	DDX_Control(pDX, IDC_LIST_LOG, m_LogList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgItem, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgItem)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgItem message handlers

BOOL CDlgItem::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	//-----------------------
	// Step1: 定义变量 
	//-----------------------
	HRESULT		hr		= S_OK;
	TCHAR		tszFileName[ MAX_PATH ];

	//------------------------------------------------
	// Step2: 准备打开播放文件,创建并初始化音频播放器
	//------------------------------------------------
	SetCurrentStatus( READY );
	
	hHeap = NULL;
	hHeap = HeapCreate(0, HEAPSIZE, 0);
	if (hHeap == NULL)
	{
		return FALSE;
	}

	g_pAudioplay = new CAudioPlay;
	if( NULL == g_pAudioplay )
	{	
		return FALSE;
	}


	hr = g_pAudioplay->Init();
	if( FAILED(hr) )
	{
		return FALSE;
	}

	g_pAudioplay->pParDlg = this;

	m_editSource.SetWindowText( g_ptszFileName );
	m_editDesFileA.SetWindowText( g_pSaveFileNameA );
	m_editDesFileB.SetWindowText( g_pSaveFileNameB );
	m_editDesFileC.SetWindowText( g_pSaveFileNameC );

	m_CheckPlay.SetCheck( m_bPlayBack );
	m_ButPlay.SetFocus();
	
	

	GetDlgItemText( IDC_EDIT_SOURCE, tszFileName, MAX_PATH );

    //------------------------------------------------
	// Step3: 如果filename不为空，则使得Play按钮可用
	//------------------------------------------------
	if( _tcslen( tszFileName) > 0 )
	{
		m_ButPlay.EnableWindow( TRUE );
		
		SetCurrentStatus( CLOSED );
	}
	else
	{
		m_ButPlay.EnableWindow( FALSE );		
	}
	
	SetCurrentStatus( READY );
	
	//OnPlay();
	SetTimer(200, 60000, NULL);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgItem::InsertLog(char *log)
{
	if (log == NULL)
		return;

	m_LogList.AddString(log);
}

void CDlgItem::SetTime(QWORD cnsTimeElapsed, QWORD cnsFileDuration)
{
	////////////////////////////////////////////////////////////////////////////////
	// Do not set new time if seeking is going on
	////////////////////////////////////////////////////////////////////////////////
	if( g_IsSeeking )
	{
		return;
	}

    DWORD dwSeconds = 0;
    TCHAR tszTime[20];
	TCHAR tszTemp[10];
	UINT  nHours = 0;
    UINT  nMins = 0;
	
	ZeroMemory( (void *)tszTime, sizeof( tszTime ) );

    dwSeconds = ( DWORD )( cnsTimeElapsed / 10000000 );
	nHours = dwSeconds / 60 / 60;
	dwSeconds %= 3600;
	nMins = dwSeconds / 60;
	dwSeconds %= 60;

    ////////////////////////////////////////////////////////////////////////////////
    // Format the string
    ////////////////////////////////////////////////////////////////////////////////
	if( 0 != nHours )
	{
		_stprintf( tszTemp, _T( "%d:" ), nHours );
		_tcscat( tszTime, tszTemp );
	}
	
	_stprintf( tszTemp, _T( "%02d:%02d / " ), nMins, dwSeconds );
	_tcscat( tszTime, tszTemp );
	
	nHours = 0;
    nMins = 0;

    dwSeconds = ( DWORD )( cnsFileDuration / 10000000 );
	nHours = dwSeconds / 60 / 60;
	dwSeconds %= 3600;
	nMins = dwSeconds / 60;
	dwSeconds %= 60;

    if( 0 != nHours )
	{
		_stprintf( tszTemp, _T( "%d:" ), nHours );
		_tcscat( tszTime, tszTemp );
	}
	
	_stprintf( tszTemp, _T( "%02d:%02d" ), nMins, dwSeconds );
	_tcscat( tszTime, tszTemp );

    SendDlgItemMessage( IDC_SLIDER , TBM_SETPOS, TRUE, ( LONG )( cnsTimeElapsed / 10000 ) );
	SendDlgItemMessage( IDC_DURATION, WM_SETTEXT, 0, ( WPARAM )tszTime );

    return;
}

void CDlgItem::SetCurrentStatus(AUDIOSTATUS currentStatus)
{
	switch( currentStatus )
	{	
	case READY:

		m_editStatus.SetWindowText( "Ready" );
				
		m_ButStop.EnableWindow( FALSE );
		m_ButPause.EnableWindow( FALSE );
		m_ButOpen.EnableWindow( TRUE );

		m_editSource.SetReadOnly( FALSE );
		m_editDesFileA.SetReadOnly( FALSE );
		m_editDesFileB.SetReadOnly( FALSE );
		m_editDesFileC.SetReadOnly( FALSE );
		
		return;

	case OPENING:

		m_editStatus.SetWindowText( "Opening..." );

		m_ButStop.EnableWindow( TRUE );
		m_ButPlay.EnableWindow( FALSE );
		m_ButPause.EnableWindow( FALSE );
		m_ButOpen.EnableWindow( FALSE );
		m_ctrlSlider.EnableWindow( FALSE );
		

		SendDlgItemMessage( IDC_EDIT_SOURCE, EM_SETREADONLY, TRUE, 0 );
		SendDlgItemMessage( IDC_EDIT_DESFILEA, EM_SETREADONLY, TRUE, 0 );
		SendDlgItemMessage( IDC_EDIT_DESFILEB, EM_SETREADONLY, TRUE, 0 );
		SendDlgItemMessage( IDC_EDIT_DESFILEC, EM_SETREADONLY, TRUE, 0 );
		m_ButStop.SetFocus();		
		break;

	case PLAY:
		////////////////////////////////////////////////////////////////////////////////
		// Reset the global variable which might have been set while seeking
		// or stop operation
		////////////////////////////////////////////////////////////////////////////////
		g_IsSeeking = FALSE;

		m_editStatus.SetWindowText( "Playing..." );

		m_ButStop.EnableWindow( TRUE );
		m_ButPlay.EnableWindow( FALSE );
		m_ButOpen.EnableWindow( FALSE );
		m_ctrlSlider.EnableWindow( g_pAudioplay->IsSeekable() );
        {
            DWORD max = SendDlgItemMessage( IDC_SLIDER, TBM_GETRANGEMAX, 0,0 );
        }

		m_editSource.SetReadOnly( TRUE );
		m_editDesFileA.SetReadOnly( TRUE );
		m_editDesFileB.SetReadOnly( TRUE );
		m_editDesFileC.SetReadOnly( TRUE );
		
		if( !g_pAudioplay->IsBroadcast() )
		{
			m_ButPause.EnableWindow( TRUE );
			m_ButPause.SetFocus();		    
		}
        else
        {
			m_ButPause.EnableWindow( FALSE );
			m_ButStop.SetFocus();		    
        }

		break;

	case PAUSE:

		m_editStatus.SetWindowText( "Paused" ) ;
		
		m_ButPause.EnableWindow( FALSE );
		m_ButPlay.EnableWindow( TRUE );
		m_ctrlSlider.EnableWindow( FALSE );

		m_ButPlay.SetFocus();
		
		break;

	case CLOSED:

		m_editStatus.SetWindowText( "" ) ;

		m_ButOpen.EnableWindow( TRUE );
		m_ctrlSlider.EnableWindow( FALSE );
		m_ButStop.EnableWindow( FALSE );
		m_ButPlay.EnableWindow( TRUE );

		m_editSource.SetReadOnly( FALSE );
		m_editDesFileA.SetReadOnly( FALSE );
		m_editDesFileB.SetReadOnly( FALSE );
		m_editDesFileC.SetReadOnly( FALSE );
		
		SendDlgItemMessage( IDC_SLIDER , TBM_SETPOS, TRUE, 0 );
		m_editDuration.SetWindowText( "" );		

		break;

	case STOP:
		
		m_editStatus.SetWindowText( "Stopped" );
		
		SendDlgItemMessage( IDC_SLIDER , TBM_SETPOS, TRUE, 0 ); 

        m_ButPause.EnableWindow( FALSE );
		m_ButStop.EnableWindow( FALSE );
		m_ButPlay.EnableWindow( TRUE );
		m_ButOpen.EnableWindow( TRUE );
		m_ctrlSlider.EnableWindow( FALSE );

		m_editSource.SetReadOnly( FALSE );
		m_editDesFileA.SetReadOnly( FALSE );
		m_editDesFileB.SetReadOnly( FALSE );
		m_editDesFileC.SetReadOnly( FALSE );

		m_ButPlay.SetFocus();
		
		g_IsSeeking = FALSE;
        SetTime( 0, g_pAudioplay->GetFileDuration() );

		break;

	case BUFFERING:

		m_editStatus.SetWindowText( "Buffering..." );
		return;

	case STOPPING:
		////////////////////////////////////////////////////////////////////////////////
		// Since we are going to position the trackbar at the beginning,
		// set the global variable
		////////////////////////////////////////////////////////////////////////////////
		g_IsSeeking = TRUE;
		m_editStatus.SetWindowText( "Trying to Stop...Please Wait" ) ;
			
		m_ButStop.EnableWindow( FALSE );
		m_ButPause.EnableWindow( FALSE );
		m_ButOpen.EnableWindow( FALSE );
		m_ctrlSlider.EnableWindow( FALSE );

		m_editSource.SetReadOnly( TRUE );
		m_editDesFileA.SetReadOnly( TRUE );
		m_editDesFileB.SetReadOnly( TRUE );
		m_editDesFileC.SetReadOnly( TRUE );
		m_editStatus.SetFocus();
		
		return;

	case ACQUIRINGLICENSE:

		m_editStatus.SetWindowText( "Acquiring License..." );
		m_ButStop.EnableWindow( TRUE );

		{
			LPTSTR ptszFile = _tcsrchr( g_ptszFileName, _T( '\\' ) );
            if( NULL == ptszFile )
            {
			    SetWindowText( g_ptszFileName );
            }
            else
            {
			    SetWindowText( ptszFile + 1 );
            }
		}

		m_ButStop.SetFocus();		
		break;

	case INDIVIDUALIZING:

		m_editStatus.SetWindowText( "Individualizing..." );
		m_ButStop.EnableWindow( TRUE );

		{
			LPTSTR ptszFile = _tcsrchr( g_ptszFileName, _T( '\\' ) );
            if( NULL == ptszFile )
            {
			    SetWindowText( g_ptszFileName );
            }
            else
            {
			    SetWindowText( ptszFile + 1 );
            }
		}

		m_ButStop.SetFocus();		
		break;

	case LICENSEACQUIRED:
		m_editStatus.SetWindowText( "License acquired" ) ;
		break;

	case INDIVIDUALIZED:
		m_editStatus.SetWindowText( "Individualization complete" ) ;
		break;
	
	default:
		return;
	}

	g_Status = currentStatus;
}

void CDlgItem::OnOpen() 
{
	//-----------------------
	// Step1: 定义变量 
	//-----------------------
	TCHAR tszFileName[ MAX_PATH ];

	//-----------------------------------------------------
	// Step2: Filename变化，则使用通知使能或不使能Play按钮 
	//-----------------------------------------------------
	GetDlgItemText( IDC_EDIT_SOURCE, tszFileName, MAX_PATH );

	if( _tcslen( tszFileName) > 0 )
	{
		m_ButPlay.EnableWindow( TRUE );
		
		SetCurrentStatus( CLOSED );
	}
	else
	{
		m_ButPlay.EnableWindow( FALSE );		
	}
	
	SetCurrentStatus( READY );

	return ;
}

void CDlgItem::OnPause() 
{	
	//-----------------------
	// Step1: 定义变量 
	//-----------------------
	HRESULT hr = S_OK;

	//-----------------------
	// Step2: 暂停音频播放器 
	//-----------------------
    if( NULL != g_pAudioplay )
    {
		hr = g_pAudioplay->Pause();
		if( FAILED( hr ) )
		{
			TCHAR tszErrMesg[128];
            _stprintf( tszErrMesg, _T("Unable to Pause (hr=%#X)"), hr );
			InsertLog( tszErrMesg );
		}
		else
		{
			SetCurrentStatus( PAUSE );
		}
    }
}

void CDlgItem::OnPlay() 
{
	//-----------------------
	// Step1: 定义变量 
	//-----------------------
	HRESULT hr = S_OK;

    if( NULL == g_pAudioplay )
    {
        return;
    }

	m_bPlayBack = m_CheckPlay.GetCheck();

	//-----------------------------
	// Step2: 检查播放器先前的状态 
	//-----------------------------
	switch( g_Status )
	{
	case PAUSE:
		////////////////////////////////////////////////////////////////////////////////
		// Player was PAUSEed, now resume it
		////////////////////////////////////////////////////////////////////////////////
		//-----------------------------
		// Step2: 检查播放器先前的状态 
		//-----------------------------
		hr = g_pAudioplay->Resume();
		if( FAILED( hr ) )
		{
			TCHAR tszErrMesg[ 128 ];
            _stprintf( tszErrMesg, _T( "Unable to resume (hr=%#X)" ), hr );
			InsertLog(tszErrMesg);			
		}
		else
		{
			SetCurrentStatus( PLAY );
		}
		
		break;
	
	case STOP:
        ////////////////////////////////////////////////////////////////////////////////
        // Player was STOPped, now start it
        ////////////////////////////////////////////////////////////////////////////////
        /*hr = g_pAudioplay->Start();
        if( FAILED( hr ) )
        {
            TCHAR tszErrMesg[ 128 ];
            _stprintf( tszErrMesg, _T("Unable to start (hr=%#X)"), hr );
            InsertLog(tszErrMesg);		
        }
        else
        {
            SetCurrentStatus( OPENING );
        }

        break;*/

    case CLOSED:
        ////////////////////////////////////////////////////////////////////////////////
        // The play is being called for the current file for the first time.
        // Start playing the file
        ////////////////////////////////////////////////////////////////////////////////
        SetCurrentStatus( OPENING );
        
        ////////////////////////////////////////////////////////////////////////////////
        // Get the file name
        ////////////////////////////////////////////////////////////////////////////////
        GetDlgItemText(IDC_EDIT_SOURCE, g_ptszFileName, MAX_PATH );

        //-------------------------------------------
        // Remove leading spaces from the file name        
        //-------------------------------------------
        TCHAR *ptszTemp = g_ptszFileName;
        while( *ptszTemp == _T(' ') )
        {
            ptszTemp++;
        }

        if( g_ptszFileName != ptszTemp )
        {
            memmove( g_ptszFileName, ptszTemp, sizeof( TCHAR ) * ( _tcslen( ptszTemp ) + 1 ) );
            SendDlgItemMessage( IDC_EDIT_SOURCE, WM_SETTEXT, 0, ( WPARAM )g_ptszFileName );
        }

		//-------------------
        // Get the file name
        //-------------------
        GetDlgItemText(IDC_EDIT_DESFILEA, g_pSaveFileNameA, MAX_PATH );
		

        //------------------------------------------------
        // Remove leading spaces from the file name        
        //------------------------------------------------
        ptszTemp = g_pSaveFileNameA;
        while( *ptszTemp == _T(' ') )
        {
            ptszTemp++;
        }

        if( g_pSaveFileNameA != ptszTemp )
        {
            memmove( g_pSaveFileNameA, ptszTemp, sizeof( TCHAR ) * ( _tcslen( ptszTemp ) + 1 ) );
            SendDlgItemMessage( IDC_EDIT_DESFILEA, WM_SETTEXT, 0, ( WPARAM )g_pSaveFileNameA );
        }

		//-------------------
        // Get the file name
        //-------------------
		GetDlgItemText(IDC_EDIT_DESFILEB, g_pSaveFileNameB, MAX_PATH );

		//------------------------------------------------
        // Remove leading spaces from the file name        
        //------------------------------------------------
		ptszTemp = g_pSaveFileNameB;
        while( *ptszTemp == _T(' ') )
        {
            ptszTemp++;
        }

        if( g_pSaveFileNameB != ptszTemp )
        {
            memmove( g_pSaveFileNameB, ptszTemp, sizeof( TCHAR ) * ( _tcslen( ptszTemp ) + 1 ) );
            SendDlgItemMessage( IDC_EDIT_DESFILEB, WM_SETTEXT, 0, ( WPARAM )g_pSaveFileNameB );
        }

		GetDlgItemText(IDC_EDIT_DESFILEC, g_pSaveFileNameC, MAX_PATH );

		//------------------------------------------------
        // Remove leading spaces from the file name        
        //------------------------------------------------
		ptszTemp = g_pSaveFileNameC;
        while( *ptszTemp == _T(' ') )
        {
            ptszTemp++;
        }

        if( g_pSaveFileNameC != ptszTemp )
        {
            memmove( g_pSaveFileNameC, ptszTemp, sizeof( TCHAR ) * ( _tcslen( ptszTemp ) + 1 ) );
            SendDlgItemMessage( IDC_EDIT_DESFILEC, WM_SETTEXT, 0, ( WPARAM )g_pSaveFileNameC );
        }
        ////////////////////////////////////////////////////////////////////////////////
        // Open the file. We may need to convert the filename string from multibytes to wide characters
        ////////////////////////////////////////////////////////////////////////////////
#ifndef UNICODE
		{
			WCHAR pwszFileName[ MAX_PATH ];

			if( 0 == MultiByteToWideChar( CP_ACP, 0, g_ptszFileName, -1, pwszFileName, MAX_PATH ) )
			{
                ////////////////////////////////////////////////////////////////////////////////
                // Convertion failed
                ////////////////////////////////////////////////////////////////////////////////
				SetCurrentStatus( CLOSED );
				SetCurrentStatus( READY );
				break;
			}

			WCHAR pwszSaveFileNameA[ MAX_PATH ];

			if( 0 == MultiByteToWideChar( CP_ACP, 0, g_pSaveFileNameA, -1, pwszSaveFileNameA, MAX_PATH ) )
			{
                ////////////////////////////////////////////////////////////////////////////////
                // Convertion failed
                ////////////////////////////////////////////////////////////////////////////////
				SetCurrentStatus( CLOSED );
				SetCurrentStatus( READY );
				break;
			}

			WCHAR pwszSaveFileNameB[ MAX_PATH ];

			if( 0 == MultiByteToWideChar( CP_ACP, 0, g_pSaveFileNameB, -1, pwszSaveFileNameB, MAX_PATH ) )
			{
                ////////////////////////////////////////////////////////////////////////////////
                // Convertion failed
                ////////////////////////////////////////////////////////////////////////////////
				SetCurrentStatus( CLOSED );
				SetCurrentStatus( READY );
				break;
			}

			WCHAR pwszSaveFileNameC[ MAX_PATH ];

			if( 0 == MultiByteToWideChar( CP_ACP, 0, g_pSaveFileNameC, -1, pwszSaveFileNameC, MAX_PATH ) )
			{
                ////////////////////////////////////////////////////////////////////////////////
                // Convertion failed
                ////////////////////////////////////////////////////////////////////////////////
				SetCurrentStatus( CLOSED );
				SetCurrentStatus( READY );
				break;
			}


			hr = g_pAudioplay->Open( pwszFileName, (LPCWSTR)&g_pSaveFileNameA, (LPCWSTR)&g_pSaveFileNameB, (LPCWSTR)&g_pSaveFileNameC, m_bPlayBack );
		}
#else
		hr = g_pAudioplay->Open( g_ptszFileName, g_pSaveFileNameA, g_pSaveFileNameB, g_pSaveFileNameC, m_bPlayBack );
#endif // UNICODE

		if( FAILED( hr ) )
		{
			SetCurrentStatus( CLOSED );
			SetCurrentStatus( READY );
		}
		else
		{
            ////////////////////////////////////////////////////////////////////////////////
            // Start to play from the beginning
            ////////////////////////////////////////////////////////////////////////////////
            hr = g_pAudioplay->Start();
            if( FAILED( hr ) )
            {
                TCHAR tszErrMesg[ 128 ];
                _stprintf( tszErrMesg, _T("Unable to start (hr=%#X)"), hr );
                InsertLog( tszErrMesg );
            }
            else
            {
                ////////////////////////////////////////////////////////////////////////////////
                // Set the max range of the slider to be the value of the file's duration in milliseconds
                ////////////////////////////////////////////////////////////////////////////////
			    SendDlgItemMessage( IDC_SLIDER, TBM_SETRANGEMAX, TRUE,
								    ( DWORD )( g_pAudioplay->GetFileDuration() / 10000 ) );
    			
                ////////////////////////////////////////////////////////////////////////////////
                // Update the window title with the file's name
                ////////////////////////////////////////////////////////////////////////////////
			    LPTSTR ptszFile = _tcsrchr( g_ptszFileName, _T( '\\' ) );
                if( NULL != ptszFile )
                {
			        SetWindowText( ptszFile + 1 );
                }
                else
                {
			        SetWindowText( g_ptszFileName );
                }
            }
		}

		break;
	}
}

void CDlgItem::OnStop() 
{	
	HRESULT	hr		= S_OK;

	//-------------------------------
    // Stop the audio player
    //-------------------------------
    if( NULL != g_pAudioplay )
    {
		SetCurrentStatus( STOPPING );		
	
	#ifndef UNICODE
		{
			hr = g_pAudioplay->Stop(  );
		}
	#else
		hr = g_pAudioplay->Stop(  );
	#endif // UNICODE    
		
		if( FAILED( hr ) )
		{
			SetCurrentStatus( g_Status );

			TCHAR tszErrMesg[128];
            _stprintf( tszErrMesg, _T( "Unable to Stop (hr=%#X)" ), hr );
			InsertLog( tszErrMesg );
		}
    }

	return ;
}

void CDlgItem::OnCancel() 
{
	// TODO: Add extra cleanup here
	if( NULL != g_pAudioplay )
	{
		g_pAudioplay->Exit();
		g_pAudioplay->Release();
	}

	if (hHeap != NULL)
	{
		HeapDestroy(hHeap);
	}

	CPropertyPage::OnCancel();
}

int CDlgItem::SetItemText(UINT nControlID, LPCWSTR pwszText)
{
#ifdef UNICODE

    return SendDlgItemMessage( this, nControlID, WM_SETTEXT, 0, ( WPARAM )pwszText );

#else

    ////////////////////////////////////////////////////////////////////////////////
    // Convert the wide-character string to a multi-byte string before sending it to the control
    ////////////////////////////////////////////////////////////////////////////////
    size_t cchLen = wcslen( pwszText );
	LPTSTR pszText = new TCHAR[ cchLen + 1 ];
	if( pszText == NULL )
	{
		return 0;
	}

	if( 0 == WideCharToMultiByte( CP_ACP, 0, pwszText, -1, pszText, cchLen + 1, NULL, NULL ) )
	{
		SAFE_ARRAYDELETE( pszText );
		return 0;
	}

	int iResult =  SendDlgItemMessage( nControlID, WM_SETTEXT, 0, ( WPARAM )pszText );
	SAFE_ARRAYDELETE( pszText );
	return iResult;

#endif
}

void CDlgItem::InitFileName(TCHAR* pSource, TCHAR* pDestA, TCHAR* pDestB, TCHAR* pDestC, BOOL bPlayBack, TCHAR* pCaption)
{
	if (( pSource == NULL )
		|| ( pDestA == NULL )
		|| ( pDestB == NULL )
		|| ( pCaption == NULL ))
		return;

	sprintf(g_ptszFileName, _T("%s"), pSource);
	sprintf(g_pSaveFileNameA, _T("%s"), pDestA);
	sprintf(g_pSaveFileNameB, _T("%s"), pDestB);
	sprintf(g_pSaveFileNameC, _T("%s"), pDestC);
	sprintf(g_pCaption, _T("%s"), pCaption);
	m_bPlayBack = bPlayBack;	
}



void CDlgItem::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 200)
	{
		OnPlay();
	}
	CPropertyPage::OnTimer(nIDEvent);
}
