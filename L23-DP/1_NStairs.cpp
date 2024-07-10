#include <iostream>
using namespace std;

int solve(int n, int k) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += solve(n - i, k);
	}
	return ans;
}

int topDown(int n, int k, int *dp) {
	// base case
	if (n == 0) return dp[n] = 1;
	if (n < 0) return 0;

	if (dp[n] != -1) return dp[n];


	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += topDown(n - i, k, dp);
	}
	return dp[n] = ans;
}

int bottomUp(int N, int k) {
	int dp[100000];
	dp[0] = 1;

	for (int n = 1; n <= N; ++n)
	{
		int ans = 0;
		for (int i = 1; i <= k and n >= i; ++i)
		{
			ans += dp[n - i];
		}
		dp[n] = ans;
	}

	for (int i = 0; i <= N; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[N];
}

int optimisedStairs(int N, int k) {
	int dp[100000];

	dp[0] = dp[1] = 1;

	for (int n = 2; n <= N; ++n)
	{
		dp[n] = 2 * dp[n - 1] - ( (n >= k + 1) ? dp[n - 1 - k] : 0 );
	}

	return dp[N];
}

int main() {

	int n;
	cin >> n;
	int k = 3;
	int dp[1000000];
	memset(dp, -1, sizeof dp);
	cout << topDown(n, k, dp) << endl;
	cout << bottomUp(n, k) << endl;
	cout << optimisedStairs(n, k) << endl;

	cout << solve(n, k) << endl;


	return 0;
}
















