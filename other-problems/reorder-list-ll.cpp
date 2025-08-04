// re order list - linked list - leetcode

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
  public:
	ListNode *get_second_start(ListNode *head)
	{
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode *reverse_ll(ListNode *head)
	{
		if (!head || !head->next)
			return head;
		ListNode *prev = nullptr;
		ListNode *cur = head;

		while (cur)
		{
			ListNode *right = cur->next;
			cur->next = prev;
			prev = cur;
			cur = right;
		}

		return prev;
	}
	void reorderList(ListNode *&head)
	{
		if (!head || !head->next || !head->next->next)
			return;

		ListNode *middle = get_second_start(head);
		ListNode *right = middle->next;
		middle->next = nullptr;

		right = reverse_ll(right);

		ListNode *left = head;
		while (left && right)
		{
			ListNode *lrem = left->next;
			ListNode *rrem = right->next;
			left->next = right;
			right->next = lrem;
			left = lrem;
			right = rrem;
		}
	}
};

void printll(ListNode *head)
{
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Solution sol;
	ListNode *head = new ListNode(
	    1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

	printll(head);
	sol.reorderList(head);
	printll(head);

	return 0;
}
