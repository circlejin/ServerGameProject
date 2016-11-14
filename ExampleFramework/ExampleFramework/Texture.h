#pragma once
#include "Component.h"

namespace BONE_FRAMEWORK
{
	class CTexture : public CComponent
	{
	private:
		LPDIRECT3DTEXTURE9 texture;
		D3DXIMAGE_INFO textureInfo;
	public:
		CTexture();
		~CTexture();

		INT GetImageWidth();
		INT GetImageHeight();
		HRESULT CreateTexture(LPSTR _file);
	};
}

