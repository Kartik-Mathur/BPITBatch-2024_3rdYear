#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int lsf = INT_MIN; // to track the "largest so far"
	int ssf = INT_MAX; // to track the "smallest so far"

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		if (x > lsf) {
			lsf = x;
		}

		if (x < ssf) {
			ssf = x;
		}

	}

	cout << lsf << endl;
	cout << ssf << endl;

	return 0;
}