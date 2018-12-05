# Microsoft Developer Studio Project File - Name="PlayMultiMedia" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PlayMultiMedia - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PlayMultiMedia.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PlayMultiMedia.mak" CFG="PlayMultiMedia - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PlayMultiMedia - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PlayMultiMedia - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PlayMultiMedia - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "PlayMultiMedia - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 GdiPlus.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PlayMultiMedia - Win32 Release"
# Name "PlayMultiMedia - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\animation.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayMultiMedia.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayMultiMedia.rc
# End Source File
# Begin Source File

SOURCE=.\PlayMultiMediaDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\realaudio.cpp
# End Source File
# Begin Source File

SOURCE=.\shockwaveflash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\wmpcdrom1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpcdromcollection1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpclosedcaption1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpcontrols1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpdvd1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmperror1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmperroritem1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpmedia1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpmediacollection1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpnetwork1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpplayer5.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpplayerapplication1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpplaylist1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpplaylistarray1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpplaylistcollection1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpsettings1.cpp
# End Source File
# Begin Source File

SOURCE=.\wmpstringcollection1.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\animation.h
# End Source File
# Begin Source File

SOURCE=.\PlayMultiMedia.h
# End Source File
# Begin Source File

SOURCE=.\PlayMultiMediaDlg.h
# End Source File
# Begin Source File

SOURCE=.\realaudio.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\shockwaveflash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\wmpcdrom1.h
# End Source File
# Begin Source File

SOURCE=.\wmpcdromcollection1.h
# End Source File
# Begin Source File

SOURCE=.\wmpclosedcaption1.h
# End Source File
# Begin Source File

SOURCE=.\wmpcontrols1.h
# End Source File
# Begin Source File

SOURCE=.\wmpdvd1.h
# End Source File
# Begin Source File

SOURCE=.\wmperror1.h
# End Source File
# Begin Source File

SOURCE=.\wmperroritem1.h
# End Source File
# Begin Source File

SOURCE=.\wmpmedia1.h
# End Source File
# Begin Source File

SOURCE=.\wmpmediacollection1.h
# End Source File
# Begin Source File

SOURCE=.\wmpnetwork1.h
# End Source File
# Begin Source File

SOURCE=.\wmpplayer5.h
# End Source File
# Begin Source File

SOURCE=.\wmpplayerapplication1.h
# End Source File
# Begin Source File

SOURCE=.\wmpplaylist1.h
# End Source File
# Begin Source File

SOURCE=.\wmpplaylistarray1.h
# End Source File
# Begin Source File

SOURCE=.\wmpplaylistcollection1.h
# End Source File
# Begin Source File

SOURCE=.\wmpsettings1.h
# End Source File
# Begin Source File

SOURCE=.\wmpstringcollection1.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\PlayMultiMedia.ico
# End Source File
# Begin Source File

