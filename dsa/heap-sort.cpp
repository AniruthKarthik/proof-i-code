#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); 
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);       
        heapify(arr, i, 0);         
    }
}

void print_vector(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "The original unsorted array:\n";
    print_vector(arr);

    heap_sort(arr);

    cout << "The array after heap sort:\n";
    print_vector(arr);

    return 0;
}
