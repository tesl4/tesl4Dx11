#include "stdafx.h"
#include "Triangles.h"


CTriangles::CTriangles() : CMesh::CMesh()
{
	m_Vertices = {
		CVertex(0.0f, 0.5f, 0.5f),
		CVertex(0.5f, -0.5f, 0.5f),
		CVertex(-0.5f, -0.5f, 0.5f),
	};

	D3D11_BUFFER_DESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(D3D11_BUFFER_DESC));
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(CVertex) * m_Vertices.size();
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA bufferData;
	ZeroMemory(&bufferData, sizeof(D3D11_SUBRESOURCE_DATA));
	bufferData.pSysMem = &m_Vertices[0];
	CRenderDX11::GetInstance()->GetDevice()->CreateBuffer(&bufferDesc, &bufferData, &m_VertextBuffer);



}


CTriangles::~CTriangles()
{
	
}

void CTriangles::Init()
{
	CMesh::Init();
}

void CTriangles::Render()
{
	std::cout << "CTriangleMesh->";
	CMesh::Render();
}
