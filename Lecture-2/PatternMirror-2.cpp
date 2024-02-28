#include <iostream>
using namespace std;

int main() {

	int n = 4;
	for (int row = 1; row <= n; ++row)
	{
		// 1. Print n-row ' '
		for (int spaces = 1; spaces <= n - row; ++spaces)
		{
			cout << "  ";
		}

		// 2. Print 2*row-1 stars
		for (int stars = 1; stars <= 2 * row - 1; ++stars)
		{
			cout << "* ";
		}
		// 3. Print endl;
		cout << endl;
	}


	// Mirror Pattern
	for (int row = n - 1; row >= 1; --row)
	{
		// 1. Print n-row ' '
		for (int spaces = 1; spaces <= n - row; ++spaces)
		{
			cout << "  ";
		}

		// 2. Print 2*row-1 stars
		for (int stars = 1; stars <= 2 * row - 1; ++stars)
		{
			cout << "* ";
		}
		// 3. Print endl;
		cout << endl;
	}

	return 0;
}
















