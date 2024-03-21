#include <iostream>
using namespace std;

void updateString(string &s) {
	s += "Updated Content";
	cout << s << endl;
}

int main() {

	string s;

	s = "Hello";
	cout << s << endl;

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << "--";
	}
	cout << endl;

	string s1 = "World";

	s = s + " " + s1;
	cout << s << endl;

	if (s > s1)
	{
		cout << "Badi Hai S\n";
	}
	else {
		cout << "Badi Nahi Hai S\n";
	}

	s1.push_back('T');
	cout << s1 << endl;
	s1.pop_back();
	cout << s1 << endl;

	updateString(s1);
	cout << s1 << endl;


	return 0;
}
















