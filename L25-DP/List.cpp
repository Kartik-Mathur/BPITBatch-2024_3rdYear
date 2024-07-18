#include <iostream>
#include <forward_list> // singly
#include <list> // doubly
using namespace std;

int main() {

	list<int> l;
	// Insertion at end
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	// insertion at start
	l.push_front(6);
	l.push_front(7);

	// deletion
	// at front
	l.pop_front();
	// at end
	l.pop_back();

	// Insertion at middle
	list<int> :: iterator y = l.begin();
	int pos = 2;
	for (int i = 0; i < pos; ++i)
	{
		y++;
	}

	l.insert(y, 100);

	list<int> :: reverse_iterator x;
	for (x = l.rbegin(); x != l.rend(); x++) {
		cout << *x << "-->";
	}
	cout << "NULL\n";



	for (int d : l) {
		cout << d << "-->";
	}
	cout << "NULL\n";

	return 0;
}
















