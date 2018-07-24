// Pham The Quyen
// 1651029
#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
using namespace std;

tree::tree()
{
	root = NULL;
}

void tree::deleteTree(node* &root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int find_height(node* root)
{
	if (root == NULL)
		return 0;
	return 1 + max(find_height(root->left), find_height(root->right));
}

node* CaseRightRight(node* &root)
{
	node* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = find_height(root);
	tmp->height = find_height(tmp);
	root->balance = find_height(root->left) - find_height(root->right);
	tmp->balance = find_height(tmp->left) - find_height(tmp->right);
	return tmp;
}

node* CaseLeftLeft(node* &root)
{
	node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height = find_height(root);
	tmp->height = find_height(tmp);
	root->balance = find_height(root->left) - find_height(root->right);
	tmp->balance = find_height(tmp->left) - find_height(tmp->right);
	return tmp;
}

node* tree::insert(node* &root, int val)
{
	if (root == NULL)
	{
		root = new node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
		root->height = 1;
	}
	else
	{
		if (root->data < val)
		{
			root->right = insert(root->right, val);
			if (find_height(root->left) - find_height(root->right) < -1)
			{
				if (val > root->right->data)
					return CaseLeftLeft(root);
				else
				{
					root->right = CaseRightRight(root->right);
					return CaseLeftLeft(root);
				}
			}
			else
			{
				root->height = find_height(root);
				root->balance = root->left - root->right;
			}
		}
		else if (root->data > val)
		{
			root->left = insert(root->left, val);
			if (find_height(root->left) - find_height(root->right) > 1)
			{
				if (val < root->left->data)
					return CaseRightRight(root);
				else
				{
					root->left = CaseLeftLeft(root->left);
					return CaseRightRight(root);
				}
			}
			else
			{
				root->height = find_height(root);
				root->balance = root->left - root->right;
			}
		}
	}
	return root;
}

node* tree::search(node* root, int x)
{
	if (root == NULL)
		return NULL;
	else if (root->data == x)
		return root;
	else if (root->data < x)
		return search(root->right, x);
	else
		return search(root->left, x);
}

void tree::print_PreOrder(node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	cout << root->balance << " ";
	cout << root->height << " ";
	cout << endl;
	print_PreOrder(root->left);
	print_PreOrder(root->right);
}

void tree::print_PostOrder(node* root)
{
	if (root == NULL)
		return;
	print_PostOrder(root->left);
	print_PostOrder(root->right);
	cout << root->data << " ";
	cout << root->balance << " ";
	cout << root->height << " ";
	cout << endl;
}

void tree::print_InOrder(node* root)
{
	if (root == NULL)
		return;
	print_InOrder(root->left);
	cout << root->data << " ";
	cout << root->balance << " ";
	cout << root->height << " ";
	cout << endl;
	print_InOrder(root->right);
}

bool tree::isEmpty(node* root)
{
	if (root == NULL)
		return true;
	return false;
}

void print_current_level(node* node, int level)
{
	if (node == NULL)
		return;
	else if (level == 1)
		cout << node->data << " ";
	else if (level > 1)
	{
		print_current_level(node->left, level - 1);
		print_current_level(node->right, level - 1);
	}
}

void print_line_by_line(node* origin)
{
	int t = find_height(origin);

	for (int i = 1; i <= t; i++)
	{
		print_current_level(origin, i);
		cout << endl;
	}
}