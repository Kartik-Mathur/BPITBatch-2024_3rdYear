#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtFront(node* &h, node* &t,
                   int d) {
	node* n = new node(d);
	if (h == NULL) {
		h = t = n;
	}
	else {
		n->next = h;
		h = n;
	}

}

void insertAtEnd(node* &h, node* &t, int d) {
	node* n = new node(d);
	if (h == NULL) {
		h = t = n;
	}
	else {
		tail->next = n;
		tail = n;
	}

}

void printLL(node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL\n";
}

int main() {

	node* head, *tail;
	head = tail = NULL;

	insertAtFront(head, tail, 1);
	insertAtFront(head, tail, 2);
	insertAtFront(head, tail, 3);
	insertAtFront(head, tail, 4);
	insertAtFront(head, tail, 5);
	printLL(head);


	return 0;
}
















