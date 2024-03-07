#include <iostream>
using namespace std;

int main() {

	int a = 10;
	int *ap;
	ap = &a;

	char ch = 'A';
	char *cp = &ch;

	cout << "ap   : " << ap << endl;
	cout << "&a   : " << &a << endl;
	cout << "&a+2 : " << &a + 2 << endl;
	cout << "*ap  : " << *ap << endl;
	cout << "cp   : " << (int*)cp << endl;
	cout << "&ch   : " << (float*)&ch << endl;


	return 0;
}
















