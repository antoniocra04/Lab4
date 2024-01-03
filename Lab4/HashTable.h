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
	/// �����������
	/// </summary>
	/// <param name="key">����</param>
	/// <returns>���</returns>
	int Hash(const string& key);

	/// <summary>
	/// ������� ������ �������
	/// </summary>
	void CreateEmptyTable();

	/// <summary>
	/// ������������� ������� �������
	/// </summary>
	void GeneratePearsonTable();

	/// <summary>
	/// �������� ������ ��� �������
	/// </summary>
	/// <param name="newCapacity">����� ������</param>
	void Resize(const int& newCapacity);

	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <param name="item">�������</param>
	/// <param name="key">����</param>
	/// <param name="value">��������</param>
	void ResolveCollision(HashTableItem* item, const string& key, const string& value);


	HashTable();
	~HashTable();

	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="key">����</param>
	/// <param name="value">��������</param>
	/// <returns>��� �������</returns>
	HashTable& AddItem(const string& key, const string& value);

	/// <summary>
	/// ������� �������
	/// </summary>
	/// <param name="key">����</param>
	/// <returns>��� �������</returns>
	HashTable& Delete(const string& key);

	/// <summary>
	/// �����
	/// </summary>
	/// <param name="key">����</param>
	/// <returns>��� �������</returns>
	HashTableItem* Search(const string& key);
};