#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for (int i = 1; i <= n; i++) {

		// for the ith row, i nos

		int num = i % 2 == 0 ? 0 : 1;

		for (int j = 1; j <= i; j++) {

			cout << num << " ";
			num = 1 - num; // toggle no.

		}

		cout << endl;

	}

	return 0;
}