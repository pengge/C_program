#ifndef CUBE_3D_H
#define CUBE_3D_H
#include "D3d9types.h"
#include "D3D9.h"

#define CUSTOM_VERTEX_FVF   (D3DFVF_XYZ | D3DFVF_DIFFUSE)

struct CUSTOM_VERTEX
{
    float x, y, z;
    D3DCOLOR color; 
};

class Cube3D
{
private:
    IDirect3D9* m_d3d;
    IDirect3DDevice9* m_d3dDevice;
	IDirect3DVertexBuffer9* m_vertexBuffer;
    IDirect3DIndexBuffer9* m_indexBuffer;

public:
    float m_curX, m_curY, m_curZ;
public:
	Cube3D();
    ~Cube3D();

public:
      
    BOOL CreateD3DDevice(HWND hWnd, BOOL fullScreen = TRUE);
    BOOL InitVertexBuffer();
	void SetWorldPosition(float x, float y, float z);
    void SetCamera();
    void Render();
    void ReleaseD3D();
};

#endif