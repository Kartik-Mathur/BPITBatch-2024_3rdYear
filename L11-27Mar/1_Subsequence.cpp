#include <iostream>
using namespace std;

void subsequence(char *ip, char*out, int i, int j) {
	// base case
	if (ip[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case
	// 1. ith character ko include mat karo
	subsequence(ip, out, i + 1, j);
	// 2. ith character ko include karlo
	out[j] = ip[i];
	subsequence(ip, out, i + 1, j + 1);
}

int main() {

	char a[] = "abc";
	char out[100];

	subsequence(a, out, 0, 0);

	return 0;
}
















