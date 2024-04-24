#include <iostream>
#include <stack>
using namespace std;

void bruteForce(int *a, int n) {
	int ng[100];

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] > a[i]) {
				ng[i] = j;
				break;
			}
		}
	}
	ng[n - 1] = -1;
	cout << "Next Greater elements\n";
	for (int i = 0; i < n; ++i)
	{
		if (ng[i] != -1)
			cout << a[ng[i]] << " ";
		else cout << -1 << " ";
	}
	cout << endl;
}

void nextSmaller(int *a, int n) {
	stack<int> s;
	int ns[1000];
	ns[n - 1] = -1;
	s.push(n - 1);
	for (int i = n - 2; i >= 0; --i)
	{
		while (!s.empty() and a[i] <= a[s.top()]) s.pop();

		if (!s.empty()) ns[i] = s.top();
		else ns[i] = -1;

		s.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ns[i] << " ";
		// if (ns[i] != -1)
		// cout << a[ns[i]] << " ";
		// else cout << -1 << " ";
	}
}


void previousSmaller(int *a, int n) {
	stack<int> s;
	int ps[1000];
	ps[0] = -1;
	s.push(0);
	for (int i = 1; i < n; ++i)
	{
		while (!s.empty() and a[i] <= a[s.top()]) s.pop();

		if (!s.empty()) ps[i] = s.top();
		else ps[i] = -1;

		s.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		// cout << ps[i] << " ";
		if (ps[i] != -1)
			cout << a[ps[i]] << " ";
		else cout << -1 << " ";
	}
}

int main() {

	int a[] = {2, 4, 6, 1, 5, 3, 8, 4};
	int n = sizeof(a) / sizeof(int);

	nextSmaller(a, n);
	cout << endl;
	previousSmaller(a, n);
	cout << endl;

	// bruteForce(a, n);


	return 0;
}
















