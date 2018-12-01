; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiskInfoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DiskInfo.h"

ClassCount=3
Class1=CDiskInfoApp
Class2=CDiskInfoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DISKINFO_DIALOG

[CLS:CDiskInfoApp]
Type=0
HeaderFile=DiskInfo.h
ImplementationFile=DiskInfo.cpp
Filter=N
LastObject=CDiskInfoApp

[CLS:CDiskInfoDlg]
Type=0
HeaderFile=DiskInfoDlg.h
ImplementationFile=DiskInfoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_LOG

[CLS:CAboutDlg]
Type=0
HeaderFile=DiskInfoDlg.h
ImplementationFile=DiskInfoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DISKINFO_DIALOG]
Type=1
Class=CDiskInfoDlg
ControlCount=9
Control1=IDC_BUTTON_CHECK_A,button,1342242816
Control2=IDC_EDIT_LOG,edit,1350631556
Control3=IDC_BUTTON_GETVOL,button,1342242816
Control4=IDC_BUTTON_GETMEDIATYPE,button,1342242816
Control5=IDC_BUTTON_GETSERIAL,button,1342242816
Control6=IDC_BUTTON_GETFREESPACE,button,1342242816
Control7=IDC_BUTTON_CHECKCDROM,button,1342242816
Control8=IDC_EDIT_DISKNAME,edit,1350631552
Control9=IDC_STATIC,static,1342308352

