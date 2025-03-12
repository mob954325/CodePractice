#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. 모두 같으면 10 * p + q의 제곱
// 2. 3개가 같고 하나가 다르면 (10 × p + q) * (10 × p + q);
// 3. 두 쌍이 같은 수면 p + q * |p - q|
// 4. 한 쌍이 같고 두 수가 다르면 서로 다른 숫자 곱셈
// 5. 모두 다르면 가장 작은 값 

// 4 
// 3 1 / 1 3
// 2 2
// 2 1 1 / 1 2 1 / 1 1 2
// 1 1 1 1

// 해결
// 배열에 나온 숫자 정리
int solution(int a, int b, int c, int d) {
    int answer = 0;

    int nums[7] = { 0, };
    int n = sizeof(nums) / sizeof(int);
    nums[a]++;
    nums[b]++;
    nums[c]++;
    nums[d]++;

    int three = 0, two = 0, one = 0, last = 0; // 3 2 1
    for (int i = 1; i < n; i++)
    {
        if(nums[i] == 4) return 1111 * i;
        else if(nums[i] == 3)
        {
            // 1 3
            if(one != 0) return (10 * i + one) * (10 * i + one);
            else three = i;
        }
        else if(nums[i] == 2)
        {
            // 2 2            
            if (two != 0 & one == 0) return (two + i) * abs(two - i);
            
            // 1 1 2
            if(one != 0 && last != 0) return one * last;                       

            two = i; 

        }
        else if(nums[i] == 1)
        {            
            // 3 1
            if(three != 0) return (10 * three + i) * (10 * three + i);
            
            // 1 2 1
            if(one != 0 && two != 0)
            {
                return one * i;
            }
            
            // 2 1 1
            if (two != 0 && one == 0) 
            {
                for(int j = i + 1; j < n; j++)
                {
                    if(nums[j] != 0) return j * i;
                }
            }
            
            if(one == 0) one = i;
            else last = i;            
        }
    }
    
    int min = one < last ? one : last;
    
    for(int i = min - 1; i > 0; i--)
    {
        if(nums[i] != 0) min = i < min ? i : min;
    }

    return min;
}