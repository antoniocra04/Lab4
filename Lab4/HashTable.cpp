#include <iostream>
#include "HashTable.h"
#include "HashTableItem.h"

void HashTable::GeneratePearsonTable()
{
	srand(time(0));
	for (int i = 0; i < _capacity; i++)
	{
		_pearsonTable[i] = i;
	}
	for (int i = 0; i < _capacity; i++)
	{
		int swapIndex = 1 + (rand() % _capacity);
		int temp = _pearsonTable[i];
		_pearsonTable[i] = _pearsonTable[swapIndex];
		_pearsonTable[swapIndex] = temp;
	}
}

void HashTable::CreateEmptyTable()
{
	_items = new HashTableItem * [_capacity];

	for (int i = 0; i < _capacity; i++)
	{
		_items[i] = nullptr;
	}
}

HashTable::HashTable()
{
	_capacity = 8;
	CreateEmptyTable();
	GeneratePearsonTable();
}

int HashTable::Hash(const string& key)
{
	int hash = key.length();
	for (int i = 0; i < key.length(); i++)
	{
		hash = _pearsonTable[(hash + key[i]) % _capacity];
	}

	return hash;
}

HashTable& HashTable::AddItem(const string& key, const string& value)
{
	int hashCode = Hash(key);
	if (!_items[hashCode])
	{
		_items[hashCode] = new HashTableItem(key, value);
		_length += 1;
	}
	else
	{
		ResolveCollision(_items[hashCode], key, value);
	}
	if (_length == _capacity)
	{
		Resize(_capacity * 2);
	}

	return *this;
}

HashTable& HashTable::Delete(const string& key)
{
	int hashCode = Hash(key);

	if (!_items[hashCode])
	{
		cout << "Element not exist";
		return *this;
	}

	HashTableItem* deleteItem = _items[hashCode];
	
	if (deleteItem->_next)
	{
		while (true)
		{
			if (!deleteItem->_next || deleteItem->_key == key)
			{
				break;
			}

			deleteItem = deleteItem->_next;
		}

		if (deleteItem->_prev && deleteItem->_next)
		{
			deleteItem->_prev->_next = deleteItem->_next;
			deleteItem->_next->_prev = deleteItem->_prev;
		}
		else if(deleteItem->_prev != nullptr)
		{
			deleteItem->_prev->_next = nullptr;
		}
		else if(deleteItem->_next != nullptr)
		{
			deleteItem->_next->_prev = nullptr;
			_items[hashCode] = deleteItem->_next;
		}

		delete deleteItem;
		cout << "Deleted successfuly" << endl;
	}
	else
	{
		delete deleteItem;
		_items[hashCode] = nullptr;
		cout << "Deleted successfuly"<<endl;
	}

	_length = _length - 1;

	if (_length <= _capacity / 2 && _capacity / 2 > 4)
	{
		Resize(_capacity / 2);
	}
}

void HashTable::Resize(const int& newCapacity)
{
	int oldCapacity = _capacity;
	_capacity = newCapacity;
	HashTableItem** oldItems = _items;
	CreateEmptyTable();
	GeneratePearsonTable();
	_length = 0;
	
	for (int i = 0; i < oldCapacity; i++)
	{
		HashTableItem* current = oldItems[i];
		while (current)
		{
			HashTableItem* temp = current;
			AddItem(current->_key, current->_value);
			current = current->_next;
			delete temp;
		}
	}

	delete oldItems;
}

void HashTable::ResolveCollision(HashTableItem* item, const string& key, const string& value)
{
	HashTableItem* itterateItem = item;
	HashTableItem* temp = item;

	while (itterateItem)
	{
		if (itterateItem->_key == key)
		{
			itterateItem->_value = value;
			return;
		}
		temp = itterateItem;
		itterateItem = itterateItem->_next;
	}

	temp->_next = new HashTableItem(key, value, item);
	temp->_next->_prev = temp;
	_length += 1;
}

HashTableItem* HashTable::Search(const string& key)
{
	int hashCode = Hash(key);
	if (_items[hashCode])
	{
		return _items[hashCode];
	}
}

ostream& operator<<(ostream& os, HashTable& table)
{
	os << "Hash table:" << endl;

	for (int i = 0; i < table._capacity; i++)
	{
		os << i + 1 << ") ";
		if (table._items[i]) 
		{
			HashTableItem* currentItem = table._items[i];

			while (currentItem)
			{
				os << currentItem->_key << " - " << currentItem->_value << " | ";
				currentItem = currentItem->_next;
			}
		}
		os << endl;
	}

	os << endl << "Length: " << table._length << " Capacity: " << table._capacity << endl;

	return os;
}

HashTable::~HashTable()
{
	
}