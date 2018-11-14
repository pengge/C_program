; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMenuSampleView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "menuSample.h"
LastPage=0

ClassCount=6
Class1=CMenuSampleApp
Class2=CMenuSampleDoc
Class3=CMenuSampleView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDR_MENU_POPTEST
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_MENUSATYPE
Resource4=IDR_MENU1
Resource5=IDD_ABOUTBOX

[CLS:CMenuSampleApp]
Type=0
HeaderFile=menuSample.h
ImplementationFile=menuSample.cpp
Filter=N

[CLS:CMenuSampleDoc]
Type=0
HeaderFile=menuSampleDoc.h
ImplementationFile=menuSampleDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMenuSampleDoc

[CLS:CMenuSampleView]
Type=0
HeaderFile=menuSampleView.h
ImplementationFile=menuSampleView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMenuSampleView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=menuSample.cpp
ImplementationFile=menuSample.cpp
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
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
Command9=ID_MENUITEMSETTITLE
CommandCount=9

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MENUSATYPE]
Type=1
Class=CMenuSampleView
Command1=ID_MENUITEM32771
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_MENUITEM32772
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
Command22=ID_SYSTEM_CONFIG
Command23=ID_MENUITEMSETTITLE
Command24=ID_MENUITEM_STATU
CommandCount=24

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

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM32778
CommandCount=1

[MNU:IDR_MENU_POPTEST]
Type=1
Class=?
CommandCount=0

