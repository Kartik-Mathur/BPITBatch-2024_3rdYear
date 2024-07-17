#include <iostream>
using namespace std;

string s1 = "Sunday";
string s2 = "Saturday";

int editDistance(int n, int m) {
	// base case
	if (n == 0) return m;
	if (m == 0) return n;

	// recursive case
	if (s1[n - 1] == s2[m - 1]) {
		return editDistance(n - 1, m - 1);
	}

	int op1 = editDistance(n - 1, m - 1); // update
	int op2 = editDistance(n - 1, m); // delete
	int op3 = editDistance(n, m - 1); // insert
	return min(op1, min(op2, op3)) + 1;
}

int topDown(int n, int m, int dp[][100]) {
	// base case
	if (n == 0) return dp[n][m] = m;
	if (m == 0) return dp[n][m] = n;

	if (dp[n][m] != -1) return dp[n][m];

	// recursive case
	if (s1[n - 1] == s2[m - 1]) {
		return dp[n][m] = topDown(n - 1, m - 1, dp);
	}

	int op1 = topDown(n - 1, m - 1, dp); // update
	int op2 = topDown(n - 1, m, dp); // delete
	int op3 = topDown(n, m - 1, dp); // insert
	return dp[n][m] = min(op1, min(op2, op3)) + 1;
}

int bottomUp() {
	int dp[100][100];
	int n = s1.size(), m = s2.size();

	for (int i = 0; i <= n; ++i) dp[i][0] = i;
	for (int j = 0; j <= m; ++j) dp[0][j] = j;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}

	return dp[n][m];

}

int main() {

	cout << editDistance(s1.size(), s2.size()) << endl;
	int dp[100][100];
	memset(dp, - 1, sizeof dp);
	cout << topDown(s1.size(), s2.size(), dp) << endl;
	cout << bottomUp() << endl;


	return 0;
}

















