#include <iostream>
#include <string>

using namespace std;

string parent;
string pattern;

int main()
{
	cout << "���ڿ� �Է� \n";
	cin >> parent;

	cout << "���� �Է� \n";
	cin >> pattern;

	int stringSize = parent.size();
	int patternSize = pattern.size();

	int value = 0;

	for (int i = 0; i < stringSize-patternSize; i++)
	{
		int count = 0;
		for (int j = 0; j < patternSize; j++)
		{
			if (pattern[j] == parent[i + j])
			{
				count++;
			}

			if (count == patternSize)
			{
				value = i;
				break;
			}
		}
	}
	cout << value+1;
}