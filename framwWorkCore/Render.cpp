#include "stdafx.h"
#include "Render.h"
#include "Singleton.h"


void CRender::InitializeRender(HWND _hwnd)
{
	HRESULT res = S_OK;

	RECT _rct;
	GetClientRect(_hwnd, &_rct);
	m_uiWidth  = _rct.right	 - _rct.left;
	m_uiHeight = _rct.bottom - _rct.top;

	UINT _deviceFlag = 0;
#ifdef DEBUG
	_deviceFlag |= D3D11_CREATE_DEVICE_DEBUG;
#endif // DEBUG

	D3D_DRIVER_TYPE _driverTps[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT _numDriverTps = ARRAYSIZE(_driverTps);

	D3D_FEATURE_LEVEL _featureLvs[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT _numfeatureLvs = ARRAYSIZE(_featureLvs);

	DXGI_SWAP_CHAIN_DESC _swapchainDesc;
	ZeroMemory(&_swapchainDesc, sizeof(_swapchainDesc));
	_swapchainDesc.BufferCount = 1;
	_swapchainDesc.BufferDesc.Width = m_uiWidth;
	_swapchainDesc.BufferDesc.Height = m_uiHeight;
	_swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	_swapchainDesc.BufferDesc.RefreshRate.Numerator = 60;
	_swapchainDesc.BufferDesc.RefreshRate.Denominator = 1;
	_swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	_swapchainDesc.OutputWindow = hWnd;
	_swapchainDesc.SampleDesc.Count = 1;
	_swapchainDesc.SampleDesc.Quality = 0;
	_swapchainDesc.Windowed = TRUE;

	for (auto type : _driverTps)
	{
		m_DriverType = type;
		res = D3D11CreateDeviceAndSwapChain(nullptr, m_DriverType, nullptr, _deviceFlag, _featureLvs, _numfeatureLvs, D3D11_SDK_VERSION, &_swapchainDesc, &m_pSwapChain, &m_pDevice, &m_FeatureLevel, &m_pContext);
		if (SUCCEEDED(res))
		{
			break;
		}
	}
	if (FAILED(res)) return;
	

	//CreateRenderTarget
	ID3D11Texture2D* _backBufferTex2d = nullptr;
	res = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&_backBufferTex2d);
	if (FAILED(res)) return;

	res = m_pDevice->CreateRenderTargetView(_backBufferTex2d, nullptr, &m_pRenderTargetView);
	_backBufferTex2d->Release();
	if (FAILED(res)) return;

	m_pContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);
	
	//SetViewport
	D3D11_VIEWPORT _viewport;
	_viewport.Width = (float)m_uiWidth;
	_viewport.Height = (float)m_uiHeight;
	_viewport.MinDepth = 0.0f;
	_viewport.MaxDepth = 1.0f;
	_viewport.TopLeftX = 0;
	_viewport.TopLeftY = 0;
	m_pContext->RSSetViewports(1, &_viewport);
}



void CRender::RenderStart()
{
}

void CRender::RenderEnd()
{
}

ID3D11Device * CRender::GetDevice()
{
	return m_pDevice;
}

ID3D11DeviceContext * CRender::GetContext()
{
	return m_pContext;
}

