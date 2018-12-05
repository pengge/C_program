#ifndef XFILE_3D_H
#define XFILE_3D_H
#include "D3d9types.h"
#include "D3D9.h"
#include "D3DX9Mesh.h"

#define CUSTOM_VERTEX_FVF   (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct CUSTOM_VERTEX
{
    float x, y, z, rhw;
    D3DCOLOR color; 
};

class XFILE3D
{
private:
    IDirect3D9* m_d3d;
    IDirect3DDevice9* m_d3dDevice;
	ID3DXBuffer*  m_AdjacencyBuffer;	// ���ӻ�����
	ID3DXBuffer*  m_MaterialBuffer;		// ���ʻ�����
	D3DMATERIAL9*  m_MaterialArray;		// ��������
	IDirect3DTexture9**  m_TextureArray;// ��������
	DWORD    m_MaterialsNum;			// ������Ŀ
	ID3DXMesh*  m_Mesh;					// �������
//    IDirect3DVertexBuffer9* m_vertexBuffer;	

public:
    XFILE3D();
    ~XFILE3D();
    BOOL CreateD3DDevice(HWND hWnd, BOOL fullScreen = TRUE); 
	BOOL LoadXFile(char* filename);
    void Render();
    void ReleaseD3D();
};

#endif