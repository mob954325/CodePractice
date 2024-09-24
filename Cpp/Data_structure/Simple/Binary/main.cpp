// 비트 연산자 사용 (&, ^, |, ~, <<, >>)

#include <iostream>

using namespace std;

/// <summary>
/// 두 개의 비트 모두가 1이면 1을 반환하는 연산자 &
///  <summary>
int Equality(int a, int b)
{
    return a & b;
}

/// <summary>
/// 두 개의 비트가 서로 다르면 1을 반환하는 연산자 ^
/// </summary>
int ExclusiveOR(int a, int b)
{
    return a ^ b;
}

/// <summary>
/// 두 개의 비트 중 하나만 1이면 1을 반환하는 연산자 |
/// </summary>
int InclusiveOR(int a, int b)
{
    return a | b;
}

/// <summary>
/// 비트 반전 연산 |
/// </summary>
int Inversion(int a)
{
    return ~a;
}

/// <summary>
/// 비트 왼쪽으로 옮기기
/// </summary>
int LeftShift(int a, int count)
{
    return a << count;
}

/// <summary>
/// 비트 오른쪽으로 옮기기
/// </summary>
int RightShift(int a, int count)
{
    return a >> count;
}

int main()
{
    int i = 243; // 1111 0011
    int j = 2;   // 0000 0010
    int result = 0;

    int k = -1;

    cout << "i : " << i << "\n"
         << "j : " << j << "\n\n";

    result = Equality(i, j);
    cout << "& : " << result << "\n";     // 0000 0010 = 2

    result = ExclusiveOR(i, j);
    cout << "^ : " << result << "\n";     // 1111 0001 = 241
    
    result = InclusiveOR(i, j);
    cout << "| : " << result << "\n";     // 1111 0011 = 243

    result = Inversion(j);
    cout << "~ : " << result << "\n";     // 11111111 11111111 11111111 11111110 = -3 (부호까지 반전) ?

    result = LeftShift(j, 1);
    cout << "~ : " << result << "\n";     // 0100 = 4

    result = RightShift(j, 1);
    cout << "~ : " << result << "\n";     // 0001 = 1
}