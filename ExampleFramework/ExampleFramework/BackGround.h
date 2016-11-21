#pragma once
#include "Common.h"
#include "GameObject.h"
#include "Texture.h"

namespace BONE_FRAMEWORK
{
	class CBackGround : public CGameObject
	{
	private:
		CTexture *backGround;
	public:
		CBackGround();
		~CBackGround();

		virtual BOOL Initialize();
		virtual VOID Reference();
		virtual VOID Update(double _timeDelta);

		VOID Render(double _timeDelta);
		virtual VOID LateRender(double _timeDelta);
	};
}
