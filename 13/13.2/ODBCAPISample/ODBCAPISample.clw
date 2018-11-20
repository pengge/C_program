; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CODBCAPISampleView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ODBCAPISample.h"
LastPage=0

ClassCount=5
Class1=CODBCAPISampleApp
Class2=CODBCAPISampleDoc
Class3=CODBCAPISampleView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource7=IDD_ODBCAPISAMPLE_FORM

[CLS:CODBCAPISampleApp]
Type=0
HeaderFile=ODBCAPISample.h
ImplementationFile=ODBCAPISample.cpp
Filter=N

[CLS:CODBCAPISampleDoc]
Type=0
HeaderFile=ODBCAPISampleDoc.h
ImplementationFile=ODBCAPISampleDoc.cpp
Filter=N

[CLS:CODBCAPISampleView]
Type=0
HeaderFile=ODBCAPISampleView.h
ImplementationFile=ODBCAPISampleView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CODBCAPISampleView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEM_DELETECUSTOMER




[CLS:CAboutDlg]
Type=0
HeaderFile=ODBCAPISample.cpp
ImplementationFile=ODBCAPISample.cpp
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
Command17=ID_MENUITEM_QUERYCUSTOMER
Command18=ID_MENUITEM_INSERTCUSTOMER
Command19=ID_MENUITEM_DELETECUSTOMER
CommandCount=19

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

[DLG:IDD_ODBCAPISAMPLE_FORM]
Type=1
Class=CODBCAPISampleView
ControlCount=5
Control1=IDC_EDIT_LOG,edit,1353781444
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_CUSTOMERID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_COMPANY,edit,1350631552

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

