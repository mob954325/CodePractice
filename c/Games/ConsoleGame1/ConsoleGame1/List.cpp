#include "List.h"

void AddNode(Node** head, ScreenElement value)
{
	if (*head == NULL)
	{
		*head = (Node*)malloc(sizeof(Node));
		(*head)->data = value;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}
	else
	{
		Node* prevNode = *head;
		*head = (Node*)malloc(sizeof(Node));
		(*head)->data = value;
		(*head)->next = NULL;
		(*head)->prev = prevNode;
		prevNode->next = *head;
	}
}

void DeleteNode(Node** head, int index)
{
	if (*head == NULL) return;

	Node* currNode = FindNode(*head, index);

	if (currNode == NULL) return;

	Node* prevNode = currNode->prev;
	Node* nextNode = currNode->next;

	if (nextNode == NULL) // 첫 번째 노드
	{
		*head = prevNode;

		if (*head != NULL)
		{
			(*head)->next = NULL;
		}
	}
	else
	{
		if (prevNode != NULL) prevNode->next = nextNode;
		if (nextNode != NULL) nextNode->prev = prevNode;
	}

	free(currNode); // 메모리 해제
}

Node* FindNode(Node* head, int index)
{
	Node* currNode = head;

	int currIndex = 0;
	while (currNode != NULL)
	{
		if (currIndex == index) // 해당 인덱스 찾음
		{
			return currNode;
		}
		else
		{
			currNode = currNode->prev;
		}

		currIndex++;
	}

	return NULL; // NULL
}

int NodeCount(Node* head)
{
	Node* currNode = head;

	int cnt = 0;
	while (currNode != NULL)
	{
		currNode = currNode->prev;
		cnt++;
	}

	return cnt;
}


void FreeAllNode(Node* head)
{
	int size = NodeCount(head);
	for (int i = 0; i < size; i++)
	{
		DeleteNode(&head, 0);
	}
}