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
	ListNode *f(ListNode *&temp)
	{
		if (temp->next->next == nullptr)
		{
			ListNode *toret = temp->next;
			temp->next = nullptr;
			return toret;
		}
		temp->next = f(temp);
	}
	void reorderList(ListNode *head)
	{
		ListNode *og = head;
		while (head != nullptr)
		{
			if (head->next->next = nullptr)
			{
			}
		}
	}
};

void printll(ListNode *&head)
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
