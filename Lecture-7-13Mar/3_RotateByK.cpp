#include <iostream>
#include <cstring>
using namespace std;

void rotate(char a[], int k) {
	cout << "Initial String: " << a << endl;
	// 1. Shift all buckets by k value ahead of their indexes
	int len = strlen(a);
	k %= len;
	int i = len - 1;
	while (i >= 0) {
		a[i + k] = a[i];
		i--;
	}
	cout << "After Shift : " << a << endl;
	// last ke K characters utha kar shuru mei lekar aao
	i = 0;
	int j = len;
	while (i < k) {
		a[i] = a[j];
		i++;
		j++;
	}

	cout << "After K char :" << a << endl;

	a[len] =  '\0';
	cout << "Final result: " << a << endl;
}

int main() {

	char a[] = "Coding";

	rotate(a, 5000);

	return 0;
}
















