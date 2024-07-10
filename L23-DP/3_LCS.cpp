#include <iostream>
using namespace std;

int lcs(string s1, string s2, int i, int j) {
	if (i == 0 || j == 0) return 0;

	if (s1[i - 1] == s2[j - 1]) {
		// If character matches then 1 + recursion will do work for smaller strings
		return 1 + lcs(s1, s2, i - 1, j - 1);
	}
	// if characters at s1[i-1] != s2[j-1]
	int op1 = lcs(s1, s2, i - 1, j);
	int op2 = lcs(s1, s2, i, j - 1);
	return max(op1, op2);
}

int topDown(string &s1, string &s2, int i, int j, int dp[][100]) {
	if (i == 0 || j == 0) return dp[i][j] = 0;

	if (dp[i][j] != -1) return dp[i][j];

	if (s1[i - 1] == s2[j - 1]) {
		// If character matches then 1 + recursion will do work for smaller strings
		return dp[i][j] = 1 + topDown(s1, s2, i - 1, j - 1, dp);
	}
	// if characters at s1[i-1] != s2[j-1]
	int op1 = topDown(s1, s2, i - 1, j, dp);
	int op2 = topDown(s1, s2, i, j - 1, dp);
	return dp[i][j] = max(op1, op2);
}

int bottomUp(string &s1, string &s2) {
	int m = s1.size(), n = s2.size();
	int dp[100][100];
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[m][n];
}

int main() {

	string s = "abcd";
	string s1 = "abc";
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << topDown(s, s1, s.size(), s1.size(), dp) << endl;
	cout << bottomUp(s, s1) << endl;
	cout << lcs(s, s1, s.size(), s1.size()) << endl;



	return 0;
}
















