#include <string>
#include <vector>

using namespace std;

// 1 2 3 4
// 12 13 14 5
// 11 16 15 6
// 10 9 8 7

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));

    int count = 1, d = 0, i = 0, j = 0;
    // 오른쪽 아래, 왼쪽 위 -> 반복 
    int dx[4] = { 1, 0 ,-1, 0 };
    int dy[4] = { 0, 1, 0 , -1 };
    answer[i][j] = count++;

    while (count <= n * n)
    {
        i += dy[d];
        j += dx[d];

        if ((i < 0 || j < 0 || i == n || j == n) || (answer[i][j] != 0))
        {
            i -= dy[d];
            j -= dx[d];
            d++;
            d %= 4;
            continue;
        }

        answer[i][j] = count++;

        // d가 바뀌는 조건 
        // 1. 배열 끝
        // 2. 다음 배열 값이 존재한다.
    }

    return answer;
}