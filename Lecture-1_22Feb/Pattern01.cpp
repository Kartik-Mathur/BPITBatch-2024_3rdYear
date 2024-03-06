#include <iostream>
using namespace std;

int main() {
	// Way - 1
	int n = 6, no;
	for (int rows = 1; rows <= n; ++rows)
	{
		// Start kaha se krna hai no ko print krna
		// dhoondo
		if (rows % 2 == 0) {
			no = 1;
		}
		else {
			no = 0;
		}

		for (int cols = 1; cols <= rows; ++cols)
		{
			cout << no;
			no = 1 - no;
		}

		cout << endl;
	}

	// Way - 2
	// int n = 4;
	// for (int rows = 1; rows <= n; ++rows)
	// {
	// 	for (int cols = 1; cols <= rows; ++cols)
	// 	{
	// 		if ((rows - cols) % 2 == 0) {
	// 			cout << "0";
	// 		}
	// 		else {
	// 			cout << "1";
	// 		}
	// 	}

	// 	cout << endl;
	// }


	return 0;
}
















