#include<iostream>
#include<bitset>

using namespace std;

int main() {

	int n = 15;
	int cnt = 0; // to track the no. of set bits in 'n'

	cout << bitset<32>(n) << endl;

	while (n > 0) {
		cnt++;
		n = n & (n - 1);
	}

	cout << cnt << endl;

	return 0;
}