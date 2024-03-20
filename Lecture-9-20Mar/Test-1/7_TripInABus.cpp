#include <iostream>
#include <climits>
using namespace std;
int minTime = INT_MAX;
int bus[100005], n, ttrips;

bool isPossible(int time) {
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += time / bus[i];
	}
	return ans >= ttrips;
}

int solve() {
	int s = minTime, e = minTime * ttrips;
	int ans;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPossible(mid)) {
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

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> bus[i];
		minTime = min(minTime, bus[i]);
	}
	cin >> ttrips;

	cout << solve() << endl;


	return 0;
}
















