#include "stdafx.h"
#include "D3dx9math.h"
#include "Cube3D.h"


#define RENDER_WIDTH	800
#define RENDER_HEIGHT	600
//------------------------------------------------------------------------------------
// ���캯��, ��ʼ����Ա����
//------------------------------------------------------------------------------------
Cube3D::Cube3D()
{
    m_d3d			= NULL;
    m_d3dDevice		= NULL;
    m_vertexBuffer	= NULL;
	m_indexBuffer	= NULL;
	m_curX = 0;
	m_curY = 0;
	m_curZ = 0;	
}

//------------------------------------------------------------------------------------
// �����������ͷ�direct3D��Դ
//------------------------------------------------------------------------------------
Cube3D::~Cube3D()
{
    ReleaseD3D();
}

//------------------------------------------------------------------------------------
// �ͷ�Direct3D��Դ
//------------------------------------------------------------------------------------
void Cube3D::ReleaseD3D()
{	
    SAFE_RELEASE(m_vertexBuffer);	
    SAFE_RELEASE(m_d3dDevice);
    SAFE_RELEASE(m_d3d);
}

//------------------------------------------------------------------------------------
// ����Direct3D�ӿڶ����Direct3D�豸
//------------------------------------------------------------------------------------
BOOL Cube3D::CreateD3DDevice(HWND hWnd, BOOL fullScreen)
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
// ʹ���Զ���Ķ���ṹ��ʼ�����㻺��������������������������
//------------------------------------------------------------------------------------
BOOL Cube3D::InitVertexBuffer()
{
	CUSTOM_VERTEX customVertex[] = {
        {0.0,  0.0, 1.0,	D3DCOLOR_XRGB(255, 255, 0)},      // ���� 0
        {-1.0, 0.0, 0.0,	D3DCOLOR_XRGB(255, 255, 0)},      // ���� 1
        {0.0,  1.0, 0.0,	D3DCOLOR_XRGB(255, 255, 0)},      // ���� 2
        {1.0,  0.0, 0.0,	D3DCOLOR_XRGB(255, 255, 0)},      // ���� 3
        {0.0,  -1.0,0.0,	D3DCOLOR_XRGB(255, 255, 0)}		  // ���� 4
    };

    BYTE* vertexData;

    // �������㻺����
    if(FAILED(m_d3dDevice->CreateVertexBuffer(5 * sizeof(CUSTOM_VERTEX), 0, 
		CUSTOM_VERTEX_FVF, D3DPOOL_MANAGED,  &m_vertexBuffer, NULL)))
        return FALSE;

    // �������ݷ�Χ������ȡָ�򻺳����ڴ��ָ��
    if(FAILED(m_vertexBuffer->Lock(0, 0, (void**) &vertexData, 0)))
        return FALSE;

    // �����������ݵ���������
    memcpy(vertexData, customVertex, sizeof(customVertex));

    // �������㻺����
    m_vertexBuffer->Unlock();

	// ������������������
    if(FAILED(m_d3dDevice->CreateIndexBuffer(36 * sizeof(WORD), 0, 
		D3DFMT_INDEX16, D3DPOOL_MANAGED,  &m_indexBuffer, NULL)))
           return FALSE;
   
    // ����ָ����Χ���������ݣ�����ȡ�����������ڴ��ָ��
    WORD* index_data;
    if(FAILED(m_indexBuffer->Lock(0, 0, (void**) &index_data, 0)))
        return FALSE;

	index_data[0]=0;  index_data[1]=1;  index_data[2]=2;
    index_data[3]=0;  index_data[4]=2;  index_data[5]=3;
	index_data[6]=0;  index_data[7]=3;  index_data[8]=4;
	index_data[9]=0;  index_data[10]=4;  index_data[11]=1;

    // ������������������
    m_indexBuffer->Unlock();

    return TRUE;
}

//------------------------------------------------------------------------------------
// ��Ⱦ��������
//------------------------------------------------------------------------------------
void Cube3D::Render()
{
    if(m_d3dDevice == NULL)
        return;

    // ʹ����ɫɫ�����ȾĿ��
    m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(155, 0, 155), 1.0, 0);

    // ��ʼ��Ⱦ���� 
    m_d3dDevice->BeginScene();

	// ʹ���߿�������
    m_d3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
    // �رյƹ�
   m_d3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    // �رձ����޳�
    m_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

    // �󶨶��㻺�������豸������
    m_d3dDevice->SetStreamSource(0, m_vertexBuffer, 0, sizeof(CUSTOM_VERTEX));

	// ������������
    m_d3dDevice->SetIndices(m_indexBuffer);

    // ���õ�ǰ�������Ķ����ʽ
    m_d3dDevice->SetFVF(CUSTOM_VERTEX_FVF);

	// �����ӿ�
    D3DVIEWPORT9 fullViewport;

    // ���ص�ǰ�豸���ӿڲ���
    m_d3dDevice->GetViewport(&fullViewport);

    D3DVIEWPORT9 topLeftViewport;

    topLeftViewport.Width  = fullViewport.Width / 5;
    topLeftViewport.Height = fullViewport.Height / 5;
    topLeftViewport.X      = 0;
    topLeftViewport.Y      = 0;
    topLeftViewport.MinZ   = 0;
    topLeftViewport.MaxZ   = 1;

    // �����豸���ӿ�
    m_d3dDevice->SetViewport(&topLeftViewport);
	// ������������Ⱦ�����嵽��������
    m_d3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST , 0, 0, 0, 0, 12);

	// �����豸���ӿ�
    m_d3dDevice->SetViewport(&fullViewport);
    // ������������Ⱦ�����嵽��������
    m_d3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

    // ��Ⱦ��������
    m_d3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

    // ������Ⱦ����
    m_d3dDevice->EndScene();

    // Ϊ��һ�λ�������Ⱦ��׼��
    m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}

//------------------------------------------------------------------------------------
// ʹ��ָ������ԭ������ϵ��������λ��
//------------------------------------------------------------------------------------
void Cube3D::SetWorldPosition(float x, float y, float z)
{
    D3DXMATRIX worldMatrix;

    // ʹ��ָ��ƫ�����������󣬶����������������(x, y, z)��
    D3DXMatrixTranslation(&worldMatrix, x, y, z);
    
    // ����Direct3D�豸������ת��״̬
    m_d3dDevice->SetTransform(D3DTS_WORLD, &worldMatrix);
}

//------------------------------------------------------------------------------------
// ������Ӱ��λ��
//------------------------------------------------------------------------------------
void Cube3D::SetCamera()
{
    D3DXVECTOR3 eye(2.0, 1.5, -3.0);
    D3DXVECTOR3 at(0.0, 0.0, 0.0);
    D3DXVECTOR3 up(0.0, 1.0, 0.0);

    D3DXMATRIX viewMatrix;

    // ���������ӵ�ľ���
    D3DXMatrixLookAtLH(&viewMatrix, &eye, &at, &up);

    // ����Direct3D�豸��ͼת��״̬
    m_d3dDevice->SetTransform(D3DTS_VIEW, &viewMatrix);

    D3DXMATRIX projMatrix;

    // ��������ͶӰ
    D3DXMatrixPerspectiveFovLH(&projMatrix, D3DX_PI/2, 800/600, 1.0, 1000.0);
    
    // ����Direct3D�豸ͶӰת��״̬
    m_d3dDevice->SetTransform(D3DTS_PROJECTION, &projMatrix);
}

