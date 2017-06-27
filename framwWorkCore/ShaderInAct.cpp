#include "stdafx.h"
#include "ShaderInAct.h"


bool CShaderInAct::CreateShader()
{
	D3D11_INPUT_ELEMENT_DESC d3dInputLayout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	UINT nElements = ARRAYSIZE(d3dInputLayout);
	CreateVertexShader(m_pFileName, "VS", "vs_4_0", &m_pVertexShader, d3dInputLayout, nElements, &m_pVertexLayout);
	CreatePixelShader(m_pFileName, "PS", "ps_4_0", &m_pPixelShader);

	return true;
}

CShaderInAct::CShaderInAct() : CShaderBase()
{

}

CShaderInAct::CShaderInAct(WCHAR * _fileName) : CShaderBase(_fileName)
{
}

CShaderInAct::~CShaderInAct()
{

}
