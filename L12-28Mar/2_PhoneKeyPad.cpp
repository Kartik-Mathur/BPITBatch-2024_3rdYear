#include <iostream>
using namespace std;

string keys[] = {
	"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

string users[] = {
	"RAJ", "YASH", "AMIT", "GOLU", "GIAN", "BHAWANSH"
};
int s = 6;

void phoneKeyPad(char *ip, int i, char* op, int j) {
	// base case
	if (ip[i] == '\0') {
		op[j] = '\0';
		cout << op << endl;
		return;
	}

	// recursive case
	int d = ip[i] - '0';
	for (int k = 0; k < keys[d].size(); ++k)
	{
		op[j] = keys[d][k];
		phoneKeyPad(ip, i + 1, op, j + 1);
	}
}

void findUser(char *ip, int i, char* op, int j) {
	// base case
	if (ip[i] == '\0') {
		op[j] = '\0';
		string x(op);
		for (int i = 0; i < s; ++i)
		{
			if (x == users[i]) cout << x << endl;
		}
		return;
	}

	// recursive case
	int d = ip[i] - '0';
	for (int k = 0; k < keys[d].size(); ++k)
	{
		op[j] = keys[d][k];
		findUser(ip, i + 1, op, j + 1);
	}
}

int main() {

	char ip[] = "24292674";
	char op[100];

	// phoneKeyPad(ip, 0, op, 0);
	findUser(ip, 0, op, 0);

	return 0;
}
















