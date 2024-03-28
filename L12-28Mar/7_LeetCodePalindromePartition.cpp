class Solution {
public:
	vector<vector<string> > ans;

	bool isPalindrome(string &x) {
		int i = 0, j = x.size() - 1;
		while (i < j) {
			if (x[i++] != x[j--]) return false;
		}
		return true;
	}

	void palindromePartition(string s, int i, vector<string> &v) {
		// base case
		if (i == s.length()) {
			ans.push_back(v);
			return;
		}
		// recursive case
		for (int j = i; j < s.length(); ++j)
		{
			string x = s.substr(i, j - i + 1);
			if (isPalindrome(x)) {
				v.push_back(x);
				palindromePartition(s, j + 1, v);
				v.pop_back();
			}
		}

	}

	vector<vector<string>> partition(string s) {
		vector<string> v;
		palindromePartition(s, 0, v);
		return ans;
	}
};











