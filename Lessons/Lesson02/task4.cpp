#include <iostream>
#include <stdlib.h>
using namespace std;

long fib10(int x);
int main( int argc, char *argv[]) {

	if (argc < 2){
		cout << "Usage is: " << argv[0] << " <FibOrder>" << endl;
		return 1;
	}
	int n = atol(argv[1]);

	cout << "Result: " << fib10(n) << endl;
}


long fib10(int x){
	if (x==10) return 55;
	if (x==9) return 34;
	if (x==8) return 21;
	if (x==7) return 13;
	if (x==6) return 8;
	if (x==5) return 5;
	if (x==4) return 3;
	if (x==3) return 2;
	if (x==2) return 1;
	if (x==1) return 1;
	return fib10(x-1) + fib10(x-2);
}
