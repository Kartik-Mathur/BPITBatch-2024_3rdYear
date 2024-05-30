#include <iostream>
#include <vector>
using namespace std;

int fibo(int n) {
	if (n <= 1) return n;

	return fibo(n - 1) + fibo(n - 2);
}


int topDown(int n, int *dp) {
	if (n <= 1) return dp[n] = n;

	// Calculated hai toh return krdo
	if ( dp[n] != -1) return dp[n];

	return dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
}

int bottomUp(int n) {
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}


int main() {

	int n;
	cin >> n;
	int dp[10000];

	for (int i = 0; i < 10000; ++i) dp[i] = -1;

	cout << topDown(n, dp) << endl;
	cout << bottomUp(n) << endl;
	cout << fibo(n) << endl;

	return 0;
}
















