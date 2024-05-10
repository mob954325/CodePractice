#include <iostream>
#include <queue>
#define MAX 100000
#define MAX_LENGTH 1000000000;

using namespace std;

int n, k, result = MAX_LENGTH; // 회사, 케이블 수, 결과값
priority_queue<int> pq;
int save[MAX];

int main()
{
    cin >> n >> k;

    int temp, used = 0;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        pq.push(-input);
        save[i] = input;
    }

    int first, second;

    if ((n - 1) / 2 < k) k -= 1;

    for (int loop = 0; loop < n; loop++)
    {
        temp = 0;
        used = 0;

        for (int i = 0; i < k; i++)
        {
            if (loop == i)
            {
                pq.pop();
                used++;
            }

            first = pq.top();
            pq.pop();
            used++;

            second = pq.top();
            pq.pop();
            used++;

            temp += (first - second);
        }
        result = min(result, temp);

        for (int i = 0; i < used; i++)
        {
            pq.push(save[i]);
        }
    }
    cout << result;
}