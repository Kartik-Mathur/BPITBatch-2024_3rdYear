#include <iostream>
#include <climits>
using namespace std;

int findLeftPos(int *a, int n) {
	bool issueCreateHua = false;
	int minElement = INT_MAX;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < a[i - 1]) issueCreateHua = true;
		if (issueCreateHua) {
			minElement = min(minElement, a[i]);
		}
	}

	int left = 0, i = 0;
	while (i < n) {
		if (minElement < a[i]) {
			left = i;
			break;
		}
		i++;
	}
	return left;
}

int findRightPos(int *a, int n) {
	bool issueCreateHua = false;
	int maxElement = INT_MIN;
	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i] > a[i + 1]) issueCreateHua = true;
		if (issueCreateHua) maxElement = max(maxElement, a[i]);
	}

	int i = n - 1, right;
	while (i >= 0) {
		if (a[i] < maxElement) {
			right = i;
			break;
		}
		i--;
	}
	return right;
}


void politeSort(int *a, int n) {
	// If array is sorted answer is zero
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) break;
		if (i == n - 1) {
			cout << 0 << endl;
			return;
		}
	}
	int left = findLeftPos(a, n);
	// cout << left << endl;
	int right = findRightPos(a, n);
	// cout << right << endl;
	cout << right - left + 1 << endl;
}

int main() {

	int a[100005];
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	if (n == 1) {
		cout << 0 << endl;
	}
	else politeSort(a, n);


	return 0;
}



