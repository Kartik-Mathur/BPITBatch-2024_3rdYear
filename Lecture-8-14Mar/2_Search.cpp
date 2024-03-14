#include <iostream>
using namespace std;

void printArray(int a[][100], int n, int m) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void assignValue(int a[][100], int n, int m) {
	int no = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = no++;
		}
	}
}

void searchKey(int a[][100], int n, int m, int key) {
	int i, j;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (a[i][j] == key) {
				cout << "Key Found at: " << i << "," << j << endl;
				break;
			}
		}

		if (j < m) {
			break;
		}
	}

	// Agar loop se bahar aa gaye
	if (i == n) {
		cout << "Key Not Found\n";
	}
}

int main() {

	// 1. 2d Array create karo
	int a[100][100];

	// 2. 2d array ka input lo
	int m, n;
	cin >> n >> m;
	assignValue(a, n, m);

	// 3. Print the 2d array
	printArray(a, n, m);

	// 4. Searching Algorithm
	int key;
	cout << "Enter Key: ";
	cin >> key;
	searchKey(a, n, m, key);

	return 0;
}
















