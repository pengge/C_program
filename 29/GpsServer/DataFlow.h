#if !defined(AFX_DATAFLOW_H__AB9B89BF_28FC_441A_81E9_3268DDED11A0__INCLUDED_)
#define AFX_DATAFLOW_H__AB9B89BF_28FC_441A_81E9_3268DDED11A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataFlow.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataFlow window

/******************************************************************   

**   ��   ��:   CDataFlow

**   ��   ��:   ����NEMA0183��Э������

**   ������:    ������

**   ��   ��:   2008-8-30 

**-----------------------------------------------------------------------------  */ 
class CDataFlow : public CWnd
{
// Construction
public:
	CDataFlow();
	CDataFlow(CString com, DWORD dwMessage);
	virtual ~CDataFlow();

// Attributes
public:	
	CString m_Com;							// ���������ݶ�Ӧ�Ĵ��ڵ����ƣ�����"COM1"

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataFlow)
	//}}AFX_VIRTUAL

// Implementation
public:	
	DWORD GetMeMsg();						// ���ص�ǰCWnd�������Ϣ
	// ������ʾ�ؼ�
	void SetEditCtrl(CEdit * pReceEdit,CEdit *pSendEdit);	
	HWND Create();							// ������Ӧ����ʾ�ؼ�

	// Generated message map functions
protected:	
	
public:		
	//{{AFX_MSG(CDataFlow)
	virtual LRESULT OnComMsg(WPARAM dwEvent,LPARAM dwLen);
	afx_msg LRESULT OnInitCenter(WPARAM wp,LPARAM lp);
	afx_msg LRESULT OnDecodeMsg(WPARAM dwData,LPARAM dwLen);
	afx_msg LRESULT OnResponseMsg(WPARAM wp,LPARAM lp);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// ��������
private:
	void InitVariable();						// ��ʼ�����еı���	
	BOOL SearchFlow();							// �����ݻ������в����Ƿ����Э�����ݰ�
	void DealFlow();							// �������ݻ������еĵ�ǰ��λ��Э�����ݰ�	
	BOOL CheckData(CString* check1, int check2);//���У����
	//�ı���ʽ
	GPSPack* DecodeNEMA_Text(CString source);
	//GPS��λ��Ϣ
	GPSPack* DecodeNEMA_GPGGA();
	//��ǰ������Ϣ
	GPSPack* DecodeNEMA_GPGSA();
	//�ɼ�������Ϣ
	GPSPack* DecodeNEMA_GPGSV();
	//�Ƽ���λ��Ϣ
	GPSPack* DecodeNEMA_GPRMC();
	//�����ٶ���Ϣ
	GPSPack* DecodeNEMA_GPVTG();
	//��λ������Ϣ
	GPSPack* DecodeNEMA_GPGLL();
	//ʱ���������Ϣ
	GPSPack* DecodeNEMA_GPZDA();
	//�������ϵ��Ϣ
	GPSPack* DecodeNEMA_GPDTM();
	//������˾��չЭ��
	//���������Ϣ
	GPSPack* DecodeNEMA_PGRME();
	//GPS��λ��Ϣ
	GPSPack* DecodeNEMA_PGRMF();
	//����ϵͳ��Ϣ
	GPSPack* DecodeNEMA_PGRMM();
	//����״̬��Ϣ
	GPSPack* DecodeNEMA_PGRMT();
	//��ά�ٶ���Ϣ
	GPSPack* DecodeNEMA_PGRMV();
	//�ű�����Ϣ
	GPSPack* DecodeNEMA_PGRMB();

	// ��������
private:		
	DWORD m_dwToMeMsg;						// CDataFlow�������Ϣ����
	DWORD m_dwComEvent;						// ��ǰ���ڵĴ����¼�
	
	CEdit * m_pSendEdit;					// ��ʾ�������ݵ�CEdit�ؼ�
	CEdit * m_pReceEdit;					// ��ʾ�������ݵ�CEdit�ؼ�

	CArray<CString*, CString*> m_dataArray;	// ��ǰ���ݰ��еĸ�����������
	CByteArray	m_Data;						// Ҫ���������ݻ�����
	
	int		m_dwDataGramLen;				// ֡��
	DWORD	m_dwDataGramTail;				// ֡β
	DWORD	m_dwDataGramHead;				// ֡ͷ
	
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAFLOW_H__AB9B89BF_28FC_441A_81E9_3268DDED11A0__INCLUDED_)
