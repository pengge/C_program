; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNamedPipeClientSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NamedPipeClientSample.h"

ClassCount=3
Class1=CNamedPipeClientSampleApp
Class2=CNamedPipeClientSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NAMEDPIPECLIENTSAMPLE_DIALOG

[CLS:CNamedPipeClientSampleApp]
Type=0
HeaderFile=NamedPipeClientSample.h
ImplementationFile=NamedPipeClientSample.cpp
Filter=N

[CLS:CNamedPipeClientSampleDlg]
Type=0
HeaderFile=NamedPipeClientSampleDlg.h
ImplementationFile=NamedPipeClientSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NamedPipeClientSampleDlg.h
ImplementationFile=NamedPipeClientSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NAMEDPIPECLIENTSAMPLE_DIALOG]
Type=1
Class=CNamedPipeClientSampleDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_CONNECT,button,1342242816
Control4=IDC_EDIT_LOG,edit,1350631556

