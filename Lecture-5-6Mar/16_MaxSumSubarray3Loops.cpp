#include <iostream>
using namespace std;

int main() {

	int a[] = { 1, 2, -2, 4, 5};
	int n = sizeof(a) / sizeof(int);
	int sum = 0;
	int max_i, max_j;
	int max_sum = INT_MIN;

	// Calculate Prefix Sum array
	int ps[100000];
	ps[0] = a[0];

	for (int i = 1; i < n; ++i)
	{
		ps[i] = a[i] + ps[i - 1];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (i - 1 >= 0) {
				sum = ps[j] - ps[i - 1];
			}
			else {
				sum = ps[j];
			}

			if (sum > max_sum) {
				max_sum = sum;
				max_i = i;
				max_j = j;
			}
		}
	}



	// Print the max sum subarray
	for (int i = max_i; i <= max_j; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "MAX SUM: " << max_sum << endl;


	return 0;
}
















