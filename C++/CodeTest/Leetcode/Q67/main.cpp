#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b);

int main()
{
    std::string a = "100";
    std::string b = "110010";
    std::cout << addBinary(a, b) << "\n"; // 11110
}

// 100011

std::string addBinary(std::string a, std::string b) 
{
    // 이진 문자열 a b를 더하시오

    // 해결
    // 문자로 해결해야함 ( 최대 길이 => 10^4 2개 -> 오버플로우 )
    // 1. two pointer
    // 2. a와 b 포인터의 위치값이 둘다 1이다 == 해당 위치값을 0,
    // 다음 위치값에 1 추가

    int pointerA = a.length() - 1;
    int pointerB = b.length() - 1;
    int pointerS = 0; // 가장 큰 자릿수의 포인터 값 ( 값 존재여부 확인용 )
    std::string s = "";

    while (pointerA >= 0 && pointerB >= 0) // ??
    {
        if (a[pointerA] == '1' && b[pointerB] == '1') // 둘다 1이다.
        {
            if (s[pointerS] == '1')
            {
                s[pointerS] = '1';
                s += "1";  
            }
            else 
            {
                s += "0";
                s += "1"; 
            }  
        }
        else if (a[pointerA] == '0' && b[pointerB] == '0') // 둘다 0
        {
            if (s[pointerS] != '1') s += "0";   // 해당 위치에 값이 없으면 추가
        }
        else // 서로 다름
        {
            if (s[pointerS] == '1') // 이미 1이 있으면 자릿수 넘기기
            {
                s[pointerS] = '0';
                s += "1";
            }
            else // 값이 없다.
            {
                s += "1";
            }
        }

        pointerA--;
        pointerB--;
        pointerS++;
    }

    // 남은 배열 처리 ( s위치값과 나머지 더하기 )
    if (pointerA < 0)
    {
        while (pointerB >= 0)
        {
            if (s[pointerS] == '1')
            {
                if (b[pointerB] == '1')
                {
                    s[pointerS] = '0';
                    s += "1";
                }
            }
            else /// 값이 없다
            {
                if (b[pointerB] == '1')
                {
                    s += '1';
                }
                else
                {
                    s += '0';
                }
            }

            pointerB--;
            pointerS++;
        }
    }
    else if (pointerB < 0)
    {
        while (pointerA >= 0)
        {
            if (s[pointerS] == '1')
            {
                if (a[pointerA] == '1')
                {
                    s[pointerS] = '0';
                    s += "1";
                }
            }
            else // 값이 없다
            {
                if (a[pointerA] == '1')
                {
                    s += '1';
                }
                else
                {
                    s += '0';
                }
            }

            pointerA--;
            pointerS++;
        }
    }

    reverse(s.begin(), s.end());

    return s;
}