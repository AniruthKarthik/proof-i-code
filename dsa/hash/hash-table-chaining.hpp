#include <iostream>
#include <list>
using namespace std;

class HashTable {
  private:
	static const int size = 10;
	list<int> table[size];

	int hashFuction(int key) { return key % size; }

  public:
	void insert(int key)
	{
		int index = hashFuction(key);
		table[index].push_back(key);
	}

	bool search(int key)
	{
		int index = hashFuction(key);
		for (int x : table[index])
		{
			if (x == key)
				return true;
		}
		return false;
	}

	void remove(int key)
	{
		int index = hashFuction(key);
		table[index].remove(key);
	}

	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << "--> ";
			for (int x : table[i])
			{
				cout << x << " ";
			}
			cout << endl;
		}
	}
};
