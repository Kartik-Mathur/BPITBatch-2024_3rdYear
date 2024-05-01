#include <iostream>
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

int countNodes(node* root) {
	// base case
	if (!root) return 0;
	// recursive case

	return countNodes(root->left) + countNodes(root->right) + 1;
}

int height(node* root) {
	// base case
	if (!root) return 0;

	return max(height(root->left), height(root->right)) + 1;
}

int diameter(node* root) {
	// base case
	if (!root) return 0;

	// 1. Dia via root node
	int op1 = height(root->left) + height(root->right);
	// 2. Dia in LST
	int op2 = diameter(root->left);
	// 3. Dia in RST
	int op3 = diameter(root->right);
	return max(op1, max(op2, op3));
}

class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(node* root) {
	// base case
	if (!root) return {0, 0};

	// Recursive case
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	Pair p;
	p.height = max(left.height, right.height) + 1;

	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;
	p.diameter = max(op1, max(op2, op3));

	return p;
}

node* findNode(node* root, int key) {
	// base case
	if (!root || root->data == key) return root;

	node* l = findNode(root->left, key);
	if (l) return l;

	return findNode(root->right, key);
}


// Mirror of Tree
void mirror(node* root) {
	if (!root) return;

	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
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

	cout << "Total Count : " << countNodes(root) << endl;
	cout << "Total Height: " << height(root) << endl;
	cout << "Diameter    : " << diameter(root) << endl;
	Pair p = fastDiameter(root);
	cout << "Fast dia: " << p.diameter << endl;
	cout << "Fast height: " << p.height << endl;

	cout << "Found: " << findNode(root, 14) << endl;



	return 0;
}
















