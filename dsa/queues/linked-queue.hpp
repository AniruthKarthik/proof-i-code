#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int x) : next(nullptr), val(x) {};
};

class LinkedQueue {
  private:
	Node *front;
	Node *rear;

  public:
	LinkedQueue() : front(nullptr), rear(nullptr) {};

	void enqueue(int val)
	{
		Node *newnode = new Node(val);
		if (rear == nullptr)
		{
			front = rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}

	int dequeue(int val)
	{
		if (front == nullptr)
		{
			cout << "queue overflow" << endl;
			return -1;
		}
		else
		{
			Node *tobedel = front;
			int x = tobedel->val;
			front = front->next;
			delete tobedel;
			return x;
		}
	}

	int peek()
	{
		if (is_empty())
		{
			cout << "queue empty" << endl;
			return -1;
		}
		else
		{
			return front->val;
		}
	}

	void display()
	{
		Node *temp = front;
		while (temp != nullptr)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	bool is_empty() { return front == nullptr; }
};
