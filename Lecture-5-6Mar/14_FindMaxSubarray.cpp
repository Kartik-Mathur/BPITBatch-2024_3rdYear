#include <iostream>
using namespace std;

int main() {

	int a[] = { 1, 2, -2, 4, 5};
	int n = sizeof(a) / sizeof(int);
	int sum = 0;
	int max_i, max_j;
	int max_sum = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			sum = 0;
			for (int k = i; k <= j; ++k)
			{
				// cout << a[k] << " ";
				sum += a[k]; // [i,j] tak wale subarray ka sum kar dega
			}
			// cout << ", Sum: " << sum << endl;
			if (sum > max_sum) {
				max_sum = sum;
				max_i = i;
				max_j = j;
			}
			// cout << endl;
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
















