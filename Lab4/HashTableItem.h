#pragma once
#include <string>
using namespace std;

struct HashTableItem
{
	string _key;
	string _value;
	HashTableItem* _next;
	HashTableItem* _prev;

	HashTableItem();
	HashTableItem(const string& key, const string& value, HashTableItem* prev = nullptr, HashTableItem* next = nullptr);
};