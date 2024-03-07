#include <iostream>
using namespace std;

int main() {

	// char a[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	// char a[100] = "Hello"; // Null gets added automatically
	char a[100]; // Null gets added automatically

	// cin >> a; // Automatically Null append kar dega
	// cin.getline(array_Name, numberOfCharacter, delimiter);
	cin.getline(a, 100);
	cout << a << endl;

	for (int i = 0; a[i] != '\0'; ++i)
	{
		cout << a[i] << " - ";
	}
	cout << endl;

	return 0;
}
















