#include <iostream>
using namespace std;

int main() {

	string s[10] = {
		"Hello",
		"World",
		"Coding",
		"Hello World",
		"",
		"Coding Blocks"
	};

	int n = 4;

	// Nested Loop
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < s[row].size(); ++col)
		{
			cout << s[row][col] << " ";
		}
		cout << endl;
	}

	string largest =  "";

	for (int i = 0; i < n; ++i)
	{
		if (s[i].size() > largest.size()) largest = s[i];
	}

	cout << "Largest string: " << largest << endl;



	return 0;
}
















