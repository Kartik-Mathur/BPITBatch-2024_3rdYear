#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

int main() {

	map<string, int> h;

	// Insertion
	// 1st way
	pair<string, int> p;
	p.first = "Mango";
	p.second = 100;
	h.insert(p);

	// 2nd way
	h.insert({"Kiwi", 50});

	// 3rd way
	h.insert(make_pair("Pineapple", 70));

	// 4th way
	h["Guava"] = 150;

	// Update
	h["Mango"] = 120;

	// Print
	for (pair<string, int> p : h) {
		cout << p.first << " : " << p.second << endl;
	}


	// Key is present or not?
	// h.count("Mango") will return either 0 or 1
	if (h.count("Mango") == 0) {
		// Mango is not present
		cout << "Mango present nahi hai\n";
	}
	else if (h.count("Mango") == 1) {
		// Mango is present
		cout << "Mango present hai\n";
	}


	unordered_map<string, vector<long long> > x;
	x["Satwik"].push_back(9999999999);
	x["Satwik"].push_back(8888888888);
	x["Karan"].push_back(7777777777);

	for (auto p : x) {
		cout << p.first << "->";
		for (auto n : p.second) {
			cout << n << ", ";
		}
		cout << endl;
	}





	return 0;
}
















