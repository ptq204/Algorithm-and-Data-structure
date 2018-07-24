// Pham The Quyen
// 1651029

#include <iostream>
#include "Header.h"
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

int main()
{
	hashMap map;
	string key;
	int choice = 1;
	int test;
	double pro;
	ifstream file;
	ofstream file1;

	cout << "1. Hash the key (from a text file) to an index" << endl;
	cout << "2. Find the node consists the key" << endl;
	cout << "3. Return the value of the found node" << endl;
	cout << "4. Print all the keys and its value as key" << endl;
	cout << "your choice or 0 to exit" << endl;
	cin >> choice;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1: 
			test = 1;
			system("cls");
			cout << "1. Hash the key (from a text file) to an index" << endl;
			file.open("input1.txt");
			while (!file.eof())
			{
				getline(file, key);
				cout << key << endl;
				// file >> pro;
				// file.ignore();
				map.insert(key);
				map.print_occurence();
			}
			cout << "Done" << endl;
			file.close();
			cout << "5. back to menu" << endl;
			break;

		case 2: 
			test = 2;
			system("cls");
			cout << "2. Find the node consists the key" << endl;
			cout << "input the key: ";
			cin >> key;
			if (map.findHash(key))
				cout << "found it !" << endl;
			else
				cout << "cannot find the key" << endl;
			cout << endl;
			cout << "5. back to menu" << endl;
			break;

		case 3:
			test = 3;
			system("cls");
			cout << "3. Return the value of the found node" << endl;
			if (test != 2)
				cout << "Please choose option 2 to continue" << endl;
			else
			{
				cout << "key's value is " << map.return_value(key) << endl;
			}
			cout << endl;
			cout << "5. back to menu" << endl;
			break;

		case 4:
			test = 4;
			system("cls");
			cout << "4. Print all the keys and its value as key" << endl;
			map.print_occurence();
			cout << endl;
			cout << "5. back to menu" << endl;
			break;
		
		case 5:
			test = 5;
			system("cls");
			cout << "1. Hash the key (from a text file) to an index" << endl;
			cout << "2. Find the node consists the key" << endl;
			cout << "3. Return the value of the found node" << endl;
			cout << "4. Print all the keys and its value as key" << endl;
			cout << "your choice or 0 to exit" << endl;
			break;
		}
		cin >> choice;
	}
	return 0;
}
