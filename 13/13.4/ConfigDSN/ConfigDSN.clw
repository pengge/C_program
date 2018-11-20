; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CConfigDSNDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ConfigDSN.h"

ClassCount=4
Class1=CConfigDSNApp
Class2=CConfigDSNDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CONFIGDSN_DIALOG

[CLS:CConfigDSNApp]
Type=0
HeaderFile=ConfigDSN.h
ImplementationFile=ConfigDSN.cpp
Filter=N

[CLS:CConfigDSNDlg]
Type=0
HeaderFile=ConfigDSNDlg.h
ImplementationFile=ConfigDSNDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ConfigDSNDlg.h
ImplementationFile=ConfigDSNDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CONFIGDSN_DIALOG]
Type=1
Class=CConfigDSNDlg
ControlCount=1
Control1=IDC_BUTTON_REGDSN,button,1342242816

