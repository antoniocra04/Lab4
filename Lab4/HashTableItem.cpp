#include "HashTableItem.h"

HashTableItem::HashTableItem()
{
	_prev = nullptr;
	_next = nullptr;
}

HashTableItem::HashTableItem(const string& key, const string& value, HashTableItem* prev, HashTableItem* next)
{
	_prev = prev;
	_next = next;
	_key = key;
	_value = value;
}