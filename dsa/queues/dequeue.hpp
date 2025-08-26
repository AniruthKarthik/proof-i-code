#include <iostream>
using namespace std;

class Dequeue {
  private:
	int capacity;
	int *arr;
	int front;
	int rear;
	int count;

  public:
	Dequeue(int x) : capacity(x), front(-1), rear(-1), count(0), arr(new int[x])
	{
	}

	~Dequeue() { delete[] arr; }

	bool is_empty() { return count == 0; }
	bool is_full() { return count == capacity; }

	void push_front(int val)
	{
		if (is_full())
		{
			cout << "Dequeue overflow\n";
			return;
		}
		if (is_empty())
		{
			front = rear = 0;
		}
		else
		{
			front = (front - 1 + capacity) % capacity;
		}
		arr[front] = val;
		count++;
	}

	void push_back(int val)
	{
		if (is_full())
		{
			cout << "Dequeue overflow\n";
			return;
		}
		if (is_empty())
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % capacity;
		}
		arr[rear] = val;
		count++;
	}

	void pop_front()
	{
		if (is_empty())
		{
			cout << "Dequeue underflow\n";
			return;
		}
		if (front == rear)
		{ // only one element
			front = rear = -1;
		}
		else
		{
			front = (front + 1) % capacity;
		}
		count--;
	}

	void pop_back()
	{
		if (is_empty())
		{
			cout << "Dequeue underflow\n";
			return;
		}
		if (front == rear)
		{ // only one element
			front = rear = -1;
		}
		else
		{
			rear = (rear - 1 + capacity) % capacity;
		}
		count--;
	}

	int get_front()
	{
		if (is_empty())
		{
			cout << "Deque empty\n";
			return -1;
		}
		return arr[front];
	}

	int get_back()
	{
		if (is_empty())
		{
			cout << "Deque empty\n";
			return -1;
		}
		return arr[rear];
	}

	void display()
	{
		if (is_empty())
		{
			cout << "Deque empty\n";
			return;
		}
		int i = front;
		for (int c = 0; c < count; c++)
		{
			cout << arr[i] << " ";
			i = (i + 1) % capacity;
		}
		cout << endl;
	}
};
