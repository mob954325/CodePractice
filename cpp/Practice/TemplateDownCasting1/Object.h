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