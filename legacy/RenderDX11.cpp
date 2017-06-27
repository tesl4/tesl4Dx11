#include "stdafx.h"
#pragma once

CRenderDX11* CRenderDX11::m_instance = nullptr;

CRenderDX11::CRenderDX11()
{
}

CRenderDX11::~CRenderDX11()
{
}

CRenderDX11* CRenderDX11::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CRenderDX11();
	}

	if(m_instance != nullptr) return m_instance;

	return nullptr;
}

HRESULT CRenderDX11::Init(HWND _hWnd)
{
	HRESULT res = S_OK;
	RECT rect;
	
	//WinPlatform
	GetClientRect(_hWnd, &rect);
	m_Width  = rect.right - rect.left;
	m_Height = rect.bottom - rect.top;

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = m_Width;
	sd.BufferDesc.Height = m_Height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = _hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;


	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		m_driverType = driverTypes[driverTypeIndex];
		res = D3D11CreateDeviceAndSwapChain(NULL, m_driverType, NULL, createDeviceFlags, 
			featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &sd, &m_pSwapChain, 
			&m_pDevice, &m_FeatureLv, &m_pIContext);
		if (SUCCEEDED(res))
			break;
	}
	
	if (FAILED(res) == false)
	{
		//create render target
		res = CreateRenderTargetView();
		if (SUCCEEDED(res))
		{
			SetViewport();
		}
	}


	return res;
}

void CRenderDX11::DrawStart()
{
	float ClearColor[4] = { 0.67f, 0.39f, 0.48f, 1.0f }; //red,green,blue,alpha
	m_pIContext->ClearRenderTargetView(m_pRenderTargetView, ClearColor);
	std::cout << "s";
}

void CRenderDX11::DrawEnd()
{
	m_pSwapChain->Present(0, 0);
	std::cout << "e" << std::endl;

}

bool CRenderDX11::CreateRenderTargetView()
{
	HRESULT res = S_OK;

	ID3D11Texture2D *pd3dBackBuffer;
	if (FAILED(res = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *)&pd3dBackBuffer))) return(false);
	if (FAILED(res = m_pDevice->CreateRenderTargetView(pd3dBackBuffer, NULL, &m_pRenderTargetView))) return(false);
	if (pd3dBackBuffer) pd3dBackBuffer->Release();

	m_pIContext->OMSetRenderTargets(1, &m_pRenderTargetView, NULL);

	return false;
}

HRESULT CRenderDX11::Cleanup()
{
	if (m_pIContext)		 m_pIContext->ClearState();
	if (m_pRenderTargetView) m_pRenderTargetView->Release();
	if (m_pSwapChain)		 m_pSwapChain->Release();
	if (m_pIContext)		 m_pIContext->Release();
	if (m_pDevice)			 m_pDevice->Release();
	return false;
}

ID3D11Device * CRenderDX11::GetDevice()
{
	return m_pDevice;
}

ID3D11DeviceContext* CRenderDX11::GetDeviceContext()
{
	return m_pIContext;
}

void CRenderDX11::SetViewport()
{
	D3D11_VIEWPORT viewport;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = m_Width;
	viewport.Height = m_Height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	m_pIContext->RSSetViewports(1, &viewport);
}


bool CRenderDX11::IsInitialized()
{
	return m_pDevice != nullptr;
}


