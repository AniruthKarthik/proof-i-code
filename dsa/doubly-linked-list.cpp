#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int x){
        val=x;
        prev=nullptr;
        next=nullptr;
    }
     void print_ll_forward(){
        Node* head=this;
        while (head!=nullptr)
        {
            cout<<head->val<<" -> ";
            head=head->next;
        }
        cout<<" NULL\n";
    }
     void print_ll_backward(){
        Node* head=this;
        while (head!=nullptr)
        {
            cout<<head->val<<" -> ";
            head=head->prev;
        }
        cout<<" NULL\n";
    }

    void print_entire_ll(){
        Node* head=this;
        while (head->prev!=nullptr) {
            head=head->prev;
        }
        cout<<"NULL <--> ";
        while (head->next!=nullptr) {
            cout<<head->val<<" <--> ";
            head=head->next;
        }
        cout<<head->val;
        cout<<" <--> NULL";

    }
    
};

int main(){

    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->prev=head;
    head->next->next=new Node(3);
    head->next->next->prev=head->next;
    head->next->next->next=new Node(4);
    head->next->next->next->prev=head->next->next;
    
    cout<<"printing the linked list in the forward direction\n";
    head->print_ll_forward();
    cout<<"printing the linked list in the backward direction\n";
    head=head->next->next->next;
    head->print_ll_backward();
    cout<<"printing the complete linked list irrespective of the node\n";
    head->print_entire_ll();

}
