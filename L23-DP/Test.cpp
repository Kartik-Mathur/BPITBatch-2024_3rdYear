#include <iostream>
using namespace std;

int fibo(int n, int *dp) {
	if (n <= 1) return dp[n] = n;
	if (dp[n] != -1) return dp[n];

	return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int main() {
	int dp[10000];
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;

	cout << fibo(n, dp) << endl;

	return 0;
}
















