#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
public:

	void solve(vi& ip, vi&x, vvi&ans, int s) {
		// jo bhi current x mei value hai that is my answer
		ans.push_back(x);

		for (int i = s; i < ip.size(); ++i)
		{
			if (i != s and ip[i] == ip[i - 1]) continue;
			x.push_back(ip[i]);
			solve(ip, x, ans, i + 1);
			x.pop_back();
		}
	}

	vvi subsetsWithDup(vi& nums) {
		vi x;
		vvi ans;
		sort(nums.begin(), nums.end());
		solve(nums, x, ans, 0);
		return ans;
	}

};