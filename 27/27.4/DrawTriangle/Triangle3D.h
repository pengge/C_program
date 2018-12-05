#ifndef TRIANGLE_3D_H
#define TRIANGLE_3D_H
#include "D3d9types.h"
#include "D3D9.h"

#define CUSTOM_VERTEX_FVF   (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct CUSTOM_VERTEX
{
    float x, y, z, rhw;
    D3DCOLOR color; 
};

class TRIANGLE3D
{
private:
    IDirect3D9* m_d3d;
    IDirect3DDevice9* m_d3dDevice;
    IDirect3DVertexBuffer9* m_vertexBuffer;
	

public:
    TRIANGLE3D();
    ~TRIANGLE3D();
    BOOL CreateD3DDevice(HWND hWnd, BOOL fullScreen = TRUE);
    BOOL InitVertexBuffer();
    void Render();
    void ReleaseD3D();
};

#endif