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

void bubbleSort(node* &head) {
	node* c, *p, *n;
	c = head;
	p = NULL;
	int len = lengthLL(head);
	for (int i = 0; i < len - 1; ++i)
	{
		c = head;
		p = NULL;
		while (c and c->next) {
			n = c->next;
			if (c->data > n->data) {
				// 1. swapping hogi
				if (p == NULL) {
					// 1.1 head swap
					c->next = n->next;
					n->next = c;
					head = p = n;
				}
				else {
					// 1.2 no head swap
					c->next = n->next;
					p->next = n;
					n->next = c;
					p = n;
				}
			}
			else {
				// 2. swapping nhi hogi
				p = c;
				c = n;
			}
		}
	}
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
	bubbleSort(head);
	printLL(head);




	return 0;
}

