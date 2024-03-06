#include <iostream>
using namespace std;

int main() {

	// Array initialisation
	// int a[5] = {1, 2, 3, 4, 5};
	// We can skip the size part only while initialisation
	int a[] = {1, 2, 3, 4, 5}; // If you initialise even a single bucket
	// all the remaining buckets will get initialised with 0
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















