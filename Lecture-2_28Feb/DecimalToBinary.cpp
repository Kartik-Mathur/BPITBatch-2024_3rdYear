#include <iostream>
using namespace std;

int main() {

	int n = 23;
	int no = (1 << 30);

	while (no > 0) {
		if ( (n & no) > 0) {
			cout << 1 ;
		}
		else {
			cout << 0;
		}

		no = (no >> 1);
	}

	cout << endl;


	return 0;
}
















