#include <iostream>
using namespace std;

void permutations(string ip, string op) {
	// base case
	if (ip.size() == 0) {
		cout << op << endl;
		return;
	}

	// recursive case
	for (int j = 0; j < ip.size(); ++j)
	{
		permutations(ip.substr(0, j) + ip.substr(j + 1), op + ip[j]);
	}
}

int main() {

	string a = "abc", op = "";

	permutations(a, op);

	return 0;
}
















