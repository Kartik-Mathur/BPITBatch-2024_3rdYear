#include <iostream>
using namespace std;

void print2D(int a[][100], int row, int col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void transpose2D(int a[][100], int row, int col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = i + 1; j < col; ++j)
		{
			swap(a[i][j], a[j][i]);
		}
	}
}

int main() {

	int a[100][100];

	int row, col, number = 1;
	cin >> row >> col;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			a[i][j] = number++;
		}
	}

	print2D(a, row, col);
	transpose2D(a, row, col);
	print2D(a, row, col);


	return 0;
}
















