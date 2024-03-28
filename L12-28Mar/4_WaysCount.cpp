#include <iostream>
using namespace std;

int ways(int i, int j) {
	// base case
	if (i == 0 and j == 0) return 1;
	if (i < 0 || j < 0) return 0;

	// recursive case
	return ways(i - 1, j) + ways(i, j - 1);
}

int main() {

	cout << ways(3, 3) << endl;


	return 0;
}
















