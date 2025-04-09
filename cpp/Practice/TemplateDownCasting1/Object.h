#pragma once
#include "base.h" 
#include <vector>

class Object
{
public:
template<class T>
	void AddComponent(T* comp);

template<class T>
	T* GetComponent();

private:
	std::vector<base*> componentList;
};

template<class T>
void Object::AddComponent(T* comp)
{
	componentList.push_back(comp);
}

template<class T>
T* Object::GetComponent()
{
	for (base* comp : componentList)
	{
		if (T* casted = dynamic_cast<T*>(comp)) // 실패 시 0 반환 (throw 반환 안함)
		{
			return casted;
		}
	}

	return nullptr;
}