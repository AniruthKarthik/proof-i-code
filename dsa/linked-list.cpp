#include <iostream>

class Node{

public:
    int val;
    Node* next;
    Node(int x=0): val(x),next(nullptr){};

    static void printll(Node* head){
        while (head!=nullptr) {
            std::cout<<head->val<<" -> ";
            head=head->next;
        }
        std::cout<<" NULL \n";
    }

    static Node* add_at_pos(Node *head,int pos,int val){
        int index=0;
        Node* temp=head;
        if(temp==nullptr){
            Node* newnode=new Node(val);
            newnode->next=head;
            return newnode;
        }
        while (temp!=nullptr) {
            if(index==pos-1){
                Node* node=head->next;
                head->next=new Node(val);
                head->next->next=node;
                return head;
            }
            temp=temp->next;
            index++;
        }
        std::cout<<"the length of the ll < position, therfore node added at last";
        return add_at_last(head, val);
    }

    static Node* reverse(Node* head ){
        Node* prev=nullptr;
        Node* curr=head;
        while (curr!=nullptr) {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    static Node* add_at_last(Node*head,int x){
        if(head==nullptr){
            return new Node(x);
        }
        Node* temp=head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=new Node(x);
        temp->next->next=nullptr;
        return head;
    }

    static Node* add_at_first(Node* head,int x){
        if(head==nullptr){
            return new Node(x);
        }
        Node * newnode=new Node(x);
        newnode->next=head;
        return newnode;
    }

    static Node* delete_node(Node* head,int x){
        if (head==nullptr){
            return nullptr;
        }
        if(head->val==x){
            Node* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        Node* temp=head;
        while (temp->next!=nullptr) {
            if(temp->next->val==x){
                Node *del=temp->next;
                temp->next=temp->next->next;
                delete del;
                break;
            }
            temp=temp->next;
        }
        return head;
    }

};

typedef Node* nodeptr ;
int main(){
    nodeptr head=new Node();
    head->val=100;
    head->next=new Node(5);
    head->next->next=new Node(11);
    head->next->next->next=new Node(23);
    head->next->next->next->next=new Node(233);

    std::cout<<"the og linked list"<<std::endl;
    Node:: printll(head);

    Node* reversed_head=Node::reverse(head);
    std::cout<<"the ll after being reversed "<<std::endl;
    Node::printll(reversed_head);

    Node::add_at_last(reversed_head, 21);
    std::cout<<"insertion at the end"<<std::endl;
    Node::printll(reversed_head);

    head=Node::add_at_first(reversed_head, 111);
    std::cout<<"insertion at the start"<<std::endl;
    Node::printll(head);

    head=Node::delete_node(head, 233);
    std::cout<<"delete node 233"<<std::endl;
    Node::printll(head);

    head=Node::add_at_pos(head,2,55);
    std::cout<<"node 55 added at postion 2"<<std::endl;
    Node::printll(head);




    return 0;
}
