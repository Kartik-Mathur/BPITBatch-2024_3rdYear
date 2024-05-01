#include<iostream>
using namespace std;

void fillFreqArr ( string s, int i, int n , int *freqArr) {
	if ( i == n ) return;
	int x = s[i];
	freqArr[x] += 1;
	fillFreqArr (s, i + 1, n, freqArr);
}

int main() {
	int freqArr[256] = {0};
	string s;
	cin >> s;
	int n = s.length();
	fillFreqArr (s, 0, n, freqArr);
	int maxfreq = 0;
	for (int i = 97; i < 107; ++i)
	{
		cout << char(i) << " : " << freqArr[i] << endl;
	}
	int indx = -1;
	for (int i = 0; i < 256; i++) {
		if ( freqArr[i] > maxfreq ) maxfreq = freqArr[i], indx = i;
	}

	char ch = indx;
	cout << "Character : " << ch << endl;
	return 0;
}










