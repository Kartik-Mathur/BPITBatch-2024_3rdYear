#include <iostream>
#include <vector>
using namespace std;

int main() {
	// vector<datatype> v;
	vector<int> v;

	for (int i = 1; i < 6; ++i)
	{
		v.push_back(i);
		cout << "After inserting: " << i << ", size: " << v.size()
		     << ", cap: " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
















