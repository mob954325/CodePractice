#include <iostream>
#include <unordered_map>

int const MAX = 100;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        return NULL;
    }
};

void InsertTest(ListNode* l1, ListNode* l2)
{
    l1->val = 9;
    l2->val = 9;

    // l1
    for (int i = 0; i < 7; i++)
    {
        (l1 + i)->val = 9;

        if (i + 1 < 7)
        {
            (l1 + i)->next = l1 + i + 1;
        }
    }
    
    // l2
    for (int i = 0; i < 4; i++)
    {
        (l2 + i)->val = 9;

        if (i + 1 < 4)
        {
            (l2 + i)->next = l1 + i + 1;
        }
    }
}

int main()
{
    ListNode nodeList1[MAX];
    ListNode nodeList2[MAX];

    InsertTest(nodeList1, nodeList2);

    Solution solution;

    solution.addTwoNumbers(nodeList1, nodeList2);
}

