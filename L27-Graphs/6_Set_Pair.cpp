#include <iostream>
#include <set>
using namespace std;

int main() {

	set < pair<int, string> > s;

	s.insert({1, "H"});
	s.insert({3, "Wor"});
	s.insert({2, "BA"});
	s.insert({4, "Code"});

	// Set mei updation isn't possible
	// delete karke dobara new data daal do
	auto x = s.find({2, "BA"});
	if (x != s.end()) {
		s.erase(x);
	}
	s.insert({2, "Hi"});

	for (auto p : s) {
		cout << p.first << ", " << p.second << endl;
	}



	return 0;
}
















