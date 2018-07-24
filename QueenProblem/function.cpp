// Pham The Quyen
// 1651029

#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

void maxqueen(int *chess, int *logic, int* logic1, int i, int n, char *arr)
{
	int j, k, q;
	for (j = 0; j < n; j++)
	{
		if (chess[j] && logic1[i - j + n - 1] && logic[i + j])
		{
			chess[j] = false;
			logic1[i - j + n - 1] = false;
			logic[i + j] = false;
			arr[i*n+j] = 'X';
			if (i == n - 1)
			{
				for (k = 0; k < n; k++)
				{
					for (q = 0; q < n; q++)
						cout << arr[k*n+q];
					cout << endl;
				}
				cout << endl;
			}
			else maxqueen(chess, logic, logic1, i + 1, n , arr);
			chess[j] = true;
			logic1[i - j + n - 1] = true;
			logic[i + j] = true;
			arr[i*n+j] = '.';
		}
	}
}