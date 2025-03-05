#include <iostream>
#include <vector>
#include <algorithm>

bool checkStraightLine(std::vector<std::vector<int>>& coordinates);

int main()
{
    std::vector<std::vector<int>> v =
    {
        {2,4} ,{2,5}, {2,8} // true
    };

    std::vector<std::vector<int>> v2 =
    {
        {1,-8}, {2,-3}, {1,2} // false
    };

    std::vector<std::vector<int>> v3 =
    { 
        { 0, 1 }, { 1, 3 }, { -4, -7 }, { 5, 11 } // true
    };

    std::cout << std::boolalpha << checkStraightLine(v) << "\n";
    std::cout << std::boolalpha << checkStraightLine(v2) << "\n";
    std::cout << std::boolalpha << checkStraightLine(v3) << "\n";
}

bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
    // ��ǥ���� �־��� �� �ش� ��ǥ���� �迭�� ���������� Ȯ��
    // [i] = [x, y];

    // �ذ�
    // x�� y ���� ���� ���� Ȯ���ϱ� (ex> 4 : 8 = 1 : 2 -> true)
    // diff_x * curDiff_y == diff_y * curDiff_x -> true
    // �迭�� ������ ������


    if (coordinates.size() == 2) return true; // ��ǥ���� 2���� ������ true

    sort(coordinates.begin(), coordinates.end());

    int diff_x = coordinates[1][0] - coordinates[0][0];
    int diff_y = coordinates[1][1] - coordinates[0][1];

    for (int i = 1; i < coordinates.size() - 1; i++) {
        // ���� �ٸ��� Ȯ��
        int curDiff_x = coordinates[i + 1][0] - coordinates[i][0];
        int curDiff_y = coordinates[i + 1][1] - coordinates[i][1];
        

        if ((diff_x != 0 || diff_y != 0) && // ���γ� ���� ����� �ƴ� �� 
            diff_x * curDiff_y != diff_y * curDiff_x) return false; //
    }

    return true;
}