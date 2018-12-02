// XMLParserSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "XMLParserSample.h"
#include "XMLParserSampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#import   "msxml4.dll"

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
// CXMLParserSampleDlg dialog

CXMLParserSampleDlg::CXMLParserSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXMLParserSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXMLParserSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXMLParserSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXMLParserSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXMLParserSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CXMLParserSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_READ_XML, OnButtonReadXml)
	ON_BN_CLICKED(IDC_BUTTON_WRITE_XML, OnButtonWriteXml)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXMLParserSampleDlg message handlers

BOOL CXMLParserSampleDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CXMLParserSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CXMLParserSampleDlg::OnPaint() 
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
HCURSOR CXMLParserSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//读XML文件
void CXMLParserSampleDlg::OnButtonReadXml() 
{
	CString log, info;
	//创建DOMDocument对象   
	MSXML2::IXMLDOMDocumentPtr pDoc;     
	//创建DOMDocument对象   
	if (!SUCCEEDED(pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30))))
		WriteLog("创建DOMDocument对象失败，请确认安装MSXMLParser组件!");	

	//加载文件   
	pDoc->load("Students.xml");   

	//在树中查找名为Students的节点,"//"表示在任意一层查找   
	MSXML2::IXMLDOMElementPtr  pChild;   
	pChild=(MSXML2::IXMLDOMElementPtr)(pDoc->selectSingleNode("//Students"));
	//节点名称和结点值 
	BSTR var;
	VARIANT varVal;
	pChild->get_nodeName(&var);
	pChild->get_nodeTypedValue(&varVal); 
	info.Format("结点名称=%s\t值=%s\r\n", (char*)(_bstr_t)pChild->nodeName, 
		(char*)(_bstr_t)pChild->nodeTypedValue);
	log += info;

	MSXML2::IXMLDOMNodeListPtr pList;
	MSXML2::IXMLDOMNodePtr pNode;
	pList = (MSXML2::IXMLDOMNodeListPtr)pChild->selectNodes("Student");
	long nodeCount = pList->Getlength();
	for (int i = 0;i <nodeCount;i++)
	{
		if (!SUCCEEDED(pList->get_item(i, &pNode))) continue;
		
		//节点名称和结点值 
		BSTR var;
		VARIANT varVal;
		pNode->get_nodeName(&var);
		pNode->get_nodeTypedValue(&varVal); 
		info.Format("\r\n结点名称=%s\t值=%s\r\n", (char*)(_bstr_t)pNode->nodeName, 
			(char*)(_bstr_t)pNode->nodeTypedValue);
		log += info;

		//节点属性,放在链表中   
		MSXML2::IXMLDOMNamedNodeMapPtr pAttrs=NULL;     
		MSXML2::IXMLDOMNodePtr   pAttrItem;   
		pNode->get_attributes(&pAttrs);   
		long   nCount;   
		pAttrs->get_length(&nCount);   
		for(int j=0; j<nCount; j++)   
		{ 
			if (!SUCCEEDED(pAttrs->get_item(j,&pAttrItem))) continue;			
			info.Format("属性名称=%s\t值=%s\r\n", (char*)(_bstr_t)pAttrItem->baseName, 
				(char*)(_bstr_t)pAttrItem->text);
			log += info;
		}	
	}
	WriteLog(log);
}

// 写XML文件
void CXMLParserSampleDlg::OnButtonWriteXml() 
{
	MSXML2::IXMLDOMDocumentPtr pDoc;     
	MSXML2::IXMLDOMElementPtr  pRoot;   
	//创建DOMDocument对象   
	if (!SUCCEEDED(pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30))))
		WriteLog("创建DOMDocument对象失败，请确认安装MSXMLParser组件!");
 
	//根节点的名称为Student   
	pDoc->raw_createElement((_bstr_t)(char*)"Students", &pRoot);   
	pDoc->raw_appendChild(pRoot, NULL);   

	MSXML2::IXMLDOMElementPtr  pChild;
	
	pDoc->raw_createElement((_bstr_t)(char*)("Student"), &pChild);   
	pChild->Puttext("张三");//节点值   
	pChild->setAttribute("ID","200801");//属性名,属性值   
	pChild->setAttribute("SEX","男");   
	pRoot->appendChild(pChild);   
 
	pDoc->raw_createElement((_bstr_t)(char*)("Student"), &pChild);   
	pChild->Puttext("李四");   
	pChild->setAttribute("ID","200802");   
	pChild->setAttribute("SEX","女");   
	pRoot->appendChild(pChild);

	//保存到文件   
	pDoc->save("Students.xml");
	WriteLog("存入XML文件成功");
}

void CXMLParserSampleDlg::WriteLog(CString log)
{
	m_editLog.SetWindowText(log);
}
