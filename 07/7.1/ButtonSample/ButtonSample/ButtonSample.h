
// ButtonSample.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CButtonSampleApp:
// �йش����ʵ�֣������ ButtonSample.cpp
//

class CButtonSampleApp : public CWinApp
{
public:
	CButtonSampleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CButtonSampleApp theApp;