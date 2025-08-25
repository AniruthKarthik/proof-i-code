#include <climits>
#include <iostream>

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
	ListNode *get_middle_node(ListNode *head)
	{
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode *merge(ListNode *l1, ListNode *l2)
	{
		ListNode *head = new ListNode(INT_MIN);
		ListNode *temp = head;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				temp->next = l1;
				l1 = l1->next;
			}
			else
			{
				temp->next = l2;
				l2 = l2->next;
			}
			temp = temp->next;
		}
		if (l1)
			temp->next = l1;
		if (l2)
			temp->next = l2;

		return head->next;
	}

	ListNode *sortList(ListNode *head) { return mergesort(head, nullptr); }

	ListNode *mergesort(ListNode *head, ListNode *last)
	{

		if (!head || !head->next)
			return head;
		ListNode *mid = get_middle_node(head);
		ListNode *newmid = mid->next;
		mid->next = nullptr;
		ListNode *left = mergesort(head, mid);
		ListNode *right = mergesort(newmid, nullptr);

		return merge(left, right);
	}
};

int main()
{
	ListNode *head = new ListNode(4);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(3);

	Solution sol;
	ListNode *sorted = sol.sortList(head);

	while (sorted)
	{
		std::cout << sorted->val << " ";
		sorted = sorted->next;
	}
}
