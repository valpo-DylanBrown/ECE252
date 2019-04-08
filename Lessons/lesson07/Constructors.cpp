#include <iostream>
using namespace std;

class ParentClass {
protected:
	int x;
	public:
		ParentClass() {  //default constructor cannot have input arguments.
			x=0;
			cout << "Calling default Parent constructor: " << x << endl;
		}
		ParentClass(int x) {
			cout << "Calling parent's one-var constructor with: " << x << endl;
		}
		~ParentClass() {  //Destructors also cannot have input arguments.
			cout << "Deleting parent class object." << endl;
		}
};


class ChildClass : public ParentClass {  //inherit everything possible from ParentClass.

	public:
		ChildClass():ParentClass(){
			cout << "Calling Child Class default constructor." << x << endl;
		}
		ChildClass(int x) : ParentClass(x){
			cout << "Calling Child Class non-default constructor with: "<< x << endl;
		}
		~ChildClass(){
			cout << "Deleting child class object."<< endl;
		}
};

int main() {
	ParentClass* pc1 = new ParentClass();
	ParentClass* pc2 = new ParentClass(377218);

	ChildClass* cc1 = new ChildClass();
	ChildClass* cc2 = new ChildClass(113);
}
