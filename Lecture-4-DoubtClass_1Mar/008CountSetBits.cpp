#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 7;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) { // logn
		int rightmost_bit = n & 1;
		if (rightmost_bit == 1) {
			cnt++;
		}
		n = n >> 1;
	}

	cout << cnt << endl;

	return 0;
}