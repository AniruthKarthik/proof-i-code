#include <iostream>
#include <list>
#include <sys/types.h>
#include <vector>
using namespace std;

class HashTableChaining {
	vector<list<int>> table;
	int size;

	int hash(int k) { return k % size; }

  public:
	HashTableChaining(int s)
	{
		size = s;
		table.resize(s);
	}

	void insert(int key)
	{
		int idx = hash(key);
		table[idx].push_back(key);
	}

	bool search(int key)
	{
		int id = hash(key);
		for (int k : table[id])
		{
			if (k == key)
				return true;
		}
		return false;
	}

	void remove(int k)
	{
		int id = hash(k);
		table[id].remove(k);
	}

	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << ": ";
			for (int k : table[i])
			{
				cout << k << " -> ";
			}
			cout << "null\n";
		}
	}
};

int main()
{
	HashTableChaining ht(7);
	ht.insert(10);
	ht.insert(20);
	ht.insert(15);
	ht.insert(7);

	cout << "Hash Table with Chaining:\n";
	ht.display();

	cout << "Search 15: " << ht.search(15) << endl;
	cout << "Search 100: " << ht.search(100) << endl;

	ht.remove(20);
	cout << "After deleting 20:\n";
	ht.display();
}
