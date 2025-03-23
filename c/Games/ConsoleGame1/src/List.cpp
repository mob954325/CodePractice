#include "List.h"

void AddNode(Node* head, int value)
{
	if (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data.INT = value;
		head->next = NULL;
	}
	else
	{
		Node* preHead = head;
		head = (Node*)malloc(sizeof(Node));
		head->data.INT = value;
		head->next = preHead;
	}
}

// 10 <- 20 <- 50(head)

void DeleteNode(Node* head, int value)
{
	Node* currNode = head;
	Node* prevNode = NULL;
	while (currNode != NULL)
	{
		if (currNode->data.INT == value) // 해당 값을 가진 노드를 발견했다.
		{
			Node* nextNode = currNode->next;
			free(currNode); // 메모리 해제
			if (prevNode == NULL) // head
			{
				head = nextNode;
			}
			else
			{
				prevNode->next = nextNode;
			}
			break;
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
	}

	if (currNode == NULL) printf("Invaild Node Value...\n");
}