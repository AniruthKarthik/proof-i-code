#include <iostream>
#include <queue>
using namespace std;

class StackofQueue{
private:
    queue<int>q;


public:
    void push(int x){
        q.push(x);
        int size=q.size()-1;
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        q.pop();
    }

    int top(){
        return q.front();
    }

    bool empty(){
        return q.empty();
    }

    void display(){
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        queue<int> temp = q;
        while (!temp.empty()) {
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }

};

int main(){
    StackofQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    cout<<"current top: "<<s.top()<<endl;
    s.pop();
    cout<<"the stack after performing a single pop\n";
    s.display();

}
