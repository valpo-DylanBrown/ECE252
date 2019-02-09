#include <iostream>
using namespace std;

#define SIZE 1000

	int main() {

		int* tmpData;

		//**************
		// standard method - no error check
		//**************
		//tmpData = new  int[SIZE];


		//**************
		// safer method -- manual check (nothrow)
		//**************
		tmpData = new int[SIZE];
		if (tmpData == NULL) {
			cout << "Error!" << endl;
			do something to correct
			return(1);
		}

		try{
			tmpData = new int[SIZE];
		}
		catch (bad_alloc& MyExceptionHam){
			cout << MyExceptionHam.what()<< endl;
			return(1); 
		}

		for (int i=0;i<SIZE;i++){
			tmpData[i]=0;
		}
		cout << "Successfully zeroed out tmpData" << endl;


		delete [] tmpData;

}
