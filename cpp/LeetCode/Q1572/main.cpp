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
    // ����� ���簢�� ����� ���
    // �밢�� ����� ���� ��ȯ
    
    // �ذ�
    // �� �� �밢�� ��ġ���� 1,1�� -1,-1�� ���� �ε����� ���� �����´�.
    // ¦���� ��� ���ϰ�
    // Ȧ���� �� ������ ��� ���� ����.
    
        if (mat.size() == 1)
            return mat[0][0]; // �� ĭ�� �����ϸ� �� ���� ��ȯ
    
        int left = 0;  // 0,0 ���� �밢��
        int right = 0; // size-1, size-1���� �����ϴ� �밢��
    
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