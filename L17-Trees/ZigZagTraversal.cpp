#define node TreeNode
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > ans;
		if (!root) return ans;
		vector<int> temp;

		queue<node*> q;

		q.push(root);
		q.push(NULL);
		int level = 0;
		while (!q.empty()) {
			node* x = q.front();
			q.pop();
			if (x) {
				temp.push_back(x->val);
				if (x->left) q.push(x->left);
				if (x->right) q.push(x->right);
			}
			else {
				if (level % 2 == 0) {
					ans.push_back(temp);
				}
				else {
					reverse(temp.begin(), temp.end());
					ans.push_back(temp);
				}
				temp.clear();

				level++;
				if (!q.empty()) q.push(NULL);
			}
		}

		return ans;
	}
};





