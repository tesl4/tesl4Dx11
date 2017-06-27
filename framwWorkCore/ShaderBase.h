#pragma once
#include "Tesl4Obj.h"


class CShaderBase : public CTesl4Obj
{
	ID3D11VertexShader*     m_pVertexShader;	
	ID3D11PixelShader*      m_pPixelShader;
	ID3D11InputLayout*      m_pVertexLayout;


public:
	
	void Render();
	
	CShaderBase();
	~CShaderBase();

	
};

