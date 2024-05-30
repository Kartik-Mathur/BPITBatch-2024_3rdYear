#include <iostream>
#include <vector>
#include <unordered_map>
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

node* createTree() {
	node* root = NULL;
	int data;
	cin >> data;
	if (data == -1) return root;

	root = new node(data);
	// create LST
	root->left = createTree();

	// create RST
	root->right = createTree();

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

class Pair {
public:
	int data;
	int level;
};

void treeTopView(node* root, unordered_map<int, Pair> &h, int &minD, int &maxD,
                 int d = 0, int level = 0) {
	// base case
	if (!root) return;

	// recursive case
	if ( (h.count(d) == 1 and level < h[d].level) || h.count(d) == 0) {
		h[d] = {root->data, level};
	}

	minD = min(minD, d);
	maxD = max(maxD, d);

	treeTopView(root->left, h, minD, maxD, d - 1, level + 1);
	treeTopView(root->right, h, minD, maxD, d + 1, level + 1);
}

class myPair {
public:
	vector<int> data;
	int level;
};

void topViewFinal(node* root, unordered_map<int, myPair> &h, int &minD, int &maxD,
                  int d = 0, int level = 0) {
	// base case
	if (!root) return;

	// recursive case
	if ( (h.count(d) == 1 and level < h[d].level) || h.count(d) == 0) {
		h[d] = { {root->data}, level};
	}
	else if (h.count(d) == 1 and level == h[d].level) {
		h[d].data.push_back(root->data);
	}

	minD = min(minD, d);
	maxD = max(maxD, d);

	topViewFinal(root->left, h, minD, maxD, d - 1, level + 1);
	topViewFinal(root->right, h, minD, maxD, d + 1, level + 1);
}

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {

	node* root = createTree();

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	// unordered_map<int, Pair> h;
	// int minD = INT_MAX, maxD = INT_MIN;
	// treeTopView(root, h, minD, maxD);

	unordered_map<int, myPair> h;
	int minD = INT_MAX, maxD = INT_MIN;
	topViewFinal(root, h, minD, maxD);

	for (int i = minD; i <= maxD; ++i)
	{
		// cout << h[i].data << " ";
		for (int j = 0 ; j < h[i].data.size() ; j++) {
			cout << h[i].data[j] << " ";
		}
	}
	cout << endl;


	return 0;
}
















