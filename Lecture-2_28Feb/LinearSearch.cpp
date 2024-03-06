#include <iostream>
using namespace std;

int main() {

	int a[] = {2, 6, 4, 3, 5, -8};
	int n = sizeof(a) / sizeof(int), i;
	int key = 4;
	for (i = 0; i < n; ++i)
	{
		if (a[i] == key) {
			cout << "Found at: " << i << endl;
			break;
		}
	}

	if (i == n) {
		cout << "Key not found\n";
	}



	return 0;
}
















