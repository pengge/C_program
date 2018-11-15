; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimerSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TimerSample.h"

ClassCount=3
Class1=CTimerSampleApp
Class2=CTimerSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TIMERSAMPLE_DIALOG

[CLS:CTimerSampleApp]
Type=0
HeaderFile=TimerSample.h
ImplementationFile=TimerSample.cpp
Filter=N

[CLS:CTimerSampleDlg]
Type=0
HeaderFile=TimerSampleDlg.h
ImplementationFile=TimerSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_STATIC_TIME

[CLS:CAboutDlg]
Type=0
HeaderFile=TimerSampleDlg.h
ImplementationFile=TimerSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TIMERSAMPLE_DIALOG]
Type=1
Class=CTimerSampleDlg
ControlCount=3
Control1=IDC_BUTTON_START,button,1342242816
Control2=IDC_BUTTON_STOP,button,1342242816
Control3=IDC_STATIC_TIME,static,1342308352

