#include "GameManager.h"
#include "DebugUtility.h"

namespace GameManager
{
	Tag gameBufferState[MAXHEIGHT][MAXWIDTH];

	int FindNodeByCoord(Node* head, COORD position);

	void GameManagerInitialize()
	{
		ClearGameBufferState();
	}

	void ClearGameBufferState()
	{
		for (int y = 0; y < MAXHEIGHT; y++)
		{
			for (int x = 0; x < MAXWIDTH; x++)
			{
				gameBufferState[y][x] = Tag::None;
			}
		}
	}

	void UpdateGameBufferState(Node* head)
	{
		Node* currNode = head;
		while (currNode != NULL)
		{
			byte y = currNode->data.coords.Y;
			byte x = currNode->data.coords.X;

			if (gameBufferState[y][x] != Tag::None)
			{
				DebugLog("Event!!!\n"); // 이벤트 발생

				int eventedNodeIndex = FindNodeByCoord(head, { x, y });
				DeleteNode(&head, eventedNodeIndex);
			}
			gameBufferState[y][x] = head->data.tag;

			currNode = currNode->prev;
		}
	}

	int FindNodeByCoord(Node* head, COORD position)
	{
		int enemyCount = NodeCount(head);
		for (int i = 0; i < enemyCount; i++)
		{
			Node* currNode = FindNode(head, i);
			if ((currNode->data.coords.X == position.X)
				&& (currNode->data.coords.Y == position.Y))
			{
				return i;
			}
		}

		return -1;
	}
}