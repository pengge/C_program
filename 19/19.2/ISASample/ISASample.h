#if !defined(AFX_ISASAMPLE_H__FB4404B3_5975_47A6_8039_2FF662911AC1__INCLUDED_)
#define AFX_ISASAMPLE_H__FB4404B3_5975_47A6_8039_2FF662911AC1__INCLUDED_

// ISASAMPLE.H - Header file for your Internet Server
//    ISASample Extension

#include "resource.h"

class CISASampleExtension : public CHttpServer
{
public:
	CISASampleExtension();
	~CISASampleExtension();

// Overrides
	// ClassWizard generated virtual function overrides
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_VIRTUAL(CISASampleExtension)
	public:
	virtual BOOL GetExtensionVersion(HSE_VERSION_INFO* pVer);
	virtual LPCTSTR GetTitle() const;
	virtual int CallFunction(CHttpServerContext* pCtxt, LPTSTR pszQuery, LPTSTR pszCommand);
	virtual void StartContent(CHttpServerContext* pCtxt) const;
	//}}AFX_VIRTUAL
	virtual BOOL TerminateExtension(DWORD dwFlags);

	// TODO: Add handlers for your commands here.
	// For example:

	void Default(CHttpServerContext* pCtxt);
	DWORD  AddUser( CHttpServerContext* pctxt, LPCTSTR pstrFirst, LPCTSTR pstrMiddle, LPCTSTR pstrLast );

	DECLARE_PARSE_MAP()

	//{{AFX_MSG(CISASampleExtension)
	//}}AFX_MSG
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ISASAMPLE_H__FB4404B3_5975_47A6_8039_2FF662911AC1__INCLUDED)
