#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

    int **square = new int*[n];
	for (int k = 0; k < n; k++)
	{
		square[k] = new int[n];
		memset(square[k], 0, sizeof(int)*n);
	}

	int key = 2;
	int i = 0;
	int j = n / 2;
	int row, col;

	square[i][j] = 1;

	while (key <= n * n)
	{
		if (i - 1 < 0)row = n - 1;
		else row = i - 1;

		if (j > n - 2)col = 0;
		else col = j + 1;

		if (square[row][col]) i = (i + 1) % n;
		else
		{
			i = row; j = col;
		}
		square[i][j] = key++;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << square[i][j] << " ";
		}
		cout << endl;
	}
}