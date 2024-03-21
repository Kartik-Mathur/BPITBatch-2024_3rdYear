#include <iostream>
using namespace std;

int main() {

	char a[] = "hello....$$$#@...world....xyz..$#@";

	char* x = strtok(a, ".$#@");

	while (x != NULL) {
		cout << x << endl;
		x = strtok(NULL, ".$#@");
	}


	return 0;
}

















