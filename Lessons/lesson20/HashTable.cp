#include <iostream>
using namespace std;

#define TABLE_LENGTH 100  
//#define TABLE_LENGTH 137  //should be a prime number.

class Student {

	private:
		string name;
		int ID;
		string address;
	public:
		Student() { name = ""; ID = 0; address = "";}
		Student( string newName, int newID, string newAddress) { name = newName; ID = newID; address = newAddress;}
		int getID() {return ID;}
		void print() { cout << name << ", " << ID << ", " << address << endl; }
		
};


class HashTable {
	
	private:
		Student* data[TABLE_LENGTH];
	
		int hashIndex(int x) {
			//x = ((x >> 16) ^ x) * 0x45d9f3b;
			//x = ((x >> 16) ^ x) * 0x45d9f3b;
			//x = ((x >> 16) ^ x);
			return x%TABLE_LENGTH;
		}
		
	public:
		HashTable() {
			for (int i=0; i<TABLE_LENGTH; i++) {
				data[i] = NULL;  //set all pointers to NULL
			}
		}
		
		// inserts a new student record to the table
		void insert (Student* newStudent);
		
		// returns the record if found, returns NULL if not
		Student* find (int ID);
		
		void printData () {
			for (int i=0; i<TABLE_LENGTH; i++) {
				if (data[i] != NULL) {
					cout << "Index[" << i << "]: "; 
					data[i]->print();
				}
			}
		}
};

void HashTable::insert(Student* newStudent) {
	int key = hashIndex(newStudent-> getID());
	while (data[key] != NULL){  //find first available table entry
		key++; //linear probing
		key=key%TABLE_LENGTH;  //Deal with wrap-around.
	}
	data[key] = newStudent;   //fill that entry.
}

Student* HashTable::find (int ID) {
	int key = hashIndex(ID);
	
	while (data[key] !=NULL) { //searching all contiguous data beginning at key. 
		if (data[key] -> getID() == ID) return data[key];  //it's a hit!
		key++;
		key = key % TABLE_LENGTH;
	}
	return NULL;  //it's a miss.
}

//Helper function for main--it does not belong to HashTable
void searchRecord(int ID, HashTable* table) {
	Student* searchResult;
	searchResult = table->find(ID);
	cout << "Results for ID: " << ID << " ";
	if (searchResult == NULL) cout << "Not Found" << endl;
	else searchResult->print();
}

int main () {

	Student* studentList[20];

	studentList[0] = new Student("Carol Seaver", 123435, "156 Hemdale");
	studentList[1] = new Student("Dale Evans", 129833, "243 Mayfield");
	studentList[2] = new Student("Jane Ace", 382723, "382 Laporte");
	studentList[3] = new Student("Abby Adams", 392123, "392 Redfield");
	studentList[4] = new Student("Louis Bianco", 382901, "293 Lonely Street");
	studentList[5] = new Student("Tim Douglas", 392829, "298 Labene Dr.");
	studentList[6] = new Student("Rick Grimes", 349284, "283 Chapel Dr.");
	studentList[7] = new Student("Beth Anders", 329283, "287 Redmond Ave.");
	studentList[8] = new Student("Fred Edgers", 348291, "283 3rd St.");
	studentList[9] = new Student("Amy Adams", 372983, "293 LaBrea Ave.");
	studentList[10] = new Student("Shiver Timbers", 382199, "928 Wilson Dr.");
	studentList[11] = new Student("Scott Duncan", 348799, "207 GEM");
	studentList[12] = new Student("Joe Henry", 839299, "392 Greendale");
	studentList[13] = new Student("Theo Huxtable", 283799, "10 Leroy St.");
	studentList[14] = new Student("Marla Gibbs", 227899, "227 Wolf St.");
	
	int addLimit = 14;  //to be changed during testing.
	
	HashTable* myTable = new HashTable();

	for (int i = 0; i<addLimit; i++) {
		myTable->insert(studentList[i]);
	}
	
	myTable->printData();
	
	searchRecord(123435, myTable);
	searchRecord(993822, myTable);
	searchRecord(329283, myTable);
	searchRecord(382901, myTable);
	searchRecord(329823, myTable);
	searchRecord(382723, myTable);
	
	
	
	return 0;
}