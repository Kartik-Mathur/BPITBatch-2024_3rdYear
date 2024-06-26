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

void printLL(node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL\n";
}

void breakCycle(node*head, node* f) {
	node* temp = head;
	while (temp->next != f) temp = temp->next;

	// Head se lekar cycle start wala distance = x
	// f se lekar cycle start wala distance = y
	// x == y, therefore we can do the steps as mentioned below
	node*s = head;
	while (s != f) {
		temp = f;
		f = f->next;
		s = s->next;
	}
	// now break the cycle when s and f meet each other
	temp->next = NULL;
}

bool isCycle(node* head) {
	node* s = head, *f = head;
	while (f and f->next) {
		f = f->next->next;
		s = s->next;
		if (f == s) {
			// Once the fast and slow meet, then we can start the algo
			// to break the cycle
			breakCycle(head, f);
			return true;
		}
	}
	return false;
}

int main() {
	node* head, *tail;
	head = tail = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 5);
	insertAtEnd(head, tail, 6);
	insertAtEnd(head, tail, 7);
	insertAtEnd(head, tail, 8);
	insertAtEnd(head, tail, 9);
	insertAtEnd(head, tail, 10);
	insertAtEnd(head, tail, 11);
	insertAtEnd(head, tail, 12);

	tail->next = head->next->next->next->next;
	if (isCycle(head)) {
		cout << "Cycle hai\n";
	}
	else {
		cout << "Cycle nahi hai\n";
	}

	printLL(head);


	return 0;
}
















