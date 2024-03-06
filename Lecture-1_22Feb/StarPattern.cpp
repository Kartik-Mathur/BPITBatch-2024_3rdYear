#include <iostream>
using namespace std;

int main() {
	int n = 4;

	for (int rows = 1; rows <= n; ++rows)
	{
		for (int cols = 1; cols <= rows; ++cols)
		{
			cout << '*' << " ";
		}

		cout << endl;
	}

	return 0;
}
















