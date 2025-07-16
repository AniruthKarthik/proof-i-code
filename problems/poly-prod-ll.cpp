#include <iostream>
// INCOMPLETE

class Node
{
public:
    int val;
    int deg;
    Node *next;

    Node(int a, int b)
    {
        val = a;
        deg = b;
        next = nullptr;
    }
};

void print_ll(Node *head)
{
    while (head->next != nullptr)
    {
        std::cout <<" ( "<< head->val << " x^" << head->deg << " ) + ";
        head = head->next;
    }
    std::cout <<" ( "<< head->val << " x^" << head->deg << " ) \n ";

};

int main()
{
    Node *l1 = new Node(2, 2);
    l1->next = new Node(3, 1);
    // l1->next->next = new Node(8, 0);

    Node *l2 = new Node(4, 3);
    l2->next = new Node(8, 2);
    l2->next->next = new Node(5, 1);

    std::cout << "linked list 1\n";
    print_ll(l1);
    std::cout << "linked list 2\n";
    print_ll(l2);

}
