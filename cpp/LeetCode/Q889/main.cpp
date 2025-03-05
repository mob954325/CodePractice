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
    // ����
    // ���� �迭�� �� �迭 preoder, postorder�� �����Ѵ�
    // preorder�� ����Ʈ���� �� ���� preorder ��ȸ�� ���̰�
    // postorder�� ���� Ʈ���� postorder ��ȸ �Ѱ��̴�.
    // �籸���ϰ� ����Ʈ���� ��ȯ�ض� -> ??? 
    // ���� �������� ���� ������ ������ �ƹ����̳� ��ȯ�ض�
    // preorder : root->left->right �� ��ȸ
    // postorder : left->right->root �� ��ȸ ( �ڽĸ��� ã�� )

    // �ذ�
    // ����Լ�
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