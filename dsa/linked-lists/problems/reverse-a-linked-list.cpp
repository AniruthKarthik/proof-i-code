#include <iostream>

class Node {
  public:
	int val;
	Node *next;

	Node(int x) : val(x), next(nullptr) {};
};

Node *reverse(Node *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	Node *newhead = reverse(head->next);
	Node *front = head->next;
	front->next = head;
	head->next = nullptr;
	return newhead;
}

void print_ll(Node *head)
{
	while (head != nullptr)
	{
		std::cout << head->val << " => ";
		head = head->next;
	}
	std::cout << " NULL\n";
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);

	std::cout << "the linked list before reversal\n";
	print_ll(head);
	std::cout << "the linked list after reversal\n";
	print_ll(reverse(head));
}
