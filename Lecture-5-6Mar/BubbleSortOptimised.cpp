#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i < n - 1; ++i)
	{
		int cnt = 0;
		cout << "Starting the comparison for " << i << " time\n";
		for (int j = 0; j <= n - 2; ++j)
		{
			if (a[j] > a[j + 1]) {
				cnt++;
				swap(a[j], a[j + 1]);
			}
		}

		if (cnt == 0) {
			break;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















