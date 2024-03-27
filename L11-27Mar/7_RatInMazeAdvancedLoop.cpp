#include <iostream>
using namespace std;
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

bool isValid(char maze[][6], int i, int j, int n, int m) {
	if (i >= 0 and i<n and j >= 0 and j < m and maze[i][j] != 'X')
		return true;
	return false;
}

bool ratInMaze(char maze[][6], int i,
               int j, int n, int m, int sol[][100]) {
	// basecase
	if (i == n - 1 and j == m - 1) {
		// Destination bhi solution ka part hoga
		sol[i][j] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}

	// recursive case
	// 1. Jis cell par khade ho usse sol ka part maanlo
	sol[i][j] = 1;

	for (int k = 0; k < 4; ++k)
	{
		int ni = i + x[k];
		int nj = j + y[k];
		if (isValid(maze, ni, nj, n, m) and !sol[ni][nj]) {
			bool kyaBaatBani = ratInMaze(maze, ni, nj, n, m, sol);
			if (kyaBaatBani) return true;
		}
	}
	// Current cell sol ka part nahi ho skta
	sol[i][j] = 0; // backtracking
	return false;
}

int main() {

	char maze[6][6] = {
		"0X000",
		"0X0X0",
		"0X0X0",
		"0X0X0",
		"000X0"
	};
	int sol[100][100] = {0};

	ratInMaze(maze, 0, 0, 5, 5, sol);

	return 0;
}
















