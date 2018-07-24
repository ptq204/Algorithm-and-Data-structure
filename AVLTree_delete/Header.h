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
	node* deleteNode(node* &root, int val);
	void print_PreOrder(node* root);
	void print_PostOrder(node* root);
	void print_InOrder(node* root);
	node* search(node* root, int x);
	bool isEmpty(node* root);
	int FindMax(node* root);
	int FindMin(node* root);
};