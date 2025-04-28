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
    // ����� ������ �Ųٷ� �����ϱ�

    // �ذ�
    // �� �����ͷ� prev current�� �����ؼ� next�� �����ϱ�
    if (!head) return head;

    ListNode* prev = {};
    ListNode* curr = {};
    ListNode* nextNode = {};

    curr = head;
    nextNode = head->next;
    while (nextNode != nullptr)
    {
        curr->next = prev; // �ڷ� ����

        // ���� ��� �̵�
        prev = curr;        // prev�� curr�� �̵�
        curr = nextNode;    // curr�� next�� �̵�
        nextNode = nextNode->next;  // next ���� ���� �̵�
    }

    curr->next = prev; // ������ ��� ����
    return curr;
}