#include <iostream>

class Node{
public:
    int val;
    Node* next;
    Node(int x=0): val(x),next(nullptr){};
};

class Circular_linked_list{
public:
    int get_length(Node* head){
        if(head==nullptr)return 0;
        if(head->next==nullptr) return 0;

        Node* temp=head;
        int count=1;
        temp=temp->next;
        while (temp!=head) {
            count++;
            temp=temp->next;
        }
        return count;
    }


};

int main(){
    Node* head=new Node(1);
    head->next=new Node(5);
    head->next->next=new Node(11);
    head->next->next->next=new Node(23);
    head->next->next->next->next=head;

    Circular_linked_list cll;

    std::cout<<"the length of the circular linked list is "<<cll.get_length(head)<<"\n";

}
