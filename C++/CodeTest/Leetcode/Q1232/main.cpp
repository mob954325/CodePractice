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
    // 좌표값이 주어질 때 해당 좌표값의 배열이 일직선인지 확인
    // [i] = [x, y];

    // 해결
    // x와 y 차이 값의 비율 확인하기 (ex> 4 : 8 = 1 : 2 -> true)
    // diff_x * curDiff_y == diff_y * curDiff_x -> true
    // 배열의 순서가 랜덤임


    if (coordinates.size() == 2) return true; // 좌표값이 2개만 있으면 true

    sort(coordinates.begin(), coordinates.end());

    int diff_x = coordinates[1][0] - coordinates[0][0];
    int diff_y = coordinates[1][1] - coordinates[0][1];

    for (int i = 1; i < coordinates.size() - 1; i++) {
        // 서로 다르면 확인
        int curDiff_x = coordinates[i + 1][0] - coordinates[i][0];
        int curDiff_y = coordinates[i + 1][1] - coordinates[i][1];
        

        if ((diff_x != 0 || diff_y != 0) && // 가로나 세로 모양이 아닐 때 
            diff_x * curDiff_y != diff_y * curDiff_x) return false; //
    }

    return true;
}