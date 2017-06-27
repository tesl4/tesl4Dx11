#pragma once
#include "Tesl4Obj.h"


class CShaderBase : public CTesl4Obj
{
protected:
	WCHAR* m_pFileName;
	ID3D11VertexShader*     m_pVertexShader;
	ID3D11PixelShader*      m_pPixelShader;
	ID3D11InputLayout*      m_pVertexLayout;

public:
	
	virtual bool CreateShader();
	bool CreateVertexShader(WCHAR* _fileName, LPCSTR _shaderName, LPCSTR _shaderModel, ID3D11VertexShader** _vertexShader, D3D11_INPUT_ELEMENT_DESC *_ilDescription, UINT _elements, ID3D11InputLayout **_inputLayout);
	bool CreatePixelShader(WCHAR *pszFileName, LPCSTR _shaderName, LPCSTR _shaderModel, ID3D11PixelShader **ppd3dPixelShader);
	

	void Render();
	
	CShaderBase();
	CShaderBase(WCHAR* _fileName);
	~CShaderBase();

	
};

