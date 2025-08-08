#include "circular-linked-list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	CircularLL cll;

	cll.add_at_last(1);
	cll.add_at_last(2);
	cll.add_at_last(3);
	cll.add_at_last(4);
	std::cout << "The original circular linked list:\n";
	cll.print();

	std::cout << "Adding 5 at the last:\n";
	cll.add_at_last(5);
	cll.print();

	std::cout << "Adding 0 at the first:\n";
	cll.add_at_first(0);
	cll.print();

	std::cout << "Adding 9 at position 2:\n";
	cll.add_at_position(2, 9);
	cll.print();

	std::cout << "Deleting the first node:\n";
	cll.del_at_first();
	cll.print();

	std::cout << "Deleting the last node:\n";
	cll.del_at_last();
	cll.print();

	std::cout << "Deleting at position 2:\n";
	cll.del_at_position(2);
	cll.print();

	std::cout << "Length: " << cll.length() << "\n";
	std::cout << "Is 3 in the list? " << (cll.search(3) ? "Yes" : "No") << "\n";
	std::cout << "Value at position 2: " << cll.get_value_at(2) << "\n";

	std::cout << "Clearing the list...\n";
	cll.clear();
	cll.print();

	return 0;
}
