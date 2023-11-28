#include "Dictionary.h"

Dictionary& Dictionary::Add(const string& key, const string& value)
{
    _hashTable.AddItem(key, value);
    return *this;
}

Dictionary& Dictionary::Delete(const string& key)
{
    _hashTable.Delete(key);
    return *this;
}

string Dictionary::Search(const string& key)
{
    HashTableItem* temp = _hashTable.Search(key);
    return temp ? temp->_value : "";
}

ostream& operator<<(ostream& os, Dictionary& dict)
{
    os << dict._hashTable;
    return os;
}