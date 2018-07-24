// Pham The Quyen
// 1651029
#include "Header.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "input size of the board: ";
	cin >> n;
	char *arr = new char[n*n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i*n + j] = '.';
	cout << "all possible way: " << endl;
	int *chess = new int[n];
	int *logic = new int[2 * n];
	int *logic1 = new int[2 * n];
	int* row = new int[n];
	for (int j = 0; j < 2 * n; j++)
		logic[j] = true;
	for (int i = 0; i < 2 * n; i++)
		logic1[i] = true;
	for (int i = 0; i < n; i++)
		chess[i] = true;
	for (int i = 0; i < n; i++)
		row[i] = true;
	maxqueen(chess, logic, logic1, 0, n , arr);
	delete[]logic;
	delete[]logic1;
	delete[]chess;
	delete[]arr;
	return  0;
}