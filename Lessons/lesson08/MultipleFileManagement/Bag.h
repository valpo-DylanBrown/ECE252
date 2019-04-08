class Bag {

	protected:
	int data[1000];
	int size;

	public:

	Bag();



	//adds the element j to the Bag.  Returns true if
	//successfully added, false if the Bag was full.
	bool add(int j);

	// returns true if j is contained in the Bag, false o.w.
	bool contains( int j );

	// removes one instance of j from the Bag.  Returns true
	// if an element is removed, false if the element was not
	// contained in the Bag
	bool remove (int j);

	// returns the number of elements stored in the Bag
	int getSize () { return size; }

	// returns true if there are no elements in the Bag
	bool isEmpty () { return size==0; }



};
