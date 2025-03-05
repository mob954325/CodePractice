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
    // 문제 - 오염된 이진트리에서 요소 찾기
    // 밑의 규칙이 있는 이진트리를 제공
    // root.val = 0;
    // 모든 treeNode에서 
    // treeNode.val는 값 x와 treeNode.left != null을 가지고 있으면 treeNode.left.val == 2 * x + 1
    // 값 x와 treeNode.right != null을 가지고 있으면 treeNode.right.val == 2 * x + 2

    // 이진 트리가 오염(contaminated)됐다.는 모든 treeNode.val이 -1로 바뀌었다는 의미이다.

    // FindElements 클래스 구현
    // FindElements(TreeNodes* root) 오염된 이진트리 오브젝트를 초기화하고 그것을 회복 시킨다.
    // bool find(int target)은 회복된 이진트리에서 target값이 존재하면 true로 반환한다.

    // 해결
    // bfs로 정화하기
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