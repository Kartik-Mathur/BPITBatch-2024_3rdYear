#include <iostream>
#include <cstring>
using namespace std;
int n;

int compareStrings(char*a, char*b) {
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}

	return 0;
}

int main() {

	char a[100000], b[100000];
	cin >> a >> b;
	n = strlen(a);

	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= 'A' and a[i] <= 'Z') a[i] ^= 32;
		if (b[i] >= 'A' and b[i] <= 'Z') b[i] ^= 32;
	}

	int ans = compareStrings(a, b);
	// a < b -->  -1
	// a > b -->  +1
	// a == b --> 0
	cout << ans << endl;


	// char ch = 'a';
	// cin >> ch;

	// cout << (char)( ch ^ (' ') ) << endl;
	// cout << (char)( ch ^ 32 ) << endl;

	return 0;
}
















