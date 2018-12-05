// BroadConvertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BroadConvert.h"
#include "BroadConvertDlg.h"
#include <Commdlg.h>
#include <commctrl.h>
#include <stdio.h>
#include "AudioPlay.h"
#include "TagDefine.h"
#include "DlgItem.h"
#include "TestPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBroadConvertDlg dialog

CBroadConvertDlg::CBroadConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBroadConvertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBroadConvertDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBroadConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBroadConvertDlg)	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBroadConvertDlg, CDialog)
	//{{AFX_MSG_MAP(CBroadConvertDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_LOAD, OnButLoad)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBroadConvertDlg message handlers

BOOL CBroadConvertDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	OnButLoad();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBroadConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBroadConvertDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBroadConvertDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



// Locate a driver that supports a given format and return its ID


//////////////////////////////////////////////////////////////////////////////////
// ��������:  ����ö�ٻص�����
// �������: 
//				HACMDRIVERID hadid	-- ����ID
//				LPACMFORMATDETAILS pafd	-- ���ACM��ʽϸ��
//				DWORD dwInstance	-- �û��������
//				DWORD fdwSupport	-- 
// �������:
// ����ֵ  :
//				BOOL				-- �Ƿ����ö��,TRUE:����ö��;FALSE:ֹͣö��
// ��    ע:
//////////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK find_format_enum(HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD dwInstance, DWORD fdwSupport)
{
	//--------------------------------
	// Step1: ����ʹ�õı���
	//--------------------------------
	FIND_DRIVER_INFO* pdi;

	//----------------------------------------------------------------------
	// Step2: Ϊ������ֵ,�������û�����ĸ�ʽƥ�������ID,���ҵ���,ֹͣö��
	//----------------------------------------------------------------------
	pdi = (FIND_DRIVER_INFO*) dwInstance;
	if (pafd->dwFormatTag == (DWORD)pdi->wFormatTag) 
	{		
		pdi->hadid = hadid;
		return FALSE; 
	}

	return TRUE; // continue enumerating
}

//////////////////////////////////////////////////////////////////////////////////
// ��������:  ����ö�ٻص�����
// �������: 
//				HACMDRIVERID hadid	-- ����ID
//				DWORD dwInstance	-- �û��������
//				DWORD fdwSupport	-- 
// �������:
// ����ֵ  :
//				BOOL				-- �Ƿ����ö��,TRUE:����ö��;FALSE:ֹͣö��
// ��    ע:
//////////////////////////////////////////////////////////////////////////////////
BOOL CALLBACK find_driver_enum(HACMDRIVERID hadid, DWORD dwInstance, DWORD fdwSupport)
{

	//--------------------------------
	// Step1: ����ʹ�õı���
	//--------------------------------
	ACMFORMATDETAILS		fd;
	FIND_DRIVER_INFO*		pdi = NULL;
	WAVEFORMATEX*			pwf	= NULL;
	HACMDRIVER				had = NULL;
	MMRESULT				mmr;	
	DWORD					dwSize = 0;
	BOOL					bSuccess = TRUE;
	

	//--------------------------------
	// Step2: Ϊ������ֵ
	//--------------------------------
	pdi	= (FIND_DRIVER_INFO*) dwInstance;
	
	//-----------------------------------
	// Step3: ������, ��ʧ��,ֹͣö��
	//-----------------------------------
	mmr = acmDriverOpen(&had, hadid, 0);
	if ( mmr != MMSYSERR_NOERROR )  
	{		
		bSuccess = FALSE;
		goto HappenError;		
	}

	//-------------------------------------------------------
	// Step4: ö�ٴ�����֧�ֵĸ�ʽ,
	//			(1) ��ѯ֧�ֵĸ�ʽ����󳤶�
	//			(2) ΪWave��ʽ������ACM������ϸ����������ֵ
	//			(3)	ö�ٴ�����֧�ֵĸ�ʽ
	//-------------------------------------------------------		
	mmr = acmMetrics( (HACMOBJ)had, ACM_METRIC_MAX_SIZE_FORMAT, &dwSize );
	if ( dwSize < sizeof( WAVEFORMATEX ) ) 
	{
		dwSize = sizeof( WAVEFORMATEX ); 
	}

	pwf = (WAVEFORMATEX*) malloc(dwSize);
	memset(pwf, 0, dwSize);
	pwf->cbSize = LOWORD(dwSize) - sizeof(WAVEFORMATEX);
	pwf->wFormatTag = pdi->wFormatTag;
	
	memset(&fd, 0, sizeof(fd));
	fd.cbStruct = sizeof(fd);
	fd.pwfx = pwf;
	fd.cbwfx = dwSize;
	fd.dwFormatTag = pdi->wFormatTag;

	
	mmr = acmFormatEnum(had, 
						&fd, 
						find_format_enum, 
						(DWORD)(VOID*)pdi, 
						0);  
	if ( mmr != MMSYSERR_NOERROR )  
	{		
		bSuccess = FALSE;
		goto HappenError; 
	}
	
	
	if ( pdi->hadid != NULL ) 
	{		
		bSuccess = FALSE;
		goto HappenError;
	}

HappenError:
	acmDriverClose(had, 0);
	SAFE_ARRAYDELETE( pwf );

	if ( bSuccess )
	{		
		return TRUE;		
	}
	else
	{
		return FALSE;
	}
}

