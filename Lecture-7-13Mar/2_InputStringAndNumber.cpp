#include <iostream>
using namespace std;

int main() {

	int a;
	char arr[1000];
	// Integer number ka input le lia
	cin >> a;
	cin.ignore(); // This will ignore one character after integer input

	// Whitespace wali string ka input lelo
	cin.getline(arr, 1000);

	cout << a << endl;
	cout << arr << endl;

	return 0;
}
















