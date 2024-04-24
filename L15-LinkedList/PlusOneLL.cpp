#define node ListNode
class Solution {
public:

	void reverseLL(node* &head) {
		node* p = NULL;
		node* c = head;
		node* n;
		while (c) {
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		head = p;
	}

	node* plusOne(node* head) {

		reverseLL(head);
		node* t = head, *p = NULL;
		int carry = 1;
		while (t)
		{
			int sum = carry + t->val;
			t->val = sum % 10;
			carry = sum / 10;

			p = t;
			t = t->next;
		}
		if (carry) {
			p->next = new node(carry);
		}
		reverseLL(head);
		return head;
	}
};












