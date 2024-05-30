#define node TreeNode
class Solution {

public:
	int ans = 0;

	int solve(node* root) {
		if (!root) return 0; // na kuch dena hai, na kuch lena hai

		int cl = solve(root->left);
		int cr = solve(root->right);
		ans += abs(cl) + abs(cr); // coins ke movements around the edges
		return root->val + cl + cr - 1;
	}

	int distributeCoins(TreeNode* root) {
		solve(root);
		return ans;
	}
};