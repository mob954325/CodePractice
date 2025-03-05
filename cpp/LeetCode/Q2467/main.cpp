#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
    // 문제 
    // 0부터 n - 1까지 기록된 노드 n을 가진 방향이 없는 트리가 있다. 노드 0이 root로 되어있다.
    // 길이가 n - 1인 간선들(Edges)의 2D 배열이 제공된다. edges[i] = [a(i), b(i)]는 노드 a(i), b(i) 사이에 간선 정보를 가지고 있다.
    // 모든 노드 i는 게이트(gate)가 있습니다. 
    //
    // 짝수 정수인 amount 배열을 제공합니다. 내용은 아래와 같습니다.
    // 1. 해당 값(price)는 노드의 게이트를 열기위해 필요한 값입니다. amount[i]는 음수 일 수 있습니다.
    // 2. 노드의 게이트를 열(open) 경우 돈(cash)를 주어집니다. (그렇지 않을 경우?)
    //
    // 게임은 해당 밑의 룰을 따릅니다.
    // 1. 처음에는 Alice는 노드 0에 있고 Bob은 bob노드에 있습니다.
    // 2. 매 초마다 각 각 Alice와 Bob은 인접한(adjacent)노드로 이동합니다. 
    // Bob이 노드 0으로 이동할 동안 Alice는 어느 leaf node로 이동합니다.
    // 3. 경로에 있는 모든 노드에 따라 Alice와 Bob은 돈(Money)을 사용해 노드의 문을 엽니다. 또는 아래와 같은 보상을 받습니다.
    // 3.1 이미 게이트가 열려있으면 돈을 낼 필요가 없고 보상을 받지 않습니다(nor will there any cash reward).
    // 3.2 만약 Alice와 Bob이 동시에 노드를 도달하면, 해당 게이트의 보상과 지출을 공유합니다.
    // 다시 말해, c의 게이트을 지불했을 대 Alice와 Bob은 각 각 c / 2 만큼 지출합니다.
    // 비슷하게(Similarly), 게이트 c에 보상이 있으면 각 각 c / 2만큼 받습니다.
    // 4. 만약 Alice가 leaf 노드에 도달하면, 그녀는 멈춥니다.
    // 비슷하게, Bob이 노드 0에 도달하면 멈춥니다.
    // 이러한 이벤트는 서로 독립적인 것을 알고 계십시오.
    //
    // 결과
    // Alice가 최적의 경로로 leaf 노드에 도달했을 때 얻을 수 있는 최대 순이익을 반환하세요

    // 해결
    // bob은 가장 작은 노드로 이동해야함
    // Alice는 가장 적은 노드를 이용해 leaf 노드에 도달해야함
    // 근데 지출량도 적어야함
    // 1. 엘리스가 각 leaf 노드로 갔을 때 해당 노드에 순이익을 저장
    // 2. bob 0까지 이동할 대 Alice가 이미 이동한 노드면 해당 노드 값을 뺀다음 절반 값을 다시 추가
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // 1. 이동은 어떻게 할것인가.
        // 2. 저장 형태를 어떻게 지정할것인가.
        map<int, vector<int>> nodes; // 현재노드, 노드랑 연결된 노드 
        vector<pair<int, int>> nodeIncome(amount.size(), make_pair(0, 0)); // income, 턴 수

        for (int i = 0; i < edges.size(); i++)
        {
            int node = edges[i][0];
            int next = edges[i][1];
            nodes[node].push_back(next);

            nodes[next].push_back(node);
        }

        queue<int> q;

        // bob
        // **Bob의 경로 찾기 (BFS)**
        vector<int> parent(amount.size(), -1); // 부모 노드 저장 (경로 추적)
        q.push(bob);
        parent[bob] = bob; // 자기 자신을 부모로 설정 (시작점)

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : nodes[curr]) {
                if (parent[next] == -1) { // 방문하지 않은 노드만 탐색
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }

        // **Bob의 실제 경로 저장 (`bob_path`)**
        vector<int> bob_path;
        int curr = 0; // 루트 노드에서 거슬러 올라감
        while (curr != bob) {
            bob_path.push_back(curr);
            curr = parent[curr];
        }
        bob_path.push_back(bob); // 마지막으로 Bob이 시작한 노드 추가

        int bobTurn = bob_path.size();
        // 지나간 경로 역으로 번호 작성
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
                
                if (visited[next] != 0) continue; // 지나간 노드 무시

                visited[next] = visited[currNode] + 1; // 턴 체크
                if (nodeIncome[next].second == visited[next]) // bob이 지나온 턴과 같은 턴 수 -> 이미 지불한 값의 /2만 지출하기
                {
                    nodeIncome[next].first = nodeIncome[next].first - amount[next] + amount[next] / 2; // 값의 절반 내기
                    nodeIncome[next].first += nodeIncome[currNode].first; // 이전 값 추가
                }
                else if(nodeIncome[next].second > visited[next]) // alice가 먼저 도착함
                {
                    nodeIncome[next].first += nodeIncome[currNode].first;
                }
                else if (nodeIncome[next].second < visited[next]) // bob이 먼저 도착함
                {
                    if (nodeIncome[next].first != 0) // bob이 열어논 곳을 지나감
                    {
                        nodeIncome[next].first = nodeIncome[currNode].first;
                    }
                    else // alice가 처음 도달함
                    {
                        nodeIncome[next].first = nodeIncome[currNode].first + amount[next];
                    }
                }
                q.push(next);
            }
        }

        // turn수가 가장 낮은 마지막 노드
        int res = INT32_MIN;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].size() == 1) // 연결된 노드가 없음 == leaf 노드
            {
                res = max(res, nodeIncome[i].first); // nodeIncome[i].first - amount[i] 해당 노드에서 멈췄기 때문에 미리 계산했던거 빼기
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