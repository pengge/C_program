// DataFlow.cpp : implementation file
//

#include "stdafx.h"
#include "DataFlow.h"
#include "GPSPublic.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataFlow

CDataFlow::CDataFlow()
{
	InitVariable();

    //��ʵ����ǰ��Ҫע���Լ�������
    WNDCLASS wndc;
    HINSTANCE hinstance = AfxGetInstanceHandle();
    if(!(::GetClassInfo(hinstance, "tipclass", &wndc)))
    {
        wndc.style = CS_SAVEBITS;
        wndc.lpfnWndProc = ::DefWindowProc;
        wndc.cbClsExtra = wndc.cbWndExtra=0;
        wndc.hInstance = hinstance;
        wndc.hIcon = NULL;
        wndc.hCursor = NULL;
        wndc.hbrBackground = NULL;
        wndc.lpszMenuName = NULL;
        wndc.lpszClassName = "tipclass";//����
        if (!AfxRegisterClass(&wndc))
            AfxThrowResourceException();
    }
}

CDataFlow::CDataFlow(CString com, DWORD dwMessage)
{
	InitVariable();
	m_Com = com;
}

CDataFlow::~CDataFlow()
{
	DestroyWindow();
}

BEGIN_MESSAGE_MAP(CDataFlow, CWnd)
	//{{AFX_MSG_MAP(CDataFlow)
	ON_MESSAGE(WM_COM_TO_DATA_FLOW,OnComMsg)
	ON_MESSAGE(WM_INITCENTER,OnInitCenter)
	ON_MESSAGE(WM_DECODE_MSG,OnDecodeMsg)
	ON_MESSAGE(WM_RESPONSE_MSG,OnResponseMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDataFlow message handlers

DWORD CDataFlow::GetMeMsg()
{
	return this->m_dwToMeMsg;
}

HWND CDataFlow::Create()
{
	CRect ct(0,0,0,0);

	CreateEx(0,"tipclass",NULL,WS_POPUP,ct,NULL,NULL);
	if(!m_hWnd)
		AfxMessageBox("Create Window Fail!");

	return m_hWnd;  
}

///////////////////////////////////////////////////////////////////
// ��������	DealFlow
// ��  �ܣ�	����¼����������ͷ������β֮���������ȡ���������ͽ�����Ϣ���ɽ��������룬����������ݻ�������ɾ��
// ��  ����	
// ����ֵ��	
// ��  ע��	
///////////////////////////////////////////////////////////////////
void CDataFlow::DealFlow()
{		
	if ((m_dwDataGramLen < 0) 
		|| (m_dwDataGramLen > MAX_NEMA_SENTENCE_MAX_LENGTH))
	{
		return;
	}

	BYTE gramBytes[MAX_NEMA_SENTENCE_MAX_LENGTH+1];
	memset(gramBytes, 0x00, sizeof(gramBytes));

	for (int i = 0;i < m_dwDataGramLen;i++)
	{
		gramBytes[i] = m_Data[m_dwDataGramHead+i];
	}

	m_Data.RemoveAt(0, m_dwDataGramTail);
	
	
	this->PostMessage(WM_DECODE_MSG,(DWORD)(BYTE*)gramBytes,(DWORD)(m_dwDataGramLen));
	
	m_dwDataGramHead=0;
	m_dwDataGramTail=0;
	m_dwDataGramLen=0;		
		
	return;
}

///////////////////////////////////////////////////////////////////
// ��������	SearchFlow
// ��  �ܣ�	�����ڽ��յ�������
// ��  ����	
// ����ֵ��	BOOL--�������ݻ��������Ƿ��з��ϱ�׼��Э�����ݰ�
// ��  ע��	
///////////////////////////////////////////////////////////////////
BOOL CDataFlow::SearchFlow()
{
	for (int i = 0;i < m_Data.GetUpperBound(); i++)
	{
		// ��⵽����ͷ�󣬽���λ�ü�¼����
		if ((m_Data[i] == NEMA_HEAD_STANDAD) 
			|| (m_Data[i] == NEMA_HEAD_TEXT))
		{
			m_dwDataGramHead = i;
		}

		// ��⵽����β�󣬽���λ�ü�¼����
		if ((m_Data[i] == NEMA_TAIL_STANDAD_1) 
			&& (m_Data[i+1] == NEMA_TAIL_STANDAD_2) )
		{
			m_dwDataGramTail = i + 1;
			m_dwDataGramLen = m_dwDataGramTail-m_dwDataGramHead+1;
			return TRUE;
		}
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////
// ��������	OnComMsg
// ��  �ܣ�	�����ڽ��յ�������
// ��  ����	DWORD dwEvent--���յ������ݴ洢��ָ��
//			DWORD dwLen--���յ������ݵĳ���
// ����ֵ��	
// ��  ע��	
//////////////////////////////////////////////////////////////////
LRESULT CDataFlow::OnComMsg(WPARAM dwEvent, LPARAM dwLen)
{
	if(!dwLen)
	{
		m_dwComEvent=dwEvent;
		return 0;
	}
	
	while(dwLen > 0)
	{
		// �����ݿ���������������
		BYTE s[MAX_COM_IN_LENGTH+1];
		int len = min(MAX_COM_IN_LENGTH, dwLen);
		memset(s, 0, sizeof(s));
		memcpy(s,(BYTE * )dwEvent, len);
		s[len]='\0';
		dwLen -= len;

		CString content = s;					
		
		// ���͸������壬�����ݵ������ʾ
		::SendMessage(AfxGetApp()->GetMainWnd()->m_hWnd, WM_RECEIVE_COM_DATA, (WPARAM)&m_Com, (LPARAM)&content);
				
		for(int i=0; i<len; i++)
		{
			m_Data.Add(s[i]);
		}	
	}

	while(SearchFlow())	DealFlow();
	return 1;
}

LRESULT CDataFlow::OnInitCenter(WPARAM wp,LPARAM lp)
{	
	return 1;
}

void CDataFlow::SetEditCtrl(CEdit *pReceEdit, CEdit *pSendEdit)
{
	m_pReceEdit=pReceEdit;
	m_pSendEdit=pSendEdit;
}


GPSPack* CDataFlow::DecodeNEMA_Text(CString source)
{
	if (source.GetLength() != NEMA_TEXT_LENGTH) return NULL;

	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	pack->GPS_NEMA_TEXT.bodyType = NEMATYPE_TEXT_POS;
	int iLen = 0;		//Э������ĵ�ǰ�ַ�λ��
	int itemLen = 0;	//Э������ĵ�ǰ��ĳ���

	
	//----------------------------------------------------------------
	// ��ͷ��ʼ��			   1       ʼ��Ϊ '@'
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.head, source.Mid(iLen, itemLen), itemLen);
	//----------------------------------------------------------------

	//----------------------------------------------------------------
	// ���ڲ���
	// ��                      2       UTC��������λ����
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_TEXT.body.date.year, source.Mid(iLen, itemLen));
	pack->GPS_NEMA_TEXT.body.date.year += 2000;
	
	// ��                      2       UTC��, "01".."12"
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_TEXT.body.date.month, source.Mid(iLen, itemLen));
		
	// ��                      2       UTC��, "01".."31"
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_TEXT.body.date.day, source.Mid(iLen, itemLen));	
	//----------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------
	// ʱ�䲿��
	// ʱ                      2       UTCʱ, "00".."23"
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_TEXT.body.time.hour, source.Mid(iLen, itemLen));	
		
	// ��                      2       UTC��, "00".."59"
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_TEXT.body.time.minute, source.Mid(iLen, itemLen));	

	// ��                      2       UTC��, "00".."59"
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_TEXT.body.time.second, source.Mid(iLen, itemLen));	
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	// λ�ò���

	// γ�Ȱ���                1       'N' �� 'S'
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.latitudeType, source.Mid(iLen, itemLen), itemLen);	
		
	// γ������                7       WGS84����ϵͳ�������ʽddmmmmm,�ڵ�4λ���ֺ�ʡ����һ��С���㡣
	iLen += itemLen;
	itemLen = 7;
	CGPSPublic::ConvertToLatitude((double&)pack->GPS_NEMA_TEXT.body.latitude.latitude, source.Mid(iLen, itemLen));
	
	// ���Ȱ���                1       'E' �� 'W'
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.longitudeType, source.Mid(iLen, itemLen), itemLen);	
		
	// ��������                8       WGS84����ϵͳ�������ʽdddmmmmm,�ڵ�5λ���ֺ�ʡ����һ��С���㡣
	iLen += itemLen;
	itemLen = 8;
	CGPSPublic::ConvertToLongitude(pack->GPS_NEMA_TEXT.body.longitude.longitude, source.Mid(iLen, itemLen));

	// ��λ״̬                1       'd'--2ά��ֶ�λ;'D'--3ά��ֶ�λ;'g'--2ά��λ;'G'--3ά��λ;'S'--ģ��״̬;'_'--��Ч
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.gpsStatus, source.Mid(iLen, itemLen), itemLen);	

	// ˮƽ��λ���            3       ��λΪ���ס�
	iLen += itemLen;
	itemLen = 3;
	CGPSPublic::ConvertToDouble(pack->GPS_NEMA_TEXT.body.hdop, source.Mid(iLen, itemLen));

	// �߶ȷ���                1       '+' �� '-'
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.altitudeSymbol, source.Mid(iLen, itemLen), itemLen);	

	// �߶�                    5       ���θߣ���λΪ���ס�
	iLen += itemLen;
	itemLen = 5;
	CGPSPublic::ConvertToDouble(pack->GPS_NEMA_TEXT.body.altitude.altitude, source.Mid(iLen, itemLen));
	//----------------------------------------------------------------------------------------


	//------------------------------------------------------------------------------------
	//������ٶȲ���

	// ��/�� �ٶȷ���          1       'E' �� 'W'
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.xDirect, source.Mid(iLen, itemLen), itemLen);	

	// ��/���ٶ�               4       ��λ�ǡ���/�롱���ڵ���λ��ʡ����һ��С���㣬("1234" = 123.4 m/s)
	iLen += itemLen;
	itemLen = 4;
	CGPSPublic::ConvertToDoubleAddPoint(pack->GPS_NEMA_TEXT.body.xVolity, source.Mid(iLen, itemLen), 3);


	// ��/�� �ٶȷ���          1       'S' �� 'N'
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.yDirect, source.Mid(iLen, itemLen), itemLen);	

	// ��/�� �ٶ�              4       ��λ�ǡ���/�롱���ڵ���λ��ʡ����һ��С����, ("1234" = 123.4 m/s)
	iLen += itemLen;
	itemLen = 4;
	CGPSPublic::ConvertToDoubleAddPoint(pack->GPS_NEMA_TEXT.body.yVolity, source.Mid(iLen, itemLen), 3);


	// ��ֱ�ٶȷ���            1       'U' (��) �� 'D' (��)
	iLen += itemLen;
	itemLen = 1;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.body.zDirect, source.Mid(iLen, itemLen), itemLen);

	// ��ֱ�ٶ�                4       ��λ�ǡ���/�롱���ڵڶ�λ��ʡ����һ��С����,("1234" = 12.34 m/s)
	iLen += itemLen;
	itemLen = 4;
	CGPSPublic::ConvertToDoubleAddPoint(pack->GPS_NEMA_TEXT.body.zVolity, source.Mid(iLen, itemLen), 3);

	// ��β������              2        �س�, '0x0D', �ͻ���'0x0A'
	iLen += itemLen;
	itemLen = 2;
	CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_TEXT.tail, source.Mid(iLen, itemLen), itemLen);
	
	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPGGA
