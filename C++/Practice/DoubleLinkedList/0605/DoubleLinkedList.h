#pragma once
#include <iostream>


/// 구조
/// Head(Dummy) <-> node1 <-> node2 ... <-> Tail(Dummy)
/// 
/// 함수
/// -- Node
/// SetNextNode
/// GetNextNode
/// SetPrevNode
/// GetPrevNode
/// GetValue
/// GetValueRef
/// 
/// -- List
/// Push_back
/// Remove
/// Insert
/// Find
/// Erase
/// Iterator begin
/// Iterator end
/// 
/// -- Iterator operator
/// ++, *, ==, !=


#pragma region Node
template<typename T>
class Node
{
public:
	Node();
	Node(T value);
	~Node();

	void SetNextNode(Node<T>* pPos) { next = pPos; };
	Node<T>* GetNextNode() { return next; };

	void SetPrevNode(Node<T>* pPos) { prev = pPos; };
	Node<T>* GetPrevNode() { return prev; };

	T GetValue() const { return value; };
	T& GetValueRef() { return value; };

private:
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
	T value;
};

template<typename T>
Node<T>::Node()
{
	prev = nullptr;
	next = nullptr;
	value = {};

	//std::cout << "-> 노드 생성됨 (기본 생성자 호출)\n";
}

template<typename T>
inline Node<T>::Node(T value)
{
	this->value = value;
	//std::cout << "-> 값[" << value << "] 노드 생성됨(생성자 호출)\n";
}

template<typename T>
Node<T>::~Node()
{
	//std::cout << "-> 값[" << value << "] 노드 제거됨(소멸자 호출)\n";
}
#pragma endregion

#pragma region DoubleLinkedList
template<typename T>
class DoubleLinkedList
{

#pragma region Iterator
public:
	class Iterator
	{
	public:
		Iterator(Node<T>* p) : pCurr(p) {}

		Iterator& operator++() 
		{
			if (pCurr) pCurr = pCurr->GetPrevNode();
			return *this;
		}

		T& operator*() 
		{
			return pCurr->GetValueRef();
		}

		bool operator==(const Iterator& other) const 
		{
			return pCurr == other.pCurr;
		}

		bool operator!=(const Iterator& other) const 
		{
			return !(*this == other);
		}

	private:
		Node<T>* pCurr;
	};

	Iterator begin() { return Iterator(pHead->GetPrevNode()); }
	Iterator end() { return Iterator(pTail); }
#pragma endregion

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void Push_back(const T& data);
	void Remove(const T& data);

	Node<T>* Insert(Node<T>* pPos, const T& data);
	Node<T>* Find(const T& data);
	Node<T>* Erase(Node<T>* pPos);

private:
	Node<T>* pHead;
	Node<T>* pTail;
};

template<typename T>
inline DoubleLinkedList<T>::DoubleLinkedList()
{
	pHead = new Node<T>();
	pTail = new Node<T>();

	pHead->SetPrevNode(pTail);
	pTail->SetNextNode(pHead);

	//std::cout << "-> 리스트 생성됨 (기본 생성자 호출)\n";
}

template<typename T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node<T>* current = pTail->GetNextNode();

	while (current != pHead)
	{
		Node<T>* next = current->GetNextNode();
		delete current;

		current = next;
	}

	delete pHead;
	delete pTail;

	//std::cout << "-> 리스트 소멸됨 (기본 소멸자 호출)\n";
}

template<typename T>
inline void DoubleLinkedList<T>::Push_back(const T& data)
{
	Node<T>* pNewNode = new Node<T>(data);
	Node<T>* pTailNextNode = pTail->GetNextNode();

	pTailNextNode->SetPrevNode(pNewNode);

	pNewNode->SetNextNode(pTailNextNode);
	pNewNode->SetPrevNode(pTail);

	pTail->SetNextNode(pNewNode);
}

template<typename T>
inline void DoubleLinkedList<T>::Remove(const T& data)
{
	Node<T>* pPos = DoubleLinkedList<T>::Find(data);

	if (pPos != nullptr)
	{
		Node<T>* pNextNode = pPos->GetNextNode();
		Node<T>* pPrevNode = pPos->GetPrevNode();

		pNextNode->SetPrevNode(pPrevNode);
		pPrevNode->SetNextNode(pNextNode);

		delete pPos;
	}
}

template<typename T>
inline Node<T>* DoubleLinkedList<T>::Insert(Node<T>* pPos, const T& data)
{
	if (pPos == nullptr || pPos->GetNextNode() == nullptr || pPos->GetPrevNode() == nullptr) // 연결이 안된 노드
	{
		return nullptr;
	}

	if (pPos == pTail)
	{
		pPos = pTail->GetNextNode();
	}

	Node<T>* pNewNode = new Node<T>(data);
	Node<T>* pNextNode = pPos->GetNextNode();
	Node<T>* pPrevNode = pPos->GetPrevNode();
	
	pPos->SetPrevNode(pNewNode);
	
	pNewNode->SetNextNode(pPos);
	pNewNode->SetPrevNode(pPrevNode);
	
	pPrevNode->SetNextNode(pNewNode);

	return pNewNode;
}

template<typename T>
inline Node<T>* DoubleLinkedList<T>::Find(const T& data)
{
	Node<T>* pPos = pTail->GetNextNode();

	while (pPos != pHead)
	{
		if (pPos->GetValue() == data) // 찾음
		{
			return pPos;
		}
		else
		{
			pPos = pPos->GetNextNode();
		}
	}

	return nullptr; // 못찾음
}

template<typename T>
inline Node<T>* DoubleLinkedList<T>::Erase(Node<T>* pPos)
{
	if (pPos == nullptr || pPos->GetNextNode() == nullptr || pPos->GetPrevNode() == nullptr)
		return nullptr;

	Node<T>* prevNode = pPos->GetPrevNode();
	Node<T>* nextNode = pPos->GetNextNode();

	prevNode->SetNextNode(nextNode);
	nextNode->SetPrevNode(prevNode);

	delete pPos;

	return prevNode;
}

#pragma endregion