#include <iostream>
using namespace std;

// int fact(int n) {
// 	// Base case
// 	if (n == 0) return 1;

// 	// Recursive case: n*(n-1)!
// 	int chotaAns = fact(n - 1); // Pure Assumption
// 	int badaAns = n * chotaAns;
// 	return badaAns;
// }

int fact(int n) {
	// Base case
	if (n == 0) return 1;

	// Recursive case: n*(n-1)!
	return n * fact(n - 1);
}

int main() {

	int n;
	cin >> n;

	cout << fact(n) << endl;

	return 0;
}
















