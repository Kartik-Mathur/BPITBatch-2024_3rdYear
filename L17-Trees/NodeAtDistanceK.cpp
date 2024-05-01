#define node TreeNode
class Solution {
public:
	void findSubtreeNodesK(node* root, int d, int k, vector<int> &ans) {
		// if root is not present go back you couldn't find anything
		if (!root) return;

		// If current node is at d == k, then this node is the answer
		if (d == k) {
			ans.push_back(root->val);
			return;
		}

		findSubtreeNodesK(root->left, d + 1, k, ans);
		findSubtreeNodesK(root->right, d + 1, k, ans);
	}

	int solve(node* root, node* target, int k, vector<int> &ans) {
		if (!root) return -1;

		if (root == target) return 0;

		// Try to solve the left side first
		int d = solve(root->left, target, k, ans);

		if (d != -1) { // Agar left side mei target present hua toh -1 nahi aaega
			// ab agar d + 1 == k hua toh root hi mere target se distance k par h
			if (d + 1 == k) {
				ans.push_back(root->val);
				// -1 return kia because ab upar wale tree mei answer milna is not
				// possible
				return -1;
			}
			int kd = k - (d + 2);
			// node* root, int d, int k, vector<int> &ans
			findSubtreeNodesK(root->right, 0, kd, ans);
			return d + 1;
		}
		else {
			d = solve(root->right, target, k, ans);
			if (d != -1) { // if rightSubtree mei target present hai
				if (d + 1 == k) {
					ans.push_back(root->val);
					return -1;
				}
			}
			int kd = k - (d + 2);
			findSubtreeNodesK(root->left, 0, kd, ans);
			return d + 1;
		}

	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		vector<int> ans;
		// Target ke subtree ka kaam krdo sabse pehle
		findSubtreeNodesK(target, 0, k, ans);
		solve(root, target, k, ans);
		return ans;
	}
};



















