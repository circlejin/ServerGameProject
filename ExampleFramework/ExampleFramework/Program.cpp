#include "Common.h"
#include "Interface.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "BackGround.h"
#include "Player.h"
#include "SmartPointer.h"

using namespace BONE_FRAMEWORK;

#define RenderManager CRenderManager::GetInstance()

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd = FastCreateWindow(hInstance, "RPG GAME", 1024, 768);
	
	CRenderManager::GetInstance()->InitializeMembers();
	CSceneManager::GetInstance()->InitializeMembers();

	{
		CRenderManager::GetInstance()->Create(hWnd);

		SmartPointer<CBackGround> backGround;
		//SmartPointer<CPlayer> player;

		SmartPointer<CScene> scene;

		scene->InitializeMembers();
		
		scene->RegisterGameObject(backGround, false);
		//scene->RegisterGameObject(player, false);

		CSceneManager::GetInstance()->RegisterScene(scene, "mainScene");
		CSceneManager::GetInstance()->Start("mainScene");

		scene->ReleaseMembers();
	}
	
	CSceneManager::GetInstance()->ReleaseMembers();
	CRenderManager::GetInstance()->ReleaseMembers();

	return 0;
}