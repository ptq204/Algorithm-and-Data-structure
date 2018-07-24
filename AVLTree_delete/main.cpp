// Pham The Quyen
// 1651029
#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int main()
{
	tree t;
	ifstream file;
	int num;
	file.open("input.txt");
	int op;
	cout << "1. insert a number" << endl;
	cout << "2. delete a number" << endl;
	cout << "choose option or press 0 to exit" << endl;
	cin >> op;
	while (op != 0)
	{
		switch(op)
		{
		case 1: cout << "which number do you want to insert: ";
			cin >> num;
			t.insert(t.root, num);
			cout << "Done!" << endl;
			break;

		case 2: cout << "which number do you want to delete: ";
			cin >> num;
			t.deleteNode(t.root, num);
			cout << "Done!" << endl;
			break;
		}
	}
	t.deleteTree(t.root);
	return 0;
}