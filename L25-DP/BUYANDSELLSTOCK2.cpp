class Solution {
public:
	int solve(vector<int>& prices, int i, int transactions, bool isActiveTransaction,
	          int dp[][2]) {
		// base case
		if (transactions == 4 || i == prices.size()) return dp[i][transactions] = 0;

		if (dp[i][transactions] != -1) return dp[i][transactions];

		// recursive case
		if (!isActiveTransaction) {
			int op1 = -prices[i] + solve(prices, i + 1, transactions + 1, true);
			int op2 = 0 + solve(prices, i + 1, transactions, isActiveTransaction);
			return dp[i][transactions] = max(op1, op2);
		}
		else {
			int op1 = prices[i] + solve(prices, i + 1, transactions + 1, false);
			int op2 = 0 + solve(prices, i + 1, transactions, isActiveTransaction);
			return dp[i][transactions] = max(op1, op2);
		}
	}

	int maxProfit(vector<int>& prices) {
		int dp[100005][2];
		memset(dp, -1, sizeof dp);

		return solve(prices, 0, 0, false, dp);
	}
};