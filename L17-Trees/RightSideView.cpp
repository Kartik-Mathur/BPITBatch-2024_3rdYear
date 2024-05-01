#define node TreeNode
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<node*> q;
		vector<int> temp;

		if (!root) return temp;

		q.push(root);
		q.push(NULL);
		int lastData;
		while (!q.empty()) {
			node* x = q.front();
			q.pop();
			if (x) {
				lastData = x->val;
				if (x->left) q.push(x->left);
				if (x->right) q.push(x->right);
			}
			else {
				temp.push_back(lastData);
				if (!q.empty()) q.push(NULL);
			}
		}

		return temp;
	}
};
