#include "Bag.h"

Bag::Bag() {
	size = 0;
}

bool Bag::remove( int j) {
	for (int i=0; i<size; i++) {
		if (data[i] == j) {
			for (int k=i; k<size-1; k++) {
				data[k] = data[k+1];
			}
			size--;
			return true;
		}
	}
	return false;
}

bool Bag::add(int j) {




	if (size == 1000) return false;

	data[size] = j;
	size++;
	return true;
}

bool Bag::contains(int j) {
	for (int i=0; i<size; i++) {
		if (data[i] == j) return true;
	}
	return false;
}
