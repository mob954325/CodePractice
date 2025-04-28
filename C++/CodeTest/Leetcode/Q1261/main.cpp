#include <iostream>
#include <map>
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

class FindElements {
    // ���� - ������ ����Ʈ������ ��� ã��
    // ���� ��Ģ�� �ִ� ����Ʈ���� ����
    // root.val = 0;
    // ��� treeNode���� 
    // treeNode.val�� �� x�� treeNode.left != null�� ������ ������ treeNode.left.val == 2 * x + 1
    // �� x�� treeNode.right != null�� ������ ������ treeNode.right.val == 2 * x + 2

    // ���� Ʈ���� ����(contaminated)�ƴ�.�� ��� treeNode.val�� -1�� �ٲ���ٴ� �ǹ��̴�.

    // FindElements Ŭ���� ����
    // FindElements(TreeNodes* root) ������ ����Ʈ�� ������Ʈ�� �ʱ�ȭ�ϰ� �װ��� ȸ�� ��Ų��.
    // bool find(int target)�� ȸ���� ����Ʈ������ target���� �����ϸ� true�� ��ȯ�Ѵ�.

    // �ذ�
    // bfs�� ��ȭ�ϱ�
public:
    map<int, bool> nodeDatas;

    FindElements(TreeNode* root) {
        root->val = 0;
        nodeDatas[0] = true;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode->right != nullptr)
            {
                currNode->right->val = 2 * currNode->val + 2;
                q.push(currNode->right);
                nodeDatas[2 * currNode->val + 2] = true;
            }
            else
            {
                nodeDatas[2 * currNode->val + 2] = false;
            }

            if (currNode->left != nullptr)
            {
                currNode->left->val = 2 * currNode->val + 1;
                q.push(currNode->left);
                nodeDatas[2 * currNode->val + 1] = true;
            }
            else
            {
                nodeDatas[2 * currNode->val + 1] = false;
            }
        }
    }

    bool find(int target) {
        auto e = nodeDatas.find(target);
        return e->second;
    }
};

int main()
{
    TreeNode a = TreeNode(-1);
    TreeNode root = TreeNode(-1, nullptr, &a);

    FindElements f = FindElements(&root);
    f.find(1);  // false
    f.find(2);  // true
}