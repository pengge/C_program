// OLEDBSampleView.cpp : implementation of the COLEDBSampleView class
//

#include "stdafx.h"
#include "OLEDBSample.h"

#include "OLEDBSampleDoc.h"
#include "OLEDBSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleView

IMPLEMENT_DYNCREATE(COLEDBSampleView, CFormView)

BEGIN_MESSAGE_MAP(COLEDBSampleView, CFormView)
	//{{AFX_MSG_MAP(COLEDBSampleView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_TABLES, OnDblclkListTables)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_TABLES, &COLEDBSampleView::OnLvnItemchangedListTables)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleView construction/destruction

COLEDBSampleView::COLEDBSampleView()
	: CFormView(COLEDBSampleView::IDD)
{
	//{{AFX_DATA_INIT(COLEDBSampleView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COLEDBSampleView::~COLEDBSampleView()
{
}

void COLEDBSampleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COLEDBSampleView)
	DDX_Control(pDX, IDC_LIST_DATA, m_DataCtrl);
	DDX_Control(pDX, IDC_LIST_TABLES, m_TablesCtrl);
	DDX_Control(pDX, IDC_LIST_COLUMES, m_ColumesCtrl);
	//}}AFX_DATA_MAP
}

BOOL COLEDBSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void COLEDBSampleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleView printing

BOOL COLEDBSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COLEDBSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COLEDBSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void COLEDBSampleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleView diagnostics

#ifdef _DEBUG
void COLEDBSampleView::AssertValid() const
{
	CFormView::AssertValid();
}

void COLEDBSampleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

COLEDBSampleDoc* COLEDBSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDBSampleDoc)));
	return (COLEDBSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleView message handlers

void COLEDBSampleView::OnFileOpen() 
{
	COLEDBSampleDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->OnOpenDocument())
		ShowTable();
	else
		ShowTitle();
}

// 显示当前连接的数据库名称
void COLEDBSampleView::ShowTitle()
{
	COLEDBSampleDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SetTitle(pDoc->GetDSN());
}

//显示数据库中所有的表
void COLEDBSampleView::ShowTable()
{
	COLEDBSampleDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SetTitle(pDoc->GetDSN());

	CString strDataSource = pDoc->GetDSN();
	strDataSource += _T(" [表]");
	pDoc->SetTitle(strDataSource);

	m_TablesCtrl.DeleteAllItems();

	// 增加显示的列
	m_TablesCtrl.InsertColumn(0,_T("表名"),LVCFMT_LEFT,100,-1);
	m_TablesCtrl.InsertColumn(1,_T("类型"),LVCFMT_LEFT,100,1);
	m_TablesCtrl.InsertColumn(2,_T("目录"),LVCFMT_LEFT,100,2);
	m_TablesCtrl.InsertColumn(3,_T("结构"),LVCFMT_LEFT,100,3);
	m_TablesCtrl.InsertColumn(4,_T("描述"),LVCFMT_LEFT,100,4);

	int item = 0;
	while (pDoc->m_pTableset->MoveNext() == S_OK)
	{
		m_TablesCtrl.InsertItem(item,
			pDoc->m_pTableset->m_szName);
		m_TablesCtrl.SetItem(item,1,LVIF_TEXT,
			pDoc->m_pTableset->m_szType,0,0,0,0);
		m_TablesCtrl.SetItem(item,2,LVIF_TEXT,
			pDoc->m_pTableset->m_szCatalog,0,0,0,0);
		m_TablesCtrl.SetItem(item,3,LVIF_TEXT,
			pDoc->m_pTableset->m_szSchema,0,0,0,0);
		m_TablesCtrl.SetItem(item,4,LVIF_TEXT,
			pDoc->m_pTableset->m_szDescription,0,0,0,0);
		item++;
	}

}

