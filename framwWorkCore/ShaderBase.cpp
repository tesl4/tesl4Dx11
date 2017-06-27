#include "stdafx.h"
#include "ShaderBase.h"


bool CShaderBase::CreateShader()
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

bool CShaderBase::CreateVertexShader(WCHAR * _fileName, LPCSTR _shaderName, LPCSTR _shaderModel, ID3D11VertexShader ** _vertexShader, D3D11_INPUT_ELEMENT_DESC * _ilDescription, UINT _elements, ID3D11InputLayout ** _inputLayout)
{
	DWORD _shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(DEBUG) || defined(_DEBUG)
	_shaderFlags |= D3DCOMPILE_DEBUG;
#endif
	ID3DBlob *_ShaderBlob = nullptr;
	ID3DBlob *_errorBlob = nullptr;
	if (SUCCEEDED(D3DX11CompileFromFile(_fileName, nullptr, nullptr, _shaderName, _shaderModel, _shaderFlags, 0, nullptr, &_ShaderBlob, &_errorBlob, nullptr)))
	{
		(CRender::GetInstance()->GetDevice()->CreateVertexShader(_ShaderBlob->GetBufferPointer(), _ShaderBlob->GetBufferSize(), nullptr, _vertexShader));
		(CRender::GetInstance()->GetDevice()->CreateInputLayout(_ilDescription, _elements, _ShaderBlob->GetBufferPointer(), _ShaderBlob->GetBufferSize(), _inputLayout));
		_ShaderBlob->Release();
		return true;
	}
	return false;
}

bool CShaderBase::CreatePixelShader(WCHAR * _fileName, LPCSTR _shaderName, LPCSTR _shaderModel, ID3D11PixelShader ** _pixelShader)
{
	DWORD _shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(DEBUG) || defined(_DEBUG)
	_shaderFlags |= D3DCOMPILE_DEBUG;
#endif
	ID3DBlob *_ShaderBlob = nullptr;
	ID3DBlob *_errorBlob = nullptr;
	if (SUCCEEDED(D3DX11CompileFromFile(_fileName, nullptr, nullptr, _shaderName, _shaderModel, _shaderFlags, 0, nullptr, &_ShaderBlob, &_errorBlob, nullptr)))
	{
		CRender::GetInstance()->GetDevice()->CreatePixelShader(_ShaderBlob->GetBufferPointer(), _ShaderBlob->GetBufferSize(), nullptr, _pixelShader);
		_ShaderBlob->Release();
		return true;
	}
	return false;
}

void CShaderBase::Render()
{
	if (m_pVertexLayout != nullptr)		CRender::GetInstance()->GetContext()->IASetInputLayout(m_pVertexLayout);
	if (m_pVertexShader != nullptr)		CRender::GetInstance()->GetContext()->VSSetShader(m_pVertexShader, nullptr, 0);
	if(m_pPixelShader != nullptr)		CRender::GetInstance()->GetContext()->PSSetShader(m_pPixelShader, nullptr, 0);

}

CShaderBase::CShaderBase()
{
	m_pVertexShader = nullptr;
	m_pVertexLayout = nullptr;
	m_pPixelShader = nullptr;
}

CShaderBase::CShaderBase(WCHAR * _fileName) : m_pFileName(_fileName)
{
	m_pVertexShader = nullptr;
	m_pVertexLayout = nullptr;
	m_pPixelShader = nullptr;
}

CShaderBase::~CShaderBase()
{
	if(m_pVertexShader != nullptr) m_pVertexShader->Release();
	if(m_pVertexLayout != nullptr) m_pVertexLayout->Release();
	if(m_pPixelShader != nullptr) m_pPixelShader->Release();
}


