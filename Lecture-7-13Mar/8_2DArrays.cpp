#include <iostream>
using namespace std;

int main() {

	int a[100][100];
	int n, m;
	cout << "Enter row and col: ";
	cin >> n >> m;
	int no = 1;

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			a[row][col] = no;
			no++;
		}
	}

	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cout << a[row][col] << " ";
		}

		cout << endl;
	}




	return 0;
}
















