#include <iostream>
using namespace std;

int main () {
	int currentYear = 2026;
	int birthYear;
	cout << "Enter your birth year: ";
	cin >> birthYear;
	cout << "Your age is "<< currentYear - birthYear << endl;
	return 0;
}
