#include <iostream>

int countOdds(int low, int high);

int main()
{
	int low = 3;
	int high = 7;
	std::cout << countOdds(low, high);
}

int countOdds(int low, int high) {
    // 음수가 아닌 정수 low, high
    // low이상 high이하 내에서 홀수인 숫자의 개수 반환

    // 해결
    // 1과 low - 1 사이의 홀수 개수는 low / 2
    // 1과 high 사이의 홀수 개수는 (high + 1) / 2
    // 위에 답에서 얻은 것
    // (1에서 high사이의 모든 홀수 개수) - (1과 low -1 사이의 홀수개수) 

    return ((high + 1) / 2) - (low / 2);
}
