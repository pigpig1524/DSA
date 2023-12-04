#include <iostream>
#include <list>

using namespace std;

struct Hash
{
	int slot;
	list<int>* table;
};

void createHash(Hash& h, int b)
{
	h.slot = b;
	h.table = new list<int>[h.slot];
}

int hash_func(Hash h, int x)
{
	return x % h.slot;
}

void insertItem(Hash& h, int key)
{
	int idx = hash_func(h, key);
	h.table[idx].push_back(key);
}

void deleteItem(Hash h, int key)
{
	int idx = hash_func(h, key);
	list<int> ::iterator i;
	for (i = h.table[idx].begin(); i != h.table[idx].end(); i++)
		if (*i == key)
			break;
	if (i != h.table[idx].end())
		h.table[idx].erase(i);
}

void display_hash(Hash h)
{
	for (int i = 0; i < h.slot; i++)
	{
		cout << "==> " << i << ": ";
		for (auto num : h.table[i])
			cout << num << " ";
		cout << endl;
	}
}

int main()
{
	Hash h;
	int slot = 10;
	createHash(h, 10);
	for (int z = 0; z < 15; z++)
		insertItem(h, z);
	deleteItem(h, 10);
	display_hash(h);
	return 0;
}