#include "QueueSkeleton.h"
#include <iostream>
using namespace std;


int main(void)
{
	QArray * myQ = new QArray();

	myQ -> enqueue(5);
	myQ -> enqueue(7);
	myQ -> enqueue(9);
	myQ -> enqueue(11);

	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;

	myQ -> enqueue(15);
	myQ -> enqueue(5);
	myQ -> enqueue(35);

	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;

	for (int i=0; i<2000; i++){
		myQ -> enqueue(i);
		myQ -> dequeue();
	}

	myQ -> enqueue(15);
	myQ -> enqueue(5);
	myQ -> enqueue(35);

	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;
	cout << "DQ:" << myQ -> dequeue()<< endl;

}
