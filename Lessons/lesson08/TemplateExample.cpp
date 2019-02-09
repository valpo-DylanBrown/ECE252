#include <iostream>
using namespace std;



int integerMin (int a, int b) {
	if (a < b) return a;
	else return b;
}

double doubleMin (double a, double b) {
	if (a < b) return a;
	else return b;
}

char characterMin (char a, char b) {
	if (a < b) return a;
	else return b;
}
template <typename TYPE>
TYPE genericMin(TYPE a, TYPE b){
	if (a < b) return a;
	else return b;
}



int main () {

	cout << "Min of 4 and -2 is: " << genericMin(4, -2) << endl;
	cout << "Min of 2.718 and 1.414 is: " << genericMin(1.414, 2.718) << endl;
	cout << "Min of c and w is: " << genericMin('w', 'c') << endl;
	cout <<endl;
	string pdt = "Tougaw";
	string jdw = "Will";

	cout << "The lesser prof is: " << genericMin(pdt,jdw) << endl;

	return 0;
}
