#include <iostream>
using namespace std;



class Bag {
	private:
	int contents[1000];
	int size;
	
	public:
	bool add(int num);
	bool remove(int num);
	Bag();
	int getSize(); // number of items in bag 
	bool contains(int x); //asks if bag contains the argument
	bool isEmpty();
	
};

Bag::Bag(){
	size = 0;
}

bool Bag::add(int num){
	if(num >= 0){
		contents[size] = num;
		size++;
		return true;
	}
	return false;
	
}
bool Bag::remove(int num){
	/*for(int i = 0; i< size; i++){
		if(num == contents[i]){
			//take out contents[i]
			for(int j = i; i < size; j++){
				contents[j] = contents[j+1];
			}
			cout << "Before size call: " << size << endl;
			size--;
			cout << "Found it:" << num << " size is:" << size << endl;
			return true;
		}
	}*/
	for(int i=0; i!=num; i++){
		for(;i<size; i++){
			contents[i] =contents[i+1];
		}
		size--;
		return true;
	}
	return false;
}

int Bag::getSize(){
	return size;
}

bool Bag::contains(int x){
	for(int i = 0; i<= size; i++){
		if(x == contents[i]){
			return true;
		}
	}
	return false;
}

bool Bag::isEmpty(){
	if(size ==0){
		return true;
	}
	else{ return false;}
}
int main(){
	Bag* one = new Bag();
	cout << "*******Welcome to Your Bag*******" << endl << endl;
	if(one->isEmpty()){
		cout << "Empty bag"<< endl;
	}
	else{
		cout << "Poop!"<<endl;
	}
	cout <<"Adding Item 6023" <<endl;
	one->add(6023);
	cout << "Size: " << one->getSize() << endl;
	cout << "6023? | ";
	if(one->contains(6023)){
		cout<< "The bag contains 6023" << endl;
	}
	else cout << "Nope" << endl;
	cout <<"Adding Item n n times" <<endl;
	for(int i = 1; i<=25; i++){
		for(int j = 0; j<i; j++){
			one->add(i);
		}
	}
	cout << "Removing" << endl;
	if((one->remove(1))) cout << "Removed" <<endl;
	else cout << "Not Removed, is the element there?" << endl;
	cout << "Checking" << endl;
	if(one->contains(1))cout<< "The bag contains 1" << endl;
	else cout << "Nope, 1 is not in the bag" << endl;
	cout << "Removing" << endl;
	if((one->remove(1))) cout << "Removed" <<endl;
	else cout << "Not Removed, is the element there?" << endl;
	cout << "Checking" << endl;
	if(one->contains(1))cout<< "The bag contains 1" << endl;
	else cout << "Nope, 1 is not in the bag" << endl;
	cout << "Removing" << endl;
	if((one->remove(2))) cout << "Removed" <<endl;
	else cout << "Not Removed, is the element there?" << endl;
	cout << "Checking" << endl;
	if(one->contains(2))cout<< "The bag contains 2" << endl;
	else cout << "Nope, 2 is not in the bag" << endl;
	cout << "Removing" << endl;
	if((one->remove(2))) cout << "Removed" <<endl;
	else cout << "Not Removed, is the element there?" << endl;
	cout << "Checking" << endl;
	if(one->contains(2))cout<< "The bag contains 2" << endl;
	else cout << "Nope, 2 is not in the bag" << endl;
	cout <<"Adding Item n until full" <<endl;
	for(int i=1; one->getSize()!=1000; i++){
		one->add(i);
		if(one->getSize() == 999) cout << "Filled at: " << i << endl;
	}
	cout << "Size: " << one->getSize() << endl;
	
}
