#include <iostream>
using namespace std;

// bool compare(int a, int b) {
// 	if (a < b) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }

bool compare(int a, int b) {
	return a < b;
}

int main() {

	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (compare(a[j], a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















