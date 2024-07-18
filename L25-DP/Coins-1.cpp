#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double coins[3001];
double dp[3001][3001];
int n;

double solve(int i, int heads) {
	// base case
	if (heads == 0) return dp[i][heads] = 1;
	if (i == n) return dp[i][heads] = 0;

	if (dp[i][heads] > -1) return dp[i][heads];

	// recursive case
	double ans = coins[i] * solve(i + 1, heads - 1) +
	             (1 - coins[i]) * solve(i + 1, heads);

	return dp[i][heads] = ans;
}

int main() {
	memset(dp, -1, sizeof dp);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> coins[i];

	cout << fixed << setprecision(10) << solve(0, n / 2 + 1) << endl;



	return 0;
}


