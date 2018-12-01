; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiskOperDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DiskOper.h"

ClassCount=3
Class1=CDiskOperApp
Class2=CDiskOperDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DISKOPER_DIALOG

[CLS:CDiskOperApp]
Type=0
HeaderFile=DiskOper.h
ImplementationFile=DiskOper.cpp
Filter=N

[CLS:CDiskOperDlg]
Type=0
HeaderFile=DiskOperDlg.h
ImplementationFile=DiskOperDlg.cpp
Filter=D
LastObject=CDiskOperDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DiskOperDlg.h
ImplementationFile=DiskOperDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DISKOPER_DIALOG]
Type=1
Class=CDiskOperDlg
ControlCount=12
Control1=IDC_BUTTON_FORMAT,button,1342242816
Control2=IDC_EDIT_LOG,edit,1350635588
Control3=IDC_BUTTON_MONITOR_DISK,button,1342242816
Control4=IDC_BUTTON_HIDEDISK,button,1342242816
Control5=IDC_BUTTON_DELSHARE,button,1342242816
Control6=IDC_BUTTON_SETVOLUM,button,1342242816
Control7=IDC_BUTTON_FAT32TONTFS,button,1342242816
Control8=IDC_BUTTON_UPDATEDISKNO,button,1342242816
Control9=IDC_BUTTON_SHOWDISK,button,1342242816
Control10=IDC_BUTTON_SPZL,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_DISKNAME,edit,1350631552

