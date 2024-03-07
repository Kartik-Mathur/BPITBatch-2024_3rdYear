#include <iostream>
using namespace std;

int main() {

	int a[] = { -1, -2, -4, -6, 10, -2, -2, -3, -100, -5, -4};
	int n = sizeof(a) / sizeof(int);

	bool containsPositive = false;
	int mx = INT_MIN;
	// Check if all numbers are -ve
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > 0) {
			containsPositive = true;
			break;
		}
		mx = max(mx, a[i]);
	}

	if (containsPositive == false) {
		cout << mx << endl;

	}
	else {

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

		cout << "Max Sum: " << max_sum << endl;
	}

	return 0;
}
















