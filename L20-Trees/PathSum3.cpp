// First Approach: Call pathsum1 on every node of the tree
#define node TreeNode
class Solution {
public:
	int ans = 0;

	void pathSum1(TreeNode* root, int targetSum, int sum = 0) {
		// base case
		if (!root) return;

		// recursive case
		sum += root->val;
		if (sum == targetSum) ans++;
		// check leaf node
		// if (!root->left and !root->right) return targetSum == sum ? true : false;
		if (!root->left and !root->right) return;

		pathSum1(root->left, targetSum, sum);
		pathSum1(root->right, targetSum, sum);
	}

	void solve(node* root, int targetSum) {
		if (!root) return;

		pathSum1(root, targetSum);
		solve(root->left, targetSum); // left subtree ke liye sabhi par pathsum1 call krde
		solve(root->right, targetSum); // right subtree ke liye sabhi par pathsum1 call krde
	}


	int pathSum(TreeNode* root, int targetSum) {
		solve(root, targetSum);
		return ans;
	}
};












