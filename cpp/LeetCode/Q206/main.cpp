#include <iostream>
#include <stack>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

ListNode* reverseList(ListNode* head);

int main()
{
    ListNode e = ListNode(5);
    ListNode d = ListNode(4, &e);
    ListNode c = ListNode(3, &d);
    ListNode b = ListNode(2, &c);
    ListNode a = ListNode(1, &b);

    ListNode* t = reverseList(&a);

    int aa = 0;
}

ListNode* reverseList(ListNode* head)
{
    // 연결된 노드들을 거꾸로 연결하기

    // 해결
    // 두 포인터로 prev current를 지정해서 next를 변경하기
    if (!head) return head;

    ListNode* prev = {};
    ListNode* curr = {};
    ListNode* nextNode = {};

    curr = head;
    nextNode = head->next;
    while (nextNode != nullptr)
    {
        curr->next = prev; // 뒤로 연결

        // 다음 노드 이동
        prev = curr;        // prev를 curr로 이동
        curr = nextNode;    // curr를 next로 이동
        nextNode = nextNode->next;  // next 다음 노드로 이동
    }

    curr->next = prev; // 마지막 노드 연결
    return curr;
}