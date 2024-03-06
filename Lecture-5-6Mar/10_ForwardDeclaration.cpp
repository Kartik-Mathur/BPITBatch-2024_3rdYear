#include <iostream>
using namespace std;
// Functions can be declared before
void printHello();
// int sum(int a, int b);
int sum(int, int);

int main() {

	printHello();
	cout << sum(10, 20) << endl;
	return 0;
}


void printHello() {
	cout << "Hello World\n";
}

int sum(int a, int b) {
	return a + b;
}