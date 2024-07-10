#include <iostream>
using namespace std;
#define ll long long
ll n, a[100005], k, sum = 0, ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> k;

	for (ll i = 0, j = 0; j < n; j++) {
		sum += a[j];
		while (sum * (j - i + 1) >= k) {
			sum -= a[i++];
		}

		ans += (j - i + 1);
	}
	cout << ans << endl;


	return 0;
}
















