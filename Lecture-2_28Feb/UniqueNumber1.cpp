#include <iostream>
using namespace std;

int main() {

	int n;
	cout << "N: ";
	cin >> n;
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		ans = ans ^ x;
	}

	cout << "Unique Number: " << ans << endl;

	return 0;
}
















