#include <iostream>
using namespace std;

int main() {
	int n = 5;
	int cnt = 0;

	for (int i = 30; i >= 0; --i)
	{
		if (n & (1 << i)) {
			cnt++;
			cout << 1;
		}
		else {
			cout << 0;
		}
	}

	cout << endl;
	cout << "Set Bits: " << cnt << endl;

	return 0;
}
















