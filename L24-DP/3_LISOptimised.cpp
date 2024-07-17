#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[] = {1, 4, 2, 3, 0, 8, 11, 10, 15};
	int n = sizeof(a) / sizeof(int);

	vector<int> x;
	x.push_back(a[0]);

	for (int i = 1; i < n; ++i)
	{
		if (a[i] > x[x.size() - 1]) {
			x.push_back(a[i]);
		}
		else {
			int indx = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
			x[indx] = a[i];
		}
	}

	cout << x.size() << endl;

	return 0;
}

















