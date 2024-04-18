#include <iostream>
using namespace std;

int main() {

	int *a = new int;

	int *arr = new int[10];

	*a = 10;
	cout << *a << endl;

	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// Memory free
	delete a;
	delete [] arr;
	a = arr = NULL;

	return 0;
}
















