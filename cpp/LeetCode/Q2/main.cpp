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
    // 비어 있지 않는 두 링크드 리스트가 제공된다.
    // 노드는 역순으로 저장되어있다. (243 -> 342)
    // 각 노드는 하나의 숫자를 담고 있다.
    // 각 두 숫자를 더하고 하나의 노드로 반환해라

    // 해결
    // 각 노드 숫자더하기
    // 더한 나머지는 노드 값
    // 10 이상히면 다음 노드에 1더하기

    // 헤드 지정
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* prev = {}; // 이전 노드 저장용 (cur1 이전 노드)
    int ten = 0;

    // 더하기
    while (cur1 && cur2)
    {
        int sum = cur1->val + cur2->val;

        cur1->val = (sum + ten) % 10;
        ten = (sum + ten) / 10;

        prev = cur1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    // 두 노드가 nullptr이면 저장한 l1반환
    if (!cur1 && !cur2)
    {
        while (ten != 0) // 올림 처리
        {
            ListNode* last = new ListNode(1);
            prev->next = last;

            prev = prev->next;
            ten = prev->val / 10;
        }

        return l1;
    }

    // 나머지 노드 처리
    if (!cur1)
    {
        cur1 = cur2;
        while (cur2)
        {
            int sum = cur2->val + ten;
            // l1에 추가 노드 연결하기
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