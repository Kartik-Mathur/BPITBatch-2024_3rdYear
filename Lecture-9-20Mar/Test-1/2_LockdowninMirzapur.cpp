#include <iostream>
using namespace std;
#define ll long long

ll fact(int n) {
	ll ans = 1;
	for (ll i = 1; i <= n; ++i)
	{
		ans *= i;
	}
	return ans;
}


int main() {

	ll t;
	cin >> t;
	while (t--) {
		ll n, r;
		cin >> n >> r;

		ll fact_n = fact(n);
		ll fact_r = fact(r);
		ll fact_nr = fact(n - r);

		cout << fact_n / (fact_r * fact_nr) << endl;
	}

	return 0;
}
















