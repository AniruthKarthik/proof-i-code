#include <iostream>
#include "./linked-stack.hpp"

long long factorial_using_stack(int n) {
    LinkedStack s;
    while (n > 1) {
        s.push(n--);
    }

    long long result = 1;
    while (!s.is_empty()) {
        result *= s.pop();
    }

    return result;
}

int main() {
    int number = 5;
    std::cout << "Factorial of " << number << " is: " << factorial_using_stack(number) << std::endl;
    return 0;
}
