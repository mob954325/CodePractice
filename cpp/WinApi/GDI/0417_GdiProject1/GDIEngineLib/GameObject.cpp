#include "pch.h"
#include "GameObject.h"

GameObject::GameObject()
{
	name = NULL;
	transform = AddComponent<Transform>();
}

GameObject::GameObject(float width, float height)
{
	name = NULL;
	transform = AddComponent<Transform>();
}

GameObject::~GameObject()
{
	// 컴포넌트 제거
	int componentCount = (int)componentList.size();
	for (int i = 0; i < componentCount; i++)
	{
		delete componentList[i];
	}

	if (name != NULL)
	{
		printf("%ws GameObject 소멸자 호출", name);
		free(name);
	}
	else
	{
		printf("GameObject 소멸자 호출");
	}
}

void GameObject::Initialize()
{
	// 초기화
}

void GameObject::Update()
{
	// 업데이트
}

void GameObject::Render()
{
	// 랜더링 내용
}

void GameObject::OnColliderOverlap(GameObject* other)
{
	// 충돌 내용
	printf("기본 오브젝트 내용 : %s, %s\n", typeid(*this).name(), typeid(*other).name());
}

void GameObject::OnColliderExit(GameObject* other)
{
	// 충돌 안 할 때 실행
}