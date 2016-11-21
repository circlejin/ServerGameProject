#include "Texture.h"
#include "RenderManager.h"

namespace BONE_FRAMEWORK
{
	CTexture::CTexture()
		:texture(NULL)
	{
		ZeroMemory(&textureInfo, sizeof(textureInfo));
	}


	CTexture::~CTexture()
	{
	}

	INT CTexture::GetImageWidth()
	{
		return textureInfo.Width;
	}

	INT CTexture::GetImageHeight()
	{
		return textureInfo.Height;
	}

	HRESULT CTexture::CreateTexture(LPSTR _file)
	{
		if (FAILED(D3DXCreateTextureFromFileEx(CRenderManager::GetInstance()->d3dDevice, 
			(LPCWSTR)_file,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_FILTER_NONE,
			NULL,
			&textureInfo,	//D3DXIMAGE_INFO안에 있는 width와 height에 이미지 크기가 저장된다.
			NULL,
			&texture)))
		{
			MessageBox(NULL, L"Texture Create Fail", L"Textures.exe", MB_OK);
			return E_FAIL;
		}

		return S_OK;
	}
}