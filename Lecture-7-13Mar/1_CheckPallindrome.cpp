#include <iostream>
using namespace std;

int length(char a[]) {
	int i;

	for (i = 0; a[i] != '\0'; ++i) {}

	return i;
}

bool isPalindrome(char a[]) {
	int i = 0;
	int j = length(a) - 1;

	while (i < j) {
		if (a[i] != a[j]) {
			return false;
		}

		i++;
		j--;
	}

	return true;
}


int main() {

	// char a[] = "abcxa";
	char a[1000];

	cin.getline(a, 100, '$');


	bool ans = isPalindrome(a);

	if (ans == true) {
		cout << "isPalindrome\n";
	}
	else {
		cout << "Not a Palindrome\n";
	}



	return 0;
}
















