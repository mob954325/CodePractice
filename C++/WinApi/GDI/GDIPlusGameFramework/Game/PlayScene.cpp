#include "../GDIEngineLib/GameTime.h"
#include "../GDIEngineLib/SceneManager.h"

#include "PlayScene.h"
#include "Collider.h"
#include "Player.h"
#include "Enemy.h"
#include "ScoreManager.h"
#include "TextManager.h"

void PlayScene::Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
{
	this->hwnd = hwnd;
	this->FrontBufferDC = frontBufferDC;	// 앞면 DC
	this->BackBufferDC = backBufferDC;	// 뒷면 DC

	Gdiplus::GdiplusStartup(&gdiPlusToken, &gsi, nullptr);
	this->graphics = Gdiplus::Graphics::FromHDC(BackBufferDC);

	srand((int)time(NULL));
	for (int i = 0; i < enemyCount; i++)
	{
		Enemy* enemy = new Enemy(graphics);

		int randX = rand() % 1024;
		int randY = rand() % 1024;
		enemy->transform->SetTransform((float)randX, (float)randY);

		gameObjectList.push_back(enemy);
	}

	currEnemyCount = enemyCount;
	gameObjectList.push_back(new Player(graphics));

	g_TextManager.Initialize(this->graphics);

	g_ScoreManager.ResetData();
	sceneTimer = 0;
}

void PlayScene::PhysicsUpdate()
{
	for (GameObject* objA : gameObjectList)
	{
		for (GameObject* objB : gameObjectList)
		{
			if (objA == objB) continue;

			Collider* colliderA = objA->GetComponent<Collider>();
			Collider* colliderB = objB->GetComponent<Collider>();

			bool isOverlap = false;
			if (colliderA->IsOverlap(colliderA, colliderB)) // a->b
			{
				isOverlap = true;
			}

			// 충돌 여부에 따른 함수 호출
			if (isOverlap)
			{
				objA->OnColliderOverlap(objB);
			}
			else
			{
				objA->OnColliderExit(objB);
			}
		}
	}
}

void PlayScene::Update()
{
	sceneTimer += g_GameTime.GetDeltaTime();
	CheckObjects();

	if (sceneTimer > sceneMaxTimer) return;

	for (GameObject* obj : gameObjectList)
	{
		obj->Update();
	}
}

void PlayScene::Render()
{
	if (sceneTimer > sceneMaxTimer)
	{
		g_SceneManager.ChangeScene(2);
	}

	for (GameObject* obj : gameObjectList)
	{
		obj->Render();
	}
}