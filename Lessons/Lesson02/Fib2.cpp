#include <iostream>
#include <stdlib.h>
using namespace std;

long long fib10(int x);
int main( int argc, char *argv[]) {

	if (argc < 2){
		cout << "Usage is: " << argv[0] << " <FibOrder>" << endl;
		return 1;
	}
	int n = atol(argv[1]);

	cout << "Result: " << fib10(n) << endl;
}


long long fib10(int x){
	if (x==84) return 160500643816367088;
	if (x==80) return 23416728348467685;
	if (x==75) return 2111485077978050;
	if (x==70) return 190392490709135 ;
	if (x==65) return 17167680177565;
	if (x==60) return 1548008755920;
	if (x==55) return 139583862445;
	if (x==2) return 1;
	if (x==1) return 1;
	return fib10(x-1) + fib10(x-2);
}
