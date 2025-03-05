#include <iostream>
#include <vector>
#include <stack>
#include <string>

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
public:
    void stringMaker(TreeNode *root, std::vector<std::string> ans, std::string currStr)
    {
        // root가 존재하지 않음
        if (!root) return; 

        // 다음 노드가 존재함
        if (root->left || root->right) currStr += (std::to_string(root->val) + "->");
        else
        {
            // 다음 노드가 존재하지 않음 -> leaf 노드임
            currStr += std::to_string(root->val);
            ans.push_back(currStr);
        }
        stringMaker(root->left, ans, currStr);
        stringMaker(root->right, ans, currStr);
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        // 이진 트리의 root 제공
        // 순서상관없이 root로 향하는 leaf 노드들을 반환해라

        // 해결
        // 문자열 만들기 (정답)
        // 문자열을 지속 갱신을 하고 노드가 비어있으면 해당 노드의 밸류를 추가하고 vector에 추가

        std::vector<std::string>res;
        std::string currStr = "";

        stringMaker(root, res, currStr);

        return res;
    }
};

int main()
{
    Solution sol = Solution();

    TreeNode a3 = TreeNode(5);
    TreeNode a2 = TreeNode(3);
    TreeNode a1 = TreeNode(2, nullptr, &a3);
    TreeNode root = TreeNode(1, &a1, &a2);

    sol.binaryTreePaths(&root);
}