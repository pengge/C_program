; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMultiThreadFuncSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MultiThreadFuncSample.h"

ClassCount=4
Class1=CMultiThreadFuncSampleApp
Class2=CMultiThreadFuncSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MULTITHREADFUNCSAMPLE_DIALOG

[CLS:CMultiThreadFuncSampleApp]
Type=0
HeaderFile=MultiThreadFuncSample.h
ImplementationFile=MultiThreadFuncSample.cpp
Filter=N

[CLS:CMultiThreadFuncSampleDlg]
Type=0
HeaderFile=MultiThreadFuncSampleDlg.h
ImplementationFile=MultiThreadFuncSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MultiThreadFuncSampleDlg.h
ImplementationFile=MultiThreadFuncSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MULTITHREADFUNCSAMPLE_DIALOG]
Type=1
Class=CMultiThreadFuncSampleDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_START_THREAD,button,1342242816
Control4=IDC_BUTTON_SUSPEND_THREAD,button,1342242816
Control5=IDC_BUTTON_RESUME_THREAD,button,1342242816
Control6=IDC_BUTTON_STOP_THREAD,button,1342242816

