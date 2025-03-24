#include "List.h"

Node* AddNode(Node* head, Data value)
{
	if (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data = value;
		head->next = NULL;
	}
	else
	{
		Node* preHead = head;
		head = (Node*)malloc(sizeof(Node));
		head->data = value;
		head->next = preHead;
	}

	return head;
}

// 10 <- 20 <- 50(head)

void DeleteNode(Node* head, int index)
{
	Node* currNode = head;
	Node* prevNode = NULL;

	int currIndex = 0;
	while (currNode != NULL)
	{
		if (currIndex == index) // 해당 인덱스 찾음
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

		currIndex++;
	}

	if (currNode == NULL) printf("Invaild Node Value...\n");
}