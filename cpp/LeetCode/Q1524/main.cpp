#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // ����
    // ���� �迭 ����
    // subarrays�� ���� Ȧ���� ������ ��ȯ�ض�

    // �ذ�
    // ���Ʈ ������ �غ��� -> �ð��ʰ�
    // ����?
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 0, answer = 0, modulus = (int)1e9 + 7;
        // odd, even�� �� �迭�� ���� ¦������ Ȧ�������� ���� ����
        for (auto number : arr)
        {
            if (number % 2 == 0) even++; // ¦�� -> ¦ + ¦�� ¦�̹Ƿ� �׳� �߰�
            else // Ȧ��
            {
                swap(odd, even); // Ȧ + Ȧ�� ¦, ¦ + Ȧ�� Ȧ�� �Ǳ� ������ ������ �ڹٲ�
                odd++; // ���� �� �߰�
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