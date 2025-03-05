#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
// ��ǰ
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
    // �츮�� ���� Ʈ���� root�� �̸� dfs�� �����Ų��.
    // �� ���� ��ȸ�ϸ鼭 D dash���� �����Ѵ�.(dash�� D�� ��� ����), �׸��� �ش� ����� ��� value�� �����Ѵ�.
    // ���� ����� ���̰� D�϶� �� ���� ������ �ڽ��� D + 1�̴�. root ����� ���̴� 0�̴�.
    // ���� ����� �ڽ��� �ϳ��� ������ �� �ڽ��� ���� �ڽ����� �����ȴ�.
    // �� traversal���� ȸ���� Ʈ���� traversal�� root�� ��带 ��ȯ�ض�

    // �ذ�
    // ���ڿ� �и�
    // ex> -���ڵ�, --���ڵ��� �ڷᱸ���� ����
    // ����� ������ -������ ���� ��� �����ϱ�
protected:
    int FindValue(vector<pair<int, int>>& v, int level)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second == level)
            {
                v[i].second = -1;
                return v[i].first;
            }
        }

        return -1; // �������� ����
    }

    TreeNode* FindPrevNodeOnLevel(vector<pair<TreeNode*, int>> &v, int level)
    {
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i].second == level)
            {
                return v[i].first;
            }
        }

        return nullptr;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {

        if (traversal.length() == 1)
        {
            TreeNode* root = new TreeNode(stoi(traversal));
            return root;
        }

        int startPosition = 0;
        int currPosition = 0;
        int level = 0;

        vector<pair<TreeNode*, int>> v;
        TreeNode* root = nullptr;
        pair<TreeNode*, int> prevData; // ? �ʱ�ȭ �ȵǾ������� �����Ⱚ��

        // ���ڿ� �и��ؼ� �� �ʿ� value, level���·� ����
        while (((startPosition = traversal.find('-', currPosition)) != std::string::npos))
        {
            int curlen = startPosition - currPosition;
            string result = traversal.substr(currPosition, curlen);
            if (result != "") // ���ڿ��� �����Ѵ� -> �ش� ��ġ�� ���ڰ� �ִ�.
            {
                int nodeValue = stoi(result);
                TreeNode* currNode = new TreeNode(nodeValue);

                if (level == 0) // root
                {
                    root = currNode;
                }
                else // root�� �ƴϸ� �����ϱ�
                {
                    TreeNode* prevNode = prevData.first;
                    int prevCount = prevData.second;

                    if (prevCount != level - 1)
                    {
                        prevData = make_pair(FindPrevNodeOnLevel(v, level - 1), level - 1);
                        prevNode = prevData.first;
                        prevCount = prevData.second;
                    }

                    if (prevNode == nullptr) return root; // �ش� �ܰ��� ����ִ� ��尡 �������� ����

                    if (prevNode->left == nullptr)
                    {
                        prevNode->left = currNode;
                    }
                    else
                    {
                        prevNode->right = currNode;
                    }
                }

                prevData = make_pair(currNode, level);
                v.push_back(prevData);
                level = 0;
            }
            currPosition = startPosition + 1;
            level++;
        }

        // ���ڿ��� ���� ���
        string lastValueStr = traversal.substr(currPosition);
        int lastValue = stoi(lastValueStr);

        TreeNode* currNode = new TreeNode(lastValue); // ������ ��� ����
        TreeNode* prevNode = prevData.first;
        int prevCount = prevData.second;

        if (prevCount != level - 1)
        {
            prevData = make_pair(FindPrevNodeOnLevel(v, level - 1), level - 1);
            prevNode = prevData.first;
            prevCount = prevData.second;
        }

        if (prevNode == nullptr) return root; // �ش� �ܰ��� ����ִ� ��尡 �������� ����
        if (prevNode->left == nullptr)
        {
            prevNode->left = currNode;
        }
        else
        {
            prevNode->right = currNode;
        }

        return root;
    }
};

int main()
{
    Solution sol = Solution();

    string str = "10-7--6-8--7--6";
    TreeNode* node = sol.recoverFromPreorder(str);
}