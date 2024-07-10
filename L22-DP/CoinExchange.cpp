#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define ll long long
vector<ll> coins({1, 5, 10});

ll solve(ll amount) {
	// base case
	if (amount == 0) {
		return 0;
	}

	// recursive case
	ll ans = INT_MAX;
	for (int i = 0; i < coins.size(); ++i)
	{
		if (amount >= coins[i]) {
			ll xi = solve(amount - coins[i]);
			if (xi != INT_MAX) {
				ans = min(ans, xi + 1);
			}
		}
	}

	return ans;
}


ll topDown(ll amount, ll *dp) {
	// base case
	if (amount == 0) {
		return dp[amount] = 0;
	}

	if (dp[amount] != -1) return dp[amount];

	// recursive case
	ll ans = INT_MAX;
	for (int i = 0; i < coins.size(); ++i)
	{
		if (amount >= coins[i]) {
			ll xi = topDown(amount - coins[i], dp);
			if (xi != INT_MAX) {
				ans = min(ans, xi + 1);
			}
		}
	}

	return dp[amount] = ans;
}

ll bottomUp(ll amount) {
	vector<ll> dp(amount + 1, INT_MAX);

	dp[0] = 0;
	for (int i = 1; i <= amount; ++i)
	{
		ll ans = INT_MAX;
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i >= coins[j]) {
				if (dp[i - coins[j]] != INT_MAX)
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	for (int i = 0; i < dp.size(); ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	return dp[amount];
}


int main() {

	ll amount;
	cin >> amount;
	ll dp[100005];

	memset(dp, -1, sizeof dp);
	cout << topDown(amount, dp) << endl;

	bottomUp(amount);
	// ll ans = solve(amount);
	// if (ans != INT_MAX)
	// 	cout << ans << endl;
	// else cout << -1 << endl;



	return 0;
}









