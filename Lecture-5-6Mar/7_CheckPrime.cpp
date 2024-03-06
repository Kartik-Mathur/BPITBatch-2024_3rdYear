#include <iostream>
using namespace std;

bool checkPrime(int n) {
	int i;

	for (i = 2; i <= n - 1; ++i)
	{
		if (n % i == 0) {
			break;
		}
	}

	if (i == n) {
		return true;
	}
	else {
		return false;
	}
}


bool checkPrime1(int n) {
	int i;

	for (i = 2; i <= n - 1; ++i)
	{
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}


int main() {

	int n, i;
	cin >> n;

	bool ans = checkPrime(n);
	if (ans == true) {
		cout << "Prime hai\n";
	}
	else {
		cout << "Prime Nahi hai\n";
	}



	return 0;
}
















