//-----------------------------------------------------------------------------
// File: Shader.h
//-----------------------------------------------------------------------------

#pragma once

#include "Object.h"

class CShader
{
public:
    CShader();
    virtual ~CShader();

	void CreateVertexShaderFromFile(ID3D11Device *pd3dDevice, WCHAR *pszFileName, LPCSTR pszShaderName, LPCSTR pszShaderModel, ID3D11VertexShader **ppd3dVertexShader, 
		D3D11_INPUT_ELEMENT_DESC *pd3dInputLayout, UINT nElements, ID3D11InputLayout **ppd3dVertexLayout);
	void CreatePixelShaderFromFile(ID3D11Device *pd3dDevice, WCHAR *pszFileName, LPCSTR pszShaderName, LPCSTR pszShaderModel, ID3D11PixelShader **ppd3dPixelShader);

	virtual void CreateShader(ID3D11Device *pd3dDevice, int nObjects);
	virtual void Render(ID3D11DeviceContext *pd3dDeviceContext);

public:
	ID3D11VertexShader				*m_pd3dVertexShader;
	ID3D11InputLayout				*m_pd3dVertexLayout;

	ID3D11PixelShader				*m_pd3dPixelShader;
};

class CObjectShader : public CShader
{
public:
    CObjectShader();
    virtual ~CObjectShader();

	virtual void CreateShader(ID3D11Device *pd3dDevice, int nObjects);
	virtual void Render(ID3D11DeviceContext *pd3dDeviceContext);

private:
	CGameObject						**m_ppObjects;       
	int								m_nObjects;
	int								m_nIndexToAdd;

public:
	void AddObject(CGameObject *pObject); 
};
