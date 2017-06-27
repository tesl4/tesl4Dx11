#include "stdafx.h"

#pragma once
extern HWND hWnd;


class ID3D11Device;
class ID3D11DeviceContext;
class IDXGISwapChain;
class ID3D11RenderTargetView;


class CRender/* : public CSingleton<CRender>*/
{
private:
	static CRender *m_Instance;

	ID3D11Device			*m_pDevice;
	ID3D11DeviceContext		*m_pContext;
	IDXGISwapChain			*m_pSwapChain;
	ID3D11RenderTargetView	*m_pRenderTargetView;

	UINT m_uiWidth;
	UINT m_uiHeight;

	D3D_DRIVER_TYPE			m_DriverType;
	D3D_FEATURE_LEVEL		m_FeatureLevel;

	
public:
	static CRender* GetInstance();

	void InitializeRender();
	void RenderStart();
	void RenderEnd();
	void SetClientSize(UINT _width, UINT _height);


	ID3D11Device*			GetDevice();
	ID3D11DeviceContext*	GetContext();
	IDXGISwapChain*			GetSwapChain();
	ID3D11RenderTargetView* GetRenderTargetView();

	HRESULT	CreateRenderTargetView();
	void SetViewport();


	CRender() {};
	~CRender() {};
};

