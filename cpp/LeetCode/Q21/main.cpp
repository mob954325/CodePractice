#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main()
{
	ListNode node3 = ListNode(4);
	ListNode node2 = ListNode(2, &node3);
	ListNode node1 = ListNode(1, &node2);

	ListNode node6 = ListNode(4);
	ListNode node5 = ListNode(3, &node6);
	ListNode node4 = ListNode(1, &node5);

	ListNode* l = &node1;
	l = mergeTwoLists(&node1, &node4);

	int count = 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
	// 정렬된 list1 과 list2의 머리를 제공한다.
	// 두 링크드 리스트를 정렬된 하나의 리스트로 합쳐라
	// 처음 두 목록의 노드를 합쳐서 만들어야한다.
	// 합친 리스트노드의 head를 반환한다.

    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* result;
    ListNode* current;

    // 첫 노드 추가
    if (list2->val > list1->val) // 2 > 1
    {
        current = list1;
        list1 = list1->next;
    }
    else // 2 < 1
    {
        current = list2;
        list2 = list2->next;
    }

    result = current;
    // list 합치기
    while (list1 && list2)
    {
        if (list2->val < list1->val)    // 2 < 1
        {
            current->next = list2;
            current = current->next;
            list2 = list2->next;
        }

        if (list1->val <= list2->val)    // 2 >= 1
        {
            current->next = list1;
            current = current->next;
            list1 = list1->next;
        }
    }

    // 남은 리스트 연결하기
    if (list1)
    {
        current->next = list1;
    }
    else if (list2)
    {
        current->next = list2;
    }

    return result;
}