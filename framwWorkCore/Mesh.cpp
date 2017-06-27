#include "stdafx.h"
#include "Mesh.h"


void CMesh::Render()
{	
	if (m_Vertexbuffer) CRender::GetInstance()->GetContext()->IASetVertexBuffers(0, 1, &m_Vertexbuffer, &m_nStride, &m_nOffset);
	CRender::GetInstance()->GetContext()->IASetPrimitiveTopology(m_PrimitiveTopology);
	CRender::GetInstance()->GetContext()->Draw(m_Vertices.size(), m_nOffset);
}

CMesh::CMesh()
{
	//m_Vertices = new std::vector<CVertex>();
	m_nStride = sizeof(CVertex);
	m_nOffset = 0;
	m_PrimitiveTopology= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	m_Vertices = 
	{
		CVertex(XMFLOAT3(0.0f, 0.5f, 0.0f)),
		CVertex(XMFLOAT3(0.5f, -0.5f, 0.0f)),
		CVertex(XMFLOAT3(-0.5f, -0.5f, 0.0f)),
	};

	//m_Vertices->push_back(CVertex(XMFLOAT3(0.0f, 0.5f, 0.0f)));
	//m_Vertices->push_back(CVertex(XMFLOAT3(0.5f, -0.5f, 0.0f)));
	//m_Vertices->push_back(CVertex(XMFLOAT3(-0.5f, -0.5f, 0.0f)));
		
	
	D3D11_BUFFER_DESC d3dBufferDesc;
	ZeroMemory(&d3dBufferDesc, sizeof(D3D11_BUFFER_DESC));
	d3dBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	d3dBufferDesc.ByteWidth = m_nStride * m_Vertices.size();
	d3dBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	d3dBufferDesc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA d3dBufferData;
	ZeroMemory(&d3dBufferData, sizeof(D3D11_SUBRESOURCE_DATA));
	d3dBufferData.pSysMem = &m_Vertices[0];
	CRender::GetInstance()->GetDevice()->CreateBuffer(&d3dBufferDesc, &d3dBufferData, &m_Vertexbuffer);

	AddRef();
}


CMesh::~CMesh()
{

}
