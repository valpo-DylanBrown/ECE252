#include <iostream>
using namespace std;

int sumUpToInteger(int x){  //n+(n-1)+...+3+2+1
	if(x <=0){
		return 0;
	}
	if(x == 1){
		return 1;
	}
	return x + sumUpToInteger(x-1);
}

int multInt(int a, int b){  //a must be positive
	if(a == 1){
		return b;
	}
	return b+multInt((a-1), b);
}

int binaryMult(int a, int b){   //divide and conquer
	if(a == 1){
		return b;
	}
	if(a%2 == 1){
		return b+binaryMult(a/2,b)+binaryMult(a/2,b);
	}
	return binaryMult(a/2,b)+binaryMult(a/2,b);
}

long long factorial(long long x){  //n!=n*(n-1)*...*3*2*1
	if(x==1){
		return 1;
	}
	return x*factorial(x-1);
}

int main() {
	cout << "20!="<< factorial(20)<< endl;
	cout << "Sum up to 20="<< sumUpToInteger(20)<< endl;
	cout << "7*6="<< multInt(7,6)<< endl;
	cout << "16*3="<< binaryMult(3,16)<< endl;
	return 0;
}
