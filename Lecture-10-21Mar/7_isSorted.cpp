#include <iostream>
using namespace std;

bool isSorted(int* a, int n) {
	// base case
	if (n <= 1) return true;
	// recursive case
	bool kyaChotaSortedHai = isSorted(a + 1, n - 1); // Pure Assumption
	if (kyaChotaSortedHai == true and a[0] <= a[1]) return true;
	return false;
}

bool isSorted2(int *a, int n) {
	// base case
	if (n <= 1) return true;
	// recursive case
	bool kyaChotaSortedHai = isSorted2(a, n - 1);
	if (kyaChotaSortedHai == true and a[n - 1] >= a[n - 2]) return true;
	else return false;
}

bool isSorted3(int*a, int i, int n) {
	// base case
	if (i == n - 1) return true;
	// recursive case
	if (isSorted3(a, i + 1, n) == true and a[i] <= a[i + 1]) return true;

	return false;
}

int main() {

	int a[] = {1, 2, 3, 4, 5, 10};
	int n = sizeof(a) / sizeof(int);

	cout << boolalpha << isSorted3(a, 0, n) << endl;

	return 0;
}
















