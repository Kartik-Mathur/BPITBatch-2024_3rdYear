#include <iostream>
using namespace std;

void printHello() {
	cout << "Hello World!!!!!\n";
}

int sum(int x, int y) {
	int ans = x + y;

	return ans; // using return keyword hum value vapis return kr skte hai
}

int subtract(int m, int n) {

	return m - n;
}

int main() {

	// Invoke/Call
	printHello();

	int a = 10, b = 20;

	int ans = sum(a, b);

	cout << "Sum : " << ans << endl;

	cout << "Subtract: " << subtract(20, 10) << endl;

	return 0;
}
















