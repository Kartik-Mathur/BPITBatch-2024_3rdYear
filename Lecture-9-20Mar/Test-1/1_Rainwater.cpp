#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int leftMax[n], rightMax[n];

	int mx = 0;

	for (int i = 0; i < n; ++i)
	{
		leftMax[i] = mx;
		mx = max(mx, a[i]);
	}

	mx = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		rightMax[i] = mx;
		mx = max(mx, a[i]);
	}


	// Calculate the accumulated water
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if ( min(leftMax[i], rightMax[i]) - a[i] > 0)
			ans += min(leftMax[i], rightMax[i]) - a[i];
	}

	cout << ans << endl;

	return 0;
}
