SOURCE=.\res\PlayMultiMedia.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section PlayMultiMedia : {CFAB6E98-8730-11D3-B388-00C04F68574B}
# 	2:5:Class:CWMPCdrom
# 	2:10:HeaderFile:wmpcdrom1.h
# 	2:8:ImplFile:wmpcdrom1.cpp
# End Section
# Section PlayMultiMedia : {679409C0-99F7-11D3-9FB7-00105AA620BB}
# 	2:5:Class:CWMPPlaylistArray
# 	2:10:HeaderFile:wmpplaylistarray1.h
# 	2:8:ImplFile:wmpplaylistarray1.cpp
# End Section
# Section PlayMultiMedia : {74C09E02-F828-11D2-A74B-00A0C905F36E}
# 	2:5:Class:CWMPControls
# 	2:10:HeaderFile:wmpcontrols1.h
# 	2:8:ImplFile:wmpcontrols1.cpp
# End Section
# Section PlayMultiMedia : {B09DE713-87C1-11D1-8BE3-0000F8754DA1}
# 	2:5:Class:CAnimation
# 	2:10:HeaderFile:animation.h
# 	2:8:ImplFile:animation.cpp
# End Section
# Section PlayMultiMedia : {8DA61686-4668-4A5C-AE5D-803193293DBE}
# 	2:5:Class:CWMPDVD
# 	2:10:HeaderFile:wmpdvd1.h
# 	2:8:ImplFile:wmpdvd1.cpp
# End Section
# Section PlayMultiMedia : {6C497D62-8919-413C-82DB-E935FB3EC584}
# 	2:5:Class:CWMPPlayer4
# 	2:10:HeaderFile:wmpplayer5.h
# 	2:8:ImplFile:wmpplayer5.cpp
# End Section
# Section PlayMultiMedia : {D27CDB6C-AE6D-11CF-96B8-444553540000}
# 	2:5:Class:CShockwaveFlash
# 	2:10:HeaderFile:shockwaveflash.h
# 	2:8:ImplFile:shockwaveflash.cpp
# End Section
# Section PlayMultiMedia : {CFCDAA01-8BE4-11CF-B84B-0020AFBBCCFA}
# 	2:5:Class:CRealAudio
# 	2:10:HeaderFile:realaudio.h
# 	2:8:ImplFile:realaudio.cpp
# End Section
# Section PlayMultiMedia : {6BF52A52-394A-11D3-B153-00C04F79FAA6}
# 	2:21:DefaultSinkHeaderFile:wmpplayer5.h
# 	2:16:DefaultSinkClass:CWMPPlayer4
# End Section
# Section PlayMultiMedia : {40897764-CEAB-47BE-AD4A-8E28537F9BBF}
# 	2:5:Class:CWMPPlayerApplication
# 	2:10:HeaderFile:wmpplayerapplication1.h
# 	2:8:ImplFile:wmpplayerapplication1.cpp
# End Section
# Section PlayMultiMedia : {9104D1AB-80C9-4FED-ABF0-2E6417A6DF14}
# 	2:5:Class:CWMPSettings
# 	2:10:HeaderFile:wmpsettings1.h
# 	2:8:ImplFile:wmpsettings1.cpp
# End Section
# Section PlayMultiMedia : {A12DCF7D-14AB-4C1B-A8CD-63909F06025B}
# 	2:5:Class:CWMPError
# 	2:10:HeaderFile:wmperror1.h
# 	2:8:ImplFile:wmperror1.cpp
# End Section
# Section PlayMultiMedia : {B09DE715-87C1-11D1-8BE3-0000F8754DA1}
# 	2:21:DefaultSinkHeaderFile:animation.h
# 	2:16:DefaultSinkClass:CAnimation
# End Section
# Section PlayMultiMedia : {4F2DF574-C588-11D3-9ED0-00C04FB6E937}
# 	2:5:Class:CWMPClosedCaption
# 	2:10:HeaderFile:wmpclosedcaption1.h
# 	2:8:ImplFile:wmpclosedcaption1.cpp
# End Section
# Section PlayMultiMedia : {D5F0F4F1-130C-11D3-B14E-00C04F79FAA6}
# 	2:5:Class:CWMPPlaylist
# 	2:10:HeaderFile:wmpplaylist1.h
# 	2:8:ImplFile:wmpplaylist1.cpp
# End Section
# Section PlayMultiMedia : {EE4C8FE2-34B2-11D3-A3BF-006097C9B344}
# 	2:5:Class:CWMPCdromCollection
# 	2:10:HeaderFile:wmpcdromcollection1.h
# 	2:8:ImplFile:wmpcdromcollection1.cpp
# End Section
# Section PlayMultiMedia : {3614C646-3B3B-4DE7-A81E-930E3F2127B3}
# 	2:5:Class:CWMPErrorItem
# 	2:10:HeaderFile:wmperroritem1.h
# 	2:8:ImplFile:wmperroritem1.cpp
# End Section
# Section PlayMultiMedia : {94D55E95-3FAC-11D3-B155-00C04F79FAA6}
# 	2:5:Class:CWMPMedia
# 	2:10:HeaderFile:wmpmedia1.h
# 	2:8:ImplFile:wmpmedia1.cpp
# End Section
# Section PlayMultiMedia : {D27CDB6E-AE6D-11CF-96B8-444553540000}
# 	2:21:DefaultSinkHeaderFile:shockwaveflash.h
# 	2:16:DefaultSinkClass:CShockwaveFlash
# End Section
# Section PlayMultiMedia : {10A13217-23A7-439B-B1C0-D847C79B7774}
# 	2:5:Class:CWMPPlaylistCollection
# 	2:10:HeaderFile:wmpplaylistcollection1.h
# 	2:8:ImplFile:wmpplaylistcollection1.cpp
# End Section
# Section PlayMultiMedia : {EC21B779-EDEF-462D-BBA4-AD9DDE2B29A7}
# 	2:5:Class:CWMPNetwork
# 	2:10:HeaderFile:wmpnetwork1.h
# 	2:8:ImplFile:wmpnetwork1.cpp
# End Section
# Section PlayMultiMedia : {CFCDAA03-8BE4-11CF-B84B-0020AFBBCCFA}
# 	2:21:DefaultSinkHeaderFile:realaudio.h
# 	2:16:DefaultSinkClass:CRealAudio
# End Section
# Section PlayMultiMedia : {4A976298-8C0D-11D3-B389-00C04F68574B}
# 	2:5:Class:CWMPStringCollection
# 	2:10:HeaderFile:wmpstringcollection1.h
# 	2:8:ImplFile:wmpstringcollection1.cpp
# End Section
# Section PlayMultiMedia : {8363BC22-B4B4-4B19-989D-1CD765749DD1}
# 	2:5:Class:CWMPMediaCollection
# 	2:10:HeaderFile:wmpmediacollection1.h
# 	2:8:ImplFile:wmpmediacollection1.cpp
# End Section
