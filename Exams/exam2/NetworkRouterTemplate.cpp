#include <iostream>
using namespace std;

class NetworkPacket {
	
	private:
		bool isPriority;
		char payload;
	public:
		char getPayload() { return payload; }
		bool getPriority() {return isPriority; }
		NetworkPacket(char newPayload, bool newPriority) {
			isPriority = newPriority;
			payload = newPayload;
		}
};


class NetworkRouter {

//your code goes here...

	
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
	cout << endl;
	
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