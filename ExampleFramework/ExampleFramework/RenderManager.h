#pragma once
#include "Common.h"
#include "Singleton.h"

namespace BONE_FRAMEWORK
{
	class CRenderManager : public ISingleton<CRenderManager>
	{
	private:
		LPDIRECT3D9			d3d9;
	public:
		LPDIRECT3DDEVICE9	d3dDevice;
		LPD3DXSPRITE		d3dSprite;

		virtual BOOL InitializeMembers();
		virtual BOOL ReleaseMembers();

		HRESULT Create(HWND _hWnd);

		BOOL RenderStart();
		VOID RenderFinish();
	};
}
