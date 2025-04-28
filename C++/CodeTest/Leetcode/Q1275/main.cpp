#include <iostream>
#include <vector>

std::string tictactoe(std::vector<std::vector<int>>& moves);

int main()
{
    std::vector<std::vector<int>> v2 = 
    {
        {0, 0},
        {2, 0},
        {1, 1},
        {2, 1},
        {2, 2}
    };
    tictactoe(v2);
}

std::string tictactoe(std::vector<std::vector<int>>& moves)
{
    // 틱택토 승리자 찾기
    // 틱택토 규칙
    // 1. 플레이어는 빈칸(' ')에 문자를 채워넣는다.
    // 2. 첫 플레이어(A)는 'X'를 놓는다.
    // 3. 두번째 플레이어(B)는 'O'를 놓는다.
    // 4. x, o는 항상 빈칸에만 채워진다.
    // 5. 같은 문자가 가로, 세로, 대각선 한 줄로 채워져있으면 게임은 끝난다.
    // 6. 또한 빈칸이 없으면 게임이 끝난다.
    // 7. 게임이 끝나면 더이상 움직이지 않는다.
    
    // moves에 2D배열 정수가 재공된다.
    // i번째 = [row, col]를 나타낸다.
    // 반환 : (승리자)A, B, (무승부)Draw, (Pending)보류

    // [0,0] [0,1] [0,2]
    // [1,0] [1,1] [1,2]
    // [2,0] [2,1] [2,2]

    // 해결
    // 1. 가로 세로 확인 
    // 1.1 동일한 x좌표값이 3개 또는 y좌표값이 3개 있으면 한 줄 (ex> [0,1][0,2][0,3])
    // 2. 대각선 확인
    // 2.1 (0,0)(1,1)(2,2) : 서로같은 좌표값이 3개 있다
    // 2.2 (0,2)(1,1)(2,0) : x == 2 - y에 해당하는 값이 3개 있다.
    
    // 배열 확인
    // 0, 1, 2 : x좌표 (조건 1.1)
    // 3, 4, 5 : y좌표 (조건 1.1)
    // 6 : 대각선1 (조건 2.1) 
    // 7 : 대각선2 (조건 2.2)
    
    std::vector<int> A(8, 0), B(8, 0);
    int size = moves.size();
    int playerA = 0;
    int playerB = 0;

    for (int i = 0; i < size; i++)
    {
        int row = moves[i][0];
        int col = moves[i][1];

        std::vector<int>& player = (i % 2 == 0) ? A : B;
        player[row]++;
        player[col + 3]++;
        if (row == col) player[6]++;        // 2.1
        if (row == 2 - col) player[7]++;    // 2.2
    }

    for (int i = 0; i < 8; i++)
    {
        if (A[i] == 3) return "A";
        if (B[i] == 3) return "B";
    }

    return size == 9 ? "Draw" : "Pending"; // 위 조건 외 모든 칸이 차있으면 비김, 안차있으면 게임 진행중
}