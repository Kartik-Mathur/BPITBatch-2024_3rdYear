#include<iostream>

using namespace std;

int main() {

	char ch;
	cout << "enter a character : ";
	cin >> ch;

	if (ch >= 'A' and ch <= 'Z') {
		cout << 'U' << endl;
	} else if (ch >= 'a' and ch <= 'z') {
		cout << 'L' << endl;
	} else if (ch >= '0' and ch <= '9') {
		cout << 'D' << endl;
	} else {
		cout << 'S' << endl;
	}


	if (ch >= 65 and ch <= 90) {
		cout << 'U' << endl;
	} else if (ch >= 97 and ch <= 122) {
		cout << 'L' << endl;
	} else if (ch >= 48 and ch <= 57) {
		cout << 'D' << endl;
	} else {
		cout << 'S' << endl;
	}

	return 0;
}