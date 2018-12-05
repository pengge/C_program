//-----------------------------------------------------------------------------
// File: DirectXAppWizardSample.h
//
// Desc: Header file DirectXAppWizardSample sample app
//-----------------------------------------------------------------------------
#ifndef AFX_DIRECTXAPPWIZARDSAMPLE_H__92DE1243_D789_46AC_B33E_9C1F56110D3B__INCLUDED_
#define AFX_DIRECTXAPPWIZARDSAMPLE_H__92DE1243_D789_46AC_B33E_9C1F56110D3B__INCLUDED_




//-----------------------------------------------------------------------------
// Defines, and constants
//-----------------------------------------------------------------------------
// TODO: change "DirectX AppWizard Apps" to your name or the company name
#define DXAPP_KEY        TEXT("Software\\DirectX AppWizard Apps\\DirectXAppWizardSample")

// DirectInput action mapper reports events only when buttons/axis change
// so we need to remember the present state of relevant axis/buttons for 
// each DirectInput device.  The CInputDeviceManager will store a 
// pointer for each device that points to this struct
struct InputDeviceState
{
    // TODO: change as needed
    FLOAT fAxisRotateLR;
    BOOL  bButtonRotateLeft;
    BOOL  bButtonRotateRight;

    FLOAT fAxisRotateUD;
    BOOL  bButtonRotateUp;
    BOOL  bButtonRotateDown;

    BOOL  bButtonPlaySoundButtonDown;
};


// Struct to store the current input state
struct UserInput
{
    // TODO: change as needed
    FLOAT fAxisRotateUD;
    FLOAT fAxisRotateLR;
    BOOL bPlaySoundButtonDown;
    BOOL bDoConfigureInput;
    BOOL bDoConfigureDisplay;
};




//-----------------------------------------------------------------------------
// Name: class CMyD3DApplication
// Desc: Application class. The base class (CD3DApplication) provides the 
//       generic functionality needed in all Direct3D samples. CMyD3DApplication 
//       adds functionality specific to this sample program.
//-----------------------------------------------------------------------------
class CMyD3DApplication : public CD3DApplication
{
    BOOL                    m_bLoadingApp;          // TRUE, if the app is loading
    CD3DFont*               m_pFont;                // Font for drawing text
    ID3DXMesh*              m_pD3DXMesh;            // D3DX mesh to store teapot

    CInputDeviceManager*    m_pInputDeviceManager;  // DirectInput device manager
    DIACTIONFORMAT          m_diafGame;             // Action format for game play
    LPDIRECT3DSURFACE8      m_pDIConfigSurface;     // Surface for config'ing DInput devices
    UserInput               m_UserInput;            // Struct for storing user input 

    FLOAT                   m_fSoundPlayRepeatCountdown; // Sound repeat timer
    CMusicManager*          m_pMusicManager;        // DirectMusic manager class
    CMusicSegment*          m_pBounceSound;         // Bounce sound

    FLOAT                   m_fWorldRotX;           // World rotation state X-axis
    FLOAT                   m_fWorldRotY;           // World rotation state Y-axis

protected:
    HRESULT OneTimeSceneInit();
    HRESULT InitDeviceObjects();
    HRESULT RestoreDeviceObjects();
    HRESULT InvalidateDeviceObjects();
    HRESULT DeleteDeviceObjects();
    HRESULT Render();
    HRESULT FrameMove();
    HRESULT FinalCleanup();
    HRESULT ConfirmDevice( D3DCAPS8*, DWORD, D3DFORMAT );
    VOID    Pause( BOOL bPause );

    HRESULT RenderText();

    HRESULT InitInput( HWND hWnd );
    void    UpdateInput( UserInput* pUserInput );
    void    CleanupDirectInput();

    HRESULT InitAudio( HWND hWnd );

    VOID    ReadSettings();
    VOID    WriteSettings();

public:
    LRESULT MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    CMyD3DApplication();

    HRESULT InputAddDeviceCB( CInputDeviceManager::DeviceInfo* pDeviceInfo, const DIDEVICEINSTANCE* pdidi );
    static HRESULT CALLBACK StaticInputAddDeviceCB( CInputDeviceManager::DeviceInfo* pDeviceInfo, const DIDEVICEINSTANCE* pdidi, LPVOID pParam );   
    BOOL    ConfigureInputDevicesCB( IUnknown* pUnknown );
    static BOOL CALLBACK StaticConfigureInputDevicesCB( IUnknown* pUnknown, VOID* pUserData );
};


#endif // !defined(AFX_DIRECTXAPPWIZARDSAMPLE_H__92DE1243_D789_46AC_B33E_9C1F56110D3B__INCLUDED_)
