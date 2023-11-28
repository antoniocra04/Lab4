#pragma once
#include <ostream>
#include "HashTableItem.h"

using std::ostream;

class HashTable
{
private:
	HashTableItem** _items;
	int _capacity;
	int _length;
	int _pearsonTable[256];

	int Hash(const string& key);
	void CreateEmptyTable();
	void GeneratePearsonTable();
	void Resize(const int& newCapacity);
	void ResolveCollision(HashTableItem* item, const string& key, const string& value);

public:
	HashTable();
	~HashTable();

	HashTable& AddItem(const string& key, const string& value);
	HashTable& Delete(const string& key);
	HashTableItem* Search(const string& key);

	friend ostream& operator<<(ostream& os, HashTable& table);
};