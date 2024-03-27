#include <iostream>
using namespace std;

bool isSafe(int i, int j, int n, int board[][100]) {
	// 1. Same column mei queen nhi honi chahiye
	for (int k = 0; k < i; ++k) if (board[k][j]) return false;

	int oi = i, oj = j;
	// 2. Upper right diagonal par nhi honi chahiye
	while (i >= 0 and j < n) {
		if (board[i][j]) return false;
		i--;
		j++;
	}
	// 3. Upper left diagonal par nhi honi chahiye
	i = oi; j = oj;
	while (i >= 0 and j >= 0) {
		if (board[i][j]) return false;
		i--;
		j--;
	}
	return true;
}

bool Nqueen(int board[][100], int i, int n) {
	// base case
	if (i == n) {
		// print the board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j]) cout << "Q ";
				else cout << "_ ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}
	// recursive case
	for (int j = 0; j < n; ++j)
	{
		if (isSafe(i, j, n, board)) {
			// Agar rakhna safe hai toh queen rakhdo
			board[i][j] = 1;
			// Ab baaki remaining queens place ho paai?
			bool kyaBaakiPlaceHui = Nqueen(board, i + 1, n);
			if (kyaBaakiPlaceHui == true) return true;
			// Agar baaki place nhi ho pai, thus remove jo humne
			// rakhi thi
			board[i][j] = 0; // backtracking
		}
	}
	// We tried every column of i from [0,n-1]
	return false;
}


int main() {

	int board[100][100] = {0};

	Nqueen(board, 0, 4);



	return 0;
}
















