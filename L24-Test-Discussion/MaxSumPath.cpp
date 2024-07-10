#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

node* buildTreeLevel() {
	node* root = NULL;

	int data;
	cin >> data;
	if (data == -1) return root;

	root = new node(data);
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* f = q.front();
		q.pop();
		int l, r; cin >> l >> r;

		if (l != -1) f->left = new node(l), q.push(f->left);
		if (r != -1) f->right = new node(r), q.push(f->right);
	}

	return root;
}

int ans = INT_MIN;

int maxPathSum(node* root) {
	// base case
	if (!root) return 0;

	// recursive case
	int left = maxPathSum(root->left);
	int right = maxPathSum(root->right);

	int tempAns = root->data;
	if (left > 0) tempAns += left;
	if (right > 0) tempAns += right;

	ans = max(ans, tempAns);

	return root->data + max(0, max(left, right));
}

int main() {

	node* root = buildTreeLevel();

	maxPathSum(root);

	cout << ans << endl;

	return 0;
}
















