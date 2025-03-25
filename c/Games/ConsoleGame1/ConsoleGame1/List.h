#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "DataTypes.h"

// Node =================================

typedef struct Node
{
	Object data;
	struct Node* next;
	struct Node* prev;
} ObjectNode;

// Function =================================

void AddNode(Node** head, Object value);
void DeleteNode(Node** head, int index);
Node* FindNode(Node* head, int index);
int NodeCount(Node* head);
void FreeAllNode(Node* head);