#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <ostream>


int main(){
    int n=13;
    int arr[15]={10,20,30,10,40,80,20,23,23,44,11,33,22,31,22};
    int prev1=0;
    int prev2=0;
    int two=abs(arr[2]-arr[0]);
    int cur=0;
    for(int i=1;i<n;i++){
        int os=prev1+abs(arr[i]-arr[i-1]);
        int ts=(i>1)?(prev2+abs(arr[i]-arr[i-2])):INT_MAX;
        cur=std::min(os,ts);
        prev2=prev1;
        prev1=cur;
    }
    std::cout<<cur<<std::endl;

    return 0;

}
