#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int top) {
	if (s.empty()) {
		s.push(top);
		return;
	}

	int t = s.top();
	s.pop();
	insertAtBottom(s, top);
	s.push(t);
}

void reverseStack(stack<int> &s) {
	// base case
	if (s.empty()) return;

	// recursive case
	int top = s.top();
	s.pop();
	// recursion se bolo choteStack ko reverse krde
	reverseStack(s);

	// top ko stack ke end mei insert krna padega
	insertAtBottom(s, top);
}

void printStack(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	printStack(s);
	reverseStack(s);

	// Print the stack after reversal
	printStack(s);



	return 0;
}
















