#include <iostream>
#include <string>

using namespace std;

class Solution {
    // 문제
    // 0인덱스인 문자열 block이 i번째 블록 색을 나타내는 'W'와 'B'로 이뤄진 문자열을 제공한다.
    // 'W'와 'B'는 각각 white와 black으로 표시한다.
    // 정수 k는 연속된 black 블록의 개수를 표시한다.
    // 한 작업마다 흰색 블록을 검정색 블록으로 바꿀수 있다.
    // 최소 작업 개수를 반환해라

    // 해결
    // 투포인터로 구간 유지하면서 작업개수 확인하고 최소값을 저장하기
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int w_count = 0, result;

        // 초기 구간 (첫 k개)에서 'W' 개수 세기
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') w_count++;
        }
        result = w_count; // 첫 번째 구간의 'W' 개수를 결과값으로 초기화

        // 슬라이딩 윈도우 이동 
        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') w_count--; // 왼쪽 끝 제거
            if (blocks[i] == 'W') w_count++; // 오른쪽 끝 추가
            result = min(result, w_count); // 최소값 갱신
        }

        return result;
    }
};

int main()
{
    Solution sol = Solution();

    string s = "BWWWBB";
    sol.minimumRecolors(s, 6);
}