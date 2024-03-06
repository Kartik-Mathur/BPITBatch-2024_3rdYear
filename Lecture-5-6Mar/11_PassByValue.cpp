#include <iostream>
using namespace std;

void UpdateVal(int x) {
	x = x + 1;
	cout << "X in function : " << x << endl;
}

int main() {

	int a = 1;
	cout << "Before Update: " << a << endl;

	UpdateVal(a);

	cout << "After Update: " << a << endl;


	return 0;
}
















