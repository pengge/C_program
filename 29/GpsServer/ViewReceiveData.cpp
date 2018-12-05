// ViewReceiveData.cpp : implementation file
//

#include "stdafx.h"
#include "GpsServer.h"
#include "ViewReceiveData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewReceiveData
IMPLEMENT_DYNCREATE(CViewReceiveData, CViewBase)

CViewReceiveData::CViewReceiveData()
{
	InitColumns();
}

CViewReceiveData::~CViewReceiveData()
{
}


BEGIN_MESSAGE_MAP(CViewReceiveData, CViewBase)
	//{{AFX_MSG_MAP(CViewReceiveData)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewReceiveData diagnostics

#ifdef _DEBUG

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewReceiveData message handlers

void CViewReceiveData::InitColumns()
{
	_gColText.Add(IDS_COL_RECEIVE_1);
	_gColText.Add(IDS_COL_RECEIVE_2);
	_gColText.Add(IDS_COL_RECEIVE_3);
	_gColText.Add(IDS_COL_RECEIVE_4);

	_gColWidth.Add(75);
	_gColWidth.Add(100);
	_gColWidth.Add(200);
	_gColWidth.Add(300);
}

void CViewReceiveData::InsertReceiveLog(CString source, CString content)
{
	// ��ȡ��ǰ�б����еļ�¼��Ŀ����������������־����,���б����е���־ɾ��
	if ((GetListCtrl().GetItemCount()) > VIEW_LOG_COUNT) 
	{
		ClearLogs();
	}

	//id
	CString sid="";
	sid.Format("%d",(GetListCtrl().GetItemCount()+1));
	//level
	
	//time
	CTime time=CTime::GetCurrentTime();	
	CString tt;
	tt.Format("%04d-%02d-%02d  %02d:%02d:%02d",time.GetYear(),
		time.GetMonth(),
		time.GetDay(),
		time.GetHour(),
		time.GetMinute(),
		time.GetSecond());
	//text

	LV_ITEM	lvItem;
	lvItem.mask = LVIF_TEXT | LVIF_STATE;
	lvItem.iItem = 0;
	lvItem.iSubItem = 0;
	lvItem.iImage = 0;
	lvItem.stateMask = LVIS_STATEIMAGEMASK;
	lvItem.state = INDEXTOSTATEIMAGEMASK(1);	
	lvItem.pszText = (char*)(LPCTSTR)(sid);	
	int result = GetListCtrl().InsertItem(&lvItem);
	if (result != -1)
	{		
		GetListCtrl().SetItemText(0, 1, source);
		GetListCtrl().SetItemText(0, 2, tt);
		GetListCtrl().SetItemText(0, 3, content);		
	}
}