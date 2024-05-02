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

class LinkedList {
public:
	node* head, *tail;
};

LinkedList bstToLL(node* root) {
	// base case
	if (!root) {
		// because root is NULL, thus head and tail -> NULL
		return {root, root};
	}

	// recursive case
	LinkedList l;
	// 1. Left and right dono nahi hai
	if (!root->left and !root->right) {
		l.head = l.tail = root;
		return l;
	}
	// 2. Left hai, right nhi hai
	else if (root->left and !root->right) {
		LinkedList left = bstToLL(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}
	// 3. right hai, left nahi hai
	else if (!root->left and root->right) {
		LinkedList right = bstToLL(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l;
	}
	// 4. left and right dono hai
	else {
		LinkedList left = bstToLL(root->left);
		LinkedList right = bstToLL(root->right);
		left.tail->right = root;
		root->right = right.head;
		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
}



int main() {

	node* root = createBST();

	printAllOrder(root);

	LinkedList l = bstToLL(root);

	node* temp = l.head;
	while (temp) {
		cout << temp->data << "-->";
		temp = temp->right;
	}
	cout << "NULL\n";

	return 0;
}
















