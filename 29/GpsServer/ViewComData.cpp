// ViewComData.cpp : implementation file
//

#include "stdafx.h"
#include "gpsserver.h"
#include "ViewComData.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewComData


IMPLEMENT_DYNCREATE(CViewComData, CFormView)

CViewComData::CViewComData()
	: CFormView(CViewComData::IDD)
{
	//{{AFX_DATA_INIT(CViewComData)
	m_Com = _T("");
	m_sendData = _T("$GPGGA,062322,3537.8333,N,13944.6667,E,0,00,99.9,0100,M,,M,000,0000*7F\r\n");
	//}}AFX_DATA_INIT
}

CViewComData::~CViewComData()
{
}

void CViewComData::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewComData)
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comboType);
	DDX_Control(pDX, IDC_EDIT_COM, m_comEdit);
	DDX_Control(pDX, IDC_SEND_EDIT, m_sendEdit);
	DDX_Control(pDX, IDC_RECE_EDIT, m_receEdit);
	DDX_Text(pDX, IDC_EDIT_COM, m_Com);
	DDX_Text(pDX, IDC_SEND_EDIT, m_sendData);
	DDV_MaxChars(pDX, m_sendData, 2048);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewComData, CFormView)
	//{{AFX_MSG_MAP(CViewComData)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
	ON_BN_CLICKED(IDC_BUTTON_ADDTAIL, OnButtonAddtail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewComData diagnostics

#ifdef _DEBUG
void CViewComData::AssertValid() const
{
	CFormView::AssertValid();
}

void CViewComData::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewComData message handlers

void CViewComData::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_receEdit.Clear();
	m_sendEdit.Clear();
	m_comEdit.Clear();

	int _index[]=
	{
		NEMATYPE_TEXT_POS, 
		NEMATYPE_STANDARD_GPGGA, 
		NEMATYPE_STANDARD_GPGSA, 
		NEMATYPE_STANDARD_GPGSV, 
		NEMATYPE_STANDARD_GPRMC, 
		NEMATYPE_STANDARD_GPVTG, 
		NEMATYPE_STANDARD_GPGLL, 
		NEMATYPE_STANDARD_GPZDA, 
		NEMATYPE_STANDARD_GPDTM, 
		NEMATYPE_GARMIN_PGRME, 
		NEMATYPE_GARMIN_PGRMF, 
		NEMATYPE_GARMIN_PGRMM, 
		NEMATYPE_GARMIN_PGRMT, 
		NEMATYPE_GARMIN_PGRMV, 
		NEMATYPE_GARMIN_PGRMB,
	};

	CString _caption[]=
	{
		"NEMA�ı�", 
		"GPGGA--�ǲ�ֶ�λ", 
		"GPGSA--��ǰ������Ϣ",
		"GPGSV--�ɼ�������Ϣ", 
		"GPRMC--�Ƽ���λ��Ϣ", 
		"GPVTG--�����ٶ���Ϣ",
		"GPGLL--��λ������Ϣ", 
		"GPZDA--ʱ���������Ϣ", 
		"GPDTM--�������ϵ��Ϣ",
		"PGRME--���������Ϣ", 
		"PGRMF--GPS��λ��Ϣ", 
		"PGRMM--����ϵͳ��Ϣ",
		"PGRMT--����״̬��Ϣ", 
		"PGRMV--��ά�ٶ���Ϣ", 
		"PGRMB--�ű�����Ϣ"
	};

	for (int i = 0 ;i < NEMA_COUNT;i++)
	{
		m_comboType.InsertString(_index[i], _caption[i]);
	}	
	m_comboType.SetCurSel(NEMATYPE_TEXT_POS);

	UpdateData(FALSE);
}

BOOL CViewComData::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFormView::PreCreateWindow(cs);
}



void CViewComData::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	// ���ͷ������ݵ���Ϣ�������ڣ���������ָ�봫�ݸ������ڣ��������ڵ�������Ӧ�ķ��ͳ���	
	UpdateData(TRUE);
	::SendMessage(AfxGetApp()->GetMainWnd()->m_hWnd, WM_SEND_COM_DATA, (WPARAM)&m_Com, (LPARAM)&m_sendData);
}

BOOL CViewComData::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CViewComData::OnSelchangeComboType() 
{
	// TODO: Add your control notification handler code here
	int type = m_comboType.GetCurSel();
	CString _content[]=
	{
		//NEMA�ı�
		_T("@080829130628N3612345E12012345d012+54321E1234S5678D0920\r\n"), 

		//GPGGA--�ǲ�ֶ�λ
		_T("$GPGGA,062322,3606.6572,N,12024.9054,E,0,00,99.9,0100,M,,M,000,0000*74\r\n"), 

		//"GPGSA--��ǰ������Ϣ"
		_T("$GPGSA,A,3,14,15,05,22,18,26,,,,,,,2.1,1.2,1.7*3D\r\n"),

		//"GPGSV--�ɼ�������Ϣ", 
		_T("$GPGSV,3,1,10,18,84,067,23,09,67,067,27,22,49,312,28,15,47,231,30*70\r\n"),

		//"GPRMC--�Ƽ���λ��Ϣ", 
		_T("$GPRMC,121252.000,A,3958.3032,N,11629.6046,E,15.15,359.95,090308,12.356,E,A*0C\r\n"),

		//"GPVTG--�����ٶ���Ϣ",
		_T("$GPVTG,359.95,T,20.654,M,15.15,N,28.0,K,A*1F\r\n"),

		//"GPGLL--��λ������Ϣ", 
		_T("$GPGLL,3537.8333,N,13944.6667,E,062321,V,A*57\r\n"),

		//"GPZDA--ʱ���������Ϣ", 
		_T("$GPZDA,062321,03,09,2008,,*4C\r\n"),

		//"GPDTM--�������ϵ��Ϣ",
		_T("$GPDTM,W84,,00.0000,N,00.0000,W,,W84*53\r\n"),

		//"PGRME--���������Ϣ", 
		_T("$PGRME,15.6,M,16.0,M,22.4,M*1F\r\n"),

		//"PGRMF--GPS��λ��Ϣ", 
		_T("$PGRMF,46,205943,110700,091210,13,4913.3112,N,00837.4950,E,A,2,30,74,2,1*26\r\n"),

		//"PGRMM--����ϵͳ��Ϣ",
		_T("$PGRMM,WGS 84*06\r\n"),

		//"PGRMT--����״̬��Ϣ", 
		_T("$PGRMT,GPS 15 Ver. 2.00,P,P,R,R,F,C,29,R*3F\r\n"),

		//"PGRMV--��ά�ٶ���Ϣ", 
		_T("$PGRMV,8.0,2.3,1.6*52\r\n"),

		//"PGRMB--�ű�����Ϣ"
		_T("$PGRMB,-1.0,25,5,34,2,K,2,W,W*1A\r\n")

	};

	if (type < NEMA_COUNT)
	{
		m_sendData.Format("%s", _content[type]);		
		UpdateData(FALSE);	
	}
}

void CViewComData::OnButtonAddtail() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_sendData += _T("\r\n");
	UpdateData(FALSE);
}

void CViewComData::InsertReceiveData(CString pSource, CString pData)
{
	int iEditLength = m_receEdit.GetWindowTextLength();
	if(iEditLength > MAX_COM_VIEW_LENGTH)
	{
		m_receEdit.SetSel(0,-1);
		m_receEdit.Clear();
	}
		
	iEditLength = m_receEdit.GetWindowTextLength();
	m_receEdit.SetSel(iEditLength, iEditLength);
	m_receEdit.ReplaceSel(pData );
}
