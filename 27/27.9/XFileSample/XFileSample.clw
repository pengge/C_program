; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CXFileSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "XFileSample.h"

ClassCount=4
Class1=CXFileSampleApp
Class2=CXFileSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_XFILESAMPLE_DIALOG

[CLS:CXFileSampleApp]
Type=0
HeaderFile=XFileSample.h
ImplementationFile=XFileSample.cpp
Filter=N

[CLS:CXFileSampleDlg]
Type=0
HeaderFile=XFileSampleDlg.h
ImplementationFile=XFileSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=XFileSampleDlg.h
ImplementationFile=XFileSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_XFILESAMPLE_DIALOG]
Type=1
Class=CXFileSampleDlg
ControlCount=1
Control1=IDC_BUTTON_LOADXFILE,button,1342242816

