/// Q.2440
/// Link : https://www.acmicpc.net/problem/2440
///

#include <iostream>

using namespace std;

int num;

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = num - i; j > 0; j--)
        {
            cout << "*";
        }
        if (i < num - 1)cout << "\n";
    }
}