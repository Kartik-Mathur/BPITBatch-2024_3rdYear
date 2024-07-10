#include <iostream>
using namespace std;

int solve(int *price, int l, int r, int day) {
	// base case
	if (l > r) return 0;

	// recursive case
	int op1 = price[l] * day + solve(price, l + 1, r, day + 1);
	int op2 = price[r] * day + solve(price, l, r - 1, day + 1);
	return max(op1, op2);
}

int topDown(int *price, int l, int r, int day, int dp[][100]) {
	// base case
	if (l > r) return dp[l][r] = 0;

	if (dp[l][r] != -1) return dp[l][r];
	// recursive case
	int op1 = price[l] * day + topDown(price, l + 1, r, day + 1, dp);
	int op2 = price[r] * day + topDown(price, l, r - 1, day + 1, dp);
	return dp[l][r] = max(op1, op2);
}

int bottomUp(int *price, int n) {
	int dp[100][100] = {};

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			int day = n - (j - i);
			int op1 = price[i] * day + ((i + 1 < n) ? dp[i + 1][j] : 0);
			int op2 = price[j] * day + ((j - 1 >= 0) ? dp[i][j - 1] : 0);
			dp[i][j] = max(op1, op2);
		}
	}

	return dp[0][n - 1];
}

int bottomUpDiagonal(int *price, int n) {
	int dp[100][100] = {};

	for (int k = 0; k < n; k++)
	{

		for (int i = 0, j = k; i < n and j < n; ++j, ++i)
		{
			int day = n - (j - i);
			int op1 = price[i] * day + ((i + 1 < n) ? dp[i + 1][j] : 0);
			int op2 = price[j] * day + ((j - 1 >= 0) ? dp[i][j - 1] : 0);
			dp[i][j] = max(op1, op2);
		}
	}

	return dp[0][n - 1];
}

int main() {

	int a[] = {2, 3, 5, 1, 4};
	int n = sizeof(a) / sizeof(int);
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << topDown(a, 0, n - 1, 1, dp) << endl;
	cout << bottomUp(a, n) << endl;
	cout << bottomUpDiagonal(a, n) << endl;
	cout << solve(a, 0, n - 1, 1) << endl;

	return 0;
}
