// ��  �ܣ�	����NEMA��GPGGAЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	GPS��λ��Ϣ
//////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPGGA()
{
	int total=16;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPGGA.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPGGA.bodyType = NEMATYPE_STANDARD_GPGGA;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	
	//----------------------------------------------------------------------------
	// GPS��λ��Ϣ
	// $GPGGA,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,M,<10>,M,<11>,<12>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//----------------------------------------------------------------------------------------------
			// ʱ�䲿��		<1> UTCʱ�䣬hhmmss��ʱ���룩��ʽ
			// ʱ                      2       UTCʱ, "00".."23"			
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGGA.body.time.hour, 
				item->Mid(iLen, itemLen));	
				
			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGGA.body.time.minute, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGGA.body.time.second, 
				item->Mid(iLen, itemLen));
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			// γ������		<2> γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToLatitudeHavePoint(
				(double&)pack->GPS_NEMA_GPGGA.body.latitude.latitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// γ�Ȱ���		<3> γ�Ȱ���N�������򣩻�S���ϰ���			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGGA.body.latitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//------------------------------------------------------------------------------------------------
			// ��������		<4> ����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToLongitudeHavePoint(
				(double&)pack->GPS_NEMA_GPGGA.body.longitude.longitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			// ���Ȱ���		<5> ���Ȱ���E����������W��������			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGGA.body.longitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
			//------------------------------------------------------------------------------------------------
			// ��λ״̬		<6> GPS״̬��0=δ��λ��1=�ǲ�ֶ�λ��2=��ֶ�λ��6=���ڹ���			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGGA.body.gpsStatus, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			// ��������		<7> ����ʹ�ý���λ�õ�����������00~12����ǰ���0Ҳ�������䣩
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGGA.body.sateCount, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 8:
			//------------------------------------------------------------------------------------------------
			// ˮƽ��λ���	<8> HDOPˮƽ�������ӣ�0.5~99.9��			
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPGGA.body.hdop, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 9:
			//------------------------------------------------------------------------------------------------
			// ����			<9> ���θ߶ȣ�-9999.9~99999.9��			
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPGGA.body.altitude.altitude, *item);
			//------------------------------------------------------------------------------------------------
			break;		

		case 11:
			//------------------------------------------------------------------------------------------------
			// �߶�			<10> ������������Դ��ˮ׼��ĸ߶�
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPGGA.body.height, *item);
			//------------------------------------------------------------------------------------------------
			break;	
			
		case 13:
			//------------------------------------------------------------------------------------------------
			// ���ʱ��		<11> ���ʱ�䣨�����һ�ν��յ�����źſ�ʼ��������������ǲ�ֶ�λ��Ϊ�գ�			
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGGA.body.diffSecond, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 14:
			//------------------------------------------------------------------------------------------------
			// ���վ���	<12> ���վID��0000~1023��ǰ���0Ҳ�������䣬������ǲ�ֶ�λ��Ϊ�գ�
			if (item->GetLength() > 0)
			{
				itemLen = 4;			
				CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGGA.body.diffStationID, 
					*item->Mid(iLen, itemLen), itemLen);
			}
			break;
			//------------------------------------------------------------------------------------------------

		case 15:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGGA.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPGGA.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPGGA.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPGGA.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPGSA
