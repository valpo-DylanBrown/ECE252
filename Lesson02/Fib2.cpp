#include <iostream>
#include <stdlib.h>
using namespace std;

long fib(int x);

int main( int argc, char *argv[]) {

	if (argc < 2){
		cout << "Usage is: " << argv[0] << " <FibOrder>" << endl;
		return 1;
	}
	int n = atoi(argv[1]);

	cout << "Result: " << fib(n) << endl;
}

long fib(int x) {
	if (x==1) return 1;
	if (x==2) return 1;
	return fib(x-1) + fib(x-2);
}
