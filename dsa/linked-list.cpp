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
  static Node* insertatend(Node*head,int x){
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
  static Node* insertatstart(Node* head,int x){
    if(head==nullptr){
      return new Node(x);
    }
    Node * newnode=new Node(x);
    newnode->next=head;
    return newnode;
  }
  static Node* deletenode(Node* head,int x){
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

  Node::insertatend(reversed_head, 21);
  std::cout<<"insertion at the end"<<std::endl;
  Node::printll(reversed_head);
  
  head=Node::insertatstart(reversed_head, 111);
  std::cout<<"insertion at the start"<<std::endl;
  Node::printll(head);

  head=Node::deletenode(head, 233);
  std::cout<<"delete node 233"<<std::endl;
  Node::printll(head);



  return 0;
}
