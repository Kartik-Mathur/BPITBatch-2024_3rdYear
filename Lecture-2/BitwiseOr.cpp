#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cout << (5 | 2) << endl;
	cout << (23 | 8) << endl;

	// Setting bth bit 1 and rest all bits zero: 2^(b-1)
	// 2^0 : 00001 (1st bit 1)
	// 2^1 : 00010 (2nd bit 1)
	// 2^2 : 00100 (3rd bit 1)

	int b = 5;
	int no = pow(2, b - 1);

	cout << (1 | no) << endl;



	return 0;
}
















