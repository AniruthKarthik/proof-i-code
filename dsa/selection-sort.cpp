#include <iostream>

class SelectionSort{
  public:

  void selectionsort(int arr[],int n){

    for(int i=0;i<n-1;i++){
      int min_index=i;

      for(int j=i+1;j<n;j++){
        if(arr[j]<=arr[min_index]){
          min_index=j;
        }
      }
      swap(arr, i, min_index);
    }
  }

  void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
  }
};

void print_array(int arr[],int n){
  for(int i=0;i<n;i++){
    std::cout<<arr[i]<<" ";
  }
  std::cout<<"\n";
};

int main(){

  int arr[]={12,434,25,245,12,34,0};
  int len=sizeof(arr)/sizeof(arr[0]);
  std::cout<<"the og array "<<std::endl;
  print_array(arr,len);
  SelectionSort sorter;
  sorter.selectionsort(arr, len);
  std::cout<<"the array after selection sort "<<std::endl;
  print_array(arr, len);
  return 0;
}
