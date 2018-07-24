// Pham The Quyen
// 1651029

#pragma once
#include <iostream>
using namespace std;

struct node
{
	string key;
	float pro;
	int value;
	node* pnext;
};

struct bucket
{
	node* phead;
	node* ptail;
};

class hashMap
{
private:
	bucket *table;
public:
	hashMap();
	int hash(string key);
	void insert(string key);
	void print_occurence();
	bool findHash(string key);
	int return_value(string key);
	~hashMap();
};
