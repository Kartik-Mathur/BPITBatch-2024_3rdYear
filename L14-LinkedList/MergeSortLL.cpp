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

node* mid(node* head) {
	if (head == NULL || head->next == NULL) return head;

	node* s = head;
	node* f = head->next;

	while (f != NULL and f->next != NULL) {
		f = f->next->next;
		s = s->next;
	}

	return s;
}

node* mergeSortedLL(node*a , node* b) {
	// base case
	if (a == NULL) return b;
	if (b == NULL) return a;

	// recursive case
	node* nH = NULL;
	if (a->data < b->data) {
		nH = a;
		nH->next = mergeSortedLL(a->next, b);
	}
	else {
		nH = b;
		nH->next = mergeSortedLL(a, b->next);
	}
	return nH;
}

node* mergeSort(node*head) {
	// base case
	if (!head || !head->next) return head;

	// recursive case
	// 1. Divide
	node* m = mid(head);
	node* a = head;
	node* b = m->next;
	m->next = NULL;

	// 2. Sort
	a = mergeSort(a);
	b = mergeSort(b);

	// 3. Merge
	return mergeSortedLL(a, b);
}



int main() {
	node* head, *tail, *head1, *tail1;
	head = tail = head1 = tail1 = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 12);
	insertAtEnd(head, tail, 6);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 5);
	printLL(head);
	mergeSort(head);
	printLL(head);




	return 0;
}

