#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
  public:
	// Public function to sort the entire vector
	static void sort(vector<int> &arr)
	{
		if (arr.empty())
			return;
		mergesort(arr, 0, arr.size() - 1);
	}

	// Utility function to print the vector
	static void print(const vector<int> &vec)
	{
		cout << "< ";
		for (int val : vec)
		{
			cout << val << " ";
		}
		cout << ">" << endl;
	}

  private:
	static void mergesort(vector<int> &arr, int low, int high)
	{
		if (low < high)
		{
			int mid = (low + high) / 2;
			mergesort(arr, low, mid);
			mergesort(arr, mid + 1, high);
			merge(arr, low, mid, high);
		}
	}

	static void merge(vector<int> &arr, int left, int mid, int right)
	{
		vector<int> temp;
		int i = left;
		int j = mid + 1;

		while (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j])
			{
				temp.push_back(arr[i++]);
			}
			else
			{
				temp.push_back(arr[j++]);
			}
		}

		while (i <= mid)
		{
			temp.push_back(arr[i++]);
		}

		while (j <= right)
		{
			temp.push_back(arr[j++]);
		}

		for (int k = left; k <= right; k++)
		{
			arr[k] = temp[k - left];
		}
	}
};
