#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> ans;

bool comparator(string a, string b) {
	return a < b;
}

void permutations(char *a, int i) {
	// base case
	if (a[i] == '\0') {
		// cout << a << endl;
		string x = a;
		ans.push_back(x);
		return;
	}
	// recursive case
	for (int j = i; a[j] != '\0'; ++j)
	{
		swap(a[i], a[j]);
		permutations(a, i + 1);
		swap(a[i], a[j]); // backtracking
	}
}

int main() {

	char a[] = "abc";
	permutations(a, 0);
	int arr[] = {4, 2, 1};
	int n = sizeof(a) / sizeof(int);

	sort(ans.begin(), ans.end(), comparator);

	for (int i = 0;  i < ans.size() ; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
















