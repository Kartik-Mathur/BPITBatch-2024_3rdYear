#include <iostream>
#include <functional>
#include <queue>
using namespace std;

class Student {
public:
	string name;
	int marks, age;

	void print() {
		cout << "Name  : " << name << endl;
		cout << "Marks : " << marks << endl;
		cout << "Age   : " << age << endl << endl;
	}
};

class compare {
public:
	// functor
	bool operator()(const Student &a, const Student &b) {
		return a.age > b.age;
	}
};

int main() {

	priority_queue<Student, vector<Student>, compare> q;

	q.push({"Raman", 80, 20});
	q.push({"Naman", 70, 22});
	q.push({"Yaman", 55, 22});
	q.push({"Aman", 82, 14});

	while (!q.empty()) {
		Student s = q.top();
		s.print();
		q.pop();
	}





	return 0;
}
















