#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;


	for (int row = 1; row <= n; ++row)
	{
		// 1. Print row times star
		for (int i = 1; i <= row; ++i)
		{
			cout << '*' << ' ';
		}

		// 2. print '\n'
		cout << endl;
	}

	// For Pattern Mirror

	for (int row = n - 1; row >= 1; --row)
	{
		// 1. Print row times star
		for (int i = 1; i <= row; ++i)
		{
			cout << '*' << ' ';
		}

		// 2. print '\n'
		cout << endl;
	}



	return 0;
}
















