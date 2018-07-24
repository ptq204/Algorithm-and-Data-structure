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
	return tmp;
}

node* CaseLeftLeft(node* &root)
{
	node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
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
		}
	}
	return root;
}

node* getMin(node* root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}

node* tree::deleteNode(node* &root, int number)
{
	// delete as normal BST
	if (root == NULL)
		return root;
	else if (root->data < number)
		root->right = deleteNode(root->right, number);
	else if (root->data > number)
		root->left = deleteNode(root->left, number);
	else
	{
		node* tmp = NULL;
		if (root->left == NULL || root->right == NULL)
		{
			if (root->left == NULL)
			{
				tmp = root->right;
				delete root;
			}
			else if (root->right == NULL)
			{
				tmp = root->left;
				delete root;
			}
			if (tmp == NULL)
				root = NULL;
			else
				root = tmp;
		}
		else
		{
			node* tmp = getMin(root->right);
			root->data = tmp->data;
			root->right = deleteNode(root->right, tmp->data);
		}
	}

	// making balance after deleting
	if (root == NULL)
		return root;
	else
	{
			if (find_height(root->left) - find_height(root->right) < -1)
			{
				if (number > root->right->data)
					return CaseLeftLeft(root);
				else
				{
					root->right = CaseRightRight(root->right);
					return CaseLeftLeft(root);
				}
			}


			if (find_height(root->left) - find_height(root->right) > 1)
			{
				if (number < root->left->data)
					return CaseRightRight(root);
				else
				{
					root->left = CaseLeftLeft(root->left);
					return CaseRightRight(root);
				}
			}
	}
	return root;
}