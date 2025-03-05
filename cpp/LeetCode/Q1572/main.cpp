#include <iostream>
#include <vector>

int diagonalSum(std::vector<std::vector<int>>& mat);

int main()
{
    std::vector<std::vector<int>> v =
    {
        {7,3,1,9},
        {3,4,6,9},
        {6,9,6,6},
        {9,5,8,5},
    };

    std::cout << diagonalSum(v);
}

int diagonalSum(std::vector<std::vector<int>>& mat)
{
    // 모양은 정사각형 모양의 행렬
    // 대각선 행렬의 합을 반환
    
    // 해결
    // 각 두 대각선 위치에서 1,1과 -1,-1을 더한 인덱스의 값을 가져온다.
    // 짝수면 모두 더하고
    // 홀수면 다 더한후 가운데 값을 뺀다.
    
        if (mat.size() == 1)
            return mat[0][0]; // 한 칸만 존재하면 그 값을 반환
    
        int left = 0;  // 0,0 시작 대각선
        int right = 0; // size-1, size-1에서 시작하는 대각선
    
        // left
        for (int i = 0; i < mat.size(); i++) {
            left += mat[1 * i][1 * i];
            std::cout << mat[1 * i][1 * i] << "\n";
        }
    
        // right
        for (int i = 0; i < mat.size(); i++) {
            right += mat[mat.size() - 1 - (1 * i)][1 * i];
            std::cout << mat[mat.size() - 1 - (1 * i)][1 * i] << "\n";
        }
    
        return mat.size() % 2 == 0
            ? left + right
            : left + right - mat[mat.size() / 2][mat.size() / 2];
}