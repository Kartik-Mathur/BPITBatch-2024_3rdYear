class Solution {
public:

	bool isPalindrome(string &s, int i, int j) {
		while (i < j) {
			if (s[i++] != s[j--]) return false;
		}
		return true;
	}

	int solve(string &s, int i, vector<int> &dp) {
		if (i == s.size()) return dp[i] = 0;

		if (dp[i] != -1) return dp[i];

		int ans = INT_MAX;
		for (int j = i; j < s.size(); ++j)
		{
			if (isPalindrome(s, i, j)) {
				ans = min(ans, 1 + solve(s, j + 1, dp));
			}
		}

		return dp[i] = ans;
	}

	int minCut(string &s) {
		vector<int> dp(s.size() + 1, -1);
		return solve(s, 0, dp);
	}
};







