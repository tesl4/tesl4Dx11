#include "stdafx.h"
#pragma once

CMesh::CMesh()
{
	m_strides = sizeof(CVertex);
	m_offset = 0;
	m_PrimeTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	m_RefCount = 1;


	
}

CMesh::~CMesh()
{
	if (m_VertextBuffer != nullptr) m_VertextBuffer->Release();
}

void CMesh::Init()
{
	
}

void CMesh::Render()
{
	std::cout << "CMesh->";
	if (m_VertextBuffer != nullptr) CRenderDX11::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertextBuffer, &m_strides, &m_offset);
	CRenderDX11::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(m_PrimeTopology);
	CRenderDX11::GetInstance()->GetDeviceContext()->Draw(m_Vertices.size(), m_offset);
	
}

void CMesh::AddRef()
{
	m_RefCount++;
}

void CMesh::Release()
{
	m_RefCount--;
	if (m_RefCount < 1) delete this;
}
