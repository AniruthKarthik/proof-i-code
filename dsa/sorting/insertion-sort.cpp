#include <iostream>

class InsertionSort {
  public:
	void swap(int arr[], int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	void insertion_sort(int arr[], int n)
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
};

void print_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
};

int main()
{
	int arr[] = {11, 4, 5, 2, 35, 67, 2, 1, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "the og array \n";
	print_array(arr, size);
	InsertionSort sorter;
	sorter.insertion_sort(arr, size);
	std::cout << "the array after insertion sort \n";
	print_array(arr, size);
	return 0;
}
