#define node TreeNode
class Solution {
public:
	node* lowestCommonAncestor(node* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		if (root == p) return p;
		if (root == q) return q;

		node* left = lowestCommonAncestor(root->left, p, q);
		node* right = lowestCommonAncestor(root->right, p, q);
		if (left and right) return root;
		if (left) return left;
		return right;
	}
};