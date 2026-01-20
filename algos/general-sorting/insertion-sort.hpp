#pragma once
#include <iostream>

class InsertionSort {
  public:
	// Performs insertion sort on the array
	void sort(int arr[], int n)
	{
		for (int i = 1; i < n; i++)
		{
			int key = arr[i];
			int j = i - 1;

			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}

	// Utility to print the array
	void print(int arr[], int n) const
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
};
