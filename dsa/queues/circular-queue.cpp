#include <iostream>
using namespace std;
#include "circular-queue.hpp"

int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	cout << "After enqueuing 5 elements:\n";
	q.print();

	cout << "Front of queue: " << q.peek() << "\n";

	q.dequeue();
	q.dequeue();
	cout << "After dequeuing 2 elements:\n";
	q.print();

	q.enqueue(60);
	q.enqueue(70);
	cout << "After enqueuing 60 and 70:\n";
	q.print();

	return 0;
}
