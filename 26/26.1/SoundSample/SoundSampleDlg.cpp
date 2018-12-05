// SoundSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SoundSample.h"
#include "SoundSampleDlg.h"
#include "mmsystem.h"
#include "digitalv.h"
#include "vfw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoundSampleDlg dialog

CSoundSampleDlg::CSoundSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoundSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoundSampleDlg)
	m_Volumn = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSoundSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoundSampleDlg)

	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_VOLUMN, m_Volumn);
	DDV_MinMaxUInt(pDX, m_Volumn, 0, 65535);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoundSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSoundSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_RECORD, OnButtonRecord)
	ON_BN_CLICKED(IDC_BUTTON_STOPRECORD, OnButtonStoprecord)
	ON_BN_CLICKED(IDC_BUTTON_CTRLVOLUMN, OnButtonCtrlvolumn)
	ON_BN_CLICKED(IDC_BUTTON_PLAYCD, OnButtonPlaycd)
	ON_BN_CLICKED(IDC_BUTTON_CTRLLEFT, OnButtonCtrlleft)
	ON_BN_CLICKED(IDC_BUTTON_PCPLAY, OnButtonPcplay)
	ON_BN_CLICKED(IDC_BUTTON_PLAYWAV, OnButtonPlaywav)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_PLAYMIDI, OnButtonPlaymidi)
	ON_BN_CLICKED(IDC_BUTTON_PLAYMP3, OnButtonPlaymp3)
	ON_BN_CLICKED(IDC_BUTTON_STOPMP3, OnButtonStopmp3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoundSampleDlg message handlers

BOOL CSoundSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_hWndMCI = NULL;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSoundSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSoundSampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSoundSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//��¼��־����
void CSoundSampleDlg::WriteLog(CString log)
{
	m_editLog.SetWindowText(log);
}

//����������
void CSoundSampleDlg::OnButtonPlay() 
{
	if (!PlaySound("C:\\Windows 7 ����.wav",  NULL, SND_SYNC | SND_NODEFAULT))
		WriteLog("���������ļ����ִ���");
}

//������¼��
void CSoundSampleDlg::OnButtonRecord() 
{
	MMRESULT mmResult;
	WAVEFORMATEX m_waveformat;
	m_waveformat.wFormatTag=WAVE_FORMAT_PCM;   
	m_waveformat.nChannels=1;   
	m_waveformat.nSamplesPerSec=11025;   
	m_waveformat.nAvgBytesPerSec=11025;   
	m_waveformat.nBlockAlign=1;   
	m_waveformat.wBitsPerSample=8;   
	m_waveformat.cbSize=0;   


	if ((mmResult = waveInOpen(&m_hWaveIn, 0, &m_waveformat, 
		(DWORD)this->m_hWnd, NULL, CALLBACK_WINDOW))!= MMSYSERR_NOERROR)
	{
		if (mmResult == MMSYSERR_ALLOCATED)
			WriteLog("��Ƶ�豸�Ѿ��������豸ռ��");
		else if (mmResult == MMSYSERR_BADDEVICEID)
			WriteLog("ָ������Ƶ�豸��ʶ��������Χ");
		else if (mmResult == MMSYSERR_NODRIVER)
			WriteLog("û��׼������Ƶ�豸");
		else if (mmResult == MMSYSERR_NOMEM)
			WriteLog("û�з�����ڴ�");
		else if (mmResult == WAVERR_BADFORMAT)
			WriteLog("�������Ƶ��ʽ");
		else WriteLog("����Ƶ�����豸ʧ��");
		return;
	}
    
	const int MAX_WAVEDATA_LENGTH = 90040;
	inbuf = new char[MAX_WAVEDATA_LENGTH];
	m_wavehdr.lpData=inbuf; 
    m_wavehdr.dwBufferLength=MAX_WAVEDATA_LENGTH; 
    m_wavehdr.dwBytesRecorded=0; 
    m_wavehdr.dwUser=0; 
    m_wavehdr.dwFlags=0; 
    m_wavehdr.dwLoops=0; 
    m_wavehdr.lpNext=NULL; 
    m_wavehdr.reserved=0;

	if (waveInPrepareHeader(m_hWaveIn, &m_wavehdr, sizeof(m_wavehdr))!= MMSYSERR_NOERROR)
	{
		WriteLog("Ϊ¼���豸׼�����溯��ʧ��");
		return;
	}

	if (waveInAddBuffer(m_hWaveIn, &m_wavehdr, sizeof(m_wavehdr))!= MMSYSERR_NOERROR)
	{
		WriteLog("�������豸����һ������ʧ��");
		return;
	}

	if (waveInStart(m_hWaveIn)!= MMSYSERR_NOERROR)
	{
		WriteLog("��ʼ¼��ʧ��");
		return;
	}
	WriteLog("��ʼ¼��������������");
}

//ֹͣ¼������
void CSoundSampleDlg::OnButtonStoprecord() 
{
	if (waveInReset(m_hWaveIn)!= MMSYSERR_NOERROR)
	{
		WriteLog("ֹͣ¼��ʧ��");
		return;
	}

	MMRESULT mmResult;
	if ((mmResult = waveInUnprepareHeader(m_hWaveIn, &m_wavehdr, sizeof(m_wavehdr))) != MMSYSERR_NOERROR)
	{
		if (mmResult == MMSYSERR_INVALHANDLE)
			WriteLog("�豸�����Ч");
		else if (mmResult == MMSYSERR_NODRIVER)
			WriteLog("û��׼�����豸����");
		else if (mmResult == MMSYSERR_NOMEM)
			WriteLog("û�з���������ڴ�");
		else if (mmResult == WAVERR_STILLPLAYING)
			WriteLog("���ڲ�������");
		else WriteLog("�������ʧ��");
		return;
	}

	if (waveInClose(m_hWaveIn)!= MMSYSERR_NOERROR)
	{
		WriteLog("�ر�¼���豸ʧ��");
		return;
	}

	WriteLog("¼���������");
}

// ����CD��Ŀ
void CSoundSampleDlg::OnButtonPlaycd() 
{
	UpdateData(TRUE);
	MCIDEVICEID deviceID = mciGetDeviceID("G:\\");
	DWORD dwPlay = m_Volumn;
	DWORD dwFlags; 
	MCI_DGV_PLAY_PARMS mciPlay; 
	mciPlay.dwCallback = MAKELONG(m_hWnd,0); 
	mciPlay.dwFrom = mciPlay.dwTo = dwPlay; 
	dwFlags = MCI_NOTIFY; 
	dwFlags |= MCI_DGV_PLAY_REVERSE;  
	MCIERROR mciError;
	if ((mciError=mciSendCommand(deviceID, MCI_PLAY, dwFlags, (DWORD)(LPMCI_DGV_PLAY_PARMS)&mciPlay)) == 0)
		WriteLog("���ڲ�����Ŀ......");
	else
	{
		char szErrorText[500]={0};
		mciGetErrorString(mciError, szErrorText, sizeof(szErrorText));
		WriteLog(szErrorText);
	}
}

//��������
void CSoundSampleDlg::OnButtonCtrlvolumn() 
{
	MMRESULT mmResult;
	DWORD dwDevNum;
	dwDevNum =  ::auxGetNumDevs();
	if (dwDevNum>0) 
	{
		DWORD dwVolume1;
		mmResult=auxGetVolume(AUX_MAPPER, &dwVolume1);
		if (mmResult != MMSYSERR_NOERROR)
		{
			if (mmResult == MMSYSERR_BADDEVICEID)	WriteLog("��Ƶ�豸��Ч");
			else WriteLog("��ȡ��ǰ��Ƶ�豸������ʧ��");
			return;
		}		
		UpdateData(FALSE);
		CString log;
		DWORD dwVolume2 = m_Volumn;
		mmResult=auxSetVolume(AUX_MAPPER, dwVolume2);
		if (mmResult != MMSYSERR_NOERROR)
			log.Format("��������ʧ�ܡ�ԭ������=%d", dwVolume1);		
		else
			log.Format("���������ɹ���ԭ������=%d;���ú������=%d", dwVolume1, dwVolume2);		
		WriteLog(log);
	}
	else
		WriteLog("û����Ч����Ƶ�豸");
}

//������������
void CSoundSampleDlg::OnButtonCtrlleft() 
{
	/*HMIXER m_hMixer;
	MIXERCONTROLDETAILS m_mxcd;   
	MMRESULT mmResult; 
	DWORD dwFlags = MIXER_OBJECTF_MIXER;
	
	mmResult = mixerOpen(&m_hMixer, 0, NULL,   NULL,   dwFlags);   
	if(mmResult != MMSYSERR_NOERROR)   return;*/

	/*MIXERLINECONTROLS mxlc;
	LPMIXERCONTROL pmxc=new MIXERCONTROL();   

	
	ZeroMemory(&pmxc,   sizeof(MIXERCONTROL));   
	pmxc[i].cbStruct   =   sizeof(MIXERCONTROL);   

	ZeroMemory(&mxlc,   sizeof(MIXERLINECONTROLS));   
	mxlc.cbStruct   =   sizeof(MIXERLINECONTROLS);   
	mxlc.dwLineID   =   pmxml->dwLineID;   
	mxlc.cControls   =   pmxml->cControls;   
	mxlc.cbmxctrl   =   sizeof(MIXERCONTROL);   
	mxlc.pamxctrl   =   pmxc;   

	result   =   mixerGetLineControls((HMIXEROBJ)m_hMixer,   &mxlc,     
	MIXER_GETLINECONTROLSF_ALL   |   MIXER_OBJECTF_HMIXER);   

	if(result   !=   MMSYSERR_NOERROR)   {   
	delete   pmxc;   
	*p2pmxcs   =   NULL; */  





	/*ZeroMemory(&m_mxcd, sizeof(MIXERCONTROLDETAILS));   
	m_mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);   
	m_mxcd.dwControlID = pmxc->dwControlID;   
	m_mxcd.cChannels = cChannels;   
	m_mxcd.cMultipleItems =  pmxc->cMultipleItems;   
	m_mxcd.cbDetails = cbDetails;   
	m_mxcd.paDetails = paDetails;   
	if(bSetValue)   
	{   
		mmResult = mixerSetControlDetails((HMIXEROBJ)m_hMixer,   
		&m_mxcd, MIXER_OBJECTF_HMIXER|MIXER_SETCONTROLDETAILSF_VALUE|dwFlags);   
	}   
	else   
	{   
		mmResult = mixerGetControlDetails((HMIXEROBJ)m_hMixer,   
		&m_mxcd, MIXER_OBJECTF_HMIXER|MIXER_GETCONTROLDETAILSF_VALUE|dwFlags);   
	}   

	if(result != MMSYSERR_NOERROR)  WriteLog("���������ɹ�");
	else WriteLog("��������ʧ��");
	mixerClose(m_hMixer);*/
}

//����PC���Ȳ�������
void CSoundSampleDlg::OnButtonPcplay() 
{
	::Beep(1570,5000);
}

//��ʱ����WAV�ļ�
void CSoundSampleDlg::OnButtonPlaywav() 
{
	SetTimer(200, 10000, NULL);
}

void CSoundSampleDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 200)
	{
		CString sFileName = _T("Windows XP ����.wav");
		::PlaySound(sFileName, NULL, SND_FILENAME);
	}
	CDialog::OnTimer(nIDEvent);
}

