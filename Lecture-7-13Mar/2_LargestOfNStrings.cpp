#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int a;
	char arr[1000], largest[1000];
	int n, max_len = 0;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i)
	{
		cin.getline(arr, 1000);
		// If jo input kari hai string vo badi hai abhi tak saari
		// strings se toh usse store karlo
		int current_len = strlen(arr); // Inbuilt function to find length

		if (current_len > max_len) {
			// update krdo largest wale array ko with current string

			strcpy(largest, arr); // Inbuilt function to copy string

			// and largest wale array ki length is in max_len
			// toh we have to update max_len as well
			max_len = current_len;
		}
	}

	cout << "Largest String: " << largest << endl;
	cout << "Largest length: " << max_len << endl;

	return 0;
}
















