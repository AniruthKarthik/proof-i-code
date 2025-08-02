#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Node {
  public:
	int val;
	Node *next;

	Node(int x) : val(x), next(nullptr) {}
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

Node *getKthNode(Node *head, int k)
{
	while (head != nullptr && k > 1)
	{
		k--;
		head = head->next;
	}
	return head;
}

void print_ll(Node *head)
{
	while (head != nullptr)
	{
		cout << head->val << " => ";
		head = head->next;
	}
	cout << "NULL\n";
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	cout << "The linked list before reversal:\n";
	print_ll(head);

	int k = 2;
	Node *temp = head;
	Node *prevTail = nullptr;

	while (temp != nullptr)
	{
		Node *kthnode = getKthNode(temp, k);
		if (kthnode == nullptr)
			break;

		Node *newstart = kthnode->next;
		kthnode->next = nullptr;

		Node *newhead = reverse(temp);
		Node *prevlast = temp;

		if (temp == head)
		{
			head = newhead;
		}
		else
		{
			prevTail->next = newhead;
		}

		prevlast->next = newstart;
		prevTail = prevlast;
		temp = newstart;
	}

	cout << "Final answer:\n";
	print_ll(head);
}
