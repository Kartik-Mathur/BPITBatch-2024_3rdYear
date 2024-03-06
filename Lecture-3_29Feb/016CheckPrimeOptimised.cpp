#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int i = 2;
	int rn = sqrt(n);

	for (; i <= rn; i++) {

		if (n % i == 0) {

			// you've found a factor 'n' in [2, rn]

			cout << "not prime" << endl;
			break;

		}

	}

	if (i > rn) {

		cout << "prime" << endl;


	}

	return 0;
}