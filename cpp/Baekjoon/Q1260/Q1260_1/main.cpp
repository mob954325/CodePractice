#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

const int MAX = 1001;

std::vector<int> adjacencyList[MAX];
bool visited[MAX];

void DFS(int start) {
    std::stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            std::cout << current << " ";

            // 스택에는 큰 번호부터 작은 번호로 넣어야 작은 번호부터 방문
            for (auto it = adjacencyList[current].rbegin(); it != adjacencyList[current].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
}

void BFS(int start) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m, v;
    std::cin >> n >> m >> v;

    for (int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }

    // 인접 리스트 정렬
    for (int i = 1; i <= n; ++i) {
        std::sort(adjacencyList[i].begin(), adjacencyList[i].end());
    }

    // DFS
    std::fill(visited, visited + MAX, false);
    DFS(v);
    std::cout << "\n";

    // BFS
    std::fill(visited, visited + MAX, false);
    BFS(v);
    std::cout << "\n";

    return 0;
}
