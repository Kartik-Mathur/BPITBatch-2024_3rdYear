#include <iostream>
using namespace std;

int main() {

	int n = 4;

	for (int row = 1; row <= n; ++row)
	{
		char alphabet = 'A';

		for (int col = 1; col <= row; ++col)
		{
			cout << alphabet;
			alphabet++;
		}

		cout << endl;
	}

	return 0;
}
