//////////////////////////////////////////////////////////////////////
// ��������: ��λ����һ��֧��ָ����ʽ������
// �������: 
//				WORD wFormatTag -- Ҫ֧�ֵĸ�ʽ
// �������:
// ����ֵ  :
//				HACMDRIVERID	-- ���ҵ���ACM Driver ID,ʧ�ܷ���NULL
// ��    ע:
//////////////////////////////////////////////////////////////////////
HACMDRIVERID find_driver(WORD wFormatTag)
{
	//--------------------------------
	// Step1: ����ʹ�õı���
	//--------------------------------
	FIND_DRIVER_INFO	fdi;
	MMRESULT			mmr;

	//--------------------------------
	// Step2: ��Ҫ���ҵĸ�ʽ��������
	//--------------------------------	
	fdi.hadid = NULL;
	fdi.wFormatTag = wFormatTag;

	//-------------------------------------------------
	// Step3: ��������ö�ٺ���,ʧ�ܻ�Ϊ���ҵ�����NULL
	//-------------------------------------------------
	mmr = acmDriverEnum( find_driver_enum, (DWORD)(VOID*)&fdi, 0 ); 
	if ( mmr != MMSYSERR_NOERROR ) 
	{
		return NULL;
	}

	return fdi.hadid;
}

// get a description of the first format supported for a given tag
//////////////////////////////////////////////////////////////////////
// ��������: ��ȡ��ָ��ACM������,֧��ָ����ʽ�ĵ�һ�ָ�ʽ������
// �������: 
//				HACMDRIVERID hadid	--ACM����ID
//				WORD wFormatTag -- Ҫ֧�ֵĸ�ʽ
// �������:
// ����ֵ  :
//				WAVEFORMATEX*	-- ���ش˸�ʽ����ϸ����,ʧ�ܷ���NULL
// ��    ע:
//////////////////////////////////////////////////////////////////////
WAVEFORMATEX* get_driver_format(HACMDRIVERID hadid, WORD wFormatTag)
{
	//--------------------------------
	// Step1: ����ʹ�õı���
	//--------------------------------
	HACMDRIVER	had = NULL;
	MMRESULT	mmr;
	DWORD		dwSize = 0;
	WAVEFORMATEX*		pwf = NULL;
	ACMFORMATDETAILS	fd;
	BOOL		bSuccess = TRUE;
	
	
	//--------------------------------
	// Step2: ��ָ��������
	//--------------------------------
	mmr = acmDriverOpen(&had, hadid, 0);
	if ( mmr != MMSYSERR_NOERROR ) 
	{
		bSuccess = FALSE;
		goto HappenError;
	}	

	// allocate a structure for the info
	//--------------------------------
	// Step3: ��������Ϣ 
	//--------------------------------
	mmr = acmMetrics((HACMOBJ)had, ACM_METRIC_MAX_SIZE_FORMAT, &dwSize);
	if ( mmr != MMSYSERR_NOERROR ) 
	{
		bSuccess = FALSE;
		goto HappenError;
	}

	if (dwSize < sizeof(WAVEFORMATEX)) 
	{
		dwSize = sizeof(WAVEFORMATEX); 
	}
	pwf = (WAVEFORMATEX*) malloc(dwSize);
	memset(pwf, 0, dwSize);
	pwf->cbSize = LOWORD(dwSize) - sizeof(WAVEFORMATEX);
	pwf->wFormatTag = wFormatTag;

	
	memset(&fd, 0, sizeof(fd));
	fd.cbStruct = sizeof(fd);
	fd.pwfx = pwf;
	fd.cbwfx = dwSize;
	fd.dwFormatTag = wFormatTag;

	// set up a struct to control the enumeration
	FIND_DRIVER_INFO fdi;
	fdi.hadid = NULL;
	fdi.wFormatTag = wFormatTag;

	mmr = acmFormatEnum( had, 
						 &fd, 
						 find_format_enum, 
						 (DWORD)(VOID*)&fdi, 
						 0 );  
	if ( mmr != MMSYSERR_NOERROR ) 
	{
		bSuccess = FALSE;
		goto HappenError;
	}

	if ( NULL == fdi.hadid ) 
	{	
		bSuccess = FALSE;
		goto HappenError;
	}

	
HappenError:
	acmDriverClose(had, 0);

	if ( bSuccess )
	{
		return pwf;
	}
	else
	{
		SAFE_ARRAYDELETE( pwf );
		return NULL;
	}	
}

void CBroadConvertDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}

void CBroadConvertDlg::OnButLoad() 
{
	CPropertySheet dlgPropertySheet("Simple Convert");
	dlgPropertySheet.m_psh.nPages = 1;

	CDlgItem stylePage[1];
	//CTestPage stylePage[2];
	
	char	cSource[2][MAX_PATH]={
		//"mms://203.129.68.232/hit997",
		//"mms://wms1.netmyne.com.my/red1"};
		//"mms://abcrad.wm.llnwd.net/abcrad_kabc",
		//"mms://61.185.214.171/fm931",
		"mms://media.iwant-in.net/pop"};
		//"mms://218.244.243.30/fm91.5"};
		//"mms://218.244.243.30/am846",
		//"mms://218.244.243.30/am1008",
		//"mms://online.njbs.com.cn/njyyt",
		//"mms://video.rednet.com.cn/901"};
	char	cCaption[2][512]={
		//"��̨1--�³����ֳ�", 
		//"��̨2--������ɫ988"};
		//"��̨3--TalkRadio 790 KABC", 
		//"��̨4--��������̨", 
		"��̨--��������"};
		//"��̨6--fm91.5"}; 
		/*"��̨7--am846", 
		"��̨8--am1008", 
		"��̨9--�Ͼ�����̨", 
		"��̨10--��������㲥��̨����Ƶ��"};*/

	char cSaveFile[512];
	memset(cSaveFile, 0x00, sizeof(cSaveFile));
	sprintf(cSaveFile, _T("%s"), _T("C:\\\\Stations\\\\"));
	for (int i = 0 ; i < 1 ; i ++)
	{		
		dlgPropertySheet.AddPage(&stylePage[i]);
		stylePage[i].m_psp.dwFlags = stylePage[i].m_psp.dwFlags | PSH_PROPSHEETPAGE|PSP_USETITLE;
		stylePage[i].m_psp.pszTitle = (char*)&cCaption[i][0];

		char cSaveFileA[512];
		char cSaveFileB[512];
		char cSaveFileC[512];
		memset(cSaveFileA, 0x00, sizeof(cSaveFileA));
		memset(cSaveFileB, 0x00, sizeof(cSaveFileB));
		memset(cSaveFileC, 0x00, sizeof(cSaveFileC));
		sprintf(cSaveFileA, "%s%2.2dVoiceA.pcm", cSaveFile, i+1);
		sprintf(cSaveFileB, "%s%2.2dVoiceB.pcm", cSaveFile, i+1);
		sprintf(cSaveFileC, "%s%2.2dVoiceC.pcm", cSaveFile, i+1);
		stylePage[i].InitFileName((char*)&cSource[i][0],
			cSaveFileA, cSaveFileB,	cSaveFileC, FALSE, (char*)&cCaption[i][0]);
	}
		
	dlgPropertySheet.m_psh.dwFlags |= PSH_NOAPPLYNOW ;//| PSH_PROPTITLE;
	dlgPropertySheet.m_psh.pszCaption = "��̨ת��";
	dlgPropertySheet.m_psh.nStartPage = 0;

	dlgPropertySheet.DoModal();
}
