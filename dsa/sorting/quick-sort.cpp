#include <iostream>

class Quicksort {
public:
    void quick_sort(int arr[], int low, int high) {
        if (low < high) { 
            int pivot = partition(arr, low, high);
            quick_sort(arr, low, pivot - 1);  
            quick_sort(arr, pivot + 1, high); 
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

void print_array(int arr[],int n ){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
};

int main() {
    int arr[] = {11, 4, 5, 2, 35, 67, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout<<"the og array \n";
    print_array(arr, size);
    Quicksort sorter;
    sorter.quick_sort(arr, 0, size - 1);
    std::cout<<"the array after quick_sort \n";
    print_array(arr, size);
    return 0;
}

