#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {

	int n = 12345;
	int no = pow(2, 30);


	while (no > 0) {
		if ( (n & no) > 0) {
			cout << 1 ;
		}
		else {
			cout << 0;
		}

		no = no / 2;
	}

	cout << endl;

	// Setting a particular to zero
	int x = pow(2, 2);
	cout << x << endl;
	cout << (23 & (~x)) << endl;


	return 0;
}
















