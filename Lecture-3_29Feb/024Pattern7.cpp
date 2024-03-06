#include<iostream>

using namespace std;

int main() {

	int n = 5;


	for (int i = 1; i <= n; i++) {

		// 1. print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << "  ";
		}

		// 2. print i nos. in the inc. order starting with i

		int num = i;

		for (int j = 1; j <= i; j++) {

			cout << num << " ";
			num++;

		}

		// 3. print i-1 more nos. in the dec. order starting with 2i-2

		num = 2 * i - 2;

		for (int j = 1; j <= i - 1; j++) {
			cout << num << " ";
			num--;
		}

		cout << endl;

	}

	return 0;
}