// ��  �ܣ�	����NEMA��GPGSAЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	��ǰ������Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPGSA()
{
	int total=19;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPGSA.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPGSA.bodyType = NEMATYPE_STANDARD_GPGSA;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	
	//----------------------------------------------------------------------------
	// ��ǰ������Ϣ
	// $GPGSA,<1>,<2>,<3>,<3>,<3>,<3>,<3>,<3>,<3>,<3>,<3>,<3>,<3>,<3>,<4>,<5>,<6>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//------------------------------------------------------------------------------------------------
			// ��λ״̬		<1> ģʽ��M=�ֶ���A=�Զ�			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGSA.body.gpsmode, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			// ��λ����		<2> ��λ���ͣ�1=û�ж�λ��2=2D��λ��3=3D��λ		
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGSA.body.postype, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			//----------------------------------------------------------------------------------------------
			// ʱ�䲿��		<3> PRN�루α��������룩���������ڽ���λ�õ����Ǻţ�01~32��ǰ���0Ҳ�������䣩��		
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGSA.body.prn[itemCount-3], *item);			
			//------------------------------------------------------------------------------------------------
			break;

		case 15:
			//------------------------------------------------------------------------------------------------
			// pdop			<4> PDOPλ�þ������ӣ�0.5~99.9��			
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPGSA.body.pdop, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 16:
			//------------------------------------------------------------------------------------------------
			// hdop			<5> HDOPˮƽ�������ӣ�0.5~99.9��		
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPGSA.body.hdop, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 17:
			//------------------------------------------------------------------------------------------------
			// vdop			<6> VDOP��ֱ�������ӣ�0.5~99.9��			
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPGSA.body.vdop, *item);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPGSA.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPGSA.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPGSA.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPGSV
// ��  �ܣ�	����NEMA��GPGSVЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	�ɼ�������Ϣ,<4>,<5>,<6>,<7>��Ϣ������ÿ�����ǽ���ѭ����ʾ��
//			ÿ��GSV�����������ʾ4�����ǵ���Ϣ��
//			����������Ϣ������һ���е�NMEA0183����������
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPGSV()
{
	int total = 5;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	total = m_dataArray.GetSize();

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPGSV.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPGSV.bodyType = NEMATYPE_STANDARD_GPGSV;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	
	//----------------------------------------------------------------------------
	// �ɼ�������Ϣ
	// $GPGSV,<1>,<2>,<3>,<4>,<5>,<6>,<7>,��<4>,<5>,<6>,<7>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//------------------------------------------------------------------------------------------------
			//		<1> GSV��������		
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGSV.body.total, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			//		<2> ����GSV�ı��		
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGSV.body.no, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			//		<3> �ɼ����ǵ�������00~12��ǰ���0Ҳ�������䣩
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGSV.body.validsate, 
				item->Mid(iLen, itemLen));
			//------------------------------------------------------------------------------------------------
			break;	

		case 4:
		case 8:
		case 12:
		case 16:
			//------------------------------------------------------------------------------------------------
			//		<4> PRN�루α��������룩��01~32��ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGSV.body.prn[(itemCount)/4-1], *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
		case 9:
		case 13:
		case 17:
			//------------------------------------------------------------------------------------------------
			//		<5> �������ǣ�00~90�ȣ�ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGSV.body.yj[(itemCount-1)/4-1], *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
		case 10:
		case 14:
		case 18:
			//------------------------------------------------------------------------------------------------
			//		<6> ���Ƿ�λ�ǣ�000~359�ȣ�ǰ���0Ҳ�������䣩
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGSV.body.fwj[(itemCount-2)/4-1], *item);
			//------------------------------------------------------------------------------------------------
			break;


		case 7:
		case 11:
		case 15:
		case 19:
			//------------------------------------------------------------------------------------------------
			//		<7> ����ȣ�00~99dB��û�и��ٵ�����ʱΪ�գ�ǰ���0Ҳ�������䣩
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPGSV.body.xzb[(itemCount-3)/4-1], *item);
			//------------------------------------------------------------------------------------------------
			break;		
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPGSV.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPGSV.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPGSV.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPRMC
// ��  �ܣ�	����NEMA��GPGGAЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	�Ƽ���λ��Ϣ
//////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPRMC()
{
	int total=14;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPRMC.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPRMC.bodyType = NEMATYPE_STANDARD_GPRMC;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// �Ƽ���λ��Ϣ
	// $GPRMC,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,<10>,<11>,<12>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//----------------------------------------------------------------------------------------------
			// ʱ�䲿��		<1> UTCʱ�䣬hhmmss��ʱ���룩��ʽ
			// ʱ                      2       UTCʱ, "00".."23"			
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPRMC.body.time.hour, 
				item->Mid(iLen, itemLen));	
				
			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPRMC.body.time.minute, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPRMC.body.time.second, 
				item->Mid(iLen, itemLen));
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			// ��λ״̬		<2> ��λ״̬��A=��Ч��λ��V=��Ч��λ			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPRMC.body.posvalid, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// γ������		<3> γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToLatitudeHavePoint(
				(double&)pack->GPS_NEMA_GPRMC.body.latitude.latitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//------------------------------------------------------------------------------------------------
			// γ�Ȱ���		<4> γ�Ȱ���N�������򣩻�S���ϰ���			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPRMC.body.latitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			// ��������		<5> ����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToLongitudeHavePoint(
				(double&)pack->GPS_NEMA_GPRMC.body.longitude.longitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
			//------------------------------------------------------------------------------------------------
			// ���Ȱ���		<6> ���Ȱ���E����������W��������			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPRMC.body.longitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			// �ٶ�			<7> �������ʣ�000.0~999.9�ڣ�ǰ���0Ҳ�������䣩
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPRMC.body.volity, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 8:
			//------------------------------------------------------------------------------------------------
			// ����			<8> ���溽��000.0~359.9�ȣ����汱Ϊ�ο���׼��ǰ���0Ҳ�������䣩		
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPRMC.body.direct, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 9:
			//----------------------------------------------------------------------------------------------
			// ���ڲ���		<9> UTC���ڣ�ddmmyy�������꣩��ʽ
			// ��                      2       UTC��, "01".."31"		
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPRMC.body.date.day, 
				item->Mid(iLen, itemLen));			
				
			// ��                      2       UTC��, "01".."12"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPRMC.body.date.month, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��������λ����
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPRMC.body.date.year, 
				item->Mid(iLen, itemLen));
			pack->GPS_NEMA_GPRMC.body.date.year += 2000;
			//------------------------------------------------------------------------------------------------
			break;

		case 10:
			//------------------------------------------------------------------------------------------------
			// ��ƫ��		<10> ��ƫ�ǣ�000.0~180.0�ȣ�ǰ���0Ҳ�������䣩		
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPRMC.body.cpj, *item);
			//------------------------------------------------------------------------------------------------
			break;			


		case 11:
			//------------------------------------------------------------------------------------------------
			// ��ƫ�Ƿ���	<11> ��ƫ�Ƿ���E��������W������
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPRMC.body.cpjdirect, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 12:
			//------------------------------------------------------------------------------------------------
			// ģʽ			<12> ģʽָʾ����NMEA0183 3.00�汾�����A=������λ��D=��֣�E=���㣬N=������Ч��
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPRMC.body.mode, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
			
		case 13:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPRMC.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPRMC.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPRMC.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPRMC.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPVTG
