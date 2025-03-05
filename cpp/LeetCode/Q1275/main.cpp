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
    // ƽ���� �¸��� ã��
    // ƽ���� ��Ģ
    // 1. �÷��̾�� ��ĭ(' ')�� ���ڸ� ä���ִ´�.
    // 2. ù �÷��̾�(A)�� 'X'�� ���´�.
    // 3. �ι�° �÷��̾�(B)�� 'O'�� ���´�.
    // 4. x, o�� �׻� ��ĭ���� ä������.
    // 5. ���� ���ڰ� ����, ����, �밢�� �� �ٷ� ä���������� ������ ������.
    // 6. ���� ��ĭ�� ������ ������ ������.
    // 7. ������ ������ ���̻� �������� �ʴ´�.
    
    // moves�� 2D�迭 ������ ����ȴ�.
    // i��° = [row, col]�� ��Ÿ����.
    // ��ȯ : (�¸���)A, B, (���º�)Draw, (Pending)����

    // [0,0] [0,1] [0,2]
    // [1,0] [1,1] [1,2]
    // [2,0] [2,1] [2,2]

    // �ذ�
    // 1. ���� ���� Ȯ�� 
    // 1.1 ������ x��ǥ���� 3�� �Ǵ� y��ǥ���� 3�� ������ �� �� (ex> [0,1][0,2][0,3])
    // 2. �밢�� Ȯ��
    // 2.1 (0,0)(1,1)(2,2) : ���ΰ��� ��ǥ���� 3�� �ִ�
    // 2.2 (0,2)(1,1)(2,0) : x == 2 - y�� �ش��ϴ� ���� 3�� �ִ�.
    
    // �迭 Ȯ��
    // 0, 1, 2 : x��ǥ (���� 1.1)
    // 3, 4, 5 : y��ǥ (���� 1.1)
    // 6 : �밢��1 (���� 2.1) 
    // 7 : �밢��2 (���� 2.2)
    
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

    return size == 9 ? "Draw" : "Pending"; // �� ���� �� ��� ĭ�� �������� ���, ���������� ���� ������
}