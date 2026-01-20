#pragma once
#include <iostream>
using namespace std;

class SelectionSort {
  public:
	// Performs selection sort on the given array
	void sort(int arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int min_index = i;

			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] <= arr[min_index])
				{
					min_index = j;
				}
			}

			swap(arr, i, min_index);
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
	// Swaps two elements in the array
	void swap(int arr[], int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
};
