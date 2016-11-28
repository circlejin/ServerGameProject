#include "BackGround.h"


namespace BONE_FRAMEWORK
{
	CBackGround::CBackGround()
	{
	}

	CBackGround::~CBackGround()
	{
	}

	BOOL CBackGround::Initialize()
	{
		backGround = new CTexture();

		backGround->SetType("Texture");
		backGround->CreateTexture("../Texture/Background/background.png");

		this->AddComponent(backGround);

		return TRUE;
	}

	VOID CBackGround::Reference()
	{

	}

	VOID CBackGround::Update(double _timeDelta)
	{
		
	}

	VOID CBackGround::Render(double _timeDelta)
	{
		
	}

	VOID CBackGround::LateRender(double _timeDelta)
	{

	}
}
