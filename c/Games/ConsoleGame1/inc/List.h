#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef union
{
	int INT;
	float FLOAT;
} Data;

typedef struct Node
{
	Data data;
	struct Node* next;
} Node;

Node* AddNode();
void DeleteNode();