#include <iostream>
#include <vector>  //includes vector standard template library.
//vector is essentially a super-powerful array type.

using namespace std;

int main() {
	vector<float> myVector(15, 2.718);  //create a vector with 15 items, all equal to 2.718.

	//run through the vector and display the content of each element.
	for (int index=0; index< 20; index++){
		try{
			cout << "Element " << index << ": " << myVector.at(index) << endl;
		}
		catch (exception &e){
			cout << "Element " << index << ": index exceeds vector dimensions." << endl;
		}
	}
	
	cout << "Length of vector is: " << myVector.size() << endl;
	
	return 0;
}











