; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRVCustomer
LastTemplate=CRecordView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCODBCSample.h"
ODLFile=MFCODBCSample.odl
LastPage=0

ClassCount=8
Class1=CMFCODBCSampleApp
Class2=CMFCODBCSampleDoc
Class3=CMFCODBCSampleView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDD_MFCODBCSAMPLE_FORM
Class5=CMFCODBCSampleSet
Resource3=IDR_MAINFRAME
Class7=CRSCustomer
Class8=CRVCustomer
Resource4=IDD_DIALOG_CUSTOMER

[CLS:CMFCODBCSampleApp]
Type=0
HeaderFile=MFCODBCSample.h
ImplementationFile=MFCODBCSample.cpp
Filter=N

[CLS:CMFCODBCSampleDoc]
Type=0
HeaderFile=MFCODBCSampleDoc.h
ImplementationFile=MFCODBCSampleDoc.cpp
Filter=N

[CLS:CMFCODBCSampleView]
Type=0
HeaderFile=MFCODBCSampleView.h
ImplementationFile=MFCODBCSampleView.cpp
Filter=D
LastObject=CMFCODBCSampleView


[CLS:CMFCODBCSampleSet]
Type=0
HeaderFile=MFCODBCSampleSet.h
ImplementationFile=MFCODBCSampleSet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r
LastObject=CMFCODBCSampleSet

[DB:CMFCODBCSampleSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[CustomerID], -8, 10
Column2=[CompanyName], -9, 80
Column3=[ContactName], -9, 60
Column4=[ContactTitle], -9, 60
Column5=[Address], -9, 120
Column6=[City], -9, 30
Column7=[Region], -9, 30
Column8=[PostalCode], -9, 20
Column9=[Country], -9, 30
Column10=[Phone], -9, 48
Column11=[Fax], -9, 48

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=MFCODBCSample.cpp
ImplementationFile=MFCODBCSample.cpp
Filter=D
LastObject=CAboutDlg

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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_MENUITEM_ADDRECORD
Command14=ID_MENUITEM_DELETERECORD
Command15=ID_MENUITEM_UPDATERECORD
Command16=ID_MENUITEM_COMMIT
Command17=ID_MENUITEM_REFRESH
Command18=ID_MENUITEM_CANCELRECORD
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_MFCODBCSAMPLE_FORM]
Type=1
Class=CMFCODBCSampleView
ControlCount=0

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

[DLG:IDD_DIALOG_CUSTOMER]
Type=1
Class=CRVCustomer
ControlCount=22
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_CUSTOMERID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_COMPANYNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_CONTACTNAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_CONTACTTITLE,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_ADDRESS,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_CITY,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_REGION,edit,1350631552
Control19=IDC_EDIT_POSTALCODE,edit,1350631552
Control20=IDC_EDIT_COUNTRY,edit,1350631552
Control21=IDC_EDIT_TELE,edit,1350631552
Control22=IDC_EDIT_FAX,edit,1350631552

[DB:CRSCutomer]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[CustomerID], -8, 10
Column2=[CompanyName], -9, 80
Column3=[ContactName], -9, 60
Column4=[ContactTitle], -9, 60
Column5=[Address], -9, 120
Column6=[City], -9, 30
Column7=[Region], -9, 30
Column8=[PostalCode], -9, 20
Column9=[Country], -9, 30
Column10=[Phone], -9, 48
Column11=[Fax], -9, 48

[CLS:CRSCustomer]
Type=0
HeaderFile=RSCustomer.h
ImplementationFile=RSCustomer.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CRSCustomer]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[CustomerID], -8, 10
Column2=[CompanyName], -9, 80
Column3=[ContactName], -9, 60
Column4=[ContactTitle], -9, 60
Column5=[Address], -9, 120
Column6=[City], -9, 30
Column7=[Region], -9, 30
Column8=[PostalCode], -9, 20
Column9=[Country], -9, 30
Column10=[Phone], -9, 48
Column11=[Fax], -9, 48

[CLS:CRVCustomer]
Type=0
HeaderFile=RVCustomer.h
ImplementationFile=RVCustomer.cpp
BaseClass=CRecordView
Filter=D
VirtualFilter=RVWC
LastObject=ID_MENUITEM_CANCELRECORD

