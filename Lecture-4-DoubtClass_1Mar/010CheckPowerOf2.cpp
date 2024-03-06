#include<iostream>

using namespace std;

int main() {

	int n = 18;

	int res  = n & (n - 1);

	if (res == 0) {

		// n has only 1 bit set therefore it is a power of 2
		cout << n << " power of 2" << endl;

	} else {

		cout << n << " not a power of 2" << endl;

	}

	return 0;
}