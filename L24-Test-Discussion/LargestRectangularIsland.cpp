#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class LargestArea {
	void nextSmaller(vector<int>& a, int n) {
		stack<int> s;
		ns[n - 1] = n;
		s.push(n - 1);
		for (int i = n - 2; i >= 0; --i)
		{
			while (!s.empty() and a[i] <= a[s.top()]) s.pop();

			if (!s.empty()) ns[i] = s.top();
			else ns[i] = n;

			s.push(i);
		}

	}

	void previousSmaller(vector<int> &a, int n) {
		stack<int> s;
		ps[0] = -1;
		s.push(0);
		for (int i = 1; i < n; ++i)
		{
			while (!s.empty() and a[i] <= a[s.top()]) s.pop();

			if (!s.empty()) ps[i] = s.top();
			else ps[i] = -1;

			s.push(i);
		}
	}

public:
	int ns[100005];
	int ps[100005];

	int largestRectangleArea(vector<int>& a) {
		if (a.size() == 1) return a[0];

		nextSmaller(a, a.size());
		previousSmaller(a, a.size());
		int n = a.size();
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int len = ns[i] - ps[i] - 1;
			int area = a[i] * len;
			ans = max(ans, area);
		}
		return ans;
	}
};

int rows, cols;
int a[1000][1000];

int main() {
	cin >> rows >> cols;

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) cin >> a[i][j];

	vector<int> height(cols, 0);
	int ans = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (a[i][j] == 1) height[j] ++;
			else height[j] = 0;
		}

		LargestArea l;
		int x = l.largestRectangleArea(height);
		ans = max(ans, x);
	}
	cout << ans << endl;
}













