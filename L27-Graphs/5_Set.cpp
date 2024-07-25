#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);

	for (auto v : s) {
		cout << v << " ";
	}
	cout << endl;
	// while (!s.empty()) {
	// 	cout << *s.begin() << " ";
	// 	s.erase(s.begin());
	// }

	// Deleting 2 in set
	auto f = s.find(2);
	if (f != s.end()) {
		s.erase(f);
	}

	for (auto v : s) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}
















