#include <iostream>
using namespace std;

class NetworkPacket {

	private:
		bool isPriority;
		char payload;
		NetworkPacket* next;
		NetworkPacket* prev;
	public:
		char getPayload() { return payload; }
		bool getPriority() {return isPriority; }
		NetworkPacket(char newPayload, bool newPriority) {
			isPriority = newPriority;
			payload = newPayload;
		}
		NetworkPacket* getNext() { return next; }
		NetworkPacket* getPrev() { return prev; }
		void setPayload (char x) { payload = x; }
		void setNext (NetworkPacket* nextPacket) { next = nextPacket; }
		void setPrev (NetworkPacket* prevPacket) { prev = prevPacket; }

};


class NetworkRouter {
private:
	NetworkPacket* front;
	int size;
public:
	NetworkRouter(){
		front = NULL;
		size = 0;
	}
	void receivePacket(NetworkPacket* x){
		NetworkPacket* tmp;
		//check if the ffront is NULL or if the incoming packet is a priority
		if(front == NULL || (x->getPriority() == true && front->getPriority() == false)){
			x->setNext(front);
			front = x;
		}
		else{
			tmp = front; //start at beginning
			if(x->getPriority() == true){ //find the end of the trues
				while(tmp->getNext() != NULL && tmp->getNext()->getPriority() == true){
					tmp = tmp->getNext(); //keep looking until you find it
				}
				x->setNext(tmp->getNext()); //set x's next to the next element
				tmp->setNext(x); //set tmp's next to x now
			}
			else{
				while(tmp->getNext() != NULL){ //if its false put it at the end
					tmp = tmp->getNext();
				}
				x->setNext(tmp->getNext());
				tmp->setNext(x);
			}
		}
		size++;
	}
	NetworkPacket* sendPacket(){ //aka dequeue
		NetworkPacket* tmp; //packet to return
		if(front == NULL){ //if the front is empty
			cout << "Queue Empty. Nothing to remove";
			return NULL;
		}
		tmp = front; //set tmp to front
		front = front->getNext(); //move forward
		size--;
		return tmp; //return out tmp

	}
	bool isEmpty(){
		return (size == 0);
	}
	/* //for debugging
	void print(){
		NetworkPacket* tmp;
		tmp = front;
		if(front == NULL){
			cout << "Queue empty" << endl;
		}
		else{
			while(tmp!=NULL){
				cout << tmp->getPayload() <<" ";
				tmp = tmp->getNext();
			}
		}
		cout << endl;
	}*/

};

char randomLetter() {
	static int seed = 123;

	seed = seed*35573%57 + 65;
	char val = seed;
	return val;
}


int main () {

	//try just a few packets...

	NetworkRouter* testRouter = new NetworkRouter();

	testRouter->receivePacket(new NetworkPacket('h', false));
	testRouter->receivePacket(new NetworkPacket('a', false));
	testRouter->receivePacket(new NetworkPacket('m', false));
	testRouter->receivePacket(new NetworkPacket('H', true));
	testRouter->receivePacket(new NetworkPacket('A', true));
	testRouter->receivePacket(new NetworkPacket('M', true));


	cout << "Easy Test" << endl;
	for (int i=0; i<6; i++) {
		cout << testRouter->sendPacket()->getPayload();
	}
	cout << endl;

	//more rigorous test
	// reset the router
	delete testRouter;
	testRouter = new NetworkRouter();

	//start adding a-z, capitals are high priority
	char lowPacket = 'a';
	char highPacket = 'A';

	for (int i=0; i<13; i++) {
		testRouter->receivePacket(new NetworkPacket	(lowPacket++,false));
	}
	for (int i=0; i<13; i++) {
		testRouter->receivePacket(new NetworkPacket	(highPacket++,true));
		testRouter->receivePacket(new NetworkPacket	(lowPacket++,false));
	}

	cout << endl << "Medium Test" << endl;
	for (int i=0; i<13; i++) {
		testRouter->receivePacket(new NetworkPacket	(highPacket++,true));
		cout << testRouter->sendPacket()->getPayload() << " ";
	}

	while (!testRouter->isEmpty()) {
		cout << testRouter->sendPacket()->getPayload() << " ";
	}
	cout << endl;

	//mother of all tests
	// this adds 1000 packets to the router.  It randomly fills in packets,
	// but will always add the same packets every time you run the program.
	//It is suggested that you test your router fully with deterministic letters, or print out several
	// of your own inputs-outputs in testing to check.  Remember, this should dump all the high-priority
	// packets first, in order that they came in.

	// reset the router
	delete testRouter;
	testRouter = new NetworkRouter();

	bool isPriority;
	int rollingNumber = 7;
	for (int i=0; i<1000; i++) {
		rollingNumber = rollingNumber*283%1000;
		isPriority = (rollingNumber < 150);
		testRouter->receivePacket(new NetworkPacket	(randomLetter(),isPriority));
		//cout << isPriority;
	}
	cout << endl << "Full Test" << endl;

	//print out the first 25 chars
	for (int i = 0; i<25; i++) {
		cout << testRouter->sendPacket()->getPayload() << " ";
	}
	cout << endl;

	//empty out 700 elements of the queue;
	for (int i = 0; i<700; i++) {
		testRouter->sendPacket()->getPayload();
	}

	//look at next 25 packets (should be 725-750)
	for (int i = 0; i<25; i++) {
		cout << testRouter->sendPacket()->getPayload() << " ";
	}
	cout << endl;

	return 0;

}

/*
**OUTPUT**
4c-32-75-9c-9c-29:exam2 dylan$ ./a.out
Easy Test
HAMham

Medium Test
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n
o p q r s t u v w x y z

Full Test
H n b S n b Q u Z c H f w n w H f S P w S P Z c N
b H S Q G N q u P B n f w Z t K c H S Q G N q P B
*/
