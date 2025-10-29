#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
  private:
	vector<int> heap;
	bool isMinHeap; // true = min-heap, false = max-heap

	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

	// Comparison based on heap type
	bool compare(int a, int b)
	{
		if (isMinHeap)
			return a < b; // smaller value has higher priority
		else
			return a > b; // larger value has higher priority
	}

	void heapifyUp(int i)
	{
		while (i > 0 && compare(heap[i], heap[parent(i)]))
		{
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
	}

	void heapifyDown(int i)
	{
		int l = left(i);
		int r = right(i);
		int best = i;

		if (l < heap.size() && compare(heap[l], heap[best]))
			best = l;
		if (r < heap.size() && compare(heap[r], heap[best]))
			best = r;

		if (best != i)
		{
			swap(heap[i], heap[best]);
			heapifyDown(best);
		}
	}

  public:
	PriorityQueue(bool minHeap = false) { isMinHeap = minHeap; }

	void insert(int val)
	{
		heap.push_back(val);
		heapifyUp(heap.size() - 1);
	}

	int top()
	{
		if (isEmpty())
			throw runtime_error("Priority Queue is empty!");
		return heap[0];
	}

	int extractTop()
	{
		if (isEmpty())
			throw runtime_error("Priority Queue is empty!");
		int root = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		if (!heap.empty())
			heapifyDown(0);
		return root;
	}

	void deleteNode(int i)
	{
		if (i < 0 || i >= heap.size())
		{
			throw runtime_error("Index out of bounds!");
		}
		heap[i] = heap.back();
		heap.pop_back();
		if (i < heap.size())
		{
			if (i > 0 && compare(heap[i], heap[parent(i)]))
				heapifyUp(i);
			else
				heapifyDown(i);
		}
	}

	void updateNode(int i, int newValue)
	{
		if (i < 0 || i >= heap.size())
		{
			throw runtime_error("Index out of bounds!");
		}
		int oldValue = heap[i];
		heap[i] = newValue;
		if (compare(newValue, oldValue))
		{
			heapifyUp(i);
		}
		else
		{
			heapifyDown(i);
		}
	}

	bool isEmpty() { return heap.empty(); }

	int size() { return heap.size(); }

	void print()
	{
		for (int x : heap)
			cout << x << " ";
		cout << endl;
	}
};
