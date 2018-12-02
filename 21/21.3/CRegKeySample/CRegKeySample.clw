; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCRegKeySampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CRegKeySample.h"

ClassCount=3
Class1=CCRegKeySampleApp
Class2=CCRegKeySampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CREGKEYSAMPLE_DIALOG

[CLS:CCRegKeySampleApp]
Type=0
HeaderFile=CRegKeySample.h
ImplementationFile=CRegKeySample.cpp
Filter=N

[CLS:CCRegKeySampleDlg]
Type=0
HeaderFile=CRegKeySampleDlg.h
ImplementationFile=CRegKeySampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_WRITEDEFAULTKEY

[CLS:CAboutDlg]
Type=0
HeaderFile=CRegKeySampleDlg.h
ImplementationFile=CRegKeySampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CREGKEYSAMPLE_DIALOG]
Type=1
Class=CCRegKeySampleDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_WRITENEWKEY,button,1342242816
Control4=IDC_BUTTON_WRITEDEFAULTKEY,button,1342242816
Control5=IDC_BUTTON_QUERYKEY,button,1342242816

