#include<iostream>

using namespace std;

int main() {

	int n = 247;

	int maxSoFar = 0;
	int cnt = 0;

	while (n > 0) {

		int rightmost_bit = n & 1;
		if (rightmost_bit == 1) {
			cnt++;
			maxSoFar = max(maxSoFar, cnt);
		} else {
			cnt = 0;
		}

		n = n >> 1;

	}

	cout << maxSoFar << endl;

	return 0;
}