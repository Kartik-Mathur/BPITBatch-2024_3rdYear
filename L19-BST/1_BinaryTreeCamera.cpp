#define node TreeNode
class Solution {
public:
	unordered_map <node*, bool> vigilance;
	int cameras = 0;

	void solve(node* root, node* parent) {
		if (!root) return;

		// LST and RST ka kaam krwaao
		solve(root->left, root);
		solve(root->right, root);

		// camera lagega toh lagado, else vapis jaao
		if ( (parent == NULL and vigilance[root] == false) or
		        vigilance[root->left] == false or
		        vigilance[root->right] == false) {
			cameras++;
			vigilance[root] = true;
			vigilance[root->left] = true;
			vigilance[root->right] = true;
			vigilance[parent] = true;
		}
	}


	int minCameraCover(TreeNode* root) {
		vigilance[NULL] = true;
		solve(root, NULL);
		return cameras;
	}
};