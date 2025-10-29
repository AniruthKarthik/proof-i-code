#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedStack {
private:
    Node* last;

public:
    CircularLinkedStack() : last(nullptr) {}

    ~CircularLinkedStack() {
        if (isEmpty()) {
            return;
        }
        Node* current = last->next;
        while (current != last) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete last;
    }

    void push(int x) {
        Node* newNode = new Node{x, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
        Node* first = last->next;
        int popped_value = first->data;
        if (last->next == last) {
            last = nullptr;
        } else {
            last->next = first->next;
        }
        delete first;
        return popped_value;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return last->next->data;
    }

    bool isEmpty() {
        return last == nullptr;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node* temp = last->next;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        std::cout << std::endl;
    }
};
