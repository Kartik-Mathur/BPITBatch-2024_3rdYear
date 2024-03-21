#include <iostream>
using namespace std;

int stringToInt(string &s, int n) {
	// base case
	if (n == 0) return 0;

	// recursive case
	int x = s[n - 1] - '0';
	return stringToInt(s, n - 1) * 10 + x;
}

int main() {

	string s = "1234";

	int x = stringToInt(s, s.size());
	cout << x << endl;
	cout << x + 40 << endl;
	return 0;
}
















