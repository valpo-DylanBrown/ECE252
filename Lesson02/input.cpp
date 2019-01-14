#include <iostream>  //no .h after c++ libraries
#include <stdlib.h>  //yes .h after C libraries

using namespace std;

int main(int argc, char *argv[]) {

	cout << "You entered " << argc << " values." << endl;
	cout << "Name of Program: " << argv[0] << endl;
	cout << "Name of 1st Argument: " << argv[1] << endl;
	cout << "Name of tenth Argument: " << argv[9] << endl;
}
