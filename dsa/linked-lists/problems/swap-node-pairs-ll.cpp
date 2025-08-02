#include <cmath>
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
	ListNode *swapPairs(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *prev = dummy;

		while (head != nullptr && head->next != nullptr)
		{
			ListNode *a = head;
			ListNode *b = head->next;

			// Swap
			prev->next = b;
			a->next = b->next;
			b->next = a;

			// Move pointers forward
			prev = a;
			head = a->next;
		}

		return dummy->next;
	}
};

void print_ll(ListNode *head)
{
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";
};

int main()
{
	ListNode *head = new ListNode(2);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(5);

	print_ll(head);

	Solution sol;

	print_ll(sol.swapPairs(head));
};
