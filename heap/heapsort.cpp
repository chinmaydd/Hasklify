#include <bits/stdc++.h>
using namespace std;


void display(int *arr, int size)
{
	for (int i = 1; i <= size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int leftChild(int p)
{
	return (p * 2);
}

int rightChild(int p)
{
	return (p * 2 + 1);
}

void maxHeapify(int * arr, int i, int size)
{
	int largest = i;
	int left = leftChild(i);
	int right = rightChild(i);

	if (left <= size && arr[left] > arr[largest])
		largest = left;
	if (right <= size && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(arr, largest, size);
	}
}

void buildHeap(int *arr, int size)
{
	for (int i = floor(size / 2); i >= 1; i--)
		maxHeapify(arr, i, size);
}

void heapSort(int *arr, int size)
{
	int length = size;
	buildHeap(arr, size);
	for (int i = length; i >= 2; i--)
	{
		swap(arr[1], arr[i]);
		size -= 1;
		maxHeapify(arr, 1, size);
	}
}

int main()
{
	int size, arr[100000];

	cout << "Enter heap size.\n";
	cin >> size;

	cout << "Enter heap elements.\n";
	for (int i = 1; i <= size; i++)
		cin >> arr[i];

	heapSort(arr, size);
	display(arr, size);

	return 0;
}
