#include <iostream>
using namespace std;

int main() {
	int n = 15;
	int cnt = 0;

	while (n > 0) {
		if ((n & 1) == 1) {
			cnt++;
		}

		n = n >> 1;
	}

	cout << "SetBits: " << cnt << endl;

	return 0;
}
















