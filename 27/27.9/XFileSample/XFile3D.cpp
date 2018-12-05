#include "stdafx.h"
#include "XFILE3D.h"
#include "D3dx9tex.h"

#define RENDER_WIDTH	800
#define RENDER_HEIGHT	600

//------------------------------------------------------------------------------------
// ���캯��,��ʼ����Ա����
//------------------------------------------------------------------------------------
XFILE3D::XFILE3D()
{
    m_d3d          = NULL;
    m_d3dDevice    = NULL;

	m_AdjacencyBuffer = NULL;	
	m_MaterialBuffer = NULL;	
	m_MaterialArray = NULL;		
	m_TextureArray = NULL;
	m_MaterialsNum = 0;	
	m_Mesh = NULL;
    
}

//------------------------------------------------------------------------------------
// ��������,�ͷ�direct3D��Դ
//------------------------------------------------------------------------------------
XFILE3D::~XFILE3D()
{
    ReleaseD3D();
}

//------------------------------------------------------------------------------------
// �ͷ�Direct3D��Դ
//------------------------------------------------------------------------------------
void XFILE3D::ReleaseD3D()
{
    
    SAFE_RELEASE(m_d3dDevice);
    SAFE_RELEASE(m_d3d);
}

//------------------------------------------------------------------------------------
// ����Direct3D�ӿڶ����Direct3D�豸
//------------------------------------------------------------------------------------
BOOL XFILE3D::CreateD3DDevice(HWND hWnd, BOOL fullScreen)
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


BOOL XFILE3D::LoadXFile(char* filename)
{    
	// ��DirectX��X�ļ���װ������
	if(FAILED(D3DXLoadMeshFromX(filename, D3DXMESH_MANAGED,  
		m_d3dDevice,   &m_AdjacencyBuffer,
		&m_MaterialBuffer,  NULL,  &m_MaterialsNum, &m_Mesh)))           
	{        
		MessageBox(NULL, "װ��X�ļ�ʧ��", "����", MB_OK);        
		return FALSE;    
	}
	if (m_MaterialBuffer==NULL || m_MaterialsNum == 0)   return FALSE;
	// ��ȡ�����еĲ���
	D3DXMATERIAL* material = (D3DXMATERIAL*) m_MaterialBuffer->GetBufferPointer();
	if(material != NULL)    
	{       
		m_MaterialArray = new D3DMATERIAL9[m_MaterialsNum];        
		m_TextureArray  = new IDirect3DTexture9*[m_MaterialsNum];    
		for(DWORD i = 0; i < m_MaterialsNum; i++)        
		{          
			m_MaterialArray[i] = material[i].MatD3D;
			m_TextureArray[i] = NULL;
			if(material[i].pTextureFilename != NULL)            
			{                
				if(FAILED(D3DXCreateTextureFromFile(m_d3dDevice, 
					material[i].pTextureFilename, &m_TextureArray[i])))  
					m_TextureArray[i] = NULL;            
			}        
		}    
	}
	m_Mesh->OptimizeInplace(D3DXMESHOPT_COMPACT | D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE, 
		(DWORD*) m_AdjacencyBuffer->GetBufferPointer(), NULL, NULL, NULL);
	m_MaterialBuffer->Release();    
	m_AdjacencyBuffer->Release();
	return TRUE;
}

void XFILE3D::Render()
{  
	// ���ԭ�е�����
	m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	// ��������
    m_d3dDevice->BeginScene();
	// ������������������ 
	for(DWORD i = 0; i < m_MaterialsNum; i++)   
	{        
		// �����豸�Ĳ�������
        m_d3dDevice->SetMaterial(&m_MaterialArray[i]);
        // �����豸������
		if (m_TextureArray[i] != NULL)
			m_d3dDevice->SetTexture(0, m_TextureArray[i]);
        // ���ƾ�����ͬ�Ӽ�ID������
		m_Mesh->DrawSubset(i);    
	}
	// ��������
    m_d3dDevice->EndScene();
    // ׼����һ����Ⱦ    
	m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}


