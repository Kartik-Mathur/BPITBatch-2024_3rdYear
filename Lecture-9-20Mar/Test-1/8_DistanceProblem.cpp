#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005], b[1000005];

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			b[m++] = a[j] - a[i];
		}
	}

	sort(b, b + m);

	cout << b[k - 1] << endl;


	return 0;
}
















