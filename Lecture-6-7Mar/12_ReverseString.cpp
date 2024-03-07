#include <iostream>
using namespace std;

int lengthString(char a[]) {
	int i;
	for (i = 0; a[i] != '\0'; ++i)
	{

	}
	return i;
}

void reverseString(char a[]) {
	int i = 0;
	int j = strlen(a) - 1;
	while (i < j) {
		swap(a[i], a[j]);
		// char temp = a[i];
		// a[i] = a[j];
		// a[j] = temp;
		i++;
		j--;
	}
}

int main() {

	char a[] = "Hello";

	// int n = lengthString(a);
	// int n = strlen(a);

	// cout << "length: " << n << endl;
	reverseString(a);
	cout << a << endl;

	return 0;
}
















