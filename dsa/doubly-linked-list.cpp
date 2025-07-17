#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int value) : val(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add node at the beginning
    void add_at_first(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void add_at_last(int value) {
        Node* new_node = new Node(value);
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void add_at_position(int pos, int value) {
        if (pos <= 0 || head == nullptr) {
            add_at_first(value);
            return;
        }

        Node* temp = head;
        int index = 0;
        while (temp != nullptr && index < pos - 1) {
            temp = temp->next;
            index++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            add_at_last(value);
            return;
        }

        Node* new_node = new Node(value);
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
    }

    void delete_node(int value) {
        Node* temp = head;

        while (temp != nullptr && temp->val != value) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp == head && temp == tail) {
            head = tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != nullptr)
            head = temp->prev;
    }

    void print_forward() const {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void print_backward() const {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->val << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.add_at_last(10);
    dll.add_at_last(20);
    dll.add_at_last(30);
    cout << "Initial list:\n";
    dll.print_forward();

    dll.add_at_first(5);
    cout << "After adding 5 at the start:\n";
    dll.print_forward();

    dll.add_at_position(2, 15);
    cout << "After inserting 15 at position 2:\n";
    dll.print_forward();

    dll.delete_node(20);
    cout << "After deleting node with value 20:\n";
    dll.print_forward();

    dll.reverse();
    cout << "After reversing the list:\n";
    dll.print_forward();

    cout << "Print list in reverse order:\n";
    dll.print_backward();

    return 0;
}
