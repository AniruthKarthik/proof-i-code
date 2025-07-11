#include <iostream>
#include <ostream>
using namespace std;

class Stack{
private:
    int top;
    int size;
    int* arr;

public:
    Stack(int n){
        size=n;
        top=-1;
        arr=new int[size];
    }

    void push(int val){
        if(top>=size-2){
            cout<<"stack overflow\n";
            return;
        }
        arr[++top]=val;
    }

    void pop(){
        if(top<0){
            cout<<"stack underflow\n";
            return;
        }
        top--;
    }

    int peek(){
        if(top<0){
            cout<<"stack underflow\n";
            return -1;
        }
        return arr[top];

    }

    bool is_empty(){
        return (top<0)?true:false;
    }

    ~Stack(){
        delete []arr;
    }
};

int main(){

    Stack* stack=new Stack(5);

    stack->push(2);
    stack->push(3);
    stack->push(4);

    cout<<"the top element if the stack is "<<stack->peek()<<endl;

    stack->pop();
    cout<<"the top element after pop is "<<stack->peek()<<endl;

    return 0;
}

