#include "PlayScene.h"
#include "Collider.h"
#include "Player.h"

void PlayScene::Enter(HWND hwnd, HDC frontBufferDC, HDC backBufferDC)
{
	this->hwnd = hwnd;
	this->FrontBufferDC = frontBufferDC;	// 앞면 DC
	this->BackBufferDC = backBufferDC;	// 뒷면 DC

	this->graphics = Gdiplus::Graphics::FromHDC(BackBufferDC); // null 반환

	Gdiplus::GdiplusStartup(&s_GdiPlusToken, &s_gsi, nullptr);
	gameObjectList.push_back(new Player(graphics));
}

void PlayScene::PhysicsUpdate()
{
	//for (GameObject* objA : gameObjectList)
	//{
	//	for (GameObject* objB : gameObjectList)
	//	{
	//		if (objA == objB) continue;

	//		std::vector<Collider*> colliderAList = objA->Getcomponents<Collider>();
	//		std::vector<Collider*> colliderBList = objB->Getcomponents<Collider>();

	//		if (colliderAList.size() == 0 || colliderBList.size() == 0) continue;

	//		bool isOverlap = false;
	//		// 오브젝트에 있는 모든 콜라이더 검사
	//		for (Collider* colliderA : colliderAList)
	//		{
	//			for (Collider* colliderB : colliderBList)
	//			{
	//				if (colliderA->IsOverlap(colliderA, colliderB)) // a->b
	//				{
	//					isOverlap = true;
	//					break;
	//				}
	//			}
	//		}

	//		// 충돌 여부에 따른 함수 호출
	//		if (isOverlap)
	//		{
	//			objA->OnColliderOverlap(objB);
	//		}
	//		else
	//		{
	//			objA->OnColliderExit(objB);
	//		}
	//	}
	//}
}

void PlayScene::Update()
{
	for (GameObject* obj : gameObjectList)
	{
		obj->Update();
	}
}

void PlayScene::Render()
{
	for (GameObject* obj : gameObjectList)
	{
		obj->Render();
	}
}
