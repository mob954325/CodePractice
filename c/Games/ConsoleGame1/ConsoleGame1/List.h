#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
typedef union
{
	int INT;
	float FLOAT;
	COORD COORD;
} Data;

typedef struct Node
{
	Data data;
	struct Node* next;
} Node;

Node* AddNode(Node* head, Data value);
void DeleteNode(Node* head, int index);