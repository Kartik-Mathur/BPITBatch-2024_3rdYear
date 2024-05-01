#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string &str) {
	stack<char> s;
	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		switch (ch) {
		case '{':
		case '[':
		case '(':
			s.push(ch);
			break;
		case ')':
			if (!s.empty() and s.top() == '(') s.pop();
			else return false;
			break;
		case ']':
			if (!s.empty() and s.top() == '[') s.pop();
			else return false;
			break;

		case '}':
			if (!s.empty() and s.top() == '{') s.pop();
			else return false;

		}
	}

	return s.empty() == true ? true : false;

}

int main() {

	string s = "[a*(b+c)+{d*(f+e)}]";
	// string s = "[a+b*(c+d";

	if (isBalanced(s)) cout << "Balanced\n";
	else cout << "Not Balanced\n";


	return 0;
}
















