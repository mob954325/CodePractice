#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<int> list;
	list.Push_back(10);
	list.Push_back(20);
	list.Push_back(30);
	list.Push_back(40);
	list.Push_back(50);
	list.Push_back(60);
	list.Remove(40);

	Node<int>* pFind = list.Find(30);
	list.Erase(pFind);

	pFind = list.Find(20);
	list.Insert(pFind, 25);

	// 전체 목록을 출력
	DoubleLinkedList<int>::Iterator iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}