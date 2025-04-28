#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& arr)
{
	int n = arr.size();

	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 0; i < n - k - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void SelectSort(vector<int>& arr)
{
	int n = arr.size();

	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void instertSort(vector<int>& arr)
{
	int n = arr.size();
}

void merge(vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}

	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while(i < n1)
	{
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		++j;
		++k;
	}
}

void mergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

bool IsPrimeNumber(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) return false;
	}

	return true;
}



int main()
{
	vector<int> arr = { 170,45,75,90,802,24,2,66 };

	cout << "정렬전 : ";

	for (int num : arr)
	{
		cout << num << ",";
	}

	cout << endl;

	//BubbleSort(arr);
	//SelectSort(arr);

	mergeSort(arr, 0, arr.size() - 1);

	cout << "정렬 후 : ";

	for (int num : arr)
	{
		cout << num << ",";
	}

	return 0;
}