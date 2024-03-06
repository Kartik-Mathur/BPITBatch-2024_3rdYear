#include <iostream>
using namespace std;

int main() {
	int n = 4;
	for (int rows = 1; rows <= n; ++rows)
	{
		// 1. Print row -1 times space
		for (int cols = 1; cols <= rows - 1; ++cols)
		{
			cout << ' ';
		}

		// 2. Print n-row+1 times star
		for (int cols = 1; cols <= n - rows + 1; ++cols)
		{
			cout << '*';
		}

		cout << endl;
	}


	return 0;
}
















