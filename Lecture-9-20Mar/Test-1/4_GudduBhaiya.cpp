#include <iostream>
#include <cstring>
using namespace std;

void rotateArr(char* a, int k) {
	// 1. Shift all buckets by k value ahead of their indexes
	int len = strlen(a);
	k %= len;
	int i = len - 1;
	while (i >= 0) {
		a[i + k] = a[i];
		i--;
	}

	// last ke K characters utha kar shuru mei lekar aao
	i = 0;
	int j = len;
	while (i < k) {
		a[i] = a[j];
		i++;
		j++;
	}

	a[len] =  '\0';
}

int main() {

	char a[10000];
	cin >> a;

	int n;
	cin >> n;
	while (n--) {
		int i, j, k;
		cin >> i >> j >> k;
		// To find the indexes from positions reduce i and j
		i--;
		j--;

		// Copy karo [i,j] tak ki range ko in b[]
		char b[10000];
		int l = 0;
		for (int m = i; m <= j ; ++m)
		{
			b[l++] = a[m];
		}
		b[l] = '\0';

		rotateArr(b, k);
		l = 0;
		for (int m = i; m <= j ; ++m)
		{
			a[m] = b[l++];
		}
	}

	cout << a << endl;


	return 0;
}
















