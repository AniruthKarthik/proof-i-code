struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int len = lenll(head);

    if (n == len) {
      return head->next;
    }

    ListNode *cur = head;

    for (int i = 0; i < len - n - 1; i++) {
      cur = cur->next;
    }

    cur->next = cur->next->next;

    return head;
  }

  int lenll(ListNode *head) {
    int n = 0;
    while (head != nullptr) {
      n++;
      head = head->next;
    }
    return n;
  }
};
