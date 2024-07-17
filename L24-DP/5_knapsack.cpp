#include <iostream>
using namespace std;

int knapsack(int *price, int *weight, int n, int capacity) {
	// basecase
	if (n == 0 || capacity == 0) {
		return 0;
	}

	// recursive case
	int op1 = INT_MIN, op2 = INT_MIN;
	if (weight[n - 1] <= capacity) {
		op1 = price[n - 1] + knapsack(price, weight, n - 1, capacity - weight[n - 1]);
	}
	op2 = 0 + knapsack(price, weight, n - 1, capacity);
	return max(op1, op2);
}

int topDown(int *price, int *weight, int n, int capacity, int dp[][100]) {
	// basecase
	if (n == 0 || capacity == 0) {
		return dp[n][capacity] = 0;
	}

	if (dp[n][capacity] != -1) return dp[n][capacity];

	// recursive case
	int op1 = INT_MIN, op2 = INT_MIN;
	if (weight[n - 1] <= capacity) {
		op1 = price[n - 1] + topDown(price, weight, n - 1, capacity - weight[n - 1], dp);
	}
	op2 = 0 + topDown(price, weight, n - 1, capacity, dp);
	return dp[n][capacity] = max(op1, op2);
}

int bottomUp(int *price, int *weight, int n, int capacity) {
	int dp[100][100] = {0};

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int op1 = INT_MIN, op2 = INT_MIN;
				if (j >= weight[i - 1]) {
					op1 = price[i - 1] + dp[i - 1][j - weight[i - 1]];
				}
				op2 = 0 + dp[i - 1][j];

				dp[i][j] = max(op1, op2);
			}
		}
	}

	return dp[n][capacity];
}

int main() {

	int price[] = {4, 2, 6, 5};
	int weight[] = {1, 2, 3, 2};
	int n = sizeof(price) / sizeof(int);
	int capacity = 4;
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << knapsack(price, weight, n, capacity) << endl;
	cout << topDown(price, weight, n, capacity, dp) << endl;
	cout << bottomUp(price, weight, n, capacity) << endl;

	return 0;
}

















