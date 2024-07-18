class Solution {
public:
	int solve(vector<int>& prices, int i, int transactions, bool isActiveTransaction,
	          int dp[][201], int k) {
		// base case
		if (transactions == 2 * k || i == prices.size()) return dp[i][transactions] = 0;

		if (dp[i][transactions] != -1) return dp[i][transactions];

		// recursive case
		if (!isActiveTransaction) {
			int op1 = -prices[i] + solve(prices, i + 1, transactions + 1, true, dp, k);
			int op2 = 0 + solve(prices, i + 1, transactions, isActiveTransaction, dp, k);
			return dp[i][transactions] = max(op1, op2);
		}
		else {
			int op1 = prices[i] + solve(prices, i + 1, transactions + 1, false, dp, k);
			int op2 = 0 + solve(prices, i + 1, transactions, isActiveTransaction, dp, k);
			return dp[i][transactions] = max(op1, op2);
		}
	}

	int maxProfit(int k, vector<int>& prices)  {
		int dp[1005][201];
		memset(dp, -1, sizeof dp);

		return solve(prices, 0, 0, false, dp, k);
	}
};