#include <iostream>
using namespace std;

class Car {
private:
	int price;

public:
	string name;
	int seats;
	// 1. Default constructor
	Car() {
		cout << "Inside Default Constructor\n";
	}
	// 2. Parameterised Constructor
	Car(string s, int p, int st) {
		cout << "Inside Parameterised Constructor\n";
		name = s;
		price = p;
		seats = st;
	}



	// 3. Functions to help us
	void print() {
		cout << "Name  " << name << endl;
		cout << "Price " << price << endl;
		cout <<	"Seats " << seats << endl << endl;
	}

	// 4. getter and setter
	void setPrice(int p) {
		if (p > 50 and p < 100) price = p;
		else price = 80;
	}

	int getPrice() {
		return price;
	}

	// 5. Copy Constructor
	Car(Car &X) {
		cout << "Inside Inside Copy Constructor\n";
		name = X.name;
		price = X.price;
		seats = X.seats;
	}
};

int main() {

	Car A; // Default constructor
	A.name = "BMW";
	// A.price = 100;
	A.setPrice(-96);
	A.seats = 5;

	Car B("Audi", 150, 2); // Parameterized Constructor



	cout << A.getPrice() << endl;


	Car C = A; // Copy Constructor

	A.print();
	B.print();
	C.print();

	// cout << B.price << endl;
	// cout << B.seats << endl;
	// cout << B.name << endl;


	return 0;
}
















