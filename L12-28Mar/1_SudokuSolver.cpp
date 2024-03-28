#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int a[][9], int n, int i, int j, int number) {
	// 1. Row and column ke andar same number nhi hona chahiye
	for (int k = 0; k < n; ++k)
	{
		if (a[k][j] == number || a[i][k] == number) return false;
	}
	// 2. Current cell ke andar same number nahi hona chahiye
	n = sqrt(n);
	int si = (i / n) * n;
	int sj = (j / n) * n;
	// si and sj se n*n matrix hai usmei number nahi hona chahiye
	for (int i = si; i < si + n; ++i)
	{
		for (int j = sj; j < sj + n; ++j)
		{
			if (a[i][j] == number) return false;
		}
	}

	return true;
}

bool sudokuSolver(int a[][9], int n, int i, int j) {
	// base case
	if (i == n) {
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	// Checking points
	if (j == n) {
		return sudokuSolver(a, n, i + 1, 0);
	}

	// On already filled cell
	if (a[i][j] != 0) {
		return sudokuSolver(a, n, i, j + 1);
	}
	// recursive case
	// 1 empty cell ka kaam krdo: Maanlo empty cell par ho
	for (int number = 1; number <= n; ++number)
	{
		if (isSafe(a, n, i, j, number)) {
			a[i][j] = number;
			bool kyaBakiSolveHua = sudokuSolver(a, n, i, j + 1);
			if (kyaBakiSolveHua) return true;
			a[i][j] = 0; // backtracking
		}
	}
	// we weren't able to place any number [1,n], thus possible nhi h
	// to solve this empty cell
	return false;
}


int main() {

	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	sudokuSolver(mat, 9, 0, 0);

	return 0;
}
















