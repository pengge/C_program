; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestPage
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BroadConvert.h"

ClassCount=5
Class1=CBroadConvertApp
Class2=CBroadConvertDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DLG_ITEM
Resource2=IDR_MAINFRAME
Resource3=IDD_BROADCONVERT_DIALOG
Class4=CDlgItem
Resource4=IDD_ABOUTBOX
Class5=CTestPage
Resource5=IDD_DIALOG1

[CLS:CBroadConvertApp]
Type=0
HeaderFile=BroadConvert.h
ImplementationFile=BroadConvert.cpp
Filter=N

[CLS:CBroadConvertDlg]
Type=0
HeaderFile=BroadConvertDlg.h
ImplementationFile=BroadConvertDlg.cpp
Filter=D
LastObject=IDC_BUT_LOAD
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=BroadConvertDlg.h
ImplementationFile=BroadConvertDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BROADCONVERT_DIALOG]
Type=1
Class=CBroadConvertDlg
ControlCount=2
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUT_LOAD,button,1342242816

[DLG:IDD_DLG_ITEM]
Type=1
Class=CDlgItem
ControlCount=25
Control1=IDC_PLAY,button,1342242817
Control2=IDC_STOP,button,1342242816
Control3=IDC_PAUSE,button,1342242816
Control4=IDC_LIST_LOG,listbox,1352728835
Control5=IDC_EDIT_SOURCE,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_DESFILEA,edit,1350631552
Control9=IDC_SLIDER,msctls_trackbar32,1476460560
Control10=IDC_STATUS,edit,1342244992
Control11=IDC_DURATION,edit,1342253194
Control12=IDC_OPEN,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_DESFILEB,edit,1350631552
Control15=IDCANCEL,button,1342242816
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_CLIP,edit,1342244992
Control21=IDC_AUTHOR,edit,1342244992
Control22=IDC_COPYRIGHT,edit,1342244992
Control23=IDC_CHECK_PLAYBACK,button,1342242819
Control24=IDC_STATIC,static,1342308352
Control25=IDC_EDIT_DESFILEC,edit,1350631552

[CLS:CDlgItem]
Type=0
HeaderFile=DlgItem.h
ImplementationFile=DlgItem.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CDlgItem
VirtualFilter=idWC

[DLG:IDD_DIALOG1]
Type=1
Class=CTestPage
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CTestPage]
Type=0
HeaderFile=TestPage.h
ImplementationFile=TestPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CTestPage

