// ADOSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOSample.h"
#include "ADOSampleDlg.h"

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
// CADOSampleDlg dialog

CADOSampleDlg::CADOSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOSampleDlg)
	m_FirstName = _T("");
	m_ID = _T("");
	m_LastName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADOSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_FirstName);
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_LastName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CADOSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_READRECORD, OnButtonReadrecord)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_WRITERECORD, OnButtonWriterecord)
	ON_BN_CLICKED(IDC_BUTTON_DELRECORD2, OnButtonDelrecord2)
	ON_BN_CLICKED(IDC_BUTTON_EXEPROC, OnButtonExeproc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOSampleDlg message handlers

BOOL CADOSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_pConnection = NULL;

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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CADOSampleDlg::OnPaint() 
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
HCURSOR CADOSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 记录日志
void CADOSampleDlg::WriteLog(CString log)
{
	m_editLog.SetWindowText(log);
}

// 连接数据库
void CADOSampleDlg::OnButtonConnect() 
{
	HRESULT hr;
	try
	{
		hr = m_pConnection.CreateInstance("ADODB.Connection");
		
		if(SUCCEEDED(hr))
            hr = m_pConnection->Open(
            "provider=SQLOLEDB;Data Source=127.0.0.1;Initial catalog=TryAgain;Integrated Security=SSPI;","sa","sa",adConnectUnspecified);
        if (m_pConnection->State)
            WriteLog("数据库连接成功");
		else WriteLog("连接数据库失败");
	}
	catch(_com_error e)
	{
		CString log;
		log.Format("连接数据库失败!\r\n原因:%s",e.ErrorMessage());
		WriteLog(log);
	}	
}

// 关闭窗口
void CADOSampleDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	if (m_pRecordset != NULL)
		m_pRecordset->Close();
	if (m_pConnection != NULL)
		if (m_pConnection->State) m_pConnection.GetInterfacePtr()->Close();
}

// 读取数据记录
void CADOSampleDlg::OnButtonReadrecord() 
{
	if (m_pConnection == NULL) return;
	m_pConnection->CursorLocation =adUseServer;
	m_pRecordset.CreateInstance("ADODB.Recordset");
	m_pRecordset->Open("SELECT * FROM Employees",
		_variant_t((IDispatch*)m_pConnection,TRUE),adOpenStatic,adLockOptimistic,adCmdText);
	GetRecordContent();
}

// 获取当前记录位置中的记录内容
void CADOSampleDlg::GetRecordContent()
{
	if (m_pRecordset == NULL) return;
	if ((m_pRecordset->BOF) || (m_pRecordset->adoEOF)) return;	
	_variant_t vID, vLastName, vFirstName;
	vID = m_pRecordset->GetCollect("EmployeeID");
	vLastName = m_pRecordset->GetCollect("LastName");
	vFirstName = m_pRecordset->GetCollect("FirstName");
	m_ID = (LPCTSTR)(_bstr_t)(vID);
	m_LastName = (LPCTSTR)(_bstr_t)(vLastName);
	m_FirstName = (LPCTSTR)(_bstr_t)(vFirstName);
	UpdateData(FALSE);
}

// 移动到第一条
void CADOSampleDlg::OnButtonFirst() 
{
	if (m_pRecordset == NULL) return;
	m_pRecordset->MoveFirst();
	GetRecordContent();
}

// 移动到最后一条
void CADOSampleDlg::OnButtonLast() 
{
	if (m_pRecordset == NULL) return;
	m_pRecordset->MoveLast();
	GetRecordContent();
}

// 移动到上一条
void CADOSampleDlg::OnButtonPrev() 
{
	if (m_pRecordset == NULL) return;
	if (m_pRecordset->BOF) return;
	m_pRecordset->MovePrevious();
	GetRecordContent();
}

// 移动到下一条
void CADOSampleDlg::OnButtonNext() 
{
	if (m_pRecordset == NULL) return;
	if (m_pRecordset->adoEOF) return;
	m_pRecordset->MoveNext();
	GetRecordContent();
}

// 写入数据记录
void CADOSampleDlg::OnButtonWriterecord() 
{
	if ((m_pConnection == NULL) || (m_pRecordset == NULL)) return;	
	try
	{
		UpdateData(TRUE);
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("LastName", _variant_t(m_LastName));
		m_pRecordset->PutCollect("FirstName", _variant_t(m_FirstName));
		m_pRecordset->Update();
		WriteLog("插入记录成功");
	}
	catch(_com_error e)
	{
		CString log;
		log.Format("插入记录失败!\r\n原因:%s",e.ErrorMessage());
		WriteLog(log);
	}
}

//删除记录
void CADOSampleDlg::OnButtonDelrecord2() 
{	
	if (m_pRecordset == NULL) return;
	try
	{
		m_pRecordset->Delete(adAffectCurrent);
		m_pRecordset->Update();
		m_pRecordset->Requery(NULL);
		GetRecordContent();
		WriteLog("删除记录成功");
	}
	catch(_com_error e)
	{
		CString log;
		log.Format("删除记录失败!\r\n原因:%s",e.ErrorMessage());
		WriteLog(log);
	}	
}

// 调用存储过程
void CADOSampleDlg::OnButtonExeproc() 
{
	try
	{
		if (m_pConnection == NULL) return;
		m_pConnection->CursorLocation =adUseClient;

		m_pRecordset.CreateInstance("ADODB.Recordset");

		// 初始化命令对象
		_CommandPtr m_pCommand;
		m_pCommand.CreateInstance("ADODB.Command");	
		m_pCommand->ActiveConnection = m_pConnection;
		m_pCommand->CommandType = adCmdStoredProc;
		m_pCommand->CommandText = _bstr_t(_T("GetEmployeeByName"));

		//创建参数
		UpdateData(TRUE);
		m_pCommand->Parameters->Refresh(); 
		m_pCommand->Parameters->Item[_variant_t(_bstr_t("@EmployeeID"))]->Value =_variant_t(short(atoi(m_ID)));
		
		//执行存储过程
		m_pRecordset =  m_pCommand->Execute(NULL,NULL,adCmdStoredProc);

		int iResult = -1;
		_variant_t vResult; 
		vResult = m_pCommand->Parameters->GetItem(short(2))->Value;  
		iResult = vResult.intVal;
   
		CString log;
		log.Format("调用存储过程，共查询到%d条记录", iResult);
		WriteLog(log);

		if (m_pRecordset->RecordCount<=0) 
		{
			m_pRecordset->Close();
			m_pRecordset = NULL;
			m_pCommand.Detach();
			return;
		}
		m_pRecordset->MoveFirst();  
		GetRecordContent();
	}
	catch(_com_error e)
	{
		CString log;
		log.Format("调用存储过程失败!\r\n原因:%s",e.ErrorMessage());
		WriteLog(log);
	}	
}

