#pragma once
#include "Tesl4Obj.h"

class CVertex;

class CMesh : public CTesl4Obj
{
	ID3D11Buffer				*m_Vertexbuffer;
	std::vector<CVertex>		m_Vertices;
	D3D11_PRIMITIVE_TOPOLOGY	m_PrimitiveTopology;

	UINT	m_nStride;
	UINT	m_nOffset;	

public:
	
	void Render();
	
	CMesh();
	virtual ~CMesh();
};

