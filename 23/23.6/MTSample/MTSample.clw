; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMTSampleView
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MTSample.h"
LastPage=0

ClassCount=7
Class1=CMTSampleApp
Class2=CMTSampleDoc
Class3=CMTSampleView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CThreadSend
Class7=CThreadRecv
Resource2=IDD_ABOUTBOX

[CLS:CMTSampleApp]
Type=0
HeaderFile=MTSample.h
ImplementationFile=MTSample.cpp
Filter=N

[CLS:CMTSampleDoc]
Type=0
HeaderFile=MTSampleDoc.h
ImplementationFile=MTSampleDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMTSampleDoc

[CLS:CMTSampleView]
Type=0
HeaderFile=MTSampleView.h
ImplementationFile=MTSampleView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMTSampleView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=MTSample.cpp
ImplementationFile=MTSample.cpp
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
Command17=ID_MENUITEM_STARTSENDTHREAD
Command18=ID_MENUITEM_STARTRECVTHREAD
Command19=ID_MENUITEM_STOPTHREAD
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

[CLS:CThreadSend]
Type=0
HeaderFile=ThreadSend.h
ImplementationFile=ThreadSend.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC
LastObject=CThreadSend

[CLS:CThreadRecv]
Type=0
HeaderFile=ThreadRecv.h
ImplementationFile=ThreadRecv.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC
LastObject=CThreadRecv

