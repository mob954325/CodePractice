#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 문제
    // 정수 배열인 두 배열 preoder, postorder을 제공한다
    // preorder는 이진트리의 각 값을 preorder 순회한 것이고
    // postorder는 같은 트리를 postorder 순회 한것이다.
    // 재구성하고 이진트리를 반환해라 -> ??? 
    // 만약 여러개의 답을 가지고 있으면 아무것이나 반환해라
    // preorder : root->left->right 순 순회
    // postorder : left->right->root 순 순회 ( 자식먼저 찾기 )

    // 해결
    // 재귀함수
public:
    int preIndex = 0, posIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[posIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[posIndex])
            root->right = constructFromPrePost(pre, post);

        posIndex++;
        return root;
    }
};

int main()
{
    vector<int> v1 = { 1,2,4,5,3,6,7 };
    vector<int> v2 = { 4,5,2,6,7,3,1 };

    Solution sol = Solution();

    sol.constructFromPrePost(v1, v2);
}