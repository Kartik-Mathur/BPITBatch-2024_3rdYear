#include <iostream>
#include <algorithm>
using namespace std;

bool myFun(int a, int b) {
	cout << "Comparing: " << a << ", " << b << endl;
	return a < b;
}

int main() {

	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	// Insertion(For smaller value of n) + mergeSort(for bigger value n)
	sort(a, a + n, myFun);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " " ;
	}
	cout << endl;

	return 0;
}
















