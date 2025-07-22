#include <iostream>

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int x){
        val=x;
        next=nullptr;
        prev=nullptr;
    }
};
class Browser{
    private:
    Node* head;
    Node* current;

    public:
    Browser(){
        head=nullptr;
        head->next=head;
        head->prev=head;
        current=head;
    }

    void goToEnd(){
        while (current->next->next!=head) {
            current=current->next;
        }
        return;
    }

    void visit(int x){
        while (current->next!=head) {
            Node*temp=current->next;
            current->next=current->next->next;
            free(temp);
            current=current->next;
        }
        current=current->prev;
        Node* newnode=new Node(x);
        current->next=newnode;
        newnode->prev=current;
        current=newnode;
        newnode->next=head;
        head->prev=newnode;
    }

    void back(int x){
        while (current!=head && x>0) {
            current=current->prev;
            x--;
        }
        if(x>0){
            std::cout<<"reached the head, cannot go back n pages\n";
        }
    }

    void snapshot(){
        Node*temp=head;
        while (temp!=current) {
            std::cout<<temp->val<<" ";
            temp=temp->next;
        }
    }

};

int main(){

    Browser* chrome=new Browser();
    chrome->visit(122323);
    chrome->visit(232323);
    chrome->snapshot();
}
