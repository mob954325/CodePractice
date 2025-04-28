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
    // 두 링크드 리스트의 합을 구하시오

    // 해결
    // stack 사용하기
    // top부터 차례대로 더하기

    std::stack<ListNode*> s1;
    std::stack<ListNode*> s2;

    // stack에 노드 삽입
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
    // 계산 시작 (l1 리스트 노드에 저장)
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

    // 남은 노드 처리
    if (s1.empty()) // s2
    {
        while (!s2.empty())
        {
            ListNode* node = s2.top();
            s2.pop();

            int sum = node->val + ten;
            // 새 노드 생성 후 연결
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

    return l1; // 나머지는 l1반환
}