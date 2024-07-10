#include <iostream>
#include <climits>
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

node* buildTree() {
	node* root = NULL;
	int data;
	cin >> data;

	if (data == -1) return root;
	root = new node(data);

	root->left = buildTree();
	root->right = buildTree();
	return root;
}

class Pair {
public:
	int min;
	int max;
};

class Ans {
public:
	int x, y;
};

Ans ans;

Pair solve(node* root) {
	// base case
	if (!root) return {INT_MAX, INT_MIN};
	// recursive case
	Pair left = solve(root->left);
	Pair right = solve(root->right);
	if (left.max > right.min) {
		ans.x = left.max;
		ans.y = right.min;
	}
	else if (root->data < left.max) {
		ans.x = root->data;
		ans.y = left.max;
	}
	else if (root->data > right.min) {
		ans.x = root->data;
		ans.y = right.min;
	}

	Pair temp;
	temp.min = min(left.min, min(right.min, root->data));
	temp.max = max(left.max, max(right.max, root->data));
	return temp;
}


int main() {

	node* root = buildTree();

	solve(root);

	if (ans.x > ans.y) swap(ans.x, ans.y);
	cout << ans.x << " " << ans.y << endl;


	return 0;
}
















