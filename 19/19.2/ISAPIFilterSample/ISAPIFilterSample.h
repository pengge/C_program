#if !defined(AFX_ISAPIFILTERSAMPLE_H__763D2F45_4F6C_4307_A69B_501415AFF00F__INCLUDED_)
#define AFX_ISAPIFILTERSAMPLE_H__763D2F45_4F6C_4307_A69B_501415AFF00F__INCLUDED_

// ISAPIFILTERSAMPLE.H - Header file for your Internet Server
//    ISAPIFilterSample Filter

#include "resource.h"


class CISAPIFilterSampleFilter : public CHttpFilter
{
public:
	CISAPIFilterSampleFilter();
	~CISAPIFilterSampleFilter();

// Overrides
	// ClassWizard generated virtual function overrides
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_VIRTUAL(CISAPIFilterSampleFilter)
	public:
	virtual BOOL GetFilterVersion(PHTTP_FILTER_VERSION pVer);
	virtual DWORD OnPreprocHeaders(CHttpFilterContext* pCtxt, PHTTP_FILTER_PREPROC_HEADERS pHeaderInfo);
	virtual DWORD OnAuthentication(CHttpFilterContext* pCtxt, PHTTP_FILTER_AUTHENT pAuthent);
	virtual DWORD OnUrlMap(CHttpFilterContext* pCtxt, PHTTP_FILTER_URL_MAP pMapInfo);
	virtual DWORD OnSendRawData(CHttpFilterContext* pCtxt, PHTTP_FILTER_RAW_DATA pRawData);
	virtual DWORD OnReadRawData(CHttpFilterContext* pCtxt, PHTTP_FILTER_RAW_DATA pRawData);
	virtual DWORD OnLog(CHttpFilterContext* pfc, PHTTP_FILTER_LOG pLog);
	virtual DWORD OnEndOfNetSession(CHttpFilterContext* pCtxt);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CISAPIFilterSampleFilter)
	//}}AFX_MSG
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ISAPIFILTERSAMPLE_H__763D2F45_4F6C_4307_A69B_501415AFF00F__INCLUDED)
