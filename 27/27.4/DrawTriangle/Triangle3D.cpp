#include "stdafx.h"
#include "TRIANGLE3D.h"

#define RENDER_WIDTH	800
#define RENDER_HEIGHT	600

//------------------------------------------------------------------------------------
// ���캯��,��ʼ����Ա����
//------------------------------------------------------------------------------------
TRIANGLE3D::TRIANGLE3D()
{
    m_d3d          = NULL;
    m_d3dDevice    = NULL;
    m_vertexBuffer = NULL;	
}

//------------------------------------------------------------------------------------
// ��������,�ͷ�direct3D��Դ
//------------------------------------------------------------------------------------
TRIANGLE3D::~TRIANGLE3D()
{
    ReleaseD3D();
}

//------------------------------------------------------------------------------------
// �ͷ�Direct3D��Դ
//------------------------------------------------------------------------------------
void TRIANGLE3D::ReleaseD3D()
{
    SAFE_RELEASE(m_vertexBuffer);
    SAFE_RELEASE(m_d3dDevice);
    SAFE_RELEASE(m_d3d);
}

//------------------------------------------------------------------------------------
// ����Direct3D�ӿڶ����Direct3D�豸
//------------------------------------------------------------------------------------
BOOL TRIANGLE3D::CreateD3DDevice(HWND hWnd, BOOL fullScreen)
{
    // ����Direct3D�ӿڶ��󣬲����ؽӿ�
    m_d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if(m_d3d == NULL)
        return FALSE;

    // �������������
    D3DCAPS9 d3dCaps;    
    m_d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);
    
	BOOL hp;//�Ƿ�֧��Ӳ������
	if(d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)  hp = TRUE;	
	else hp = FALSE;	

    // ��ȡ�������ĵ�ǰ��ʾģʽ
    D3DDISPLAYMODE display_mode;
    if(FAILED(m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display_mode)))
        return FALSE;

	// ����Direct3D�豸�ĵ�ǰ����
    D3DPRESENT_PARAMETERS param = {0};	

    param.BackBufferWidth      = RENDER_WIDTH;
    param.BackBufferHeight     = RENDER_HEIGHT;
    param.BackBufferFormat     = display_mode.Format;
    param.BackBufferCount      = 1;
    param.hDeviceWindow        = hWnd;
    param.Windowed             = !fullScreen;
    param.SwapEffect           = D3DSWAPEFFECT_FLIP;
    param.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

    // ����������ʾ���������豸
    DWORD flags = hp ? D3DCREATE_HARDWARE_VERTEXPROCESSING : D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	HRESULT hr;
    if(FAILED(hr=m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, flags, 
                                 &param, &m_d3dDevice)))
	{
		switch(hr)
		{
		case D3DERR_DEVICELOST:
			AfxMessageBox("D3DERR_DEVICELOST");
			break;
		case D3DERR_INVALIDCALL:
			AfxMessageBox("D3DERR_INVALIDCALL");
			break;
		case  D3DERR_NOTAVAILABLE:
			AfxMessageBox("D3DERR_NOTAVAILABLE");
			break;
		case D3DERR_OUTOFVIDEOMEMORY:
			AfxMessageBox("D3DERR_OUTOFVIDEOMEMORY");
			break;
		default:
			AfxMessageBox("OTHER");
			break;
		}
		return FALSE;
	}   
    return TRUE;
}

//------------------------------------------------------------------------------------
// ʹ���Զ���Ķ���ṹ��ʼ�����㻺����
//------------------------------------------------------------------------------------
BOOL TRIANGLE3D::InitVertexBuffer()
{
	CUSTOM_VERTEX customVertex[] =
    {
        { 300.0f, 100.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(255, 0, 0) }, 
        { 500.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 0, 255) },
        { 100.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 255)},
    };

    BYTE* vertexData;

    // �������㻺����
    if(FAILED(m_d3dDevice->CreateVertexBuffer(3 * sizeof(CUSTOM_VERTEX), 0, 
		CUSTOM_VERTEX_FVF, D3DPOOL_MANAGED,  &m_vertexBuffer, NULL)))
        return FALSE;

    // �������ݷ�Χ������ȡָ�򻺳����ڴ��ָ��
    if(FAILED(m_vertexBuffer->Lock(0, 0, (void**) &vertexData, 0)))
        return FALSE;

    // �����������ݵ���������
    memcpy(vertexData, customVertex, sizeof(customVertex));

    // �������㻺����
    m_vertexBuffer->Unlock();

    return TRUE;
}

//------------------------------------------------------------------------------------
// ��Ⱦ��������
//------------------------------------------------------------------------------------
void TRIANGLE3D::Render()
{
    if(m_d3dDevice == NULL)
        return;

    // ʹ�ú�ɫɫ�����ȾĿ��
    m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0, 0);

    // ��ʼ��Ⱦ���� 
    m_d3dDevice->BeginScene();

    // �󶨶��㻺�������豸������
    m_d3dDevice->SetStreamSource(0, m_vertexBuffer, 0, sizeof(CUSTOM_VERTEX));

    // ���õ�ǰ�������Ķ����ʽ
    m_d3dDevice->SetFVF(CUSTOM_VERTEX_FVF);

    // ��Ⱦ��������
    m_d3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

    // ������Ⱦ����
    m_d3dDevice->EndScene();

    // Ϊ��һ�λ�������Ⱦ��׼��
    m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}