#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int ans = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		int x;
		cin >> x;
		ans ^= x;
	}

	for (int i = 1; i <= n; ++i)
	{
		ans ^= i;
	}

	cout << "Missing Number: " << ans << endl;



	return 0;
}
















