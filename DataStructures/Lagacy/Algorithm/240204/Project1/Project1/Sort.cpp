#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];

	int i = low-1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i + 1], arr[high]);
		}
	}

	swap(arr[i + 1], arr[high]);

	return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi, high);
	}
}

void maxHeapify(vector<int>& arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void HeapSort(vector<int>& arr)
{
	int size = arr.size();

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		maxHeapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}

int main()
{
	vector<int> arr = { 12,11,13,5,6,7,100 };

	cout << "정렬전 배열 : ";
	for (int num : arr)
	{
		cout << num << " ";
	}

	cout << endl;

	HeapSort(arr);

	cout << "정렬 후 배열 : ";
	for (int num : arr)
	{
		cout << num << " ";
	}

	cout << endl;
}