#include <iostream>
using namespace std;

void solve(int open, int close, char *a, int i, int n) {
	if (i == 2 * n) {
		a[i] = '\0';
		cout << a << endl;
		return;
	}

	if (open < n) {
		a[i] = '(';
		solve(open + 1, close, a, i + 1, n);
	}
	if (open > close) {
		a[i] = ')';
		solve(open, close + 1, a, i + 1, n);
	}
}


int main() {

	int n = 3;

	char a[100];
	solve(0, 0, a, 0, n);

	return 0;
}
















