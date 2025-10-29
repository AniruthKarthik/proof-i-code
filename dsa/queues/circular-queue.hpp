#include <iostream>
#pragma once
using namespace std;

class Queue {
  private:
	int *arr;
	int front;
	int rear;
	int capacity;
	int count;

  public:
	Queue(int size)
	{
		capacity = size;
		arr = new int[capacity];
		front = 0;
		rear = -1;
		count = 0;
	}

	~Queue() { delete[] arr; }

	void enqueue(int value)
	{
		if (is_full())
		{
			cout << "Queue Overflow! Cannot enqueue " << value << "\n";
			return;
		}
		rear = (rear + 1) % capacity;
		arr[rear] = value;
		count++;
	}

	int dequeue()
	{
		if (is_empty())
		{
			cout << "Queue Underflow! Cannot dequeue.\n";
			return -1;
		}
		int value = arr[front];
		front = (front + 1) % capacity;
		count--;
		return value;
	}

	int peek() const
	{
		if (is_empty())
		{
			cout << "Queue is empty.\n";
			return -1;
		}
		return arr[front];
	}

	bool is_empty() const { return count == 0; }

	bool is_full() const { return count == capacity; }

	void print() const
	{
		cout << "Queue (Front to Rear): ";
		for (int i = 0; i < count; ++i)
		{
			cout << arr[(front + i) % capacity] << " ";
		}
		cout << "\n";
	}
};
