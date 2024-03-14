#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

bool kyaCowsPlaceHoPaai(ll*a, ll n, ll mid , ll cows) {
	// Check karo kya mid distance atleast har do cows ke beech mei ho skta h?
	ll cows_placed = 1;
	ll pd = a[0];

	for (int i = 1; i < n; ++i)
	{
		if (a[i] - pd >= mid) {
			cows_placed++;
			pd = a[i];
		}

		if (cows_placed == cows) return true;
	}

	return false;
}

ll aggresiveCows(ll*a, ll n, ll cows) {
	ll s = 0, e = 10e9; // 10^9 is from problem constraints
	// because the maximum location of a stall can be 10^9
	ll ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;

		if (kyaCowsPlaceHoPaai(a, n, mid, cows)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		ll n, cows;
		ll a[100005];

		cin >> n >> cows;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		cout << aggresiveCows(a, n, cows) << endl;
	}


	return 0;
}
















