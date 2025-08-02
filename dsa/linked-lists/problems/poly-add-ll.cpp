#include <iostream>

class Node {
  public:
	int val;
	int deg;
	Node *next;

	Node(int a, int b)
	{
		val = a;
		deg = b;
		next = nullptr;
	}
};

Node *poly_add(Node *l1, Node *l2)
{
	Node *result = new Node(0, 0);
	Node *temp = result;
	while (l1 != nullptr && l2 != nullptr)
	{
		int l1_val = l1->val;
		int l2_val = l2->val;
		int l1_deg = l1->deg;
		int l2_deg = l2->deg;

		if (l1_deg > l2_deg)
		{
			temp->next = new Node(l1_val, l1_deg);
			l1 = l1->next;
		}
		else if (l2_deg > l1_deg)
		{
			temp->next = new Node(l2_val, l2_deg);
			l2 = l2->next;
		}
		else
		{
			temp->next = new Node(l1_val + l2_val, l1_deg);
			l1 = l1->next;
			l2 = l2->next;
		}
		temp = temp->next;
	}

	Node *rest = (l1 != nullptr) ? l1 : l2;
	while (rest != nullptr)
	{
		temp->next = new Node(rest->val, rest->deg);
		rest = rest->next;
		temp = temp->next;
	}

	return result->next;
};
void print_ll(Node *head)
{
	while (head->next != nullptr)
	{
		std::cout << " ( " << head->val << "x^" << head->deg << " ) + ";
		head = head->next;
	}
	std::cout << " ( " << head->val << "x^" << head->deg << " ) \n ";
};

int main()
{
	Node *l1 = new Node(2, 2);
	l1->next = new Node(3, 1);
	// l1->next->next = new Node(8, 0);

	Node *l2 = new Node(4, 3);
	l2->next = new Node(8, 2);
	l2->next->next = new Node(5, 1);

	std::cout << "linked list 1\n";
	print_ll(l1);
	std::cout << "linked list 2\n";
	print_ll(l2);

	std::cout << "poly add l1 + l2\n";
	print_ll(poly_add(l1, l2));
}
