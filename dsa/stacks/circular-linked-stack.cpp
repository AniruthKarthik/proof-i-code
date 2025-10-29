#include "circular-linked-stack.hpp"
#include <iostream>

int main() {
    CircularLinkedStack stack;

    std::cout << "Initial stack: ";
    stack.display();

    std::cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nPushing 1, 2, 3..." << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack after pushes: ";
    stack.display();

    std::cout << "Peek: " << stack.peek() << std::endl;

    std::cout << "\nPopping an element..." << std::endl;
    int popped = stack.pop();
    std::cout << "Popped value: " << popped << std::endl;

    std::cout << "Stack after pop: ";
    stack.display();

    std::cout << "Peek: " << stack.peek() << std::endl;

    std::cout << "\nPopping remaining elements..." << std::endl;
    stack.pop();
    stack.pop();

    std::cout << "Stack after popping all elements: ";
    stack.display();

    std::cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nAttempting to pop from empty stack..." << std::endl;
    stack.pop();

    return 0;
}
