#include <iostream>
using namespace std;

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

	return dp[m][n];
}

string ans = "";

void findLCS(string &s1, int n, string &s2,  int m, string &x) {
	// base case
	if (!n || !m) {
		if (ans.size() < x.size()) ans = x;
		return;
	}


	// recursive case
	if (s1[n - 1] == s2[m - 1]) {
		x.push_back(s1[n - 1]);
		findLCS(s1, n - 1, s2, m - 1, x);
		x.pop_back(); // backtracking
	}
	else {
		findLCS(s1, n - 1, s2, m, x);
		findLCS(s1, n, s2, m - 1, x);
	}
}

int main() {

	string s = "abcd";
	string s1 = "acd";
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << topDown(s, s1, s.size(), s1.size(), dp) << endl;
	cout << bottomUp(s, s1) << endl;

	int n = s.size(), m = s1.size();
	string x = "";
	while (n and m) {
		if (s[n - 1] == s1[m - 1]) {
			x.push_back(s[n - 1]);
			n--;
			m--;
		}
		else {
			if (dp[n - 1][m] > dp[n][m - 1]) n--;
			else m--;
		}
	}
	reverse(x.begin(), x.end());
	cout << x << endl;


	// FINDING LCS CHARACTERS USING RECURSION, WITHOUT DP
	x = "";
	findLCS(s1, s1.size(), s, s.size(), x);
	reverse(ans.begin(), ans.end());
	cout << ans << endl;


	return 0;
}













