#include<iostream>
#include<climits>

using namespace std;

int main() {

	// int i;
	// cin >> i;

	// int j = i % 2 == 0 ? 0 : 1;

	// cout << "j : " << j << endl;

	int n;
	cin >> n;

	if (n > 0) {
		cout << "positive" << endl;
	} else if (n < 0) {
		cout << "negative" << endl;
	} else {
		cout << "zero" << endl;
	}

	n > 0 ? cout << "positive" << endl :
	             n < 0 ? cout << "negative" << endl :
	             cout << "zero" << endl;

	return 0;
}