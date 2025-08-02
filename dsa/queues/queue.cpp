#include <iostream>
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

int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	cout << "After enqueuing 5 elements:\n";
	q.print();

	cout << "Front of queue: " << q.peek() << "\n";

	q.dequeue();
	q.dequeue();
	cout << "After dequeuing 2 elements:\n";
	q.print();

	q.enqueue(60);
	q.enqueue(70);
	cout << "After enqueuing 60 and 70:\n";
	q.print();

	return 0;
}
