#include "Player.h"


namespace BONE_FRAMEWORK
{
	CPlayer::CPlayer()
	{
	}

	CPlayer::~CPlayer()
	{
	}

	BOOL CPlayer::Initialize()
	{
		player = new CTexture();

		player->SetType("Texture");
		//player->CreateTexture("Texture/Character/background.jpg");

		this->AddComponent(player);

		return TRUE;
	}

	VOID CPlayer::Reference()
	{

	}

	VOID CPlayer::Update(double _timeDelta)
	{

	}

	VOID CPlayer::Render(double _timeDelta)
	{

	}

	VOID CPlayer::LateRender(double _timeDelta)
	{

	}
}
