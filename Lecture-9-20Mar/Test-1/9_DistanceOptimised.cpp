#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int n, k;

int solve() {
	int s = 0, e = a[n - 1] - a[0];

	while (s <= e) {
		int mid = (s + e) / 2;
		// Ab lets find the total pairs that have difference <= mid
		int i = 0, j = i + 1;
		while (j < n) {

		}
	}
}

int main() {


	cin >> n >> k;


	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	cout << solve() << endl;




	return 0;
}
















