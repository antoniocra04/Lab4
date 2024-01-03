#include <iostream>
#include "HashTable.h"
#include "Dictionary.h"
using namespace std;

void PrintHashTable(HashTable* table)
{
    cout << "Hash table:" << endl;

    for (int i = 0; i < table->_capacity; i++)
    {
        cout << i + 1 << ") ";
        if (table->_items[i])
        {
            HashTableItem* currentItem = table->_items[i];

            while (currentItem)
            {
                cout << currentItem->_key << " - " << currentItem->_value << " | ";
                currentItem = currentItem->_next;
            }
        }
        cout << endl;
    }

    cout << endl << "Length: " << table->_length << " Capacity: " << table->_capacity << endl;
}

template <typename T>
void ValidInput(T& variable)
{
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter correct value: ";
        cin >> variable;
    }
}

void MenuController()
{
    string menu = "Choose one of activity:\n1) Add\n2) Search\n3) Delete\nq - Quit\nYour choice: ";
    string key;
    string value;
    Dictionary* dictionary = new Dictionary;
    char mode = '\0';

    while (mode != 'q')
    {
        PrintHashTable(dictionary->_hashTable);
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            cout << "Enter key for adding: ";
            ValidInput(key);
            cout << "Enter value: ";
            ValidInput(value);
            dictionary->Add(key, value);
            break;
        case '2':
            cout << "Enter key for search: ";
            ValidInput(key);
            value = dictionary->Search(key);
            if (value != "")
            {
                cout << "Key \"" << key << "\" contains value \"" << value << "\"\n";
            }
            else
            {
                cout << "No key in dictionary!\n";
            }
            break;
        case '3':
            cout << "Enter key for deletion: ";
            ValidInput(key);
            dictionary->Delete(key);
            break;
        default:
            break;
        }
    }
}


int main()
{
    MenuController();
	return 0;
}