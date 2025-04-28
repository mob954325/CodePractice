#include <iostream>
#include <vector>

using namespace std;

// table
void computerLPSArray(string& pattern, vector<int>& lps)
{
	int m = pattern.length();
	int len = 0;

	lps.resize(m); // pattern의 길이 만큼 메모리 확보
	lps[0] = 0;

	int i = 1;
	while (i < m)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string& text, string& pattern)
{
	int n = text.length();
	int m = pattern.length();


	vector<int> lps;
	computerLPSArray(pattern, lps);

	int i = 0;
	int j = 0;

	while (i < n)
	{
		if (pattern[j] == text[i])
		{
			i++; j++;
		}

		if (j == m) // found
		{
			cout << i - j << "에서 발견 되었습니다." << endl;
			j = lps[j - 1];
		}
		else if (i < n && pattern[j] != text[i])
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
				i++;
		}

	}
}

void findSumSequence(vector<int>& arr, int targetNum)
{
	int n = arr.size();
	for (int i = 0; i + 1 < n; i++)
	{
		if (arr[i] + arr[i + 1] == targetNum)
		{
			cout << "합이 5인 연속 수열 [" << arr[i] << "," << arr[i + 1] << "]" << endl;
		}
	}

	if (arr[n - 1] == targetNum)
	{
		cout << "합이 5인 연속 수열 [" << arr[n - 1] << "]" << endl;
	}

}

int main()
{
	//string parent = "Hello World! Hello World";
	//string pattern = "llo W";
	//
	//KMPSearch(parent, pattern);

	vector<int> Number = { 1,2,3,4,5 };
	int m = 5;

	// O(n^2) 수열 구하기
	//for (int i = 0; i < Number.size(); i++)
	//{
	//	int sum = 0;
	//	for (int j = i; j < Number.size(); j++)
	//	{
	//		sum += Number[j];

	//		if (sum == m)
	//		{
	//			cout << "합이 5인 연속 수열 [";
	//			for (int s = i; s <= j; s++)
	//			{
	//				cout << Number[s] << " ";
	//			}
	//			cout << "]" << endl;
	//		}
	//	}
	//}

	// O(n) 수열 구하기
	findSumSequence(Number, m);

	return 0;
}