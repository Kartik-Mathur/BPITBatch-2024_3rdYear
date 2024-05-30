#include <iostream>
#include <functional>
#include <queue>
using namespace std;

class compare {
public:
	// functor
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {

	// Min heap
	// priority_queue < int, vector<int>, greater<int> > q;
	// Max heap
	// priority_queue <int> q;
	// priority_queue < int, vector<int>, less<int> > q;
	// SYNTAX: priority_queue<dataType,vector<dataType>, class> queue_NAME;
	priority_queue<int, vector<int>, compare> q;

	q.push(1);
	q.push(3);
	q.push(2);
	q.push(5);
	q.push(4);

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}





	return 0;
}
















