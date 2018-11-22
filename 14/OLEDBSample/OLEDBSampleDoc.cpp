// OLEDBSampleDoc.cpp : implementation of the COLEDBSampleDoc class
//

#include "stdafx.h"
#include "OLEDBSample.h"

#include "OLEDBSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleDoc

IMPLEMENT_DYNCREATE(COLEDBSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(COLEDBSampleDoc, CDocument)
	//{{AFX_MSG_MAP(COLEDBSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COLEDBSampleDoc, CDocument)
	//{{AFX_DISPATCH_MAP(COLEDBSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOLEDBSample to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {DB73D1EA-0D88-4E33-BDDB-C398FFBDA085}
static const IID IID_IOLEDBSample =
{ 0xdb73d1ea, 0xd88, 0x4e33, { 0xbd, 0xdb, 0xc3, 0x98, 0xff, 0xbd, 0xa0, 0x85 } };

BEGIN_INTERFACE_MAP(COLEDBSampleDoc, CDocument)
	INTERFACE_PART(COLEDBSampleDoc, IID_IOLEDBSample, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleDoc construction/destruction

COLEDBSampleDoc::COLEDBSampleDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
	m_pTableset = NULL;
	m_pColumnset = NULL;
	pBind = NULL;
	m_strTableName = _T("");
	m_nPrevColumns = 0;
	m_nColumns = 0;
}

COLEDBSampleDoc::~COLEDBSampleDoc()
{
	AfxOleUnlockApp();
}

BOOL COLEDBSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleDoc serialization

void COLEDBSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleDoc diagnostics

#ifdef _DEBUG
void COLEDBSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COLEDBSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleDoc commands
// ��ȡDSN��Ϣ
CString COLEDBSampleDoc::GetDSN()
{
	// �ж��Ƿ��Ѿ�������Դ
	if (!m_pTableset)
		return _T("��ǰû�д�����Դ");

	// �������ݿ�������Ϣ
	return m_strConnect;
}

// ��ȡ�������Ϣ
void COLEDBSampleDoc::FetchColumnInfo(LPCSTR lpszName)
{
	// �����ǰ�м�����ʹ�ã��������ǰ������Ϣ��
	if (m_pColumnset)
	{
		delete m_pColumnset;
		m_pColumnset = NULL;
	}

	m_pColumnset = new CColumns;
	HRESULT hr = m_pColumnset->Open(m_session, NULL, NULL, lpszName);
	if (FAILED(hr))
	{
		AfxMessageBox(_T("������Ϣ��¼��ʧ��"));
		delete m_pColumnset;
		m_pColumnset = NULL;
	}	
}

// ��ȡ����Ϣ
BOOL COLEDBSampleDoc::FetchTableInfo()
{
	// �����ǰ���ϲ�Ϊ�գ�����ձ���
	if (m_pTableset != NULL)
	{
		delete m_pTableset;
		m_pTableset = NULL;
	}
	m_pTableset = new CTables;

	
	char lpszType[MAX_PATH];
	strcpy(lpszType, "TABLE");
	//strcat(lpszType, ",VIEW");//������ͼ
	//strcat(lpszType, ",SYSTEM TABLE");//����ϵͳ��
	//strcat(lpszType, ",ALIAS,SYNONYM");//���ӱ���
	if (m_pTableset->Open(m_session, NULL, NULL, NULL, lpszType) != S_OK)
	{
		delete m_pTableset;
		m_pTableset = NULL;
		return FALSE;
	}
	return TRUE;
}

// �ر��ĵ�
void COLEDBSampleDoc::OnCloseDocument() 
{
	ClearSet();
	CDocument::OnCloseDocument();
}

BOOL COLEDBSampleDoc::OnOpenDocument() 
{
	USES_CONVERSION;

	// �رյ�ǰ���еļ�¼��
	if (m_pTableset)
	{
		delete m_pTableset;
		m_pTableset = 0;
	}

	if (m_pColumnset)
	{
		delete m_pColumnset;
		m_pColumnset = 0;
	}

	//�ͷŵ�ǰ�Ự�еļ�¼
	if (m_session.m_spOpenRowset != NULL)
		m_session.m_spOpenRowset.Release();

	// �ر����ݿ�
	if (!m_strConnect.IsEmpty())
		m_strConnect = "";

	m_source.Close();

	// ������Դ
	if (m_source.Open() != S_OK)
	{
		AfxMessageBox(_T("�޷����ӵ�����Դ"));
		m_strConnect = _T("");
		return FALSE;
	}
	else
	{
		USES_CONVERSION;
		if (m_session.Open(m_source) != S_OK)
		{
			AfxMessageBox(_T("�޷�����Ӧ���ṩ�����ϴ����Ự"));
			return FALSE;
		}
		// ����ǰ�򿪵�����Դ�����ַ�����¼��m_strConnect������
		CComVariant var;
		m_source.GetProperty(DBPROPSET_DATASOURCEINFO, DBPROP_DATASOURCENAME, &var);
		m_strConnect = OLE2T(var.bstrVal);
	}

	//������ǰ���ݿ��е����б�
	if (FetchTableInfo())
		return TRUE;
	else
		return FALSE;	
}

// ��յ�ǰ���д򿪵ļ�¼��
void COLEDBSampleDoc::ClearSet()
{
	if (m_pTableset)
	{
		delete m_pTableset;
		m_pTableset = 0;
	}

	if (m_pColumnset)
	{
		delete m_pColumnset;
		m_pColumnset = 0;
	}
}

// ��ȡ��ǰ���е���������
void COLEDBSampleDoc::FetchTableData(LPCSTR lpszName)
{
	USES_CONVERSION;

	if (pBind != NULL)
	{
		delete pBind;
		pBind = NULL;
	}
	
	pBind = new MYBIND[m_nColumns];

	m_Rowset.CreateAccessor(m_nColumns, pBind, sizeof(MYBIND)*m_nColumns);
	for (int i=0; i<m_nColumns; i++)
	{
		m_Rowset.AddBindEntry(i+1, DBTYPE_STR, sizeof(TCHAR)*40, &pBind[i].szValue,
				NULL, &pBind[i].dwStatus);
	}
	// ��ѯָ���������
	CString m_strQuery;
	m_strQuery.Format("select * from %s", lpszName);

	m_Rowset.Close();

	if (m_Rowset.Open(m_session, m_strQuery) != S_OK)
	{
		AfxMessageBox(_T("��ȡָ�����е�����ʧ��"));
		return;
	}
}
