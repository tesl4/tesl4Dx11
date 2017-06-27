#include "stdafx.h"
#include "ShaderBase.h"


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

CShaderBase::~CShaderBase()
{
	if(m_pVertexShader != nullptr) m_pVertexShader->Release();
	if(m_pVertexLayout != nullptr) m_pVertexLayout->Release();
	if(m_pPixelShader != nullptr) m_pPixelShader->Release();
}


