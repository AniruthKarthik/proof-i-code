#include "priority-queue.hpp"
#include <iostream>
using namespace std;

int main()
{
	// Max-Heap
	PriorityQueue maxPQ(false);
	maxPQ.insert(10);
	maxPQ.insert(30);
	maxPQ.insert(20);
	maxPQ.insert(5);

	cout << "Max-Heap: ";
	maxPQ.print();
	cout << "Extract Top (Max): " << maxPQ.extractTop() << endl;
	maxPQ.print();

	// Min-Heap
	PriorityQueue minPQ(true);
	minPQ.insert(10);
	minPQ.insert(30);
	minPQ.insert(20);
	minPQ.insert(5);

	cout << "\nMin-Heap: ";
	minPQ.print();
	cout << "Extract Top (Min): " << minPQ.extractTop() << endl;
	minPQ.print();

	// Test deleteNode
	cout << "\nTesting deleteNode on Max-Heap:\n";
	PriorityQueue maxPQ2(false);
	maxPQ2.insert(40);
	maxPQ2.insert(30);
	maxPQ2.insert(20);
	maxPQ2.insert(10);
	maxPQ2.insert(5);
	cout << "Initial Max-Heap: ";
	maxPQ2.print();
	cout << "Deleting node at index 1 (value 30)\n";
	maxPQ2.deleteNode(1);
	cout << "Max-Heap after deleting node at index 1: ";
	maxPQ2.print();

	// Test updateNode
	cout << "\nTesting updateNode on Min-Heap:\n";
	PriorityQueue minPQ2(true);
	minPQ2.insert(10);
	minPQ2.insert(20);
	minPQ2.insert(30);
	minPQ2.insert(40);
	minPQ2.insert(50);
	cout << "Initial Min-Heap: ";
	minPQ2.print();
	cout << "Updating node at index 2 (value 30) to 5\n";
	minPQ2.updateNode(2, 5);
	cout << "Min-Heap after updating node at index 2: ";
	minPQ2.print();
	cout << "Updating node at index 0 (value 5) to 60\n";
	minPQ2.updateNode(0, 60);
	cout << "Min-Heap after updating node at index 0: ";
	minPQ2.print();

	return 0;
}
