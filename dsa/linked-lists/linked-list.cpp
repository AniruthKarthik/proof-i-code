#include "linked-list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	LinkedList list;

	list.add_at_last(10);
	list.add_at_last(20);
	list.add_at_last(30);
	std::cout << "Initial list:\n";
	list.print();

	list.add_at_first(5);
	std::cout << "After adding 5 at the start:\n";
	list.print();

	list.add_at_position(2, 15);
	std::cout << "After inserting 15 at position 2:\n";
	list.print();

	list.delete_node(20);
	std::cout << "After deleting node with value 20:\n";
	list.print();

	list.reverse();
	std::cout << "After reversing the list:\n";
	list.print();

	std::cout << "Length: " << list.length() << "\n";
	std::cout << "Is 15 in the list? " << (list.search(15) ? "Yes" : "No")
	          << "\n";
	std::cout << "Value at position 2: " << list.get_value_at(2) << "\n";

	list.delete_at_position(2);
	std::cout << "After deleting node at position 2:\n";
	list.print();

	list.clear();
	std::cout << "After clearing the list:\n";
	list.print();

	return 0;
}
