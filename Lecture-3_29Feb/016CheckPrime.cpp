#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int i = 2;

	for (; i <= n - 1; i++) {

		if (n % i == 0) {

			// you've found a factor 'n' in [2, n-1]

			cout << "not prime" << endl;
			break;

		}

	}

	if (i == n) {

		cout << "prime" << endl;

	}

	return 0;
}