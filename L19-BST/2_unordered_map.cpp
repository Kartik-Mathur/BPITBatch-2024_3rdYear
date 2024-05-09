#include <iostream>
#include <unordered_map> // STL : Standard Template library
// Average-O(1) time mei search, remove and update kar skte hai perform
using namespace std;

int main() {
	// CRUD operations in O(1) time when indexes are not integers
	// hashmap STL: Key and value ka pair insert krte hai
	// SYNTAX: unordered_map<key,value> name;
	unordered_map<string, int> h;

	h["Mango"] = 100;
	h["Pineapple"] = 20;
	h["Kiwi"] = 120; // Insert

	h["Kiwi"] = 40; // Update
	cout << "Mango Price      : " << h["Mango"] << endl; // Print
	cout << "Pineapple Price  : " << h["Pineapple"] << endl;
	cout << "KIWI Price       : " << h["Kiwi"] << endl;


	return 0;
}
















