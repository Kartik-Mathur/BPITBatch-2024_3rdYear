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

// void printSubstrings(char*a) {
// 	int len = strlen(a);
// 	// Finding all odd length substrings
// 	for (int center = 0; center < len; ++center)
// 	{
// 		int j = center + 1;
// 		int i = center; // center wale character ka index hai yeh

// 		while (i >= 0 and j < len) {
// 			// i--, j++

// 			for (int k = i; k <= j; ++k)
// 			{
// 				cout << a[k];
// 			}
// 			cout << endl;

// 			i--;
// 			j++;
// 		}
// 	}
// }

int countPalindromic(char *a) {
	int len = strlen(a);
	int i, j, cnt = 0;
	for (int center = 0; center < len; ++center)
	{
		// Checking Odd Length
		i = j = center;
		while (i >= 0 and j < len) {
			if (a[i] == a[j]) cnt++;
			else break;
			i--;
			j++;
		}

		// Checking Even Length
		i = center;
		j = center + 1;
		while (i >= 0 and j < len) {
			if (a[i] == a[j]) cnt++;
			else break;
			i--;
			j++;
		}
	}

	return cnt;
}

int main() {

	char a[] = "abc";


	// printSubstrings(a);
	cout << countPalindromic(a) << endl;


	return 0;
}
















