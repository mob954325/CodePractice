#include <iostream>
#include <vector>
#include <algorithm>

double average(std::vector<int>& salary);

int main()
{
    std::vector<int> v = { 48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000 };

    std::cout << average(v);
}

double average(std::vector<int>& salary) {
    // salary는 각 i번째 직원의 급여 제공한다.
    // 최소, 최대를 제외한 직원들 평균 급여를 반환해라
    // 10^-5이내의 값을 반환해야한다.

    // 해결
    // 짝수, 직원수 / 2의 가장 가까운 직원 2명의 평균 
    // 홀수 직원수 / 2의 평균

    sort(salary.begin(), salary.end());
    int size = salary.size();
    int sum = 0;

    for (int i = 1; i < size - 1; i++)
    {
        sum += salary[i];
    }

    return (double)sum / (size - 2);
}