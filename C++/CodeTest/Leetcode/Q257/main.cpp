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
        // root�� �������� ����
        if (!root) return; 

        // ���� ��尡 ������
        if (root->left || root->right) currStr += (std::to_string(root->val) + "->");
        else
        {
            // ���� ��尡 �������� ���� -> leaf �����
            currStr += std::to_string(root->val);
            ans.push_back(currStr);
        }
        stringMaker(root->left, ans, currStr);
        stringMaker(root->right, ans, currStr);
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        // ���� Ʈ���� root ����
        // ����������� root�� ���ϴ� leaf ������ ��ȯ�ض�

        // �ذ�
        // ���ڿ� ����� (����)
        // ���ڿ��� ���� ������ �ϰ� ��尡 ��������� �ش� ����� ����� �߰��ϰ� vector�� �߰�

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