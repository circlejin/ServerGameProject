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

	HRESULT CTexture::CreateTexture(LPSTR _file)
	{
		if (FAILED(D3DXCreateTextureFromFile(CRenderManager::GetInstance()->d3dDevice, (LPCWSTR)_file, &texture)))
		{
			MessageBox(NULL, L"Texture Create Fail", L"Textures.exe", MB_OK);
			return E_FAIL;
		}

		return S_OK;
	}

	INT CTexture::GetImageWidth()
	{
		return textureInfo.Width;
	}

	INT CTexture::GetImageHeight()
	{
		return textureInfo.Height;
	}
}