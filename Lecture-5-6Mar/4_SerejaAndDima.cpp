// https://codeforces.com/problemset/problem/381/A
#include <iostream>
using namespace std;

int main() {

	int a[1001];
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int turn = 1;

	int sereja = 0, dima = 0;

	int i = 0, j = n - 1;
	while (i <= j) {
		if ( (turn % 2) == 1) {
			// sereja pick krega
			sereja += (  (a[i] > a[j])  ?   a[i++]   :   a[j--]    );
			turn ++;
		}
		else {
			// dima pick krega
			dima += (  (a[i] > a[j])  ?  a[i++]   :   a[j--]   );
			turn ++;
		}
	}

	/*
	while (i <= j) {
		if ( (turn % 2) == 1) {
			// sereja pick krega
			if (a[i] > a[j]) {
				sereja += a[i];
				i++;
			}
			else {
				sereja += a[j];
				j--;
			}
			turn ++;
		}
		else {
			// dima pick krega
			if (a[i] > a[j]) {
				dima += a[i];
				i++;
			}
			else {
				dima += a[j];
				j--;
			}
			turn ++;
		}
	}
	*/

	cout << sereja << " " << dima << endl;
	return 0;
}
















