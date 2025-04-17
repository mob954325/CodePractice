#include "PlayScene.h"
#include "Collider.h"
#include "Player.h"
#include "Enemy.h"

void PlayScene::Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
{
	this->hwnd = hwnd;
	this->FrontBufferDC = frontBufferDC;	// 앞면 DC
	this->BackBufferDC = backBufferDC;	// 뒷면 DC

	Gdiplus::GdiplusStartup(&s_GdiPlusToken, &s_gsi, nullptr);
	this->graphics = Gdiplus::Graphics::FromHDC(BackBufferDC); // null 반환

	gameObjectList.push_back(new Enemy(graphics));
	gameObjectList.push_back(new Player(graphics));
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
	for (GameObject* obj : gameObjectList)
	{
		if(obj != nullptr) obj->Update();
	}
}

void PlayScene::Render()
{
	for (GameObject* obj : gameObjectList)
	{
		if (obj != nullptr) obj->Render();
	}
}
