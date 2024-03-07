#include <iostream>
using namespace std;

int main() {

	int a = 10;
	float f = 2.11;

	float *x =  &f;
	// int *ap = &a;
	int *ap;

	ap = &a;



	cout << "ap : " << ap << endl;
	cout << "&a : " << &a << endl;
	cout << "&f : " << &f << endl;
	cout << "x  : " << x << endl;


	return 0;
}
















