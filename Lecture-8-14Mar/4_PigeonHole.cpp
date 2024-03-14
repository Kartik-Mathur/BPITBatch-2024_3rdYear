#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);
	int csum[1000];


	csum[0] = a[0];
	// 1. Find Cumulative Sum
	for (int i = 1; i < n; ++i)
	{
		csum[i] = csum[i - 1] + a[i];
	}

	// 2. Taking mod with n
	for (int i = 0; i < n; ++i)
	{
		csum[i] %= n;
	}

	// 3. Lets count the remainders
	int freq[1000] = {0};
	freq[0] = 1;// Because of the empty subarray

	for (int i = 0; i < n; ++i)
	{
		int val = csum[i];
		freq[val]++;
	}

	// 4. Lets find the answer
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (freq[i] * (freq[i] - 1)) / 2;
	}
	cout << ans << endl;






	return 0;
}
















