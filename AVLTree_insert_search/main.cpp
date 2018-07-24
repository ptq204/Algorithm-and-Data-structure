// Pham The Quyen
// 1651029

#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
	tree t;
	ifstream file;
	node* find = NULL;
	int key;
	int op;
	cout << "1. insert a key into AVL tree" << endl;
	cout << "2. search a key" << endl;
	cout << "3. print Post Order" << endl;
	cout << "4. print Pre Order" << endl;
	cout << "5. print In Order" << endl;
	cout << "choose option or 0 to exit " << endl;
	cin >> op;
	while (op != 0)
	{
	switch (op)
	{
	case 1: cout << "1. insert a key into AVL tree" << endl;
	cout << "input a key: ";
	cin >> key;
	t.insert(t.root, key);
	cout << "Done !" << endl;
	cout << endl;
	break;

	case 2: cout << "2. search a node which has value x" << endl;
	cout << "input x: ";
	cin >> key;
	find = t.search(t.root, key);
	if (find == NULL)
	cout << "Cannot find" << endl;
	else
	cout << "found it: "<< find->data << endl;
	cout << endl;
	break;

	case 3: cout << "3. print Post Order" << endl;
	t.print_PostOrder(t.root);
	cout << endl;
	break;

	case 4: cout << "4. print Pre Order" << endl;
	t.print_PreOrder(t.root);
	cout << endl;
	break;

	case 5: cout << "5. print In Order" << endl;
	t.print_InOrder(t.root);
	cout << endl;
	break;
	}
	cout << "1. insert a key into AVL tree" << endl;
	cout << "2. search a key" << endl;
	cout << "3. print Post Order" << endl;
	cout << "4. print Pre Order" << endl;
	cout << "5. print In Order" << endl;
	cout << "choose option or 0 to exit ";
	cin >> op;
	}
	t.deleteTree(t.root);
	return 0;
}