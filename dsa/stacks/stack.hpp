#include <iostream>
#pragma once
using namespace std;

class Stack {
  private:
	int *arr;
	int top;
	int capacity;

  public:
	Stack(int size)
	{
		capacity = size;
		arr = new int[capacity];
		top = -1;
	}

	~Stack() { delete[] arr; }

	void push(int value)
	{
		if (is_full())
		{
			cout << "Stack Overflow! Cannot push " << value << "\n";
			return;
		}
		arr[++top] = value;
	}

	int pop()
	{
		if (is_empty())
		{
			cout << "Stack Underflow! Cannot pop.\n";
			return -1;
		}
		return arr[top--];
	}

	int peek() const
	{
		if (is_empty())
		{
			cout << "Stack is empty.\n";
			return -1;
		}
		return arr[top];
	}

	bool is_empty() const { return top == -1; }

	bool is_full() const { return top == capacity - 1; }

	void print() const
	{
		if (is_empty())
		{
			cout << "Stack is empty.\n";
			return;
		}
		cout << "Stack (Top to Bottom): ";
		for (int i = top; i >= 0; --i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};
