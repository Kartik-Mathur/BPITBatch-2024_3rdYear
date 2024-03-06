#include<iostream>

using namespace std;

int main() {

	int n = 5;

	if ((n & 1) == 0) {
		// 0th bit of n is not set
		cout << "even" << endl;
	} else {
		// 0th bit of n is set
		cout << "odd" << endl;
	}

	return 0;
}