#ifndef QUEUE_H
#define QUEUE_H

#define MAXSIZE 100

class QArray {

	private:
		int element[MAXSIZE];  //Contents of the queue
		int size; 				//How many valid numbers are in queue.

	public:
		QArray();				//Default constructor
		bool enqueue(int j);	//Return true if successful, false if not.
		int dequeue();			//Return oldest value in queue.
		int getSize();			//Returns size (# valid ints in the queue)
		int getFirst();			//Return the newest data in queue.
		bool isEmpty();			//Returns true if queue empty, false otherwise.

};

#endif
