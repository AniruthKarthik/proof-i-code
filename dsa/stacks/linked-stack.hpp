#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int x) : next(nullptr), val(x) {};
};

class LinkedStack {
  private:
	Node *top;

  public:
	LinkedStack() : top(nullptr) {};

	void push(int x)
	{
		Node *newnode = new Node(x);
		newnode->next = top;
		top = newnode;
	}

	int pop()
	{
		if (is_empty())
		{
			cout << "stack underflow" << endl;
			return -1;
		}
		Node *tobeldel = top;
		int x = tobeldel->val;
		top = top->next;
		delete tobeldel;
		return x;
	}

	bool is_empty() { return top == nullptr; }

	int peek()
	{
		if (is_empty())
		{
			cout << "stack empty" << endl;
			return -1;
		}
		return top->val;
	}

	void display()
	{
		Node *temp = top;
		while (temp != nullptr)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
