#include<iostream>
#include<vector>
using namespace std;


int wrapper(vector<int>&vec){
    int res=0;
    // for the bottom and the top
    res+=2*vec.size();
    res+=2*(vec[0]);
    for(int i=0;i<vec.size()-1;i++){
        // for the sides
        res+=2*(vec[i+1]);
        // for the gaps
        res+=abs(vec[i]-vec[i+1]);
    }
    // for the end
    res+=vec[0];
    res+=vec[vec.size()-1];

    return res;
}

int main(){
    vector<int>vec={1,2,3,1,1,1,4};
    cout<<wrapper(vec);
    
    return 0;
}