#include <iostream>
using namespace std;

void stairCase(int a[][100], int n, int m, int key) {
	int i = 0, j = m - 1;
	bool flag = false;
	while (i<n and j >= 0) {
		if (a[i][j] == key) {
			cout << "Key Found at : " << i << "," << j << endl;
			flag = true;
			break;
		}
		else if (a[i][j] < key) {
			i++;
		}
		else {
			j--;
		}
	}

	if (flag == false) {
		cout << "Key Not Found\n";
	}
}

void stairCase1(int a[][100], int n, int m, int key) {
	int i = 0, j = m - 1;

	while (i<n and j >= 0) {
		if (a[i][j] == key) {
			cout << "Key Found at : " << i << "," << j << endl;
			return;
		}
		else if (a[i][j] < key) {
			i++;
		}
		else {
			j--;
		}
	}

	cout << "Key Not Found\n";
}


int main() {

	// 1. 2d Array create karo
	// Aise jismei row and cols sorted ho, sirf tabhi staircase kaam krega
	int a[][100] = {
		{1, 2, 4, 5},
		{3, 7, 15, 20},
		{6, 16, 18, 22},
		{10, 17, 24, 28},
	};

	int n, m;
	n = m = 4;
	int key = 17;
	stairCase1(a, n, m, key);

	return 0;
}
















