#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
    // ���� 
    // 0���� n - 1���� ��ϵ� ��� n�� ���� ������ ���� Ʈ���� �ִ�. ��� 0�� root�� �Ǿ��ִ�.
    // ���̰� n - 1�� ������(Edges)�� 2D �迭�� �����ȴ�. edges[i] = [a(i), b(i)]�� ��� a(i), b(i) ���̿� ���� ������ ������ �ִ�.
    // ��� ��� i�� ����Ʈ(gate)�� �ֽ��ϴ�. 
    //
    // ¦�� ������ amount �迭�� �����մϴ�. ������ �Ʒ��� �����ϴ�.
    // 1. �ش� ��(price)�� ����� ����Ʈ�� �������� �ʿ��� ���Դϴ�. amount[i]�� ���� �� �� �ֽ��ϴ�.
    // 2. ����� ����Ʈ�� ��(open) ��� ��(cash)�� �־����ϴ�. (�׷��� ���� ���?)
    //
    // ������ �ش� ���� ���� �����ϴ�.
    // 1. ó������ Alice�� ��� 0�� �ְ� Bob�� bob��忡 �ֽ��ϴ�.
    // 2. �� �ʸ��� �� �� Alice�� Bob�� ������(adjacent)���� �̵��մϴ�. 
    // Bob�� ��� 0���� �̵��� ���� Alice�� ��� leaf node�� �̵��մϴ�.
    // 3. ��ο� �ִ� ��� ��忡 ���� Alice�� Bob�� ��(Money)�� ����� ����� ���� ���ϴ�. �Ǵ� �Ʒ��� ���� ������ �޽��ϴ�.
    // 3.1 �̹� ����Ʈ�� ���������� ���� �� �ʿ䰡 ���� ������ ���� �ʽ��ϴ�(nor will there any cash reward).
    // 3.2 ���� Alice�� Bob�� ���ÿ� ��带 �����ϸ�, �ش� ����Ʈ�� ����� ������ �����մϴ�.
    // �ٽ� ����, c�� ����Ʈ�� �������� �� Alice�� Bob�� �� �� c / 2 ��ŭ �����մϴ�.
    // ����ϰ�(Similarly), ����Ʈ c�� ������ ������ �� �� c / 2��ŭ �޽��ϴ�.
    // 4. ���� Alice�� leaf ��忡 �����ϸ�, �׳�� ����ϴ�.
    // ����ϰ�, Bob�� ��� 0�� �����ϸ� ����ϴ�.
    // �̷��� �̺�Ʈ�� ���� �������� ���� �˰� ��ʽÿ�.
    //
    // ���
    // Alice�� ������ ��η� leaf ��忡 �������� �� ���� �� �ִ� �ִ� �������� ��ȯ�ϼ���

    // �ذ�
    // bob�� ���� ���� ���� �̵��ؾ���
    // Alice�� ���� ���� ��带 �̿��� leaf ��忡 �����ؾ���
    // �ٵ� ���ⷮ�� �������
    // 1. �������� �� leaf ���� ���� �� �ش� ��忡 �������� ����
    // 2. bob 0���� �̵��� �� Alice�� �̹� �̵��� ���� �ش� ��� ���� ������ ���� ���� �ٽ� �߰�
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // 1. �̵��� ��� �Ұ��ΰ�.
        // 2. ���� ���¸� ��� �����Ұ��ΰ�.
        map<int, vector<int>> nodes; // ������, ���� ����� ��� 
        vector<pair<int, int>> nodeIncome(amount.size(), make_pair(0, 0)); // income, �� ��

        for (int i = 0; i < edges.size(); i++)
        {
            int node = edges[i][0];
            int next = edges[i][1];
            nodes[node].push_back(next);

            nodes[next].push_back(node);
        }

        queue<int> q;

        // bob
        // **Bob�� ��� ã�� (BFS)**
        vector<int> parent(amount.size(), -1); // �θ� ��� ���� (��� ����)
        q.push(bob);
        parent[bob] = bob; // �ڱ� �ڽ��� �θ�� ���� (������)

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : nodes[curr]) {
                if (parent[next] == -1) { // �湮���� ���� ��常 Ž��
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }

        // **Bob�� ���� ��� ���� (`bob_path`)**
        vector<int> bob_path;
        int curr = 0; // ��Ʈ ��忡�� �Ž��� �ö�
        while (curr != bob) {
            bob_path.push_back(curr);
            curr = parent[curr];
        }
        bob_path.push_back(bob); // ���������� Bob�� ������ ��� �߰�

        int bobTurn = bob_path.size();
        // ������ ��� ������ ��ȣ �ۼ�
        for (auto e : bob_path)
        {
            nodeIncome[e].second = bobTurn--;
            nodeIncome[e].first = amount[e];
        }

        // Alice
        q.push(0);
        vector<int> visited(amount.size(), 0);
        visited[0]++;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            for (int i = 0; i < nodes[currNode].size(); i++)
            {
                int next = nodes[currNode][i];
                
                if (visited[next] != 0) continue; // ������ ��� ����

                visited[next] = visited[currNode] + 1; // �� üũ
                if (nodeIncome[next].second == visited[next]) // bob�� ������ �ϰ� ���� �� �� -> �̹� ������ ���� /2�� �����ϱ�
                {
                    nodeIncome[next].first = nodeIncome[next].first - amount[next] + amount[next] / 2; // ���� ���� ����
                    nodeIncome[next].first += nodeIncome[currNode].first; // ���� �� �߰�
                }
                else if(nodeIncome[next].second > visited[next]) // alice�� ���� ������
                {
                    nodeIncome[next].first += nodeIncome[currNode].first;
                }
                else if (nodeIncome[next].second < visited[next]) // bob�� ���� ������
                {
                    if (nodeIncome[next].first != 0) // bob�� ����� ���� ������
                    {
                        nodeIncome[next].first = nodeIncome[currNode].first;
                    }
                    else // alice�� ó�� ������
                    {
                        nodeIncome[next].first = nodeIncome[currNode].first + amount[next];
                    }
                }
                q.push(next);
            }
        }

        // turn���� ���� ���� ������ ���
        int res = INT32_MIN;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].size() == 1) // ����� ��尡 ���� == leaf ���
            {
                res = max(res, nodeIncome[i].first); // nodeIncome[i].first - amount[i] �ش� ��忡�� ����� ������ �̸� ����ߴ��� ����
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> edges =
    {
        {0, 1},
        {1, 2},
        {1, 3},
        {3, 4}
    };

    int bob = 3;

    vector<int> amount = { -2,4,2,-4,6 };

    Solution sol = Solution();
    sol.mostProfitablePath(edges, bob, amount);
}