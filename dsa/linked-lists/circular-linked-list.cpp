#include <iostream>
#include <stdexcept>

class Node {
  public:
	int val;
	Node *next;

	Node(int x) : val(x), next(nullptr) {}
};

class CircularLL {
  private:
	Node *head;
	Node *last;

  public:
	CircularLL() : head(nullptr), last(nullptr) {}

	// Add at the end
	void add_at_last(int val)
	{
		Node *newnode = new Node(val);
		if (head == nullptr)
		{
			head = last = newnode;
			last->next = head;
			return;
		}
		last->next = newnode;
		last = newnode;
		last->next = head;
	}

	// Add at the beginning
	void add_at_first(int val)
	{
		Node *newnode = new Node(val);
		if (head == nullptr)
		{
			head = last = newnode;
			last->next = head;
			return;
		}
		newnode->next = head;
		head = newnode;
		last->next = head;
	}

	// Add at a specific position (0-based index)
	void add_at_position(int pos, int val)
	{
		if (pos <= 0 || head == nullptr)
		{
			add_at_first(val);
			return;
		}
		Node *temp = head;
		int index = 0;
		while (index < pos - 1 && temp->next != head)
		{
			temp = temp->next;
			index++;
		}
		Node *newnode = new Node(val);
		newnode->next = temp->next;
		temp->next = newnode;
		if (temp == last)
			last = newnode;
	}

	// Delete the last node
	void del_at_last()
	{
		if (head == nullptr)
			return;

		if (head == last)
		{
			delete head;
			head = last = nullptr;
			return;
		}

		Node *temp = head;
		while (temp->next != last)
		{
			temp = temp->next;
		}

		delete last;
		last = temp;
		last->next = head;
	}

	// Delete the first node
	void del_at_first()
	{
		if (head == nullptr)
			return;

		if (head == last)
		{
			delete head;
			head = last = nullptr;
			return;
		}

		Node *to_delete = head;
		head = head->next;
		last->next = head;
		delete to_delete;
	}

	// Delete node at specific position
	void del_at_position(int pos)
	{
		if (head == nullptr)
			return;

		if (pos == 0)
		{
			del_at_first();
			return;
		}

		Node *temp = head;
		int index = 0;
		while (index < pos - 1 && temp->next != head)
		{
			temp = temp->next;
			index++;
		}

		if (temp->next == head || temp->next == nullptr)
			return;

		Node *to_delete = temp->next;
		temp->next = to_delete->next;

		if (to_delete == last)
			last = temp;

		delete to_delete;
	}

	// Search a value
	bool search(int val) const
	{
		if (head == nullptr)
			return false;
		Node *temp = head;
		do
		{
			if (temp->val == val)
				return true;
			temp = temp->next;
		}
		while (temp != head);
		return false;
	}

	// Get value at a given position
	int get_value_at(int pos) const
	{
		if (head == nullptr || pos < 0)
			throw std::out_of_range("Invalid position");
		Node *temp = head;
		int index = 0;
		do
		{
			if (index == pos)
				return temp->val;
			temp = temp->next;
			index++;
		}
		while (temp != head);
		throw std::out_of_range("Position out of range");
	}

	// Length of list
	int length() const
	{
		if (head == nullptr)
			return 0;
		int count = 1;
		Node *temp = head->next;
		while (temp != head)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	// Clear the entire list
	void clear()
	{
		if (head == nullptr)
			return;

		Node *curr = head->next;
		while (curr != head)
		{
			Node *next = curr->next;
			delete curr;
			curr = next;
		}
		delete head;
		head = last = nullptr;
	}

	// Print the list
	void print() const
	{
		if (head == nullptr)
		{
			std::cout << "Linked list empty\n";
			return;
		}

		Node *temp = head;
		do
		{
			std::cout << temp->val << " -> ";
			temp = temp->next;
		}
		while (temp != head);
		std::cout << "HEAD\n";
	}

	// Destructor to release memory
	~CircularLL() { clear(); }
};

int main()
{
	CircularLL cll;

	cll.add_at_last(1);
	cll.add_at_last(2);
	cll.add_at_last(3);
	cll.add_at_last(4);
	std::cout << "The original circular linked list:\n";
	cll.print();

	std::cout << "Adding 5 at the last:\n";
	cll.add_at_last(5);
	cll.print();

	std::cout << "Adding 0 at the first:\n";
	cll.add_at_first(0);
	cll.print();

	std::cout << "Adding 9 at position 2:\n";
	cll.add_at_position(2, 9);
	cll.print();

	std::cout << "Deleting the first node:\n";
	cll.del_at_first();
	cll.print();

	std::cout << "Deleting the last node:\n";
	cll.del_at_last();
	cll.print();

	std::cout << "Deleting at position 2:\n";
	cll.del_at_position(2);
	cll.print();

	std::cout << "Length: " << cll.length() << "\n";
	std::cout << "Is 3 in the list? " << (cll.search(3) ? "Yes" : "No") << "\n";
	std::cout << "Value at position 2: " << cll.get_value_at(2) << "\n";

	std::cout << "Clearing the list...\n";
	cll.clear();
	cll.print();

	return 0;
}
