#include <iostream>
#include <vector>
#include <algorithm>

bool canMakeArithmeticProgression(std::vector<int>& arr);

int main()
{
	std::vector<int> v = { 7, -7, 14, 0 };

	std::cout << std::boolalpha << canMakeArithmeticProgression(v);
}

bool canMakeArithmeticProgression(std::vector<int>& arr)
{
	std::sort(arr.begin(), arr.end()); 
	
	int diff = arr[0] - arr[1];
	int size = arr.size();

	for (int i = 1; i < size - 1; i++)
	{
		int curDiff = arr[i] - arr[i + 1];

		if (curDiff != diff)
		{
			return false;
		}
	}

	return true;
}