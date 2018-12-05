#include "stdafx.h"
#include "XFILE3D.h"
#include "D3dx9tex.h"

#define RENDER_WIDTH	800
#define RENDER_HEIGHT	600

//------------------------------------------------------------------------------------
// 构造函数,初始化成员数据
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
// 析构函数,释放direct3D资源
//------------------------------------------------------------------------------------
XFILE3D::~XFILE3D()
{
    ReleaseD3D();
}

//------------------------------------------------------------------------------------
// 释放Direct3D资源
//------------------------------------------------------------------------------------
void XFILE3D::ReleaseD3D()
{
    
    SAFE_RELEASE(m_d3dDevice);
    SAFE_RELEASE(m_d3d);
}

//------------------------------------------------------------------------------------
// 创建Direct3D接口对象和Direct3D设备
//------------------------------------------------------------------------------------
BOOL XFILE3D::CreateD3DDevice(HWND hWnd, BOOL fullScreen)
{
    // 创建Direct3D接口对象，并返回接口
    m_d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if(m_d3d == NULL)
        return FALSE;

    // 检测适配器功能
    D3DCAPS9 d3dCaps;    
    m_d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);
    
	BOOL hp;//是否支持硬件配置
	if(d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)  hp = TRUE;	
	else hp = FALSE;	

    // 获取适配器的当前显示模式
    D3DDISPLAYMODE display_mode;
    if(FAILED(m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display_mode)))
        return FALSE;

	// 设置Direct3D设备的当前参数
    D3DPRESENT_PARAMETERS param = {0};	

    param.BackBufferWidth      = RENDER_WIDTH;
    param.BackBufferHeight     = RENDER_HEIGHT;
    param.BackBufferFormat     = display_mode.Format;
    param.BackBufferCount      = 1;
    param.hDeviceWindow        = hWnd;
    param.Windowed             = !fullScreen;
    param.SwapEffect           = D3DSWAPEFFECT_FLIP;
    param.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

    // 创建代表显示适配器的设备
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
	// 从DirectX的X文件中装载网格
	if(FAILED(D3DXLoadMeshFromX(filename, D3DXMESH_MANAGED,  
		m_d3dDevice,   &m_AdjacencyBuffer,
		&m_MaterialBuffer,  NULL,  &m_MaterialsNum, &m_Mesh)))           
	{        
		MessageBox(NULL, "装载X文件失败", "错误", MB_OK);        
		return FALSE;    
	}
	if (m_MaterialBuffer==NULL || m_MaterialsNum == 0)   return FALSE;
	// 获取网格中的材质
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
	// 清除原有的网格
	m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	// 启动绘制
    m_d3dDevice->BeginScene();
	// 绘制所有网格三角面 
	for(DWORD i = 0; i < m_MaterialsNum; i++)   
	{        
		// 设置设备的材质属性
        m_d3dDevice->SetMaterial(&m_MaterialArray[i]);
        // 设置设备的纹理
		if (m_TextureArray[i] != NULL)
			m_d3dDevice->SetTexture(0, m_TextureArray[i]);
        // 绘制具有相同子集ID的网格
		m_Mesh->DrawSubset(i);    
	}
	// 结束绘制
    m_d3dDevice->EndScene();
    // 准备下一次渲染    
	m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}


