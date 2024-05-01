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

bool findPath(node*root, int key, vector<int> &ans) {
	// base
	if (!root) return false;

	if (root->data == key) {
		ans.push_back(root->data);
		return true;
	}

	// Abhi assume krlo current node path mei aati hai
	ans.push_back(root->data);
	// left se pucho kya leftSubtree mei key milli

	bool kyaLeftSePathMilla = findPath(root->left, key, ans);
	// if true aaya toh path mill chuka hai, left tak ka
	if (kyaLeftSePathMilla) return true;

	// right se pucho kya RST mei key milli
	bool kyaRightSePathMilla = findPath(root->right, key, ans);
	// if true aaya toh path mill chuka hai, left tak ka
	if (kyaRightSePathMilla) return true;

	ans.pop_back();
	return false;
}


// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main() {
	int inorder[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
	int preorder[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
	int n = sizeof(inorder) / sizeof(int);
	int i = 0;
	node* root = createTree(inorder, 0, n - 1, preorder, i);

	// printAllOrder(root);

	vector<int> pathA;
	findPath(root, 13, pathA);

	vector<int> pathB;
	findPath(root, 10, pathB);


	for (int i = 0; i < pathA.size(); ++i)
	{
		cout << pathA[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < pathB.size(); ++i)
	{
		cout << pathB[i] << " ";
	}
	cout << endl;

	return 0;
}
















