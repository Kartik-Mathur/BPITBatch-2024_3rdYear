#include <iostream>
using namespace std;

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
	// 2. Right jaa skte hai toh right jakar check karo
	if (j + 1 < m and maze[i][j + 1] != 'X' and sol[i][j + 1] != 1) {
		bool kyaRightSeRaastaMilla =
		    ratInMaze(maze, i, j + 1, n, m, sol);
		if (kyaRightSeRaastaMilla)
			return true;
	}
	// 3. Neeche jaa skte hai toh Neeche jakar check karo
	if (i + 1 < n and maze[i + 1][j] != 'X' and !sol[i + 1][j]) {
		bool kyaNeecheSeRaastaMilla = ratInMaze(maze, i + 1, j, n, m, sol);
		if (kyaNeecheSeRaastaMilla) return true;
	}
	// 4. Peeche se jaa skte hai toh jaakar check karo
	if (j - 1 >= 0 and maze[i][j - 1] != 'X' and !sol[i][j - 1]) {
		bool kyaPeecheSeRaastaHai = ratInMaze(maze, i, j - 1, n, m, sol);
		if (kyaPeecheSeRaastaHai) return true;
	}
	if (i - 1 >= 0 and maze[i - 1][j] != 'X' and !sol[i - 1][j]) {
		bool kyaUparSeRaastaHai = ratInMaze(maze, i - 1, j, n, m, sol);
		if (kyaUparSeRaastaHai) return true;
	}
	// . Right and Neeche kahi se raasta nahi milla toh
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
















