#include "Camera.h"


namespace BONE_FRAMEWORK
{
	CCamera::CCamera()
	{
	}


	CCamera::~CCamera()
	{
	}

	BOOL CCamera::Create(LPDIRECT3DDEVICE9 _Device)
	{
		eyePt = D3DXVECTOR3(0.0f, 3.0f, -5.0f);
		lookatPt = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		upVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		D3DXMatrixLookAtLH(&view, &eyePt, &lookatPt, &upVec);
		_Device->SetTransform(D3DTS_VIEW, &view);

		D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
		_Device->SetTransform(D3DTS_PROJECTION, &proj);

		return TRUE;
	}
}