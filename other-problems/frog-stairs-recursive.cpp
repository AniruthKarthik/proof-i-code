#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>

int f(int index,int h[]){
    if (index==0) return 0;
    int onestep=f(index-1,h)+abs(h[index]-h[index-1]);
    int twostep=1000;
    if(index>1){
        twostep=f(index-2,h)+abs(h[index]-h[index-2]);
    }
    return std::min(onestep,twostep);
}

int main(){
    int n=13;
    int arr[15]={10,20,30,10,40,80,20,23,23,44,11,33,22,31,22};
    std::cout<<f(n,arr);

}

