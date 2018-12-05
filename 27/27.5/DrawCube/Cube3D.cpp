#include "stdafx.h"
#include "D3dx9math.h"
#include "Cube3D.h"


#define RENDER_WIDTH	800
#define RENDER_HEIGHT	600
//------------------------------------------------------------------------------------
// 构造函数, 初始化成员数据
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
// 析构函数，释放direct3D资源
//------------------------------------------------------------------------------------
Cube3D::~Cube3D()
{
    ReleaseD3D();
}

//------------------------------------------------------------------------------------
// 释放Direct3D资源
//------------------------------------------------------------------------------------
void Cube3D::ReleaseD3D()
{	
    SAFE_RELEASE(m_vertexBuffer);	
    SAFE_RELEASE(m_d3dDevice);
    SAFE_RELEASE(m_d3d);
}

//------------------------------------------------------------------------------------
// 创建Direct3D接口对象和Direct3D设备
//------------------------------------------------------------------------------------
BOOL Cube3D::CreateD3DDevice(HWND hWnd, BOOL fullScreen)
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
// 使用自定义的顶点结构初始化顶点缓冲区，并建立顶点索引缓冲区
//------------------------------------------------------------------------------------
BOOL Cube3D::InitVertexBuffer()
{
	CUSTOM_VERTEX customVertex[] = {
        {0.0,  0.0, 1.0,	D3DCOLOR_XRGB(255, 255, 0)},      // 顶点 0
        {-1.0, 0.0, 0.0,	D3DCOLOR_XRGB(255, 255, 0)},      // 顶点 1
        {0.0,  1.0, 0.0,	D3DCOLOR_XRGB(255, 255, 0)},      // 顶点 2
        {1.0,  0.0, 0.0,	D3DCOLOR_XRGB(255, 255, 0)},      // 顶点 3
        {0.0,  -1.0,0.0,	D3DCOLOR_XRGB(255, 255, 0)}		  // 顶点 4
    };

    BYTE* vertexData;

    // 创建顶点缓冲区
    if(FAILED(m_d3dDevice->CreateVertexBuffer(5 * sizeof(CUSTOM_VERTEX), 0, 
		CUSTOM_VERTEX_FVF, D3DPOOL_MANAGED,  &m_vertexBuffer, NULL)))
        return FALSE;

    // 锁定数据范围，并获取指向缓冲区内存的指针
    if(FAILED(m_vertexBuffer->Lock(0, 0, (void**) &vertexData, 0)))
        return FALSE;

    // 拷贝顶点数据到缓冲区中
    memcpy(vertexData, customVertex, sizeof(customVertex));

    // 解锁顶点缓冲区
    m_vertexBuffer->Unlock();

	// 创建顶点索引缓冲区
    if(FAILED(m_d3dDevice->CreateIndexBuffer(36 * sizeof(WORD), 0, 
		D3DFMT_INDEX16, D3DPOOL_MANAGED,  &m_indexBuffer, NULL)))
           return FALSE;
   
    // 锁定指定范围的索引数据，并获取索引缓冲区内存的指针
    WORD* index_data;
    if(FAILED(m_indexBuffer->Lock(0, 0, (void**) &index_data, 0)))
        return FALSE;

	index_data[0]=0;  index_data[1]=1;  index_data[2]=2;
    index_data[3]=0;  index_data[4]=2;  index_data[5]=3;
	index_data[6]=0;  index_data[7]=3;  index_data[8]=4;
	index_data[9]=0;  index_data[10]=4;  index_data[11]=1;

    // 解锁顶点索引缓冲区
    m_indexBuffer->Unlock();

    return TRUE;
}

//------------------------------------------------------------------------------------
// 渲染三角形面
//------------------------------------------------------------------------------------
void Cube3D::Render()
{
    if(m_d3dDevice == NULL)
        return;

    // 使用蓝色色清除渲染目标
    m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(155, 0, 155), 1.0, 0);

    // 开始渲染绘制 
    m_d3dDevice->BeginScene();

	// 使用线框填充对象
    m_d3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
    // 关闭灯光
   m_d3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    // 关闭背面剔除
    m_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

    // 绑定顶点缓冲区到设备数据流
    m_d3dDevice->SetStreamSource(0, m_vertexBuffer, 0, sizeof(CUSTOM_VERTEX));

	// 设置索引数据
    m_d3dDevice->SetIndices(m_indexBuffer);

    // 设置当前顶点流的顶点格式
    m_d3dDevice->SetFVF(CUSTOM_VERTEX_FVF);

	// 设置视口
    D3DVIEWPORT9 fullViewport;

    // 返回当前设备的视口参数
    m_d3dDevice->GetViewport(&fullViewport);

    D3DVIEWPORT9 topLeftViewport;

    topLeftViewport.Width  = fullViewport.Width / 5;
    topLeftViewport.Height = fullViewport.Height / 5;
    topLeftViewport.X      = 0;
    topLeftViewport.Y      = 0;
    topLeftViewport.MinZ   = 0;
    topLeftViewport.MaxZ   = 1;

    // 设置设备的视口
    m_d3dDevice->SetViewport(&topLeftViewport);
	// 根据索引，渲染立方体到顶点数组
    m_d3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST , 0, 0, 0, 0, 12);

	// 设置设备的视口
    m_d3dDevice->SetViewport(&fullViewport);
    // 根据索引，渲染立方体到顶点数组
    m_d3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

    // 渲染三角形面
    m_d3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

    // 结束渲染绘制
    m_d3dDevice->EndScene();

    // 为下一次缓冲区渲染做准备
    m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}

//------------------------------------------------------------------------------------
// 使用指定世界原点坐标系设置世界位置
//------------------------------------------------------------------------------------
void Cube3D::SetWorldPosition(float x, float y, float z)
{
    D3DXMATRIX worldMatrix;

    // 使用指定偏移量构建矩阵，对象放置在世界坐标(x, y, z)处
    D3DXMatrixTranslation(&worldMatrix, x, y, z);
    
    // 设置Direct3D设备的世界转换状态
    m_d3dDevice->SetTransform(D3DTS_WORLD, &worldMatrix);
}

//------------------------------------------------------------------------------------
// 设置摄影机位置
//------------------------------------------------------------------------------------
void Cube3D::SetCamera()
{
    D3DXVECTOR3 eye(2.0, 1.5, -3.0);
    D3DXVECTOR3 at(0.0, 0.0, 0.0);
    D3DXVECTOR3 up(0.0, 1.0, 0.0);

    D3DXMATRIX viewMatrix;

    // 生成左手视点的矩阵
    D3DXMatrixLookAtLH(&viewMatrix, &eye, &at, &up);

    // 设置Direct3D设备视图转换状态
    m_d3dDevice->SetTransform(D3DTS_VIEW, &viewMatrix);

    D3DXMATRIX projMatrix;

    // 生成左手投影
    D3DXMatrixPerspectiveFovLH(&projMatrix, D3DX_PI/2, 800/600, 1.0, 1000.0);
    
    // 设置Direct3D设备投影转换状态
    m_d3dDevice->SetTransform(D3DTS_PROJECTION, &projMatrix);
}

