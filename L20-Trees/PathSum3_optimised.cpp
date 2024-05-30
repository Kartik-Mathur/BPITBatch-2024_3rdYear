#define node TreeNode
class Solution {
public:

	int ans = 0;

	void solve(node* root, int targetSum, unordered_map<long long int, long long int> &h,
	           long long int sum = 0) {
		if (!root) return;

		sum += root->val;
		long long int val = sum - targetSum;
		// h.count will tell you whether val is present or not
		// h.count(key) : key present hai ya nahi hai
		// h.count(val) -> 0, this means val is not present
		// h.count(val) -> 1, this means val is present
		if (h.count(val) == 1) {
			ans += h[val]; // if val exist krta hai then uski occurances jitni baar hai unhe
			// ans mei add krdo
		}
		h.count(sum) == 0 ? h[sum] = 1 : h[sum]++;
		solve(root->left, targetSum, h, sum);
		solve(root->right, targetSum, h, sum);

		h[sum]--; // backtracking
	}

	int pathSum(TreeNode* root, int targetSum) {
		unordered_map<long long int, long long int> h;
		if (!root) return 0;
		if (!root->left and !root->right) return root->val == targetSum;
		h[0] = 1; // because of the empty tree
		solve(root, targetSum, h);
		return ans;
	}
};






