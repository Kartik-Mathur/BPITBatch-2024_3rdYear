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

int lengthLL(node* head) {
	int ans = 0;
	while (head != NULL) head = head->next, ans++;

	return ans;
}

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
		t->next = n;
		t = n;
	}
}

void insertAtMiddle(node* &head, node* &tail, int d, int pos) {
	if (pos == 0) {
		insertAtFront(head, tail, d);
	}
	else if (pos >= lengthLL(head)) {
		insertAtEnd(head, tail, d);
	}
	else {
		node* temp = head;
		for (int i = 0; i < pos - 1; ++i)
		{
			temp = temp->next;
		}

		node* n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

// DELETION CODE IN LINKED LIST /////////////////////////////////////////////
void deleteAtFront(node* &head, node* &tail) {
	if (head == NULL) return;
	if (head->next == NULL) {
		delete head;
		head = tail = NULL;
	}
	else {
		node* temp = head;
		head = head->next;
		delete temp;
	}
}

void deleteAtEnd(node* &head, node* &tail) {
	if (head == NULL) return;
	if (head->next == NULL) {
		delete head;
		head = tail = NULL;
	}
	else {
		node* temp = head;
		while (temp->next != tail) temp = temp->next;
		delete tail;
		tail = temp;
		tail->next = NULL;
	}
}


void deleteAtMiddle(node* &head, node*&tail, int pos) {
	if (pos == 0) {
		deleteAtFront(head, tail);
	}
	else if (pos >= lengthLL(head) - 1) {
		deleteAtEnd(head, tail);
	}
	else {
		node* temp = head;
		for (int i = 0; i < pos - 1; ++i)
		{
			temp = temp->next;
		}
		node* n = temp->next;
		temp->next = n->next;
		delete n;
	}
}
// DELETION CODE IN LINKED LIST /////////////////////////////////////////////

// REVERSE LL
void reverseLL(node* &head, node* &tail) {
	node* c, *p, *n;
	c = head;
	p = NULL;
	while (c != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	swap(head, tail);
}
// REVERSE LL

// REVERSE LL - Recursion
void reverseLLRecHelper(node* c, node* p = NULL) {
	if (c == NULL) return;
	node* n = c ->next;
	c->next = p;
	reverseLLRecHelper(n, c);
}

void reverseLLRec(node* &head, node* &tail) {
	reverseLLRecHelper(head);
	swap(head, tail);
}
// REVERSE LL - Recursion

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
	insertAtMiddle(head, tail, 8, 3);
	printLL(head);
	deleteAtEnd(head, tail);
	deleteAtFront(head, tail);
	printLL(head);
	reverseLLRec(head, tail);
	printLL(head);


	// cout << "Length " << lengthLL(head) << endl;


	return 0;
}
















