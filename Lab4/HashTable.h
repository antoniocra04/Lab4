#pragma once
#include "HashTableItem.h"

class HashTable
{
public:
	HashTableItem** _items;
	int _capacity;
	int _length;
	int _pearsonTable[256];

	/// <summary>
	/// Хеширование
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>хеш</returns>
	int Hash(const string& key);

	/// <summary>
	/// создать пустую таблицу
	/// </summary>
	void CreateEmptyTable();

	/// <summary>
	/// сгенерировать таблицу пирсона
	/// </summary>
	void GeneratePearsonTable();

	/// <summary>
	/// изменить размер хеш таблицы
	/// </summary>
	/// <param name="newCapacity">новый размер</param>
	void Resize(const int& newCapacity);

	/// <summary>
	/// разрешение колизий
	/// </summary>
	/// <param name="item">элемент</param>
	/// <param name="key">ключ</param>
	/// <param name="value">значение</param>
	void ResolveCollision(HashTableItem* item, const string& key, const string& value);


	HashTable();
	~HashTable();

	/// <summary>
	/// добавить элемент
	/// </summary>
	/// <param name="key">ключ</param>
	/// <param name="value">значение</param>
	/// <returns>хеш таблица</returns>
	HashTable& AddItem(const string& key, const string& value);

	/// <summary>
	/// удалить элемент
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>хеш таблица</returns>
	HashTable& Delete(const string& key);

	/// <summary>
	/// поиск
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>хеш таблица</returns>
	HashTableItem* Search(const string& key);
};