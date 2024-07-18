class Solution {
public:
	bool solve(string &s, int i, string &p, int j, int dp[][2001]) {
		// base case
		if (i == s.size()) {
			for (int k = j; k < p.size(); ++k)
			{
				if (p[k] != '*') return false;
			}
			return true;
		}

		if (j == p.size()) return false;

		if (dp[i][j] != -1) return dp[i][j] == 1;

		// recursive case
		bool ans = false; // lets assume abhi string s and p don't match with each other
		if (s[i] == p[j] || p[j] == '?') {
			ans = solve(s, i + 1, p, j + 1, dp);
		}
		else if (p[j] == '*') {
			// Match krlo s[i] ko with '*'
			bool match = solve(s, i + 1, p, j, dp);
			// Match mat kro s[i] ko with '*'
			bool noMatch = solve(s, i, p, j + 1, dp);
			if (match || noMatch) ans = true;
		}

		if (ans == true) {
			dp[i][j] = 1; // 1 denotes s and p match hote hai
		}
		else {
			dp[i][j] = 2; // 2 denotes s and p match nahi hote
		}
		return ans;
	}

	bool isMatch(string &s, string &p) {
		int dp[2001][2001];
		memset(dp, -1, sizeof dp);
		return solve(s, 0, p, 0, dp);
	}
};











