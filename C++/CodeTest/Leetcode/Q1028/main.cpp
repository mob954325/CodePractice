#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
// 못품
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
    // 우리는 이진 트리인 root에 미리 dfs를 실행시킨다.
    // 각 노드는 순회하면서 D dash들을 제공한다.(dash는 D의 노드 깊이), 그리고 해당 노드의 결과 value를 산출한다.
    // 만약 노드의 깊이가 D일때 그 다음 깊이의 자식은 D + 1이다. root 노드의 깊이는 0이다.
    // 만약 노드의 자식이 하나만 있으면 그 자식은 왼쪽 자식으로 생성된다.
    // 이 traversal에서 회복된 트리의 traversal의 root의 노드를 반환해라

    // 해결
    // 문자열 분리
    // ex> -숫자들, --숫자들을 자료구조에 저장
    // 저장된 내용을 -개수에 따라 노드 연결하기
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

        return -1; // 존재하지 않음
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
        pair<TreeNode*, int> prevData; // ? 초기화 안되어있지만 쓰래기값임

        // 문자열 분리해서 각 맵에 value, level형태로 변경
        while (((startPosition = traversal.find('-', currPosition)) != std::string::npos))
        {
            int curlen = startPosition - currPosition;
            string result = traversal.substr(currPosition, curlen);
            if (result != "") // 문자열이 존재한다 -> 해당 위치에 숫자가 있다.
            {
                int nodeValue = stoi(result);
                TreeNode* currNode = new TreeNode(nodeValue);

                if (level == 0) // root
                {
                    root = currNode;
                }
                else // root가 아니면 연결하기
                {
                    TreeNode* prevNode = prevData.first;
                    int prevCount = prevData.second;

                    if (prevCount != level - 1)
                    {
                        prevData = make_pair(FindPrevNodeOnLevel(v, level - 1), level - 1);
                        prevNode = prevData.first;
                        prevCount = prevData.second;
                    }

                    if (prevNode == nullptr) return root; // 해당 단계의 비어있는 노드가 존재하지 않음

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

        // 문자열의 지막 노드
        string lastValueStr = traversal.substr(currPosition);
        int lastValue = stoi(lastValueStr);

        TreeNode* currNode = new TreeNode(lastValue); // 마지막 노드 생성
        TreeNode* prevNode = prevData.first;
        int prevCount = prevData.second;

        if (prevCount != level - 1)
        {
            prevData = make_pair(FindPrevNodeOnLevel(v, level - 1), level - 1);
            prevNode = prevData.first;
            prevCount = prevData.second;
        }

        if (prevNode == nullptr) return root; // 해당 단계의 비어있는 노드가 존재하지 않음
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