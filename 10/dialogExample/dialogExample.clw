; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgTest2
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dialogExample.h"

ClassCount=9
Class1=CDialogExampleApp
Class2=CDialogExampleDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_DIALOGEXAMPLE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_TEST
Class4=CDlgTest
Resource4=IDD_ABOUTBOX
Class5=CDlgNonModal
Resource5=IDD_DIALOG_TEACHER
Resource6=IDD_DIALOG_NONMODAL
Class6=CPageStudent
Class7=CPageTeacher
Resource7=IDD_DIALOG_STUDENT
Class8=CDlgSample
Resource8=IDD_DIALOG1
Class9=CDlgTest2
Resource9=IDD_DIALOG2

[CLS:CDialogExampleApp]
Type=0
HeaderFile=dialogExample.h
ImplementationFile=dialogExample.cpp
Filter=N

[CLS:CDialogExampleDlg]
Type=0
HeaderFile=dialogExampleDlg.h
ImplementationFile=dialogExampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON_DIALOG_COLOR

[CLS:CAboutDlg]
Type=0
HeaderFile=dialogExampleDlg.h
ImplementationFile=dialogExampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGEXAMPLE_DIALOG]
Type=1
Class=CDialogExampleDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_NAME,edit,1350631552
Control4=IDC_CHECK_PASS,button,1342242819
Control5=IDC_COMBO_SEX,combobox,1344340226
Control6=IDC_BUTTON_DIALOG_COLOR,button,1342242816
Control7=IDC_BUTTON_DIALOG_FILE,button,1342242816
Control8=IDC_BUTTON_DIALOG_MESSAGE,button,1342242816
Control9=IDC_BUTTON_DIALOG_FONT,button,1342242816
Control10=IDC_BUTTON_DIALOG_FIND,button,1342242816
Control11=IDC_BUTTON_DIALOG_PRINT,button,1342242816
Control12=IDC_BUTTON_MODAL,button,1342242816
Control13=IDC_BUTTON_NONMODAL,button,1342242816
Control14=IDC_BUTTON_OPEN_SHEET,button,1342242816
Control15=IDC_BUTTON_TEST2,button,1342242816

[DLG:IDD_DIALOG_TEST]
Type=1
Class=CDlgTest
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgTest]
Type=0
HeaderFile=DlgTest.h
ImplementationFile=DlgTest.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DIALOG_NONMODAL]
Type=1
Class=CDlgNonModal
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgNonModal]
Type=0
HeaderFile=DlgNonModal.h
ImplementationFile=DlgNonModal.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DIALOG_STUDENT]
Type=1
Class=CPageStudent
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_TEACHER]
Type=1
Class=CPageTeacher
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CPageStudent]
Type=0
HeaderFile=PageStudent.h
ImplementationFile=PageStudent.cpp
BaseClass=CPropertyPage
Filter=D

[CLS:CPageTeacher]
Type=0
HeaderFile=PageTeacher.h
ImplementationFile=PageTeacher.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPageTeacher

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgSample
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[CLS:CDlgSample]
Type=0
HeaderFile=DlgSample.h
ImplementationFile=DlgSample.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgSample
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CDlgTest2
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_LOG,edit,1350631556
Control4=IDC_BUTTON_TEST,button,1342242816

[CLS:CDlgTest2]
Type=0
HeaderFile=DlgTest2.h
ImplementationFile=DlgTest2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_TEST
VirtualFilter=dWC

