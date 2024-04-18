#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
public:

	void solve(vi& ip, vvi& ans, vi &x, int s, int target) {
		if (target == 0) {
			ans.push_back(x);
			return;
		}

		for (int i = s; i < ip.size(); ++i)
		{
			if (i != s and ip[i] == ip[i - 1]) continue;
			if (ip[i] > target) break;
			// Otherwise lets do the work for ith element
			x.push_back(ip[i]);
			solve(ip, ans, x, i + 1, target - ip[i]);
			x.pop_back();
		}
	}

	vvi combinationSum2(vi& nums, int target) {
		sort(nums.begin(), nums.end());
		vvi ans;
		vi x;
		solve(nums, ans, x, 0, target);
		return ans;
	}
};