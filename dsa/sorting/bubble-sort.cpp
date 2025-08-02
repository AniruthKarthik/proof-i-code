#include <iostream>
#include <ostream>

class BubbleSort {
  public:
	void bubble_sort(int arr[], int n)
	{
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n - k - 1; i++)
			{
				if (arr[i + 1] < arr[i])
				{
					swap(arr, i, i + 1);
				}
			}
		}
	}
	void swap(int arr[], int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
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
	int arr[] = {2323, 32, 2342, 2, 12, 43, 0};
	int len = sizeof(arr) / sizeof(arr[0]);
	std::cout << "the og array " << std::endl;
	print_array(arr, len);
	BubbleSort sorter;
	sorter.bubble_sort(arr, len);
	std::cout << "the array after bubble sort " << std::endl;
	print_array(arr, len);
}
