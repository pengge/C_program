/// GpsServerDoc.h : interface of the CGpsServerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GPSSERVERDOC_H__5FE33884_95CB_4D77_A529_B600F923EA13__INCLUDED_)
#define AFX_GPSSERVERDOC_H__5FE33884_95CB_4D77_A529_B600F923EA13__INCLUDED_

#include "StdAfx.h"
#include "RSUser.h"
#include "RSComConfig.h"
#include "ThreadCom.h"
#include "DataFlow.h"
#include "ComWorkFlow.h"
#include "MainFrm.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CGpsServerDoc : public CDocument
{
protected: // create from serialization only
	CGpsServerDoc();
	DECLARE_DYNCREATE(CGpsServerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGpsServerDoc)
	public:
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	
	BOOL ConnectDB();				// �������ݿ�
	
	void FuncCommTimer();			// �򴮿ڷ������ݵĶ�ʱ��
	BOOL IsUserValid(CString UserName, CString Pass);	// �ж��û��Ƿ���Ч
	BOOL ReadComConfigs();			// ��ȡ���ڲ���

	BOOL OpenComWorkFlow(CString com);	// ��ָ�����ڹ�����
	BOOL OpenAllComWorkFlow();			// �����õ����д��ڵĹ�����
	BOOL CloseComWorkFlow(CString com);	// �رմ��ڵĹ�����
	BOOL CloseAllComWorkFlow();			// �ر����еĴ��ڹ�����

	int GetComCount();					// ��ȡ���ڵĸ���
	CComWorkFlow* GetComWorkFlow(CString com);	// ��ȡָ���������ƵĴ��ڹ�����	

	
	void AddGPSPackToDB(GPSPack *pack, CString m_com);

	
	BOOL m_bCom;						// ��ʶ�����Ƿ��Ѿ���
	BOOL m_bInitCom;					// ��ʶ�����Ƿ��Ѿ���ʼ���ɹ�
	
	HANDLE MutexObject[5];				
	CArray<CComWorkFlow*,CComWorkFlow*> m_ComWorkFlow;	// ���ڹ���������
	CArray<CSendObject*, CSendObject*> m_CommandList;	// ���������б�


	/////////////////////////////////////////
	// ��ʼ--�й����ݿ�����ı���

	BOOL m_bUseDB;					// �Ƿ�ʹ�����ݿ�	
	CDatabase* m_pDBGps;			// ���ݿ����	
	CRSUser* m_pRSUser;				// �û���¼�����	
	CRSComConfig* m_pRSComConfig;	// ���ڼ�¼�����
	
	// ����--�й����ݿ�����ı���
	///////////////////////////////////////////
		
	virtual ~CGpsServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL ReadDBComConfigs();			// �����ݿ��ж�ȡ����������Ϣ
	BOOL ReadDefaultComConfigs();		// ��ȡĬ�ϵĴ���������Ϣ

	CMainFrame* GetMainFrame();			// ��ȡ�����

	void CheckSendList();				// ��ⷢ������

// Generated message map functions
protected:
	//{{AFX_MSG(CGpsServerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPSSERVERDOC_H__5FE33884_95CB_4D77_A529_B600F923EA13__INCLUDED_)
