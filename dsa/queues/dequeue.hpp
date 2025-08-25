#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *prev;
	Node *next;
	Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class Dequeue {
  private:
	int capacity;
	int *arr;
	int front;
	int rear;
	int count;

  public:
	Dequeue(int x)
	    : capacity(x), front(0), rear(0), count(0), arr(new int[capacity]) {};

	bool is_empty() { return count == 0; }

	bool is_full() { return count == capacity; }

	void push_front(int val)
	{
		if (is_empty())
		{
			cout << "Dequeue underflow" << endl;
		}
		if (front == -1)
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
};
