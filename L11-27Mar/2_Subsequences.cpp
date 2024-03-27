#include <iostream>
using namespace std;

void subsequence(string ip, string op, int i) {
	// base case
	if (i == ip.length()) {
		cout << op << endl;
		return;
	}

	// recursive case
	// 1. ith character ko include mat karo
	subsequence(ip, op, i + 1);
	// 2. ith character ko include karlo
	subsequence(ip, op + ip[i], i + 1);

}

int main() {
	string ip = "abc";
	string op = "";

	subsequence(ip, op, 0);

	return 0;
}
















