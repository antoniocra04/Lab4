#pragma once
#include <string>
#include "HashTable.h"

class Dictionary
{
public:
	HashTable* _hashTable;

	Dictionary();

	Dictionary& Add(const string& key, const string& value);
	Dictionary& Delete(const string& key);
	string Search(const string& key);
};