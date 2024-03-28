#include <iostream>
using namespace std;

int nstairs(int n) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;
	// recursive case
	return nstairs(n - 1) + nstairs(n - 2) + nstairs(n - 3);
}

int nstairs1(int n, int k) {
	// base case
	if (n == 0) return 1;
	if (n < 0) return 0;
	// recursive case
	// return nstairs1(n - 1, k) + nstairs1(n - 2, k) + .. + nstairs1(n - k, k);
	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += nstairs1(n - i, k);
	}
	return ans;
}

int main() {

	int n = 5;

	cout << nstairs(n) << endl;
	cout << nstairs1(n, 3) << endl;


	return 0;
}
















