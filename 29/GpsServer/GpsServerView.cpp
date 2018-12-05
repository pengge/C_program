// GpsServerView.cpp : implementation of the CGpsServerView class
//

#include "stdafx.h"
#include "GpsServer.h"
#include "GpsServerDoc.h"
#include "GpsServerView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGpsServerView
IMPLEMENT_DYNCREATE(CGpsServerView, CHtmlView)

BEGIN_MESSAGE_MAP(CGpsServerView, CHtmlView)
	//{{AFX_MSG_MAP(CGpsServerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CGpsServerView construction/destruction

CGpsServerView::CGpsServerView()   	
{	
	// TODO: add construction code here
}

CGpsServerView::~CGpsServerView()
{
}

CMainFrame* CGpsServerView::GetMainFrame()
{
	return (CMainFrame*)AfxGetApp()->GetMainWnd();
}


/////////////////////////////////////////////////////////////////////////////
// CGpsServerView drawing

void CGpsServerView::OnDraw(CDC* pDC)
{
	CGpsServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here	

}

/////////////////////////////////////////////////////////////////////////////
// CGpsServerView printing

/////////////////////////////////////////////////////////////////////////////
// CGpsServerView diagnostics

#ifdef _DEBUG
void CGpsServerView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CGpsServerView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CGpsServerDoc* CGpsServerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGpsServerDoc)));
	return (CGpsServerDoc*)m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGpsServerView message handlers

void CGpsServerView::OnInitialUpdate() 
{
	CHtmlView::OnInitialUpdate();

	CMainFrame* pFrame =  GetMainFrame();
	if (pFrame != NULL)	
		pFrame->SetView(this);

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	InitMap();
}

int CGpsServerView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CHtmlView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CMainFrame* pFrame =  GetMainFrame();
	if (pFrame != NULL)	
		pFrame->SetView(this);

	return 0;
}


void CGpsServerView::DrawPositionOnMap(GPSPack *pack)
{	
	if (pack == NULL) return;

	double x;
	double y;
	CString name;

	switch(pack->GPS_NEMA_TEXT.bodyType)
	{
	case NEMATYPE_TEXT_POS:
		x = pack->GPS_NEMA_TEXT.body.longitude.longitude*100000;
		y = pack->GPS_NEMA_TEXT.body.latitude.latitude*100000;
		name = "(GPS_NEMA_TEXT)�����ҵĲ���λ��!!!";	
		ShowPoint(x, y, name);
		break;

	case NEMATYPE_STANDARD_GPGGA:
		x = pack->GPS_NEMA_GPGGA.body.longitude.longitude*100000;
		y = pack->GPS_NEMA_GPGGA.body.latitude.latitude*100000;
		name = "(GPS_NEMA_GPGGA)�����ҵĲ���λ��!!!";
		ShowPoint(x, y, name);
		break;

	case NEMATYPE_STANDARD_GPRMC:
		x = pack->GPS_NEMA_GPRMC.body.longitude.longitude*100000;
		y = pack->GPS_NEMA_GPRMC.body.latitude.latitude*100000;
		name = "(GPS_NEMA_GPRMC)�����ҵĲ���λ��!!!";
		ShowPoint(x, y, name);
		break;

	case NEMATYPE_STANDARD_GPGLL:
		x = pack->GPS_NEMA_GPGLL.body.longitude.longitude*100000;
		y = pack->GPS_NEMA_GPGLL.body.latitude.latitude*100000;
		name = "(GPS_NEMA_GPGLL)�����ҵĲ���λ��!!!";
		ShowPoint(x, y, name);
		break;

	case NEMATYPE_GARMIN_PGRMF:
		x = pack->GPS_NEMA_PGRMF.body.longitude.longitude*100000;
		y = pack->GPS_NEMA_PGRMF.body.latitude.latitude*100000;
		name = "(GPS_NEMA_PGRMF)�����ҵĲ���λ��!!!";
		ShowPoint(x, y, name);
		break;
	}	
}

///////////////////////////////////////////////////////////////////
// ��������	ShowPoint
// ��  �ܣ�	��ʾ��λ��
// ��  ����	double x--��ʾ�ľ���
//			double y--��ʾ��γ��
//			CString name--��ʾ������
// ����ֵ��	
///////////////////////////////////////////////////////////////////
void CGpsServerView::ShowPoint(double x, double y, CString name)
{
	CString js;	
	js.Format(_T("showpoint(%f, %f, \"%s\");"), x, y, name);
	ExecJavaScript(js);
}

///////////////////////////////////////////////////////////////////
// ��������	ExecJavaScript
// ��  �ܣ�	ִ��JavaScript�ű�����
// ��  ����	CString js--Ҫִ�еĽű�
// ����ֵ��	
///////////////////////////////////////////////////////////////////
void CGpsServerView::ExecJavaScript(CString js)
{
	//��ȡHTML�ĵ�
	CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL) return;

	//��ȡHTML����
	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL) return;

	//ִ��JavaScript�ű�
	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);

	return;
}

void CGpsServerView::InitMap()
{	
	//��ȡ��ǰӦ�ó��������·��
	char szCurDir[MAX_PATH];
	memset(szCurDir, 0x00, sizeof(szCurDir));
	DWORD length=sizeof(szCurDir);  
	GetModuleFileName(NULL, szCurDir, length);
	
	//��Ӧ�ó�������ȥ�����õ���ǰ���г����Ŀ¼
	CString app;
	app.Format("%s", szCurDir);
	int end = app.ReverseFind('\\');
	app = app.Left(end);

	//�ҵ���ǰ·���µĵ�ͼ��Ϣ��ģ���ļ���
	CString sPath;
	sPath.Format(_T("%s\\%s"), app, MAP_TEMPLATE_PATH);	

	//�����ͼҳ�档
	Navigate2(_T(sPath),NULL,NULL);
}





