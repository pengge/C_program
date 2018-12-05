; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CThreadCommSampleDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ThreadCommSample.h"

ClassCount=4
Class1=CThreadCommSampleApp
Class2=CThreadCommSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CSubThread
Resource3=IDD_THREADCOMMSAMPLE_DIALOG

[CLS:CThreadCommSampleApp]
Type=0
HeaderFile=ThreadCommSample.h
ImplementationFile=ThreadCommSample.cpp
Filter=N

[CLS:CThreadCommSampleDlg]
Type=0
HeaderFile=ThreadCommSampleDlg.h
ImplementationFile=ThreadCommSampleDlg.cpp
Filter=D
LastObject=CThreadCommSampleDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ThreadCommSampleDlg.h
ImplementationFile=ThreadCommSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_THREADCOMMSAMPLE_DIALOG]
Type=1
Class=CThreadCommSampleDlg
ControlCount=2
Control1=IDC_BUTTON_START,button,1342242816
Control2=IDC_EDIT_LOG,edit,1350631556

[CLS:CSubThread]
Type=0
HeaderFile=SubThread.h
ImplementationFile=SubThread.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC
LastObject=CSubThread

