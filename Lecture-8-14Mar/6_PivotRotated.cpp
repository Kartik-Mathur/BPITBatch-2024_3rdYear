#include <iostream>
using namespace std;

int findPivot(int *a, int n) {
	int s = 0, e = n - 1;
	if (a[s] <= a[e]) return 0;

	while (s <= e) {
		int mid = (s + e) / 2;
		if ( (mid - 1) >= 0 and a[mid] < a[mid - 1]) return mid;
		else if (a[mid] >= a[n - 1] and a[s] < a[mid]) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}

int main() {

	// int a[] = {20, 24, 28, 30, 1, 6, 10};
	// int a[] = { 6, 10, 12, 15, 20, 21, 22, 25, 30, 1};
	// int a[] = {20, 21, 22, 24, 1, 1, 1, 1, 1, 2, 3, 4, 5};
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	int indx = findPivot(a, n);
	cout << indx << endl;

	return 0;
}
















