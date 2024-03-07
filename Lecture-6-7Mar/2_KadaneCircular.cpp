#include <iostream>
using namespace std;

int kadanesAlgo(int a[], int n) {
	int max_sum = 0;
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		ans += a[i];
		max_sum = max(max_sum, ans);
		if (ans < 0) {
			ans = 0;
		}
	}

	return max_sum;
}

int main() {

	int a[] = { 1, 2, -100, 20, 30, -100 , 3, 4};
	int n = sizeof(a) / sizeof(int);

	int max_sum = 0, total_sum = 0;
	int ans = 0;
	bool containsNegative = false;

	for (int i = 0; i < n; ++i)
	{
		total_sum += a[i];
		if (a[i] < 0) {
			containsNegative = true;
		}
	}

	if (containsNegative == false) {
		// 1. SAB positive hai
		cout << total_sum << endl;
	}
	else {
		int op1 = kadanesAlgo(a, n);

		// Option 2 calculate
		// 1. Flip all signs
		for (int i = 0; i < n; ++i)
		{
			a[i] *= -1;
		}

		// 2. Find the maxSum of the new update array
		int x = kadanesAlgo(a, n);

		// 3. total_sum - (-x);
		int op2 = total_sum + x;
		cout << max(op1, op2) << endl;
	}



	return 0;
}
















