#include<iostream>

using namespace std;

int main() {

	int n = 15;
	int m = 3;

	int res = n ^ m;

	int cnt = 0;

	while (res > 0) {

		cnt++;
		res = res & (res - 1); // clear the rightmost bit of 'res'

	}

	cout << cnt << endl; // hamming dist.

	return 0;
}