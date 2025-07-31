#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int min_cost(vector<int>&cost){
    int n=cost.size();
    for(int i=2;i<n;i++)
    {
        cost[i]+=min(cost[i-1],cost[i-2]);
    }
    return min(cost[n-1],cost[n-2]);
}


int main(){
    int n=10;
    vector<int>cost={10,15,20};

    cout<<min_cost(cost)<<endl;

    return 0;

}
