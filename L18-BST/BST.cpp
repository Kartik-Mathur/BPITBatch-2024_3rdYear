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

node* insertInBST(node* root, int data) {
	if (!root) {
		root = new node(data);
		return root;
	}

	if (data > root->data) {
		// root ke RST par data insert krke merko root node return krde RST ki
		root->right = insertInBST(root->right, data);
	}
	else {
		root->left = insertInBST(root->left, data);
	}

	return root;
}

node* createBST() {
	node* root = NULL;

	int data;
	cin >> data;
	while (data != -1) {
		root = insertInBST(root, data);
		cin >> data;
	}
	return root;
}


void preOrder(node* root) {
	// base case
	if (!root) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	// base case
	if (!root) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node* root) {
	// base case
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
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


void printAllOrder(node*root) {
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	printLevelOrder(root);
}

void printRange(node* root, int k1, int k2) {
	if (!root) return;

	printRange(root->left, k1, k2);
	if (root->data >= k1 and root->data <= k2) cout << root->data << " ";
	printRange(root->right, k1, k2);
}

node* searchKey(node* root, int key) {
	// base case
	if (!root) return NULL;
	// recursive case
	// root par key hai toh root ko return krdo
	if (root->data == key) return root;
	// left par key ko search karo, agar mill gai toh answer return krdo
	node* ans = searchKey(root->left, key);
	if (ans) return ans;
	// agar left par key nahi hai toh right par search karo,
	// if right se answer aa gaya toh answer return krdo
	// if right se answer nahi aaya toh key hi nhi exist krti
	return searchKey(root->right, key);
}

bool isBST(node* root, int mi = INT_MIN, int mx = INT_MAX) {
	if (!root) return true;
	bool isLeftBST = isBST(root->left, mi, root->data);
	bool isRightBST = isBST(root->right, root->data, mx);
	if (root->data >= mi and root->data <= mx and isLeftBST and isRightBST) {
		return true;
	}
	return false;
}

int height(node* root) {
	if (!root) return 0;

	return max(height(root->left), height(root->right)) + 1;
}

bool isBalancedBST(node* root) {

	if (!root) return true;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (abs(leftHeight - rightHeight) <= 1 and isBalancedBST(root->left) and
	        isBalancedBST(root->right)) return true;

	return false;
}


class Pair {
public:
	bool isBalanced;
	int height;
};

Pair isBalancedFast(node* root) {
	if (!root) return {true, 0};

	Pair left = isBalancedFast(root->left);
	Pair right = isBalancedFast(root->right);

	Pair p;
	p.isBalanced = (abs(left.height - right.height) <= 1 and left.isBalanced
	                and right.isBalanced) ? true : false;
	p.height = max(left.height, right.height) + 1;
	return p;
}


node* arrayToBST(int *a, int s, int e) {
	if (s > e) return NULL;

	int m = (s + e) / 2;

	node* root = new node(a[m]);
	root->left = arrayToBST(a, s, m - 1);
	root->right = arrayToBST(a, m + 1, e);
	return root;
}


int main() {

	// node* root = createBST();
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(a) / sizeof(int);

	node* root = arrayToBST(a, 0, n - 1);

	printAllOrder(root);
	printRange(root, 4, 10);
	cout << endl;

	node*ans = searchKey(root, 100);
	if (ans) cout << "Key found " << ans->data << " ";
	else cout << "Key not found\n";

	if (isBST(root)) cout << "BST hai\n";
	else cout << "BST nahi hai\n";

	Pair x = isBalancedFast(root);
	if (x.isBalanced) cout << "Balanced BST hai\n";
	else cout << "Balanced BST nahi hai\n";
	return 0;
}
















