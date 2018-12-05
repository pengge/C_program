; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDLLAppSampleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DLLAppSample.h"

ClassCount=3
Class1=CDLLAppSampleApp
Class2=CDLLAppSampleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DLLAPPSAMPLE_DIALOG

[CLS:CDLLAppSampleApp]
Type=0
HeaderFile=DLLAppSample.h
ImplementationFile=DLLAppSample.cpp
Filter=N

[CLS:CDLLAppSampleDlg]
Type=0
HeaderFile=DLLAppSampleDlg.h
ImplementationFile=DLLAppSampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_GETDIALOG

[CLS:CAboutDlg]
Type=0
HeaderFile=DLLAppSampleDlg.h
ImplementationFile=DLLAppSampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DLLAPPSAMPLE_DIALOG]
Type=1
Class=CDLLAppSampleDlg
ControlCount=10
Control1=IDC_BUTTON_GETALLICON,button,1342242816
Control2=IDC_LIST_ICON,SysListView32,1082195970
Control3=IDC_EDIT_LOG,edit,1350631552
Control4=IDC_BUTTON_GETBITMAP,button,1342242816
Control5=IDC_STATIC_BITMAP,static,1342177294
Control6=IDC_BUTTON_GETDIALOG,button,1342242816
Control7=IDC_BUTTON_REPLACEDIALOG,button,1342242816
Control8=IDC_BUTTON_DISABLE_POWER,button,1342242816
Control9=IDC_BUTTON_DISABLE_WIN,button,1342242816
Control10=IDC_BUTTON_DISABLE_ALTF4,button,1342242816

