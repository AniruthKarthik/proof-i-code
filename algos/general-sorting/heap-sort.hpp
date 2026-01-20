#pragma once
#include <iostream>
#include <vector>
using namespace std;

class HeapSorter {
  public:
	// Sorts the given vector using heap sort
	void sort(vector<int> &arr)
	{
		int n = arr.size();

		// Build max heap
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i);
		}

		// One by one extract elements
		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}

	// Prints the contents of the vector
	void print(const vector<int> &arr) const
	{
		for (int val : arr)
		{
			cout << val << " ";
		}
		cout << "\n";
	}

  private:
	// Maintains the heap property for subtree rooted at index i
	void heapify(vector<int> &arr, int n, int i)
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
			heapify(arr, n, largest);
		}
	}
};
