#include <iostream>

class ArrayQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    ArrayQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow! Cannot enqueue " << value << "\n";
            return;
        }
        rear++;
        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Cannot dequeue.\n";
            return -1;
        }
        int value = arr[front];
        front++;
        count--;
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void print() const {
        std::cout << "Queue (Front to Rear): ";
        for (int i = front; i <= rear; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

