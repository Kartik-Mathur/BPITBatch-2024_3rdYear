#include<iostream>

using namespace std;

int main() {

	int a = 2;
	int n = 7;

	// // time : O(n)

	// int ans = 1;

	// for (int i = 1; i <= n; i++) {

	// 	ans = ans * a; // const op.

	// }

	// cout << ans << endl;

	// time : O(logn)

	int res = 1;

	int wgt = a;

	while (n > 0) {

		int rightmostbit = n & 1;
		if (rightmostbit == 1) {
			res = res * wgt;
		}
		wgt = wgt * wgt;
		n = n >> 1;

	}

	cout << res << endl;

	return 0;
}