#if !defined (AFX_TAGDEFINE_H)
#define AFX_TAGDEFINE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <mmreg.h>
#include <msacm.h>

HACMDRIVERID find_driver(WORD wFormatTag);
BOOL CALLBACK find_driver_enum(HACMDRIVERID hadid, DWORD dwInstance, DWORD fdwSupport);
BOOL CALLBACK find_format_enum(HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD dwInstance, DWORD fdwSupport);
WAVEFORMATEX* get_driver_format(HACMDRIVERID hadid, WORD wFormatTag);

typedef enum AUDIOSTATUS
{
	CLOSED = 0,
	STOP = 1,
	PAUSE= 2,
	PLAY = 3,
	OPENING = 4,
	ACQUIRINGLICENSE = 5,
	INDIVIDUALIZING,
	STOPPING,
	READY,
	BUFFERING,
	LICENSEACQUIRED,
	INDIVIDUALIZED
} AUDIOSTATUS;

struct FIND_DRIVER_INFO
{
	HACMDRIVERID hadid;
	WORD wFormatTag;
} ;
#define	BUFFERSIZE	1920;	//����ACM��ԭ��,����Ϊ1920�ı���

#define	MAXFILERECSECOND	60;
#define	MAX_BROADCASTNUM	5

#define	_FREE		0;		//��ʶĳ��������
#define	_INUSE		1;		//��ʶĳ�������ʹ����

#define	BUFFERNUM	10;		//��������
#define HEAPSIZE	51200	//�����ĶѵĴ�С

#define ERROR_DIALOG_TITLE  _T( "WM Audio Player Sample" )

#define SAFE_HEAPFREE(p)	{ if ((p) != NULL) { HeapFree(hHeap, 0, (p)); (p) = NULL;}}

#define WM_USER_ACMINCMPLT	WM_USER+1123	//�Զ�����Ϣ��ѹ�����
#define WM_USER_ACMOUTCMPLT	WM_USER+1124	//�Զ�����Ϣ����ѹ���

#define	MSG_DATABLOCKERR	"Data block initialize error.\nUnable to record."
#define	MSG_ERRTITLE		"Error"
#define	MSG_ACMERR			"Unable to start ACM.\nPlease selete another one."
#define	MSG_ACMERRCANCEL	"Unable to start ACM.\nPlease selete another one.\nClick Cancel to exit"
#define	MSG_FORMATNOTSUPPORT	"The format not supported by the OS. \nPlease selete another one.\nClick Cancel to exit."
#define MSG_FORMATNEEDED	"You must select one format \n Click Cancel to exit."
#define MSG_FORMATNOTFIT	"The format is not fit. \nPlease selete another one.\nClick Cancel to exit."
#define MSG_FORMATCHOOSETITLE	"Format"
#define	MSG_WAVEINERR		"Error to start audio in device.\nPlease confirm whether it's installed correctly.\n Or the device is using by another program."
#define MSG_WAVEOUTERR		"Error to start audio out device.\nPlease confirm whether it's installed correctly.\n Or the device is using by another program."

#define ERROR_DIALOG_TITLE  _T( "WM Audio Player Sample" )
#endif