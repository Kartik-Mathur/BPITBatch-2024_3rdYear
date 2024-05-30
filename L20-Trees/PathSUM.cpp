class Solution {
public:
	bool solve(TreeNode* root, int targetSum, int sum = 0) {
		// base case
		if (!root) return false;

		// recursive case
		sum += root->val;

		// check leaf node
		// if (!root->left and !root->right) return targetSum == sum ? true : false;
		if (!root->left and !root->right) return targetSum == sum;

		bool ans = solve(root->left, targetSum, sum);
		if (ans == true) return true;
		return solve(root->right, targetSum, sum);
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		// corner case
		if (!root) return false;

		return solve(root, targetSum);
	}
};