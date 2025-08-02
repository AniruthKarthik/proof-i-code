#include <iostream>

class Node {
  public:
	int val;
	Node *next;

	Node(int x)
	{
		val = x;
		next = nullptr;
	}

	// friend void remove_adj_dup(Node *head);
	// friend void print_ll(Node* head);

	static void remove_adj_dup(Node *head)
	{
		if (head == nullptr || head->next == nullptr)
			return;
		Node *temp = head;
		while (temp != nullptr && temp->next != nullptr)
		{
			if (temp->next->val == temp->val)
			{
				Node *del = temp->next;
				temp->next = temp->next->next;
				free(del);
				// delete del;
			}
			temp = temp->next;
		}
	}
};
void print_ll(Node *head)
{
	while (head != nullptr)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << "\n";
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(1);
	head->next->next = new Node(2);
	head->next->next->next = new Node(2);
	head->next->next->next->next = new Node(3);

	std::cout << "the og linked list\n";
	print_ll(head);

	Node::remove_adj_dup(head);

	std::cout << "the linked list after removing adjacent duplicates\n";
	print_ll(head);
}
