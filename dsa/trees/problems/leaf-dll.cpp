#include "../../linked-lists/doubly-linked-list.hpp"
#include "../tree.hpp"
#include <iostream>

int main()
{
	DoublyLinkedList dll;
	dll.add_at_last(2);
	dll.print();

	return 0;
}
