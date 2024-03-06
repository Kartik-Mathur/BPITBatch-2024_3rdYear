#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n = 10;

	for (int i = 1; i <= n; i++) {
		if (i == 3) {
			continue;
		}
		cout << i << " ";
	}

	cout << endl;

	int i = 0;
	while (i < n) {
		i++;
		if (i == 3) {
			continue;
		}

		cout << i << " ";

	}

	return 0;
}