//����MIDI�ļ����ų���
void CSoundSampleDlg::OnButtonPlaymidi() 
{
	HWND hMCIWnd;
	hMCIWnd = MCIWndCreate(NULL, NULL, 0, "town.mid");
	MCIWndPlay(hMCIWnd);
}

//�������м��书�ܵ�MP3������
void CSoundSampleDlg::OnButtonPlaymp3() 
{	
	int type=0;
	if (m_hWndMCI == NULL)
	{		
		fileName="���н���.mp3";
		m_hWndMCI=MCIWndCreate(m_hWnd, AfxGetInstanceHandle(), type, fileName);
		MCIWndPlay(m_hWndMCI);
		return;
	}
	
	m_hWndMCI=MCIWndCreate(m_hWnd,AfxGetInstanceHandle(), type, fileName);
	long nLength = MCIWndGetLength(m_hWndMCI);
	MCIWndPlayFromTo(m_hWndMCI, m_lPosition, nLength);
}

//ֹͣ����MP3
void CSoundSampleDlg::OnButtonStopmp3() 
{
	MCIWndGetFileName(m_hWndMCI, fileName.GetBuffer(1000), 1000);
	m_lPosition = MCIWndGetPosition(m_hWndMCI);
	MCIWndStop(m_hWndMCI);
	MCIWndDestroy(m_hWndMCI);
}
