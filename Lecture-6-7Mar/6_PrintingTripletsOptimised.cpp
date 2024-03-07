#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int a[] = { -1, 0, 1, 2, -1, 3, -2};
	int n = sizeof(a) / sizeof(int);

	sort(a, a + n);

	for (int i = 0; i < n - 2; ++i)
	{
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}

		// Remaining two numbers ko find krna
		int j = i + 1;
		int k = n - 1;

		while (j < k) {
			if (a[i] + a[j] + a[k] == 0) {
				cout << a[i] << " " << a[j] << " " << a[k] << endl;
				j++;
				k--;

				// ki bhai a[j] == a[j-1] --> j++;
				// ki bhai a[k] == a[k+1] --> k--;
				while (j < k and a[j] == a[j - 1]) j++;
				while (j < k and a[k] == a[k + 1]) k--;
			}
			else if (a[i] + a[j] + a[k] > 0 ) k--;
			else j++;
		}

	}


	return 0;
}
















