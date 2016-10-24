#pragma once
#include "Common.h"
#include "Singleton.h"

namespace BONE_FRAMEWORK
{
	struct CUSTOMVERTEX
	{
		FLOAT x, y, z, rhw;
		DWORD color;
	};

	class CRenderManager : public ISingleton<CRenderManager>
	{
	private:
		LPDIRECT3D9			g_pD3D;
		LPDIRECT3DDEVICE9	g_pd3dDevice;
		LPDIRECT3DVERTEXBUFFER9 g_pVB;

	public:
		virtual BOOL InitializeMembers();
		virtual BOOL ReleaseMembers();

		HRESULT InitD3D(HWND _hWnd);
		HRESULT InitVB();
		VOID Render();
	};
}
