#include <iostream>
#include <algorithm>
#include <vector>

bool compare(int i, int j) {
	if (j == 0) return true;
	else return false;
}

void moveZeroes(std::vector<int>& nums);

int main()
{
	std::vector<int> v = { -58305,-22022,0,0,0,0,0,-76070,42820,48119,0,95708,-91393,60044,0,-34562,0,-88974 };
	moveZeroes(v);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
}

void moveZeroes(std::vector<int>& nums) 
{
	int count = 0;
	int size = nums.size();

	for (std::vector<int>::iterator it = nums.begin(); count != size;)
	{
		if (*it == 0)
		{
			it = nums.erase(it);
			nums.push_back(0);
		}
		else
		{
			++it;
		}
		++count;
	}
}