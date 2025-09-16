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

	return 0;
}
