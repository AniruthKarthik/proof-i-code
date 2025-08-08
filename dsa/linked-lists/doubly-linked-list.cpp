#include <iostream>
using namespace std;
#include "doubly-linked-list.hpp"

int main()
{
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
