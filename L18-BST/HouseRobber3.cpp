#define node TreeNode
class Solution {
public:

	class Pair {
	public:
		int choriKari = 0;
		int choriNahiKari = 0;
	};

	Pair solve(node* root) {
		if (!root) return {0, 0};

		Pair left = solve(root->left);
		Pair right = solve(root->right);

		Pair p;
		p.choriKari = root->val + left.choriNahiKari + right.choriNahiKari;
		p.choriNahiKari = max(left.choriKari, left.choriNahiKari) +
		                  max(right.choriKari, right.choriNahiKari);
		return p;
	}

	int rob(TreeNode* root) {
		Pair p = solve(root);
		return max(p.choriKari, p.choriNahiKari);
	}
};






