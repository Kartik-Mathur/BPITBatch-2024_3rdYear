#include <iostream>
#include <cstring>
using namespace std;

bool isSubsequence(char *s, char *t) {
	int freq[256] = {0};

	for (int i = 0; t[i] != '\0'; ++i)
	{
		char ch = t[i];
		freq[ch]++;
	}

	for (int i = 0; s[i] != '\0'; ++i)
	{
		char ch = s[i];
		if (freq[ch] > 0) freq[ch]--;
		else return false;
	}
	return true;
}

bool isSubsequence2(char *s, char *t) {
	int n = strlen(s);
	int m = strlen(t);
	int i = 0, j = 0;
	while (i < n and j < m) {
		while (j < m and s[i] != t[j]) j++;

		i++;
		j++;
	}
	return i == n;
}


int main() {

	char s[100005], t[100005];

	cin >> s >> t;

	cout << boolalpha << isSubsequence2(s, t) << endl;

	return 0;
}
















