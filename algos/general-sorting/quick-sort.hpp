#pragma once
#include <iostream>
using namespace std;

class Quicksort {
  public:
	// Performs quicksort on the array from index low to high
	void sort(int arr[], int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(arr, low, high);
			sort(arr, low, pivot - 1);
			sort(arr, pivot + 1, high);
		}
	}

	// Utility function to print the array
	void print(int arr[], int n) const
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

  private:
	// Partition function using Lomuto partition scheme
	int partition(int arr[], int low, int high)
	{
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (arr[j] < pivot)
			{
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, high);
		return i + 1;
	}

	// Swaps elements at indices a and b
	void swap(int arr[], int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
};
