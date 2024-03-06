#include <iostream>
using namespace std;

int main() {

	int a[] = {3, 5, 4, 2, 1};
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i <= n - 2; ++i)
	{
		int min = i;
		for (int j = i + 1; j <= n - 1; ++j)
		{
			if (a[j] < a[min]) {
				min = j;
			}
		}

		swap(a[min], a[i]);
	}

	// Print karke dekhlo kya array sort ho gaya
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















