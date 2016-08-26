//----------------------------------------------------------------
//1������Ĵ�����ɾ������SoD3DTextureManager����
//2��������ͼ�����¼��ַ�ʽ��
//   a)��̬��ͼ���Ӵ����ϼ���һ��ͼƬ��Ϊ��ͼ��
//   b)��̬��ͼ������һ���ڴ棬��̬����PixelData��
//3�����ɸ��߼�ʹ��ͬһ����ͼ�������Ƿǳ��ձ�ġ���������������ü������ܣ�
//   ��SoD3DTextureManager�л��ж����ü������������Ϊ0��ɾ����ͼ����
//----------------------------------------------------------------
#include "SoD3DTexture.h"
#include "SoD3DSystem.h"
//----------------------------------------------------------------
SoD3DTexture::SoD3DTexture()
:m_pTexture2D(NULL)
,m_pTextureSRV(NULL)
,m_nTextureID(-1)
,m_nTextureWidth(0)
,m_nTextureHeight(0)
,m_nRefCount(0)
{

}
//----------------------------------------------------------------
SoD3DTexture::~SoD3DTexture()
{
	ClearD3DTexture();
}
//----------------------------------------------------------------
bool SoD3DTexture::InitD3DTextureFromFile(SoD3DTexture::stInitParamFromFile& kParam)
{
	if (kParam.szFileName == 0 || kParam.szFileName[0] == 0)
	{
		return false;
	}
	if (SoD3DSystem::Get() == NULL)
	{
		return false;
	}
	ID3D11Device* pD3DDevice = SoD3DSystem::Get()->GetD3DDevice();
	if (pD3DDevice == NULL)
	{
		return false;
	}

	HRESULT hr = S_OK;
	hr = D3DX11CreateShaderResourceViewFromFile(pD3DDevice, kParam.szFileName, &kParam.kLoadInfo, NULL, &m_pTextureSRV, NULL);
	if (FAILED(hr))
	{
		return false;
	}

	m_pTextureSRV->GetResource((ID3D11Resource**)&m_pTexture2D);
	if (m_pTexture2D == NULL)
	{
		ClearD3DTexture();
		return false;
	}

	D3D11_TEXTURE2D_DESC texDesc;
	m_pTexture2D->GetDesc(&texDesc);
	m_nTextureWidth = (int)texDesc.Width;
	m_nTextureHeight = (int)texDesc.Height;
	return true;
}
//----------------------------------------------------------------
bool SoD3DTexture::InitD3DTextureDynamic(stInitParamDynamic& kParam)
{
	if (SoD3DSystem::Get() == NULL)
	{
		return false;
	}
	ID3D11Device* pD3DDevice = SoD3DSystem::Get()->GetD3DDevice();
	if (pD3DDevice == NULL)
	{
		return false;
	}

	HRESULT hr = pD3DDevice->CreateTexture2D(&kParam.kTexture2DDesc, &kParam.kResourceData, &m_pTexture2D);
	if (FAILED(hr))
	{
		return false;
	}

	hr = pD3DDevice->CreateShaderResourceView(m_pTexture2D, NULL, &m_pTextureSRV);
	if (FAILED(hr))
	{
		ClearD3DTexture();
		return false;
	}

	m_nTextureWidth = (int)kParam.kTexture2DDesc.Width;
	m_nTextureHeight = (int)kParam.kTexture2DDesc.Height;
	return true;
}
//----------------------------------------------------------------
void SoD3DTexture::ClearD3DTexture()
{
	if (m_pTexture2D)
	{
		m_pTexture2D->Release();
		m_pTexture2D = NULL;
	}
	if (m_pTextureSRV)
	{
		m_pTextureSRV->Release();
		m_pTextureSRV = NULL;
	}
	m_nTextureID = -1;
	m_nTextureWidth = 0;
	m_nTextureHeight = 0;
	m_nRefCount = 0;
}
//----------------------------------------------------------------
bool SoD3DTexture::SetDynamicTexturePixelData(void* pPixelData, int m_nSizeOfPixelData)
{
	if (pPixelData == NULL)
	{
		return false;
	}
	if (m_pTexture2D == NULL)
	{
		return false;
	}
	if (SoD3DSystem::Get() == NULL)
	{
		return false;
	}
	ID3D11DeviceContext* pD3DDeviceContext = SoD3DSystem::Get()->GetD3DDeviceContext();
	if (pD3DDeviceContext == NULL)
	{
		return false;
	}

	D3D11_MAPPED_SUBRESOURCE kMappedResource;
	memset(&kMappedResource, 0, sizeof(kMappedResource));
	HRESULT hr = pD3DDeviceContext->Map(m_pTexture2D, 0, D3D11_MAP_WRITE_DISCARD, 0, &kMappedResource);
	if (SUCCEEDED(hr))
	{
		memcpy(kMappedResource.pData, pPixelData, m_nSizeOfPixelData);
		pD3DDeviceContext->Unmap(m_pTexture2D, 0);
	}
	return SUCCEEDED(hr);
}
//----------------------------------------------------------------
