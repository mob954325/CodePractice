#include <iostream>

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
    ListNode* l2 = new ListNode(9);
    ListNode* l1 = new ListNode(9, l2);
    ListNode* l3 = new ListNode(9);

    addTwoNumbers(l2, l3);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // ��� ���� �ʴ� �� ��ũ�� ����Ʈ�� �����ȴ�.
    // ���� �������� ����Ǿ��ִ�. (243 -> 342)
    // �� ���� �ϳ��� ���ڸ� ��� �ִ�.
    // �� �� ���ڸ� ���ϰ� �ϳ��� ���� ��ȯ�ض�

    // �ذ�
    // �� ��� ���ڴ��ϱ�
    // ���� �������� ��� ��
    // 10 �̻����� ���� ��忡 1���ϱ�

    // ��� ����
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* prev = {}; // ���� ��� ����� (cur1 ���� ���)
    int ten = 0;

    // ���ϱ�
    while (cur1 && cur2)
    {
        int sum = cur1->val + cur2->val;

        cur1->val = (sum + ten) % 10;
        ten = (sum + ten) / 10;

        prev = cur1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    // �� ��尡 nullptr�̸� ������ l1��ȯ
    if (!cur1 && !cur2)
    {
        while (ten != 0) // �ø� ó��
        {
            ListNode* last = new ListNode(1);
            prev->next = last;

            prev = prev->next;
            ten = prev->val / 10;
        }

        return l1;
    }

    // ������ ��� ó��
    if (!cur1)
    {
        cur1 = cur2;
        while (cur2)
        {
            int sum = cur2->val + ten;
            // l1�� �߰� ��� �����ϱ�
            ListNode* node = new ListNode(sum % 10);
            prev->next = node;
            prev = prev->next;

            ten = sum / 10;

            cur2 = cur2->next;
        }

        if (ten == 1)
        {
            ListNode* last = new ListNode(1);
            prev->next = last;
        }
    }
    else // !cur2
    {
        cur2 = cur1;
        while (cur1)
        {
            int sum = cur1->val + ten;
            cur1->val = sum % 10;
            ten = sum / 10;

            prev = cur1;
            cur1 = cur1->next;
        }

        if (ten == 1)
        {
            ListNode* last = new ListNode(1);
            prev->next = last;
        }
    }

    return l1;
}