// ��  �ܣ�	����NEMA��GPGGAЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	�����ٶ���Ϣ
//////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPVTG()
{
	int total=11;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPVTG.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPVTG.bodyType = NEMATYPE_STANDARD_GPVTG;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// �����ٶ���Ϣ
	// $GPVTG,<1>,T,<2>,M,<3>,N,<4>,K,<5>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);


		// ��ʼ�������������
		switch (itemCount)
		{
		
		case 1:
			//------------------------------------------------------------------------------------------------
			// ����			<1> ���汱Ϊ�ο���׼�ĵ��溽��000~359�ȣ�ǰ���0Ҳ�������䣩		
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPVTG.body.directtn, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// ����			<2> �Դű�Ϊ�ο���׼�ĵ��溽��000~359�ȣ�ǰ���0Ҳ�������䣩	
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_GPVTG.body.directcn, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			// �ٶ�			<3> �������ʣ�000.0~999.9�ڣ�ǰ���0Ҳ�������䣩	
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPVTG.body.volityj, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			// ����			<4> �������ʣ�0000.0~1851.8����/Сʱ��ǰ���0Ҳ�������䣩
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_GPVTG.body.volitykm, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 9:
			//------------------------------------------------------------------------------------------------
			// ģʽ			<5> ģʽָʾ����NMEA0183 3.00�汾�����A=������λ��D=��֣�E=���㣬N=������Ч��
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPVTG.body.mode, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 10:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPVTG.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}			
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPVTG.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPVTG.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPVTG.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPGLL
// ��  �ܣ�	����NEMA��GPGGAЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	��λ������Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPGLL()
{
	int total=9;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPGLL.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPGLL.bodyType = NEMATYPE_STANDARD_GPGLL;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// ��λ������Ϣ
	// $GPGLL,<1>,<2>,<3>,<4>,<5>,<6>,<7>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//------------------------------------------------------------------------------------------------
			// γ������		<1> γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩		
			CGPSPublic::ConvertToLatitudeHavePoint(
				(double&)pack->GPS_NEMA_GPGLL.body.latitude.latitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			// γ�Ȱ���		<2> γ�Ȱ���N�������򣩻�S���ϰ���		
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGLL.body.latitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// ��������		<3> ����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩		
			CGPSPublic::ConvertToLongitudeHavePoint(
				(double&)pack->GPS_NEMA_GPGLL.body.longitude.longitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//------------------------------------------------------------------------------------------------
			// ���Ȱ���		<4> ���Ȱ���E����������W��������			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGLL.body.longitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//----------------------------------------------------------------------------------------------
			// ʱ�䲿��		<5> UTCʱ�䣬hhmmss��ʱ���룩��ʽ
			// ʱ                      2       UTCʱ, "00".."23"			
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGLL.body.time.hour, 
				item->Mid(iLen, itemLen));	
				
			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGLL.body.time.minute, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPGLL.body.time.second, 
				item->Mid(iLen, itemLen));
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
			//------------------------------------------------------------------------------------------------
			// ��λ״̬		<6> ��λ״̬��A=��Ч��λ��V=��Ч��λ			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGLL.body.posvalid, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		
		case 7:
			//------------------------------------------------------------------------------------------------
			// ģʽ			<7> ģʽָʾ����NMEA0183 3.00�汾�����A=������λ��D=��֣�E=���㣬N=������Ч
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGLL.body.mode, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
			
		case 8:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPGLL.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPGLL.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPGLL.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPGLL.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;

}


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPZDA
// ��  �ܣ�	����NEMA��GPZDAЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	ʱ���������Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPZDA()
{
	int total=6;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPZDA.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPZDA.bodyType = NEMATYPE_STANDARD_GPZDA;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// ʱ���������Ϣ
	// $GPZDA,<1>,<2>,<3>,<4>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//----------------------------------------------------------------------------------------------
			// ʱ�䲿��		<1> UTCʱ�䣬hhmmss��ʱ���룩��ʽ
			// ʱ                      2       UTCʱ, "00".."23"			
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPZDA.body.time.hour, 
				item->Mid(iLen, itemLen));	
				
			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPZDA.body.time.minute, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPZDA.body.time.second, 
				item->Mid(iLen, itemLen));
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//----------------------------------------------------------------------------------------------
			// ��			<2> UTC���ڣ���			
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPZDA.body.date.day, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//----------------------------------------------------------------------------------------------
			// ��			<3> UTC���ڣ���		
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPZDA.body.date.month, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//----------------------------------------------------------------------------------------------
			// ��			<4> UTC���ڣ���	
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_GPZDA.body.date.year, *item);	
			//------------------------------------------------------------------------------------------------
			break;
		
		case 5:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPZDA.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPZDA.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPZDA.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPZDA.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_GPDTM
