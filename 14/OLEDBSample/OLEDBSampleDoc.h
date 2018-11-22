// OLEDBSampleDoc.h : interface of the COLEDBSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBSAMPLEDOC_H__58637367_7DBF_4312_8AE3_FD4B270B2204__INCLUDED_)
#define AFX_OLEDBSAMPLEDOC_H__58637367_7DBF_4312_8AE3_FD4B270B2204__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct MYBIND
{
	MYBIND()
	{
		memset(this, 0, sizeof(*this));
	}

	TCHAR   szValue[40];
	DWORD   dwStatus;
};

class COLEDBSampleDoc : public CDocument
{
public:
	CString m_strConnect;	//�����ַ���
	CDataSource m_source;	//����Դ����
	CSession    m_session;	//�Ự����

	
	CTables* m_pTableset;	//����	
	CColumns* m_pColumnset;	//�м���
	int m_nColumns;			//����Ŀ
	int m_nPrevColumns;		//ԭ������Ŀ
	CCommand<CManualAccessor> m_Rowset;		//��¼������
	struct MYBIND* pBind;	//�ֶΰ�
	
	CString     m_strTableName;	//����
protected: // create from serialization only
	COLEDBSampleDoc();
	DECLARE_DYNCREATE(COLEDBSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void OnCloseDocument();
	virtual BOOL OnOpenDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	void FetchTableData(LPCSTR lpszName);
	void ClearSet();
	BOOL FetchTableInfo();
	void FetchColumnInfo(LPCSTR lpszName);
	CString GetDSN();
	virtual ~COLEDBSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDBSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COLEDBSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBSAMPLEDOC_H__58637367_7DBF_4312_8AE3_FD4B270B2204__INCLUDED_)
