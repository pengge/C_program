#include "stdafx.h"
#include "TRIANGLE3D.h"

#define RENDER_WIDTH	800
#define RENDER_HEIGHT	600

//------------------------------------------------------------------------------------
// 构造函数,初始化成员数据
//------------------------------------------------------------------------------------
TRIANGLE3D::TRIANGLE3D()
{
    m_d3d          = NULL;
    m_d3dDevice    = NULL;
    m_vertexBuffer = NULL;	
}

//------------------------------------------------------------------------------------
// 析构函数,释放direct3D资源
//------------------------------------------------------------------------------------
TRIANGLE3D::~TRIANGLE3D()
{
    ReleaseD3D();
}

//------------------------------------------------------------------------------------
// 释放Direct3D资源
//------------------------------------------------------------------------------------
void TRIANGLE3D::ReleaseD3D()
{
    SAFE_RELEASE(m_vertexBuffer);
    SAFE_RELEASE(m_d3dDevice);
    SAFE_RELEASE(m_d3d);
}

//------------------------------------------------------------------------------------
// 创建Direct3D接口对象和Direct3D设备
//------------------------------------------------------------------------------------
BOOL TRIANGLE3D::CreateD3DDevice(HWND hWnd, BOOL fullScreen)
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

//------------------------------------------------------------------------------------
// 使用自定义的顶点结构初始化顶点缓冲区
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

    // 创建定点缓冲区
    if(FAILED(m_d3dDevice->CreateVertexBuffer(3 * sizeof(CUSTOM_VERTEX), 0, 
		CUSTOM_VERTEX_FVF, D3DPOOL_MANAGED,  &m_vertexBuffer, NULL)))
        return FALSE;

    // 锁定数据范围，并获取指向缓冲区内存的指针
    if(FAILED(m_vertexBuffer->Lock(0, 0, (void**) &vertexData, 0)))
        return FALSE;

    // 拷贝顶点数据到缓冲区中
    memcpy(vertexData, customVertex, sizeof(customVertex));

    // 解锁顶点缓冲区
    m_vertexBuffer->Unlock();

    return TRUE;
}

//------------------------------------------------------------------------------------
// 渲染三角形面
//------------------------------------------------------------------------------------
void TRIANGLE3D::Render()
{
    if(m_d3dDevice == NULL)
        return;

    // 使用黑色色清除渲染目标
    m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0, 0);

    // 开始渲染绘制 
    m_d3dDevice->BeginScene();

    // 绑定顶点缓冲区到设备数据流
    m_d3dDevice->SetStreamSource(0, m_vertexBuffer, 0, sizeof(CUSTOM_VERTEX));

    // 设置当前顶点流的顶点格式
    m_d3dDevice->SetFVF(CUSTOM_VERTEX_FVF);

    // 渲染三角形面
    m_d3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

    // 结束渲染绘制
    m_d3dDevice->EndScene();

    // 为下一次缓冲区渲染做准备
    m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}