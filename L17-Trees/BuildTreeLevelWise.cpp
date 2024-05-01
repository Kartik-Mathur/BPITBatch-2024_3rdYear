#include <iostream>
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


node* buildTreeLevelWise() {
	node* root = NULL;
	cout << "Enter data for root: ";
	int data;
	cin >> data;
	if (data == -1) return root;

	queue<node*> q;
	root = new node(data);
	q.push(root);

	while (!q.empty()) {
		node* x = q.front();
		q.pop();

		cout << "Enter children of " << x->data << " : ";
		int l, r; cin >> l >> r;

		if (l != -1) {
			x->left = new node(l);
			q.push(x->left);
		}
		if (r != -1) {
			x->right = new node(r);
			q.push(x->right);
		}
	}

	return root;
}

void printLevelOrder(node* root) {
	queue<node*> q;
	if (!root) return;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* x = q.front();
		q.pop();
		if (x) {
			cout << x->data << " ";
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}
		else {
			cout << endl;
			if (!q.empty()) q.push(NULL);
		}
	}
}


void preOrder(node* root) {
	// base case
	if (!root) return;

	cout << root->data << ", ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	// base case
	if (!root) return;

	inOrder(root->left);
	cout << root->data << ", ";
	inOrder(root->right);
}

void postOrder(node* root) {
	// base case
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << ",";
}

void printAllOrder(node*root) {
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	printLevelOrder(root);
}

node* createTree(int *inorder, int s, int e, int *preorder, int &i) {
	// base case
	if (s > e) return NULL;

	// recursive case
	int d = preorder[i++];

	node* root = new node(d);
	int k = -1;
	for (int j = s; j <= e; ++j)
	{
		if (inorder[j] == d) {
			k = j;
			break;
		}
	}

	root->left = createTree(inorder, s, k - 1, preorder, i);
	root->right = createTree(inorder, k + 1, e, preorder, i);
	return root;
}


void printSubtreeNodesK(node* root, int d, int k, vector<int> &ans) {
	// if root is not present go back you couldn't find anything
	if (!root) return;

	// If current node is at d == k, then this node is the answer
	if (d == k) {
		ans.push_back(root->data);
		return;
	}

	printSubtreeNodesK(root->left, d + 1, k, ans);
	printSubtreeNodesK(root->right, d + 1, k, ans);
}


// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main() {
	int inorder[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
	int preorder[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
	int n = sizeof(inorder) / sizeof(int);
	int i = 0;
	node* root = createTree(inorder, 0, n - 1, preorder, i);
	// node* root = buildTreeLevelWise();

	// printAllOrder(root);

	vector<int> ans;
	printSubtreeNodesK(root, 0, 2, ans);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;




	return 0;
}
















