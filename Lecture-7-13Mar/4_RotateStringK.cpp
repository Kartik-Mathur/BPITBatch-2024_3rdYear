#include <iostream>
using namespace std;

void reverseString(char a[], int i, int j) {
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

int main() {
	char a[] = "Coding";
	int len = strlen(a);
	int k = 5000;
	k %= len;

	reverseString(a, len - k, len - 1);
	reverseString(a, 0, len - k - 1);
	reverseString(a, 0, len - 1);

	cout << a << endl;



	return 0;
}
















