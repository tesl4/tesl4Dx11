//------------------------------------------------------- ----------------------
// File: Mesh.h
//-----------------------------------------------------------------------------

#pragma once

class CVertex
{
	XMFLOAT3 m_vPosition;

    //D3DXVECTOR3						m_d3dxvPosition;		
public:
	CVertex() { m_vPosition = XMFLOAT3(0, 0, 0); }
	CVertex(XMFLOAT3 d3dxvPosition) { m_vPosition = d3dxvPosition; }
	~CVertex() { }
};

class CMesh
{
private:
	int								m_nReferences;

protected:
	ID3D11Buffer					*m_pd3dVertexBuffer;

	D3D11_PRIMITIVE_TOPOLOGY		m_d3dPrimitiveTopology;

	UINT							m_nVertices;
	UINT							m_nStride;
	UINT							m_nOffset;

public:
    CMesh();
    virtual ~CMesh();

	void AddRef();
	void Release();

	virtual void Render(ID3D11DeviceContext *pd3dDeviceContext);
};

class CTriangleMesh : public CMesh
{
public:
    CTriangleMesh(ID3D11Device *pd3dDevice);
    virtual ~CTriangleMesh();

	virtual void Render(ID3D11DeviceContext *pd3dDeviceContext);
};
