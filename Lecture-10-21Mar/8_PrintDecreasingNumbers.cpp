#include <iostream>
using namespace std;

void printNumbers(int n) {
	// base case
	if (n == 0) return;
	// recursive case
	cout << n << " ";
	printNumbers(n - 1);
}

void printNumbers1(int n) {
	// base case
	if (n == 0) return;
	// recursive case
	printNumbers1(n - 1);
	cout << n << " ";
}

int main() {

	int n = 5;
	printNumbers(n);

	cout << endl;
	printNumbers1(n);

	cout << endl;
	return 0;
}
















