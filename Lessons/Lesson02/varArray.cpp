#include <iostream>
using namespace std;
int main() {
	
	int arraySize=0;
	
	cout << "Please enter the array size:";
	cin >> arraySize;
	
	int * variableArray = new int[arraySize];
	
	for (int i=0; i<arraySize ; i++){
		variableArray[i]=arraySize-i;
	}
	
	for (int i=0; i<arraySize ; i++){
		cout << variableArray[i] << " ";
	}
	
	return 0;

}