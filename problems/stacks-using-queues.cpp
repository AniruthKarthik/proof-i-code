#include <vector>
using namespace std ;

class MyStack {
public:
    vector<int> vals ;
    int t;
    MyStack() {
        t=-1;
    }

    void push(int x) {
        vals.push_back(x);
        t++;
    }

    int pop() {
        if (t > -1) {
            int val = vals[t--];
            vals.pop_back();
            return val;
        } else {
            return -1;
        }
    }


    int top() {
        return vals[t];

    }

    bool empty() {
        return (t==-1)?true:false;

    }
};
