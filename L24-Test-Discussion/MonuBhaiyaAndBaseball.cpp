#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {

	string s;


	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> rounds;
		int ans = 0, score = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			if (s == "C") {
				rounds.pop_back();
				ans -= score;
				score = rounds.back();
				continue;
			}

			if (s == "D") {
				ans += score = score * 2;
			}
			else if (s == "+") {
				ans += score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
			}
			else {
				ans += score = stoi(s);
			}
			rounds.push_back(score);
		}

		cout << ans << endl;

	}


	return 0;
}
















