#pragma once
#include "Common.h"
#include "Component.h"

namespace BONE_FRAMEWORK
{
	class CCamera
	{
	private:
		D3DXMATRIXA16 view;
		D3DXMATRIXA16 proj;
		D3DXVECTOR3 eyePt;
		D3DXVECTOR3 lookatPt;
		D3DXVECTOR3 upVec;

	public:
		CCamera();
		~CCamera();

		BOOL Create(LPDIRECT3DDEVICE9 _Device);
	};
}
