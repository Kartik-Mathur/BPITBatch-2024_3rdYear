#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n / 2 + 1; ++i)
	{
		// 1. print n/2+1 -i times ' '
		for (int spaces = 1; spaces <= n / 2 + 1 - i; ++spaces)
		{
			cout << ' ';
		}
		// 2. print '*'
		cout << '*';
		// 3. print 2*(i-1)-1 times ' '
		for (int spaces = 1; spaces <= 2 * (i - 1) - 1; ++spaces)
		{
			cout << ' ';
		}
		// 4. print '*', only if (i!= 1)
		if (i != 1) {
			cout << '*';
		}

		// 5. cout << endl;
		cout << endl;
	}

	// Mirror Pattern
	for (int i = n / 2; i >= 1; --i)
	{
		// 1. print n/2+1 -i times ' '
		for (int spaces = 1; spaces <= n / 2 + 1 - i; ++spaces)
		{
			cout << ' ';
		}
		// 2. print '*'
		cout << '*';
		// 3. print 2*(i-1)-1 times ' '
		for (int spaces = 1; spaces <= 2 * (i - 1) - 1; ++spaces)
		{
			cout << ' ';
		}
		// 4. print '*', only if (i!= 1)
		if (i != 1) {
			cout << '*';
		}

		// 5. cout << endl;
		cout << endl;
	}


	return 0;
}
















