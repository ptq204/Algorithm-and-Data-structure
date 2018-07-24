// Pham The Quyen
// 1651029
#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
	int data;
	int height;
	int balance;
	node* left;
	node* right;
};

class tree
{
public:
	node* root;
	tree();
	void deleteTree(node* &root);
	node* insert(node* &root, int val);
	void print_PreOrder(node* root);
	void print_PostOrder(node* root);
	void print_InOrder(node* root);
	node* search(node* root, int x);
	bool isEmpty(node* root);
};

// additional function just for testing the insertion function =))
void print_current_level(node* node, int level);
void print_line_by_line(node* origin);