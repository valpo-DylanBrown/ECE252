#include<iostream>
using namespace std;
#define LENGTHTOPRINT 5

int main () {

	string myString = "Hello World";
	string myString2;

	getline(cin, myString2);

	cout << myString << endl << myString2 << endl;
	cout << myString << ", " << myString2 << endl;
	string myString3 = myString + ", " + myString2;

	cout << endl << myString3 << endl;
	return 0;
}