//显示列信息
void COLEDBSampleView::ShowColumes()
{
	COLEDBSampleDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_ColumesCtrl.DeleteAllItems();
	int column;

	// 设置文档标题
	CString strDataSource = pDoc->GetDSN();
	strDataSource += _T(" - ");
	strDataSource += pDoc->m_strTableName;
	strDataSource += _T(" [列信息]");
	pDoc->SetTitle(strDataSource);

	// 显示列信息
	column = 0;
	m_ColumesCtrl.InsertColumn(column++,_T("列名"),LVCFMT_LEFT,100,-1);
	m_ColumesCtrl.InsertColumn(column,_T("类型"),LVCFMT_LEFT,100,column++);	
	m_ColumesCtrl.InsertColumn(column,_T("长度"),LVCFMT_LEFT,80,column++);	
	m_ColumesCtrl.InsertColumn(column,_T("精度"),LVCFMT_LEFT,80,column++);
	m_ColumesCtrl.InsertColumn(column,_T("大小"),LVCFMT_LEFT,50,column++);	
	m_ColumesCtrl.InsertColumn(column,_T("是否可为空"),LVCFMT_LEFT,50,column++);

	
	int item = 0;
	if (pDoc->m_pColumnset == NULL) return;	

	while (pDoc->m_pColumnset->MoveNext() == S_OK)
	{
		// 列名
		CString strValue;		
		m_ColumesCtrl.InsertItem(item, pDoc->m_pColumnset->m_szColumnName);
		
		// 列类型
		column = 1;
		CString strType;
		strType.Format("%d", pDoc->m_pColumnset->m_nDataType);
		m_ColumesCtrl.SetItem(item,column++,LVIF_TEXT, strType,0,0,0,0);

		// 长度
		strValue.Format(_T("%ld"),pDoc->m_pColumnset->m_nMaxLength);
		m_ColumesCtrl.SetItem(item,column++,LVIF_TEXT,strValue,0,0,0,0);
		
		// 大小
		strValue.Format(_T("%d"),pDoc->m_pColumnset->m_nNumericPrecision);
		m_ColumesCtrl.SetItem(item,column++,LVIF_TEXT,strValue,0,0,0,0);

		// 精度
		int nOrdinal = pDoc->m_pColumnset->m_nOrdinalPosition;
		strValue.Format(_T("%d"),pDoc->m_pColumnset->m_nNumericScale);
		m_ColumesCtrl.SetItem(item,column++,LVIF_TEXT,strValue,0,0,0,0);
		
		// 是否为NULL		
		if (pDoc->m_pColumnset->m_bIsNullable == FALSE)
			m_ColumesCtrl.SetItem(item,column++,LVIF_TEXT,_T("No"),0,0,0,0);
		else
			m_ColumesCtrl.SetItem(item,column++,LVIF_TEXT,_T("Yes"),0,0,0,0);
		item++;
	}

	pDoc->m_nPrevColumns = pDoc->m_nColumns;
	pDoc->m_nColumns = item;
}

// 双击表时，同时显示表结构和表数据
void COLEDBSampleView::OnDblclkListTables(NMHDR* pNMHDR, LRESULT* pResult) 
{
	COLEDBSampleDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int nCount = m_TablesCtrl.GetItemCount();
    int i;
	for ( i = 0; i < nCount; i++)
	{
		if (m_TablesCtrl.GetItemState(i,LVIS_SELECTED))
			break;
	}

	if ( i < nCount)
	{
		pDoc->m_strTableName = m_TablesCtrl.GetItemText(i,0);

		LPCSTR lpszName;
		lpszName = pDoc->m_strTableName;
		pDoc->FetchColumnInfo(lpszName);
		ShowColumes();
		pDoc->FetchTableData(lpszName);
		ShowData();
	}	
	*pResult = 0;
}

//显示数据
void COLEDBSampleView::ShowData()
{
	COLEDBSampleDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_DataCtrl.DeleteAllItems();
	for (int i = 0;i < pDoc->m_nPrevColumns;i++)
	{
		m_DataCtrl.DeleteColumn(i);
	}
	
	int item = 0, nMaxRecords = 1000;	
	int column = 0;
	pDoc->m_pColumnset->MoveFirst();
    m_DataCtrl.InsertColumn(column++,pDoc->m_pColumnset->m_szColumnName,LVCFMT_LEFT,100,-1);
	while (pDoc->m_pColumnset->MoveNext() == S_OK)
	{
		m_DataCtrl.InsertColumn(column++,pDoc->m_pColumnset->m_szColumnName,LVCFMT_LEFT,100,-1);
	}

 //   CRowset<CAccessorBase>* pRS = (CRowset<CAccessorBase>*)&(pDoc->m_Rowset);
 //   pRS->MoveFirst();
 //   while (pRS->MoveNext() == S_OK)
//    {
        if (item < nMaxRecords)
        {
            for (int j=0; j<=column; j++)
            {
                if (pDoc->pBind[j-1].dwStatus == DBSTATUS_S_ISNULL)
                    _tcscpy(pDoc->pBind[j-1].szValue, _T(""));
                if (j == 1)
                    m_DataCtrl.InsertItem(item, pDoc->pBind[j-1].szValue);
                else
                    m_DataCtrl.SetItem(item,j-1,LVIF_TEXT,pDoc->pBind[j-1].szValue,0,0,0,0);
            }
            item++;
        }
  //  }

	// 设置文档标题
	CString strDataSource = pDoc->GetDSN();
	strDataSource += _T(" - ");
	strDataSource += pDoc->m_strTableName;
	CString strRecCount;
	strRecCount.Format(_T(" - [%d]"), item);
	strDataSource += strRecCount;
	strDataSource += _T(" 条记录");	
	pDoc->SetTitle(strDataSource);
}


void COLEDBSampleView::OnLvnItemchangedListTables(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
}
