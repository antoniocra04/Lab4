#pragma once
#include <string>
#include "HashTable.h"
using namespace std;

class Dictionary
{
private:
	HashTable _hashTable;

public:
	Dictionary& Add(const string& key, const string& value);
	Dictionary& Delete(const string& key);
	string Search(const string& key);

	friend ostream& operator<<(ostream& os, Dictionary& dict);
};