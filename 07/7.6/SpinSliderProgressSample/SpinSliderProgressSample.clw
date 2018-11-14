; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpinSliderProgressSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SpinSliderProgressSample.h"

ClassCount=3
Class1=CSpinSliderProgressSampleApp
Class2=CSpinSliderProgressSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SPINSLIDERPROGRESSSAMPLE_DIALOG

[CLS:CSpinSliderProgressSampleApp]
Type=0
HeaderFile=SpinSliderProgressSample.h
ImplementationFile=SpinSliderProgressSample.cpp
Filter=N

[CLS:CAboutDlg]
Type=0
HeaderFile=SpinSliderProgressSampleDlg.h
ImplementationFile=SpinSliderProgressSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SPINSLIDERPROGRESSSAMPLE_DIALOG]
Type=1
Class=CSpinSliderProgressSampleDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_PERCENT,edit,1350639744
Control4=IDC_SPIN_PERCENT,msctls_updown32,1342177458
Control5=IDC_SLIDER_PERCENT,msctls_trackbar32,1350631461
Control6=IDC_SLIDER2,msctls_trackbar32,1342242842
Control7=IDC_PROGRESS_PERCENT,msctls_progress32,1350565888
Control8=IDC_BUTTON_TIMER,button,1342242816

[CLS:CSpinSliderProgressSampleDlg]
Type=0
HeaderFile=spinsliderprogresssampledlg.h
ImplementationFile=spinsliderprogresssampledlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_PROGRESS_PERCENT

