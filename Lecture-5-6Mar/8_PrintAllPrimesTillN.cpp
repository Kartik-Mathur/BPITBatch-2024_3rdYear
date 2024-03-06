#include <iostream>
using namespace std;

bool checkPrime(int n) {
	int i;

	for (i = 2; i <= n - 1; ++i)
	{
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void printAllPrimes(int n) {
	for (int i = 2; i <= n; ++i)
	{
		if (checkPrime(i) == true) {
			cout << i << " ";
		}
	}
	cout << endl;
}

int main() {

	int n = 20;

	printAllPrimes(n);

	return 0;
}
















