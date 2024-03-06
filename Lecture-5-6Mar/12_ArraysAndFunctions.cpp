#include <iostream>
using namespace std;

void insertionSort(int a[5], int n) {
	int j;

	for (int i = 1; i < n; ++i)
	{
		int hpc = a[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (hpc < a[j]) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}

		a[j + 1] = hpc;
	}
}

void print(int a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[5] = {5, 4, 1, 2, 3};
	int n = sizeof(a) / sizeof(int);

	int b[] = {4, 5, 67, 2, 1, 323133, 13, 53};
	int m = sizeof(b) / sizeof(int);

	// Arrays are always passed by reference
	insertionSort(a, n);
	print(a, n);

	insertionSort(b, m);
	print(b, m);

	return 0;
}

















