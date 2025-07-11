#include <iostream>
using namespace std;

class Queue{

private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap){
        capacity=cap;
        arr=new int[cap];
        front=0;
        rear=-1;
        size=0;
    }

    void enqueue(int val){
        if(size==capacity){
            cout<<"stack overflow\n";
            return;
        }
        rear=(rear+1)%capacity;
        arr[rear]=val;
        size++;
    }

    void dequeue(){
        if(size==0){
            cout<<"queue underflow\n";
            return;
        }
        front=(front+1)%capacity;
        size--;
    }

    int peek(){
        if(size==0){
            cout << "queue is empty\n";
            return -1;
        }
        return arr[front];

    }

    bool is_empty(){
        return (size==0)?true:false;
    }

    ~Queue(){
        delete []arr;
    }
};

int main(){
    Queue* q=new Queue(5);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(25);

    cout<<"initial front: "<<q->peek()<<endl;
    q->dequeue();
    cout<<"front after dequeue: "<<q->peek()<<endl;

    return 0;
}
