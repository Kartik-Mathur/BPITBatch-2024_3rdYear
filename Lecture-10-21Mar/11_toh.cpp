#include <iostream>
using namespace std;

void toh(char src, char helper, char destination, int n) {
	// base case
	if (n == 0) return;
	// recursive case
	// 1. n-1 disk ko src se helper par le jaao
	toh(src   ,  destination   ,  helper, n - 1);

	// 2. Take nth disk from src to destination
	cout << "Taking disk " << n << " from " << src << " to " << destination << endl;

	// 3. Take n-1 disk from helper to destination
	toh(helper,       src    ,  destination, n - 1);
}

int main() {

	int n;
	cin >> n;

	toh('A', 'B', 'C', n);

	return 0;
}












