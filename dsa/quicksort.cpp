#include <iostream>

class Quicksorter {
public:
    void sort(int arr[], int low, int high) {
        if (low < high) { 
            int pivot = partition(arr, low, high);
            sort(arr, low, pivot - 1);  
            sort(arr, pivot + 1, high); 
        }
    }

private:
    int partition(int arr[], int low, int high) {
        int pivot = arr[high]; 
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    void swap(int arr[], int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
};

int main() {
    int myarr[] = {11, 4, 5, 2, 35, 67, 2, 1, 3};
    int size = sizeof(myarr) / sizeof(myarr[0]);
    Quicksorter sorter;
    sorter.sort(myarr, 0, size - 1);

    for (int i : myarr) {
        std::cout << i << " ";
    }
    return 0;
}

