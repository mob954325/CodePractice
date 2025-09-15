#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단일 연결 리스트 만들기

#define MAX_BUFFER_SIZE 8

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* head = NULL;

void checkNode()
{
	if (head == NULL) printf("Invaild head node\n");

	Node* currNode = head;
	while (currNode != NULL)
	{
		if (currNode->next != NULL) printf("%d -> ", currNode->data);
		else printf("%d", currNode->data);
		currNode = currNode->next;
	}
}

void AddNode(int value)
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
}
 
// 10 <- 20 <- 50(head)

void DeleteNode(int value)
{
	Node* currNode = head;
	Node* prevNode = NULL;
	while (currNode != NULL)
	{
		if (currNode->data == value) // 해당 값을 가진 노드를 발견했다.
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


int main()
{
	printf("command list ============\n");
	printf("add [number] : add node\n");
	printf("del [number] : delete node\n");
	printf("check : check node state\n");
	printf("end : program end \n");
	printf("==========================\n\n");

	char* command = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
	int dataValue = 0;
	while (1)
	{
		scanf("%s", command);

		if (strcmp(command, "add") == 0)
		{
			scanf("%d", &dataValue);
			AddNode(dataValue);
		}
		else if (strcmp(command, "del") == 0)
		{
			scanf("%d", &dataValue);
			DeleteNode(dataValue);
		}
		else if (strcmp(command, "check") == 0)
		{
			checkNode();
		}
		else if (strcmp(command, "end") == 0)
		{
			printf("program end\n");
			return 0;
		}
		else
		{
			printf("wrong command !!!\n");
		}
	}
}