// ��  �ܣ�	����NEMA��GPDTMЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	�������ϵ��Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_GPDTM()
{
	int total=10;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_GPDTM.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_GPDTM.bodyType = NEMATYPE_STANDARD_GPDTM;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// �������ϵ��Ϣ
	// $GPDTM,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//------------------------------------------------------------------------------------------------
			// ����ϵ		<1>��������ϵ���� W84	
			itemLen = item->GetLength();
			pack->GPS_NEMA_GPDTM.body.localdatum = new char[itemLen+1];
			memset(pack->GPS_NEMA_GPDTM.body.localdatum, 0x00, itemLen+1);
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPDTM.body.localdatum[0], 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			// �Ӵ���		<2>����ϵ�Ӵ��� ��		
			itemLen = item->GetLength();
			pack->GPS_NEMA_GPDTM.body.subdatum = new char[itemLen+1];
			memset(pack->GPS_NEMA_GPDTM.body.subdatum, 0x00, itemLen+1);
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPDTM.body.subdatum[0], 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// γ��ƫ����	<3>γ��ƫ����	
			CGPSPublic::ConvertToDouble(
				(double&)pack->GPS_NEMA_GPDTM.body.latitudeoffset, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//------------------------------------------------------------------------------------------------
			// γ�Ȱ���		<4>γ�Ȱ���N�������򣩻�S���ϰ���	
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPDTM.body.latitudetype, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			// ����ƫ����	<5>����ƫ����	
			CGPSPublic::ConvertToDouble(
				(double&)pack->GPS_NEMA_GPDTM.body.longitudeoffset, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
			//------------------------------------------------------------------------------------------------
			// ���Ȱ���		<6>���Ȱ���E����������W��������		
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPDTM.body.longitudetype, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			// �߶�ƫ����	<7>�߶�ƫ����	
			CGPSPublic::ConvertToDouble(
				(double&)pack->GPS_NEMA_GPDTM.body.alitudeoffset, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 8:
			//------------------------------------------------------------------------------------------------
			// ����ϵ		<8>����ϵ���� W84	
			itemLen = item->GetLength();
			pack->GPS_NEMA_GPDTM.body.datum = new char[itemLen+1];
			memset(pack->GPS_NEMA_GPDTM.body.datum, 0x00, itemLen+1);
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPDTM.body.datum[0], 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;		
			
		case 9:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_GPDTM.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_GPDTM.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_GPDTM.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_GPDTM.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

//������˾��չЭ��


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_PGRME
// ��  �ܣ�	����NEMA��PGRMEЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	���������Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_PGRME()
{
	int total=8;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_PGRME.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_PGRME.bodyType = NEMATYPE_GARMIN_PGRME;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// ���������Ϣ
	// $PGRME,<1>,M,<2>,M,<3>,M*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{	
		case 1:
			//------------------------------------------------------------------------------------------------
			// ���			<1> HPE��ˮƽ��������0.0~999.9��
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRME.body.hpe, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// ���			<2> VPE����ֱ��������0.0~999.9��
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRME.body.vpe, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			// ���			<3> EPE��λ�ù�������0.0~999.9��
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRME.body.epe, *item);
			//------------------------------------------------------------------------------------------------
			break;			
			
		case 7:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRME.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_PGRME.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_PGRME.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_PGRME.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_PGRMF
// ��  �ܣ�	����NEMA��PGRMFЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	������˾GPS��λ��Ϣ
//////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_PGRMF()
{
	int total=17;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_PGRMF.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_PGRMF.bodyType = NEMATYPE_GARMIN_PGRMF;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// GPS��λ��Ϣ
	// $PGRMF,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,<10>,<11>,<12>,<13>,<14>,<15>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//----------------------------------------------------------------------------------------------
			// GPS����		<1> GPS������0~1023��	
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.gpscircle, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//----------------------------------------------------------------------------------------------
			// GPS����		<2> GPS������0~604799��	
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.gpssecond, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//----------------------------------------------------------------------------------------------
			// ���ڲ���		<3> UTC���ڣ�ddmmyy�������꣩��ʽ
			// ��                      2       UTC��, "01".."31"				
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.date.day, 
				item->Mid(iLen, itemLen));	
				
			// ��                      2       UTC��, "01".."12"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.date.month, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��������λ����
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.date.year, 
				item->Mid(iLen, itemLen));
			pack->GPS_NEMA_PGRMF.body.date.year += 2000;
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//----------------------------------------------------------------------------------------------
			// ʱ�䲿��		<4> UTCʱ�䣬hhmmss��ʱ���룩��ʽ
			// ʱ                      2       UTCʱ, "00".."23"
			itemLen = 2;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.time.hour, 
				item->Mid(iLen, itemLen));	
				
			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.time.minute, 
				item->Mid(iLen, itemLen));

			// ��                      2       UTC��, "00".."59"
			iLen += itemLen;
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.time.second, 
				item->Mid(iLen, itemLen));
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//----------------------------------------------------------------------------------------------
			// GPS������	<5> GPS������
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMF.body.gpsjump, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
			//------------------------------------------------------------------------------------------------
			// γ������		<6> γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩		
			CGPSPublic::ConvertToLatitudeHavePoint(
				(double&)pack->GPS_NEMA_PGRMF.body.latitude.latitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			// γ�Ȱ���		<7> γ�Ȱ���N�������򣩻�S���ϰ���			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMF.body.latitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 8:
			//------------------------------------------------------------------------------------------------
			// ��������		<8> ����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩			
			CGPSPublic::ConvertToLongitudeHavePoint(
				(double&)pack->GPS_NEMA_PGRMF.body.longitude.longitude, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 9:
			//------------------------------------------------------------------------------------------------
			// ���Ȱ���		<9> ���Ȱ���E����������W��������			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMF.body.longitudeType, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;


		case 10:
			//------------------------------------------------------------------------------------------------
			// ��λ״̬		<10> ģʽ��M=�ֶ���A=�Զ�			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMF.body.gpsmode, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 11:
			//------------------------------------------------------------------------------------------------
			// ��λ����		<11> ��λ���ͣ�0=û�ж�λ��1=2D��λ��2=3D��λ		
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMF.body.postype, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 12:
			//------------------------------------------------------------------------------------------------
			// �ٶ�			<12> �������ʣ�0~1851����/Сʱ��
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_PGRMF.body.volity, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 13:
			//------------------------------------------------------------------------------------------------
			// ����			<13> ���溽��000~359�ȣ����汱Ϊ�ο���׼��		
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_PGRMF.body.direct, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 14:
			//------------------------------------------------------------------------------------------------
			// PDOP			<14> PDOPλ�þ������ӣ�0~9����������ȡ����	
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_PGRMF.body.pdop, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 15:
			//------------------------------------------------------------------------------------------------
			// TDOP			<15> TDOPʱ�侫�����ӣ�0~9����������ȡ����	
			CGPSPublic::ConvertToInt(pack->GPS_NEMA_PGRMF.body.tdop, *item);
			//------------------------------------------------------------------------------------------------
			break;		
			
		case 16:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMF.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_PGRMF.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_PGRMF.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_PGRMF.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_PGRMM
// ��  �ܣ�	����NEMA��PGRMMЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	������˾����ϵͳ��Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_PGRMM()
{
	int total=3;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_PGRMM.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_PGRMM.bodyType = NEMATYPE_GARMIN_PGRMM;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// ����ϵͳ��Ϣ
	// $PGRMM,<1>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{	
		case 1:
			//------------------------------------------------------------------------------------------------
			//����ϵ����	<1> ��ǰʹ�õ�����ϵ���ƣ����ݳ��ȿɱ䣬�硰WGS 84������MapSource����ʵʱ���ӵ�ʱ��ʹ�á���
			itemLen = item->GetLength();	
			pack->GPS_NEMA_PGRMM.body.dwLen = itemLen;
			pack->GPS_NEMA_PGRMM.body.datum = new char[itemLen+1];
			memset(pack->GPS_NEMA_PGRMM.body.datum, 0x00, itemLen+1);
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMM.body.datum[0], 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		
		case 2:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMM.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_PGRMM.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_PGRMM.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_PGRMM.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_PGRMT
// ��  �ܣ�	����NEMA��PGRMTЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	������˾����״̬��Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_PGRMT()
{
	int total=11;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_PGRMT.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_PGRMT.bodyType = NEMATYPE_GARMIN_PGRMT;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// ����״̬��Ϣ
	// $PGRMT,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{	
		case 1:
			//------------------------------------------------------------------------------------------------
			//	<1> ��Ʒ�ͺź�����汾�����ݳ��ȿɱ䣬�硰GPS 15L/15H VER 2.05����
			itemLen = item->GetLength();
			pack->GPS_NEMA_PGRMT.body.dwLen = itemLen;
			pack->GPS_NEMA_PGRMT.body.version = new char[itemLen+1];
			memset(pack->GPS_NEMA_PGRMT.body.version, 0x00, itemLen+1);
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.version[0], 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			//	<2> ROMУ����ԣ�P=ͨ����F=ʧ��
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.romcheck, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			//	<3> ���ջ����������ϣ�P=ͨ����F=ʧ��
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.fault, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//------------------------------------------------------------------------------------------------
			//	<4> �洢�����ݣ�R=���֣�L=��ʧ
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.storedata, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			//	<5> ʱ�ӵ���Ϣ��R=���֣�L=��ʧ
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.clock, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 6:
			//------------------------------------------------------------------------------------------------
			//	<6> ����������Ư�ƣ�P=ͨ����F=��⵽����Ư��
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.piaoyi, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			//	<7> ���ݲ������ɼ���C=���ڲɼ������û�вɼ���Ϊ��
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.datacollect, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 8:
			//------------------------------------------------------------------------------------------------
			//	<8> GPS���ջ��¶ȣ���λΪ���϶�
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRMT.body.temperature, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 9:
			//------------------------------------------------------------------------------------------------
			//	<9> GPS���ջ��������ݣ�R=���֣�L=��ʧ
			itemLen = 1;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.body.configdata, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		
		case 10:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMT.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_PGRMT.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_PGRMT.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_PGRMT.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}


///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_PGRMV
// ��  �ܣ�	����NEMA��PGRMVЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	������˾��ά�ٶ���Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_PGRMV()
{
	int total=5;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_PGRMV.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_PGRMV.bodyType = NEMATYPE_GARMIN_PGRMV;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// ��ά�ٶ���Ϣ
	// $PGRMV,<1>,<2>,<3>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{	
		case 1:
			//------------------------------------------------------------------------------------------------
			// �ٶ�			<1> �����ٶȣ�514.4~514.4��/��
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRMV.body.xVolity, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//------------------------------------------------------------------------------------------------
			// �ٶ�			<2> �����ٶȣ�514.4~514.4��/��
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRMV.body.yVolity, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 3:
			//------------------------------------------------------------------------------------------------
			// �ٶ�			<3> �����ٶȣ�999.9~9999.9��/��
			CGPSPublic::ConvertToDouble(pack->GPS_NEMA_PGRMV.body.zVolity, *item);
			//------------------------------------------------------------------------------------------------
			break;			
			
		case 4:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMV.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_PGRMV.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_PGRMV.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_PGRMV.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}

///////////////////////////////////////////////////////////////////
// ��������	DecodeNEMA_PGRMB
// ��  �ܣ�	����NEMA��PGRMBЭ������
// ��  ����	
// ����ֵ��	GPSPack*--�������Э�����ݰ�
// ��  ע��	������˾�ű�����Ϣ
///////////////////////////////////////////////////////////////////
GPSPack* CDataFlow::DecodeNEMA_PGRMB()
{
	int total=11;

	// �жϵ����ݰ��е�����������Э��涨��15��ʱ,����
	if (m_dataArray.GetSize() < total) return NULL;

	// �������ݱ���
	GPSPack* pack = new GPSPack;
	memset(pack, 0x00, sizeof(GPSPack));

	// Ϊ���ݰ��İ�ͷ�Ͱ����͸�ֵ
	pack->GPS_NEMA_PGRMB.head = NEMA_HEAD_STANDAD;
	pack->GPS_NEMA_PGRMB.bodyType = NEMATYPE_GARMIN_PGRMB;

	// �����������ʱ�õ��ı���	
	int itemCount;		// ��ǰ�������ǵڼ���
	int itemLen;		// ��ǰ������ĳ���
	int iLen = 0;		// ��ǰ������ӵڼ����ַ���ʼ��ȡ
	

	//----------------------------------------------------------------------------
	// �ű�����Ϣ
	// $PGRMB,<1>,<2>,<3>,<4>,<5>,K,<6>,<7>,<8>*hh<CR><LF>
	// �ӵ�һ�����ν���ÿ��������
	//----------------------------------------------------------------------------
	for (itemCount = 1; itemCount <total; itemCount++)
	{
		// ����ÿ������ݵĵ�һ���ַ���ʼ����
		iLen = 0;
		// ����������ȡ��Ҫ������������
		CString* item = m_dataArray.GetAt(itemCount);

		// ��ʼ�������������
		switch (itemCount)
		{
		case 1:
			//----------------------------------------------------------------------------------------------
			// Ƶ��			<1> �ű�վƵ�ʣ�0.0��283.5~325.0kHz�����Ϊ0.5kHz��	
			CGPSPublic::ConvertToDouble((double&)pack->GPS_NEMA_PGRMB.body.freq, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 2:
			//----------------------------------------------------------------------------------------------
			// ������		<2> �ű�����ʣ�0��25��50��100��200bps��
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMB.body.banud, *item);	
			//------------------------------------------------------------------------------------------------
			break;	

		case 3:
			//----------------------------------------------------------------------------------------------
			// SNR			<3> SNR�ű��ź�����ȣ�0~31��
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMB.body.snr, *item);	
			//------------------------------------------------------------------------------------------------
			break;

		case 4:
			//------------------------------------------------------------------------------------------------
			// ��������		<4> �ű�����������0~100��	
			CGPSPublic::ConvertToInt((int&)pack->GPS_NEMA_PGRMB.body.quality, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 5:
			//------------------------------------------------------------------------------------------------
			// ����			<5> ���ű�վ�ľ��룬��λΪ����
			CGPSPublic::ConvertToDouble((double&)pack->GPS_NEMA_PGRMB.body.distance, *item);
			//------------------------------------------------------------------------------------------------
			break;

		case 7:
			//------------------------------------------------------------------------------------------------
			// ͨѶ״̬		<6> �ű���ջ���ͨѶ״̬��0=�����ߣ�1=���źţ�2=���ڵ�г��3=���ڽ��գ�4=����ɨ��			
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMB.body.commstatu, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 8:
			//------------------------------------------------------------------------------------------------
			// ���Դ		<7> ���Դ��R=RTCM��W=WAAS��N=�ǲ�ֶ�λ
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMB.body.source, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;

		case 9:
			//------------------------------------------------------------------------------------------------
			// ���״̬		<8> ���״̬��A=�Զ���W=��ΪWAAS��R=��ΪRTCM��N=�����ղ���ź�
			itemLen = 1;
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMB.body.statu, 
				*item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;		
			
		case 10:
			//------------------------------------------------------------------------------------------------
			//hhУ����
			itemLen = 2;			
			CGPSPublic::ConvertToChar((char&)pack->GPS_NEMA_PGRMB.check, 
				item->Mid(iLen, itemLen), itemLen);
			//------------------------------------------------------------------------------------------------
			break;
		}		
	}

	// �������ݰ�������β��Э��У���뿪ʼ��
	pack->GPS_NEMA_PGRMB.checkBegin = NEMA_CHECK_STANDAD;
	pack->GPS_NEMA_PGRMB.tail[0] = NEMA_TAIL_STANDAD_1;
	pack->GPS_NEMA_PGRMB.tail[1] = NEMA_TAIL_STANDAD_2;

	return pack;
}
	

///////////////////////////////////////////////////////////////////
// ��������	OnDecodeMsg
// ��  �ܣ�	����NEMAЭ������
// ��  ����	DWORD dwEvent--���ݰ������ݻ�����ָ��
//			DWORD dwLen--���ݰ������ݳ���
// ����ֵ��	
// ��  ע��	
//////////////////////////////////////////////////////////////////
LRESULT CDataFlow::OnDecodeMsg(WPARAM dwData,LPARAM dwLen)
{
	// ������ݳ���С�������С���ȣ��򷵻�
	if (dwLen < MAX_NEMA_SENTENCE_MIN_LENGTH)	return 0;
	if (!dwData) return 0;

	GPSPack* pack=NULL;		// ����������ݰ�
	
	// ��Э�����ݷ���������
	BYTE gramBytes[MAX_NEMA_SENTENCE_MAX_LENGTH+1];
	memset(gramBytes, 0x00, sizeof(gramBytes));
	memcpy((void*)gramBytes, (void*)dwData, dwLen);

	// �ж�����β�Ƿ���ȷ
	if ((gramBytes[dwLen-1] != NEMA_TAIL_STANDAD_2)
		&& (gramBytes[dwLen-2] != NEMA_TAIL_STANDAD_1))
	{
		return 0;
	}
	
	//--------------------------------------------------------------------
	// ����NEMA�ı���ʽ�����ݰ�
	if (gramBytes[0] == NEMA_HEAD_TEXT)
	{
		CString content;
		content = gramBytes;
		pack = DecodeNEMA_Text(content);
	}
	//---------------------------------------------------------------------
	//---------------------------------------------------------------------
	// ����NEMA���
	else if (gramBytes[0] == NEMA_HEAD_STANDAD)
	{
		// �ж���������λ�Ƿ�ΪУ���룬�����ȷ����ȡ��
		if (gramBytes[dwLen-5] != NEMA_CHECK_STANDAD) return 0;
		CString* packCheck=new CString();
		packCheck->Format("%c%c", gramBytes[dwLen-4], gramBytes[dwLen-3]);

		// ������ͨ��,�ָ������
		int check = 0;
		CString m_item;
		m_dataArray.RemoveAll();
		for (int i = 0;i < dwLen-NEMA_TAIL_LENGTH;i++)
		{
			if (gramBytes[i] == NEMA_SPLIT)
			{
				CString* inArray = new CString();
				inArray->Format("%s", m_item);				
				m_item.Empty();
				m_dataArray.Add(inArray);						
			}
			else
			{
				m_item += gramBytes[i];
			}
			
			if ((i < dwLen - MAX_COM_COMMAND_TAIL_LENGTH)
				&& (i >0))
			{
				check ^= gramBytes[i];
			}
		}		

		CString* inLast = new CString();
		inLast->Format("%s", m_item);		
		m_dataArray.Add(inLast);	

		if (m_dataArray.GetSize() < 1) return 0;	
		
		// У�����ݣ��ж������Ƿ���ȷ
		if (!CheckData(packCheck, check))	return 0;		

		// ��У������ӵ�����������
		m_dataArray.Add(packCheck);

		// ȡ�������
		CString type = *(CString*)m_dataArray.GetAt(0);	
		type = type.Mid(1);	

		//-----------------------------------------------------------------
		// �����׼NEMA���, ��$GP��ͷ
		if ((gramBytes[1] == NEMA_STANDAD_HEAD_1)
		&& (gramBytes[2] == NEMA_STANDAD_HEAD_2))
		{				
			if (type == NEMA_STANDARD_GPGGA)	//�ǲ�ֶ�λ
			{
				pack = DecodeNEMA_GPGGA();
			}
			else if (type == NEMA_STANDARD_GPGSA) //��ǰ������Ϣ
			{
				pack = DecodeNEMA_GPGSA();
			}
			else if (type == NEMA_STANDARD_GPGSV) //�ɼ�������Ϣ
			{
				pack = DecodeNEMA_GPGSV();
			}
			else if (type == NEMA_STANDARD_GPRMC) //�Ƽ���λ��Ϣ
			{
				pack = DecodeNEMA_GPRMC();
			}
			else if (type == NEMA_STANDARD_GPVTG) //�����ٶ���Ϣ
			{
				pack = DecodeNEMA_GPVTG();
			}
			else if (type == NEMA_STANDARD_GPGLL) //��λ������Ϣ
			{
				pack = DecodeNEMA_GPGLL();
			}
			else if (type == NEMA_STANDARD_GPZDA) //ʱ���������Ϣ
			{
				pack = DecodeNEMA_GPZDA();
			}
			else if (type == NEMA_STANDARD_GPDTM) //�������ϵ��Ϣ
			{
				pack = DecodeNEMA_GPDTM();
			}
		}
		//----------------------------------------------------------------------
		//----------------------------------------------------------------------
		//������˾����չЭ��
		else if ((gramBytes[1] == NEMA_GARMIN_HEAD_1)
		&& (gramBytes[2] == NEMA_GARMIN_HEAD_2)
		&& (gramBytes[3] == NEMA_GARMIN_HEAD_3)
		&& (gramBytes[4] == NEMA_GARMIN_HEAD_4))
		{
			if (type == NEMA_USER_GARMIN_PGRME) //���������Ϣ
			{
				pack = DecodeNEMA_PGRME();
			}
			else if (type == NEMA_USER_GARMIN_PGRMF) //GPS��λ��Ϣ
			{
				pack = DecodeNEMA_PGRMF();
			}
			else if (type == NEMA_USER_GARMIN_PGRMM) //����ϵͳ��Ϣ
			{
				pack = DecodeNEMA_PGRMM();
			}
			else if (type == NEMA_USER_GARMIN_PGRMT) //����״̬��Ϣ
			{
				pack = DecodeNEMA_PGRMT();
			}
			else if (type == NEMA_USER_GARMIN_PGRMV) //��ά�ٶ���Ϣ
			{
				pack = DecodeNEMA_PGRMV();
			}
			else if (type == NEMA_USER_GARMIN_PGRMB) //�ű�����Ϣ
			{
				pack = DecodeNEMA_PGRMB();
			}
		}
		//----------------------------------------------------------------------		
	}

	// �����ȷ���������ݣ�������Ϣ����ܣ����������磬��¼���ڵ�ͼ����ʾ�ȵȡ�
	if (pack != NULL)
	{
		::SendMessage(AfxGetApp()->GetMainWnd()->m_hWnd, WM_DECODED_NEMA_SENTENCE, (WPARAM)&m_Com, (LPARAM)pack);
	}
	//---------------------------------------------------------------------------
    return 1;
}

LRESULT CDataFlow::OnResponseMsg(WPARAM wp,LPARAM lp)
{
	return 1;
}


void CDataFlow::InitVariable()
{
	m_Com = "";
	m_dwToMeMsg=WM_COM_TO_DATA_FLOW;

	m_dwDataGramTail=0;
	m_dwDataGramHead=0;
	m_dwDataGramLen = 0;
	m_Data.RemoveAll();

	m_dwComEvent=0;		

	m_pReceEdit=NULL;
	m_pSendEdit=NULL;		
}

///////////////////////////////////////////////////////////////////
// ��������	CheckData
// ��  �ܣ�	�ж�У�����Ƿ���ȷ
// ��  ����	CString *check1--��׼У����
//			int check2--������У���� 
// ����ֵ��	BOOL--У�����Ƿ���ȷ
// ��  ע��	������˾����ϵͳ��Ϣ
///////////////////////////////////////////////////////////////////
BOOL CDataFlow::CheckData(CString *check1, int check2)
{
	char c2=check2 & 0x0f; 
	char c1=(check2 >> 4) & 0x0f; 
	if (c1 < 10) c1+= '0'; else c1 += 'A' - 10; 
	if (c2 < 10) c2+= '0'; else c2 += 'A' - 10; 

	if ((c1 == check1->GetAt(0))
		&& (c2 == check1->GetAt(1)))
	{
		return TRUE;
	}

	return FALSE;
}
