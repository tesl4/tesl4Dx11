//-----------------------------------------------------------------------------
// File: CGameObject.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "Mesh.h"
#include <vector>

CMesh::CMesh()
{
    m_nStride = sizeof(CVertex);
    m_nOffset = 0;
	m_d3dPrimitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_nReferences = 1;
}

CMesh::~CMesh()
{
    if (m_pd3dVertexBuffer) m_pd3dVertexBuffer->Release();
}

void CMesh::AddRef() 
{ 
	m_nReferences++; 
}

void CMesh::Release() 
{ 
	m_nReferences--; 
	if (m_nReferences == 0) delete this;
}

void CMesh::Render(ID3D11DeviceContext *pd3dDeviceContext)
{
	std::cout << "CMesh->";
    if (m_pd3dVertexBuffer) pd3dDeviceContext->IASetVertexBuffers(0, 1, &m_pd3dVertexBuffer, &m_nStride, &m_nOffset);
    pd3dDeviceContext->IASetPrimitiveTopology(m_d3dPrimitiveTopology);
    pd3dDeviceContext->Draw(m_nVertices, m_nOffset);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
CTriangleMesh::CTriangleMesh(ID3D11Device *pd3dDevice)
{
	m_nVertices = 3;
    m_nStride = sizeof(CVertex);
    m_nOffset = 0;
	m_d3dPrimitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	/*CVertex pVertices[3];
	pVertices[0] = CVertex(XMFLOAT3(0.0f, 0.5f, 0.0f));
	pVertices[1] = CVertex(XMFLOAT3(0.5f, -0.5f, 0.0f));
	pVertices[2] = CVertex(XMFLOAT3(-0.5f, -0.5f, 0.0f));*/

	std::vector<CVertex> pVertices =
	{
		CVertex(XMFLOAT3(0.0f, 0.5f, 0.0f)),
		CVertex(XMFLOAT3(0.5f, -0.5f, 0.0f)),
		CVertex(XMFLOAT3(-0.5f, -0.5f, 0.0f)),
	};


    D3D11_BUFFER_DESC d3dBufferDesc;
	ZeroMemory(&d3dBufferDesc, sizeof(D3D11_BUFFER_DESC));
    d3dBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    d3dBufferDesc.ByteWidth = m_nStride * m_nVertices;
    d3dBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	d3dBufferDesc.CPUAccessFlags = 0;
    
	D3D11_SUBRESOURCE_DATA d3dBufferData;
	ZeroMemory(&d3dBufferData, sizeof(D3D11_SUBRESOURCE_DATA));
    d3dBufferData.pSysMem = &pVertices[0];
    pd3dDevice->CreateBuffer(&d3dBufferDesc, &d3dBufferData, &m_pd3dVertexBuffer);
}

CTriangleMesh::~CTriangleMesh()
{

}

void CTriangleMesh::Render(ID3D11DeviceContext *pd3dDeviceContext)
{
	std::cout << "CTriangleMesh->";
	CMesh::Render(pd3dDeviceContext);
}
