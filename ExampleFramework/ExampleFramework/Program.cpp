#include "Common.h"
#include "Interface.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderManager.h"
using namespace BONE_FRAMEWORK;

#define RenderManager CRenderManager::GetInstance()

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd = FastCreateWindow(hInstance, "RPG GAME", 1280, 1024);
	
	CRenderManager::GetInstance()->InitializeMembers();
	CSceneManager::GetInstance()->InitializeMembers();

	{
		CRenderManager::GetInstance()->Create(hWnd);
		CScene* scene = new CScene();

		scene->InitializeMembers();

		CSceneManager::GetInstance()->RegisterScene(scene, "mainScene");
		CSceneManager::GetInstance()->Start("mainScene");

		//scene->ReleaseMembers();
	}
	CRenderManager::GetInstance()->ReleaseMembers();
	CSceneManager::GetInstance()->ReleaseMembers();

	return 0;
}