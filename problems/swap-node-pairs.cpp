#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// INCOMPLETE

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* temp=head;
        head=head->next;
        ListNode* prev=nullptr;
        while (temp!=nullptr&& temp->next!=nullptr) {
            ListNode* a=temp;
            ListNode* b=temp->next;
            a->next=b->next;
            b->next=a;

            if(prev!=nullptr){
                prev->next=b;
            }
            prev=a;
            temp=a->next;
        }
        return head;


    }
};

void print_ll(ListNode* head){
    while (head!=nullptr) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n"; 
}

int main(){
    ListNode* head=new ListNode(2);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);

    print_ll(head);

    Solution sol;
    sol.swapPairs(head);

    print_ll(head);

}


