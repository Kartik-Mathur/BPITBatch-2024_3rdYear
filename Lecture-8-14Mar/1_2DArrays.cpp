#include <iostream>
using namespace std;

void spiralPrint(int a[][100], int n, int m) {

	// 1. Pehle create the required variables
	int sr, er, sc, ec;
	sr = sc = 0;

	er = n - 1;
	ec = m - 1;

	// 2. Algorithm
	while (sr <= er and sc <= ec) {
		// 1. Print sr from sc to ec
		for (int col = sc; col <= ec; ++col)
		{
			cout << a[sr][col] << " ";
		}

		sr++;

		// 2. Print ec from sr to er
		for (int row = sr; row <= er; ++row)
		{
			cout << a[row][ec] << " ";
		}

		ec--;

		// 3. Print er from ec to sc
		if (sr < er) {
			for (int col = ec; col >= sc ; --col)
			{
				cout << a[er][col] << " ";
			}
			er--;
		}

		// 4. Print sc from er to sr
		if (sc < ec) {
			for (int row = er; row >= sr; --row)
			{
				cout << a[row][sc] << " ";
			}
			sc++;
		}
	}

}



int main() {

	// 1. 2d Array create karo
	int a[100][100];

	// 2. 2d array ka input lo
	int m, n;
	cin >> n >> m;
	int no = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = no++;
		}
	}

	// 2. Print the 2d array
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	// 3. Sprial Print Algorithm
	spiralPrint(a, n, m);

	return 0;
}
















