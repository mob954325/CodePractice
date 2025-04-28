#include <string>
#include <vector>
#include <stack>

using namespace std;

// 문제
// 네트워크 개수 찾기
// 간선에 연결된 노드들을 하나의 네트워크로 한다.
// 1. 방문 리스트 초기화
// 2. BFS로 탐색하여 모든 요소들을 탐색한다.
// 3. BFS가 끊긴 빈도수가 네트워크 개수이다.

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> visited(computers.size(), false);
    stack<int> s;
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i]) continue; // 방문한 노드 무시

        s.push(i);
        while (!s.empty())
        {
            int currNode = s.top();
            s.pop();
            visited[currNode] = true;
            for (int j = 0; j < computers[currNode].size(); j++)
            {
                if (currNode == j) continue; // 같은 노드 무시

                if (!visited[j] && computers[currNode][j] == 1)
                {
                    s.push(j);
                }
            }
        }

        answer++;
    }

    return answer;
}