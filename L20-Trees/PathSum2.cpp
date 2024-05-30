#define node TreeNode
class Solution {
public:
	vector<vector<int>> ans;
	void solve(node* root, int targetSum, vector<int> &x, int sum = 0) {
		// base case
		if (!root) return;

		// recursive case
		sum += root->val;
		x.push_back(root->val);
		// check leaf node
		// if (!root->left and !root->right) return targetSum == sum ? true : false;
		if (!root->left and !root->right) {
			if (targetSum == sum) {
				ans.push_back(x);
			}
			x.pop_back(); // backtracking at leaf node too
			return;
		}

		solve(root->left, targetSum, x, sum);
		solve(root->right, targetSum, x, sum);
		x.pop_back(); // backtracking
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> x;
		solve(root, targetSum, x);
		return ans;
	}
};











