#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main()
{
    ListNode* l1 = new ListNode(7);
    ListNode* l3 = new ListNode(6);
    ListNode* l2 = new ListNode(5, l3);

    addTwoNumbers(l1, l2);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // �� ��ũ�� ����Ʈ�� ���� ���Ͻÿ�

    // �ذ�
    // stack ����ϱ�
    // top���� ���ʴ�� ���ϱ�

    std::stack<ListNode*> s1;
    std::stack<ListNode*> s2;

    // stack�� ��� ����
    ListNode* temp = l1;
    while (temp)
    {
        s1.push(temp);
        temp = temp->next;
    }

    temp = l2;
    while (temp)
    {
        s2.push(temp);
        temp = temp->next;
    }

    ListNode* prev = nullptr;
    int ten = 0;
    // ��� ���� (l1 ����Ʈ ��忡 ����)
    while (!s1.empty() && !s2.empty())
    {
        ListNode* node1 = s1.top();
        ListNode* node2 = s2.top();
        s1.pop();
        s2.pop();

        int sum = node1->val + node2->val + ten;
        node1->val = sum % 10;
        ten = sum / 10;

        if (node1 != nullptr) prev = node1;
    }

    // ���� ��� ó��
    if (s1.empty()) // s2
    {
        while (!s2.empty())
        {
            ListNode* node = s2.top();
            s2.pop();

            int sum = node->val + ten;
            // �� ��� ���� �� ����
            ListNode* frontNode = new ListNode(sum % 10);
            frontNode->next = prev;
            prev = frontNode;

            ten = sum / 10;
        }

        l1 = prev;
    }
    else if (s2.empty()) // s1
    {
        while (!s1.empty())
        {
            ListNode* node = s1.top();
            s1.pop();

            int sum = node->val + ten;
            node->val = sum % 10;
            ten = sum / 10;
        }
    }

    if (ten == 1)
    {
        ListNode* frontNode = new ListNode(1);
        frontNode->next = l1;
        l1 = frontNode;
    }

    return l1; // �������� l1��ȯ
}