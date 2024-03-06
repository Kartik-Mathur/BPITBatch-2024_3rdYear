#include<iostream>

using namespace std;

int main() {

	char ch;
	ch = 'b';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'Z';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '#';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '0';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '7';

	cout << ch - '0' << endl;

	return 0;
}