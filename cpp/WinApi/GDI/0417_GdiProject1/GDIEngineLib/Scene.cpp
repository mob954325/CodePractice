#include "pch.h"
#include "Scene.h"

void Scene::Clear()
{
	for (auto& gameObject : gameObjectList)
	{
		delete gameObject;
	}
	
	gameObjectList.clear();
}

void Scene::PhysicsUpdate()
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

void Scene::Update()
{
}

void Scene::Render()
{
}
