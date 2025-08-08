#include <iostream>
#include <stdexcept>
#pragma once

class Node {
  public:
	int val;
	Node *next;

	Node(int value) : val(value), next(nullptr) {}
};

class LinkedList {
  private:
	Node *head;

  public:
	LinkedList() : head(nullptr) {}

	// Add at the beginning
	void add_at_first(int value)
	{
		Node *new_node = new Node(value);
		new_node->next = head;
		head = new_node;
	}

	// Add at the end
	void add_at_last(int value)
	{
		Node *new_node = new Node(value);
		if (head == nullptr)
		{
			head = new_node;
			return;
		}

		Node *temp = head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = new_node;
	}

	// Add at a specific position (0-based)
	void add_at_position(int pos, int value)
	{
		if (pos <= 0 || head == nullptr)
		{
			add_at_first(value);
			return;
		}

		Node *temp = head;
		int index = 0;
		while (temp != nullptr && index < pos - 1)
		{
			temp = temp->next;
			index++;
		}

		Node *new_node = new Node(value);
		if (temp == nullptr)
		{
			std::cout << "Position out of range. Adding at last.\n";
			add_at_last(value);
			return;
		}

		new_node->next = temp->next;
		temp->next = new_node;
	}

	// Delete node by value
	void delete_node(int value)
	{
		if (head == nullptr)
			return;

		if (head->val == value)
		{
			Node *to_delete = head;
			head = head->next;
			delete to_delete;
			return;
		}

		Node *temp = head;
		while (temp->next != nullptr && temp->next->val != value)
		{
			temp = temp->next;
		}

		if (temp->next != nullptr)
		{
			Node *to_delete = temp->next;
			temp->next = temp->next->next;
			delete to_delete;
		}
	}

	// Delete node by position
	void delete_at_position(int pos)
	{
		if (head == nullptr || pos < 0)
			return;

		if (pos == 0)
		{
			Node *to_delete = head;
			head = head->next;
			delete to_delete;
			return;
		}

		Node *temp = head;
		int index = 0;
		while (temp != nullptr && index < pos - 1)
		{
			temp = temp->next;
			index++;
		}

		if (temp == nullptr || temp->next == nullptr)
			return;

		Node *to_delete = temp->next;
		temp->next = temp->next->next;
		delete to_delete;
	}

	// Reverse the list
	void reverse()
	{
		Node *prev = nullptr;
		Node *curr = head;
		while (curr != nullptr)
		{
			Node *next_node = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next_node;
		}
		head = prev;
	}

	// Search for a value
	bool search(int value) const
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			if (temp->val == value)
				return true;
			temp = temp->next;
		}
		return false;
	}

	// Get length of the list
	int length() const
	{
		int count = 0;
		Node *temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	// Get value at position
	int get_value_at(int pos) const
	{
		if (pos < 0)
			throw std::out_of_range("Invalid position");

		Node *temp = head;
		int index = 0;
		while (temp != nullptr)
		{
			if (index == pos)
				return temp->val;
			temp = temp->next;
			index++;
		}

		throw std::out_of_range("Position out of range");
	}

	// Clear the entire list
	void clear()
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			Node *next = temp->next;
			delete temp;
			temp = next;
		}
		head = nullptr;
	}

	// Print the list
	void print() const
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->val << " -> ";
			temp = temp->next;
		}
		std::cout << "NULL\n";
	}

	// Destructor to avoid memory leak
	~LinkedList() { clear(); }
};
