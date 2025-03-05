#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2);

int main()
{
    std::string n1 = "123", n2 = "456";
    std::cout << multiply(n1, n2);
}

std::string multiply(std::string num1, std::string num2)
{
        // 변환하지 않고 음수가 아닌 두 문자열형태의 정수를 곱하기
        
        // 0 곱셈 처리
        if (num1 == "0" || num2 == "0") return "0";

        // 숫자 개수만큼 있는 vector
        std::vector<int> num(num1.size() + num2.size(), 0);

        // 한번에 한자릿수를 곱하여 숫자 구성
        for(int i = num1.size() - 1; i >= 0; --i)
        {
            for(int j = num2.size() - 1; j >= 0; --j)
            {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // 곱셈
                num[i + j] += num[i + j + 1] / 10; // 10을 초과하면 자릿수 올리기
                num[i + j + 1] %= 10;              // -10 
            }
        }

        // 0인 칸 체크 (문자열 변환 시 먼저 0이 나오는 것 방지)
        int i = 0;
        while(1 < num.size() && num[i] == 0) ++i;

        // vector를 문자열로 변환
        std::string res = "";
        while(i < num.size()) res.push_back(num[i++] + '0'); // 문자 추가 , i번째부터 변환

        return res;    
}
