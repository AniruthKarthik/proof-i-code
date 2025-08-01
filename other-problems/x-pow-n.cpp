#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;



class Solution {
public:
    unordered_map<long, double>memo;
    double f(double x, long n) {
        if (n == 0 || n == 1)
            return x;
        if(memo.count(n)){
            return memo[n];
        }
        if (n % 2 != 0)
            return x * f(x, n - 1);
        int res=1.0;
        if (n % 2 == 0) {
            double d = f(x, n / 2);
            cout<<d<<" ";
            res= d * d;
            memo[n]=res;
        }
        return res;
    }
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n >= 0) {
            return f(x, n);
        } else {
            double ans = f(x,-(long)n);
            return 1 / ans;
        }
    }
};

int main(){
    Solution sol;
    cout<<sol.myPow(2, 10);
}
