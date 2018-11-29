; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CommSample.h"

ClassCount=3
Class1=CCommSampleApp
Class2=CCommSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_COMMSAMPLE_DIALOG

[CLS:CCommSampleApp]
Type=0
HeaderFile=CommSample.h
ImplementationFile=CommSample.cpp
Filter=N

[CLS:CCommSampleDlg]
Type=0
HeaderFile=CommSampleDlg.h
ImplementationFile=CommSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCommSampleDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=CommSampleDlg.h
ImplementationFile=CommSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMMSAMPLE_DIALOG]
Type=1
Class=CCommSampleDlg
ControlCount=7
Control1=IDC_BUTTON_OPEN,button,1342242816
Control2=IDC_EDIT_LOG,edit,1352728708
Control3=IDC_EDIT_SEND,edit,1352728708
Control4=IDC_EDIT_RECV,edit,1352728708
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON_SEND,button,1342242816

