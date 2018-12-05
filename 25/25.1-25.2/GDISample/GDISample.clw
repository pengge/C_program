; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgEllip
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GDISample.h"
LastPage=0

ClassCount=6
Class1=CGDISampleApp
Class2=CGDISampleDoc
Class3=CGDISampleView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CDlgEllip
Resource3=IDD_DIALOG_ELLIPSEWND

[CLS:CGDISampleApp]
Type=0
HeaderFile=GDISample.h
ImplementationFile=GDISample.cpp
Filter=N

[CLS:CGDISampleDoc]
Type=0
HeaderFile=GDISampleDoc.h
ImplementationFile=GDISampleDoc.cpp
Filter=N

[CLS:CGDISampleView]
Type=0
HeaderFile=GDISampleView.h
ImplementationFile=GDISampleView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGDISampleView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEM_REGION




[CLS:CAboutDlg]
Type=0
HeaderFile=GDISample.cpp
ImplementationFile=GDISample.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_MENUITEM_PEN
Command18=ID_MENUITEM_BRUSH
Command19=ID_MENUITEM_BITMAP
Command20=ID_MENUITEM_REGION
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG_ELLIPSEWND]
Type=1
Class=CDlgEllip
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgEllip]
Type=0
HeaderFile=DlgEllip.h
ImplementationFile=DlgEllip.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgEllip
VirtualFilter=dWC

