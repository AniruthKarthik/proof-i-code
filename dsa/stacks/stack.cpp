#include <iostream>
using namespace std;
#include "stack.hpp"

int main()
{
	Stack st(5);

	st.push(10);
	st.push(20);
	st.push(30);

	cout << "After pushing 10, 20, 30:\n";
	st.print();

	cout << "Top element is: " << st.peek() << "\n";

	cout << "Popped: " << st.pop() << "\n";
	st.print();

	st.push(40);
	st.push(50);
	st.push(60);
	st.push(70);

	cout << "Final stack:\n";
	st.print();

	return 0;
}
