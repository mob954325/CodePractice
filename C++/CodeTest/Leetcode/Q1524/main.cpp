#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 문제
    // 정수 배열 제공
    // subarrays의 합이 홀수인 개수를 반환해라

    // 해결
    // 브루트 포스로 해보기 -> 시간초과
    // 수학?
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 0, answer = 0, modulus = (int)1e9 + 7;
        // odd, even은 각 배열의 합이 짝수인지 홀수인지에 대한 개수
        for (auto number : arr)
        {
            if (number % 2 == 0) even++; // 짝수 -> 짝 + 짝은 짝이므로 그냥 추가
            else // 홀수
            {
                swap(odd, even); // 홀 + 홀은 짝, 짝 + 홀을 홀이 되기 때문에 개수가 뒤바뀜
                odd++; // 본인 값 추가
            }
            answer = (answer % modulus + odd % modulus) % modulus;
        }
        return answer;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> v = { 1,2,3,4,7,9,11 };
    sol.numOfSubarrays(v);
}