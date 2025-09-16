#include "hash-table-chaining.hpp"
#include <iostream>
using namespace std;

int main()
{
	HashTable h;

	h.insert(15);
	h.insert(25);
	h.insert(35);
	h.insert(20);

	cout << "Hash Table:\n";
	h.display();

	cout << "Search 25: " << (h.search(25) ? "Found" : "Not Found") << endl;

	h.remove(25);
	cout << "After deleting 25:\n";
	h.display();

	return 0;
}
