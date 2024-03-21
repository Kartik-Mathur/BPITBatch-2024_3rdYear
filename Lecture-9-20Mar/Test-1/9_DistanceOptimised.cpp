#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int n, k;

int countPairs(int diff) {
	int cnt = 0;
	int i = 0, j = i + 1;
	while (i < n and j < n) {
		while (i < n and a[j] - a[i] > diff)
			i++;
		cnt += j - i;
		j++;
	}
	return cnt;
}

int solve() {
	int s = 0, e = a[n - 1] - a[0];
	int ans;
	while (s <= e) {
		int mid = (s + e) / 2;

		// We have to count total pairs that have value of difference <=mid
		if (countPairs(mid) >= k) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {


	cin >> n >> k;


	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	cout << solve() << endl;




	return 0;
}
















