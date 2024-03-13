#include <iostream>
using namespace std;

bool isPalindrome(char *a, int i, int j) {
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

	char a[] = "aaa";
	int cnt = 0;

	for (int i = 0; a[i] != '\0'; ++i)
	{
		for (int j = i; a[j] != '\0' ; ++j)
		{
			if (isPalindrome(a, i, j)) cnt++;
		}
	}

	cout << cnt << endl;


	return 0;
}
















