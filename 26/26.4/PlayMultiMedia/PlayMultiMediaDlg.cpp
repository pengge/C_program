// PlayMultiMediaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlayMultiMedia.h"
#include "PlayMultiMediaDlg.h"
#include "gdiplus.h"
#include "shockwaveflash.h"
#include "mmsystem.h"
#include "vfw.h"

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
// CPlayMultiMediaDlg dialog

CPlayMultiMediaDlg::CPlayMultiMediaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayMultiMediaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayMultiMediaDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlayMultiMediaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayMultiMediaDlg)
	DDX_Control(pDX, IDC_REALPLAYER1, m_realplayCtrl);
	DDX_Control(pDX, IDC_VCDOCX, m_wmPlayer);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH1, m_shockWaveFlash);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlayMultiMediaDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayMultiMediaDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PLAYGIF, OnButtonPlaygif)
	ON_BN_CLICKED(IDC_BUTTON_PLAYFLASH, OnButtonPlayflash)
	ON_BN_CLICKED(IDC_BUTTON_PLAYRM, OnButtonPlayrm)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_PLAYCD, OnButtonPlaycd)
	ON_BN_CLICKED(IDC_BUTTON_SHOWJPEG, OnButtonShowjpeg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayMultiMediaDlg message handlers

BOOL CPlayMultiMediaDlg::OnInitDialog()
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

void CPlayMultiMediaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlayMultiMediaDlg::OnPaint() 
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
HCURSOR CPlayMultiMediaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//播放Gif动画
void CPlayMultiMediaDlg::OnButtonPlaygif() 
{
	Image image(L"C:\\byebye.gif");

	UINT uiCount = image.GetFrameDimensionsCount();
	GUID *pDimensionIDs=(GUID*)new GUID[uiCount];
	image.GetFrameDimensionsList(pDimensionIDs, uiCount);
	UINT uiFrameCount=image.GetFrameCount(&pDimensionIDs[0]);
	delete []pDimensionIDs;

	UINT uiSize;
	uiSize = image.GetPropertyItemSize(PropertyTagFrameDelay);	
	PropertyItem* pItem = (PropertyItem*)malloc(uiSize);
	image.GetPropertyItem(PropertyTagFrameDelay, uiSize, pItem);

	GUID Guid = FrameDimensionTime;
	CDC* pDC = GetDC();	
	while(true)
	{	
		Graphics gh(pDC->m_hDC); //hDC是外部传入的画图DC
		gh.DrawImage(&image,0, 0, image.GetWidth(), image.GetHeight());	
		image.SelectActiveFrame(&Guid, uiCount++);//重新设置当前的活动数据帧
		if(uiCount == uiFrameCount) uiCount= 0;			
		long lPause = ((long*)(pItem->value))[uiCount];//计算此帧要延迟的时间
		Sleep(lPause);	
	}
}

//播放Flash动画
void CPlayMultiMediaDlg::OnButtonPlayflash() 
{
	m_shockWaveFlash.SetMovie("C:\\reading1.swf");   
	m_shockWaveFlash.Play();  
}

//播放RM文件
void CPlayMultiMediaDlg::OnButtonPlayrm() 
{
	m_realplayCtrl.SetSource("C:\\又见炊烟.rm");
	m_realplayCtrl.DoPlay();
}

void CPlayMultiMediaDlg::OnDestroy() 
{
	CDialog::OnDestroy();	
}

//播放VCD
void CPlayMultiMediaDlg::OnButtonPlaycd() 
{
	m_wmPlayer.SetUrl("E:\\LLN\\回忆\\宝宝四维彩超\\MPEGAV\\AVSEQ01.DAT");
}

//显示JPEG图像
void CPlayMultiMediaDlg::OnButtonShowjpeg() 
{
	CDC*   pDC=GetDC();   
    LPPICTURE   gpPicture = NULL;    
	CString fileName = "C:\\BeautyGirl.JPG";
    HANDLE hFile = CreateFile(fileName, GENERIC_READ,  0,  NULL,OPEN_EXISTING, 0, NULL);
	if (hFile==INVALID_HANDLE_VALUE) return;
	DWORD   dwFileSize = GetFileSize(hFile, NULL);   //取得文件大小
	if (dwFileSize == -1) return;  
	LPVOID pvData=NULL;  
	HGLOBAL hGlobal= GlobalAlloc(GMEM_MOVEABLE, dwFileSize);  //根据文件大小分配内存
	if (hGlobal != NULL) pvData=GlobalLock(hGlobal);
	if (pvData  == NULL) return;
	DWORD dwBytesRead = 0;	
	BOOL bRead= ReadFile(hFile, pvData, dwFileSize, &dwBytesRead, NULL);//读取文件并存入全局内存
	GlobalUnlock(hGlobal);   
	CloseHandle(hFile);  
	if (!bRead) 
	{		
		return;
	}
	LPSTREAM pstm=NULL;   
	HRESULT hr=CreateStreamOnHGlobal(hGlobal, TRUE, &pstm);// 通过全局内存创建IStream*的指针
	if (!SUCCEEDED(hr)) return;
	//通过图形文件创建IPicture对象   
	if (gpPicture)   
		gpPicture->Release();   
	hr = OleLoadPicture(pstm, dwFileSize, FALSE, IID_IPicture, (LPVOID*)&gpPicture);
	if (!SUCCEEDED(hr)) return; 
	pstm->Release();   
	HDC hdc=pDC->GetSafeHdc();   
	if (gpPicture)   
	{   
		//取得图片的宽和高   
		long   hmWidth;   
		long   hmHeight;   
		gpPicture->get_Width(&hmWidth);   
		gpPicture->get_Height(&hmHeight);   
		//宽高转换为象素
		int inch = 2540;
		int nWidth = MulDiv(hmWidth, GetDeviceCaps(hdc, LOGPIXELSX), inch);   
		int  nHeight = MulDiv(hmHeight, GetDeviceCaps(hdc, LOGPIXELSY), inch);   
		RECT rc;   
		GetClientRect(&rc);/*取得客户区*/

		int x = 0;
		int y = 0;
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;		
		gpPicture->Render(hdc, x, y, (int)height*hmWidth/hmHeight, height, 0, hmHeight, hmWidth, -hmHeight, &rc);
	}
}
