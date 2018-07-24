// Pham The Quyen
// 1651029

#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
using namespace std;

const int table_size = 11000;

hashMap::hashMap()
{
	table = new bucket[table_size];
	for (int i = 0; i < table_size; i++)
	{
		table[i].phead = NULL;
		table[i].ptail = NULL;
	}
}

int hashMap::hash(string key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash += (int)(key[i]);
	}
	return hash;
}

void hashMap::insert(string key)
{
	int index = hash(key) % table_size;

	if (table[index].phead == NULL)
	{
		table[index].phead = new node;
		table[index].phead->key = key;
		table[index].phead->value = 1;
		table[index].phead->pnext = NULL;
		table[index].ptail = table[index].phead;
	}
	else
	{
		node* sub = new node;
		sub->key = key;
		int count = 0;

		node* tmp = table[index].phead;
		while (tmp != NULL)
		{
			if (tmp->key == key)
			{
				tmp->value++;
				count = tmp->value;
				break;
			}
			tmp = tmp->pnext;
		}
		if (count == 0)
		{
			sub->value = 1;
			table[index].ptail->pnext = sub;
			sub->pnext = NULL;
		}
	}
}

bool hashMap::findHash(string key)
{
	int index = hash(key) % table_size;

	if (table[index].phead == NULL)
		return false;

	node* sub = table[index].phead;
	while (sub != NULL)
	{
		if (sub->key == key)
		{
			return true;
		}
		sub = sub->pnext;
	}
	return false;
}

int hashMap::return_value(string key)
{
	int index = hash(key) % table_size;

	if (table[index].phead == NULL)
		return 0;

	node* sub = table[index].phead;
	while (sub != NULL)
	{
		if (sub->key == key)
		{
			return sub->value;
		}
		sub = sub->pnext;
	}
	return 0;
}

void hashMap::print_occurence()
{
	ofstream file;
	file.open("output5.txt");
	for (int i = 0; i < table_size; i++)
	{
		if (table[i].phead != NULL)
		{
			node* sub = table[i].phead;
			while (sub != NULL)
			{
				/*cout << sub->key << " " << sub->value << endl;*/
				file << sub->key << " " << sub->value << endl;
				sub = sub->pnext;
			}
		}
	}
	file.close();
}

hashMap::~hashMap()
{
	for (int i = 0; i < table_size; i++)
	{
		node* sub = table[i].phead;
		while (sub != NULL)
		{
			node* tmp = sub;
			sub = sub->pnext;
			delete tmp;
		}
	}
	delete[]table;
}