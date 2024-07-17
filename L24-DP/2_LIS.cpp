#include <iostream>
#include <vector>
using namespace std;
// Globally banaya hai taaki baaki functions mei bhi use kar sakte hai
vector<int> dp(100000, 1);

void printAllLIS(int *a, int indx, int len, vector<int> &x, int previousElement = INT_MAX) {
	// base case
	if (len == 0) {
		for (int i = x.size() - 1 ; i >= 0 ; i--) {
			cout << x[i] << " ";
		}
		cout << endl;
		return;
	}

	if (indx < 0) return;

	// recursive case
	if (dp[indx] == len and a[indx] < previousElement) {
		x.push_back(a[indx]);
		printAllLIS(a, indx - 1, len - 1, x, a[indx]);
		x.pop_back();
	}

	printAllLIS(a, indx - 1, len, x, previousElement);
}

void printLIS(int *a, int n) {
	int ans = 0;
	int indx = -1;
	for (int i = 0; i < n; ++i)
	{
		if (dp[i] > ans) {
			indx = i;
			ans = dp[i];
		}
	}

	// We got the index jaha tak LIS ki value is maximum
	vector<int> x;
	int previousElement = INT_MAX;
	while (ans > 0) {
		if (dp[indx] == ans and a[indx] < previousElement) {
			x.push_back(a[indx]);
			ans--;
			previousElement = a[indx];
		}

		indx--;
	}

	reverse(x.begin(), x.end());
	for (auto el : x) {
		cout << el << " ";
	}
	cout << endl;
}

int LISLen(int *a, int n) {
	int ans = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}

	return ans;
}

int main() {

	int a[] = {1, 4, 2, 3, 0, 8, 11, 10, 15};
	int n = sizeof(a) / sizeof(int);

	int ans = LISLen(a, n);
	cout << ans << endl;
	// printLIS(a, n);
	vector<int> x;
	printAllLIS(a, n - 1, ans, x);

	return 0;
}
















