; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileSample.h"

ClassCount=3
Class1=CFileSampleApp
Class2=CFileSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILESAMPLE_DIALOG

[CLS:CFileSampleApp]
Type=0
HeaderFile=FileSample.h
ImplementationFile=FileSample.cpp
Filter=N

[CLS:CFileSampleDlg]
Type=0
HeaderFile=FileSampleDlg.h
ImplementationFile=FileSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FileSampleDlg.h
ImplementationFile=FileSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILESAMPLE_DIALOG]
Type=1
Class=CFileSampleDlg
ControlCount=3
Control1=IDC_EDIT_CONTENT,edit,1350631620
Control2=IDC_BUTTON_READ,button,1342242816
Control3=IDC_BUTTON_WRITE,button,1342242816

