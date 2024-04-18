#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
public:
	void solve(int s, int k, int target, vi &x, vvi &ans) {
		if (target == 0 and k == 0) {
			ans.push_back(x);
			return;
		}

		if (target <= 0 || k <= 0) return;

		for (int no = s; no <= 9; ++no)
		{
			if (target < no) break;

			x.push_back(no);
			solve(no + 1, k - 1, target - no, x, ans);
			x.pop_back();

		}
	}

	vvi combinationSum3(int k, int target) {
		vvi ans;
		vi x;
		solve(1, k, target, x, ans);
		return ans;
	}
};



