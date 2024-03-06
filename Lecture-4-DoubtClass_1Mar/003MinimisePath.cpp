#include<iostream>

using namespace std;

int main() {

	char ch;

	int x = 0;
	int y = 0;

	while (true) {

		ch = cin.get();

		if (ch == '\n') break;

		if (ch == 'N') {
			y++;
		} else if (ch == 'S') {
			y--;
		} else if (ch == 'E') {
			x++;
		} else {
			// ch == 'W'
			x--;
		}

	}

	// cout << x << " " << y << endl;

	if (x > 0) {

		// print 'E' x times

		for (int i = 1; i <= x; i++) {
			cout << 'E';
		}

	}

	if (y > 0) {

		// print 'N' y times

		for (int i = 1; i <= y; i++) {
			cout << 'N';
		}

	}

	if (y < 0) {

		// print 'S' -y times or abs(y)

		for (int i = 1; i <= -y; i++) {
			cout << 'S';
		}

	}

	if (x < 0) {

		// print 'W' -x times or abs(x)

		for (int i = 1; i <= abs(x); i++) {
			cout << 'W';
		}

	}


	return 0;
}







