#include <iostream>
#include <iterator>
#include <vector>
using namespace std ;

class MergeSort{
  public:

  static void mergesort(vector<int>&arr,int low,int high){
    if(low<high){
      int mid=(low+high)/2;
      mergesort(arr, low, mid);
      mergesort(arr, mid+1, high);

      merge(arr,low,mid,high );

    }
    return;
  }

  static void merge(vector<int>&arr,int left,int mid,int right){
    vector<int>temp;
    int i=left;
    int j=mid+1;
    while (i<=mid && j<=right) {
      if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
      }
      else{
        temp.push_back(arr[j]);
        j++;
    }}
    while (i<=mid) {
    temp.push_back(arr[i]);
    i++;
    }

    while (j<=right) {
    temp.push_back(arr[j]);
    j++;
    }
    for (int k= left;k<=right;k++) {
    arr[k]=temp[k-left];
    }
  }
};

void print_vector(vector<int>&vec){
  cout<<"< ";
  for(int i:vec){
    cout<<i<<" ";
  }
  cout<<">"<<endl;
}

int main(){
  vector<int> vec={23,54,31,3,4,1,3,4,54};
  cout<<"the og list"<<endl;
  print_vector(vec);
  MergeSort sorter;
  sorter.mergesort(vec,0,vec.size()-1);
  cout<<"the same list after mergesort"<<endl;
  print_vector(vec);

  
}
