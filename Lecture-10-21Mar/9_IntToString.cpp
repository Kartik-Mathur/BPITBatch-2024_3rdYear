#include <iostream>
using namespace std;

string keys[] = {
	"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
};

void intToString(int n) {
	// base case
	if (n == 0) return;
	// recursive case
	int ld = n % 10;
	intToString(n / 10);
	cout << keys[ld] << " ";
}

int main() {

	intToString(2048);

	return 0;
}
















