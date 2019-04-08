//*********************************
//DataPath   JDW
//
// Implements simple datapath
//
//**********************************

//*******************
//
// ISA:
//
// 0: STOP
// 1: GOTO #n
// 2: LDI  Rd, #n
// 3: ADD  Rd, Rs
// 4: MULT Rd, Rs
//
// to be implemented later:
//
// 5: LOAD  Rd, M[Rs]
// 6: STORE M[Rd], Rs
//
//***********************
#define NUM_REGISTERS 10
#define MAX_MEMORY 1000
#define MAX_VALUE 1000

#include <iostream>
using namespace std;

class DataPath {
	
	private:

	//member data - the register file, PC, RAM


	//define inner variables for opcode, arg1, arg2



	//********PRIVATE FUNCTION THAT I FOUND HELPFUL
	//updates the opcode, arg1, and arg2 based on the instruction
	// located at the current program counter
	// Note: constants here are hard-wired to be 3 digits
	//void instructionDecode() {
	//}
	//******************************
	
	public:
	
	DataPath() {
		//initialize all values to zero
	
	
	}
	// step() executes the current instruction and
	// loads the program counter with the address of
	// the next instruction.
	// Changes state of register file and memory as appropriate
	//
	// If the program has halted on a previous instruction,
	// step() has no effect.  If HALT is encountered, PC is
	// not updated
	void step() {
		
		// if the program has halted, do nothing
	
	
	}
	

	// Returns the current value of the program counter
	int getPC() {

	}
	
	// Returns the code for the current instruction
	int getCurrentInstruction() {

	}

	// Returns the value stored at Rx
	//  if x is not within range, x mod (number of registers)
	//  is returned
	int getRegister(int x) {

	}
	
	//returns the value stored at M[address]
	// if address is not in range, address mod (memory size) is
	// assumed
	int getMemory( int address) {

	}

	// stores value at M[address]
    // if address is not in range, address mod (memory size) is
    // assumed
    void loadMemory( int address, int data) {

	}
	
	
	// Returns true of the program has halted.
	bool isHalted() {

	}

	void print() {

		cout << "System Status:\n";
		
		//print each register, 5 to a line.
		for (int i=0; i<NUM_REGISTERS; i++) {
			cout << "R" << i << ": " << getRegister(i) << "\t";
			if ((i+1)%5 == 0) cout << "\n";
		}

		//if we don't have a multiple of 5 registers, add endln
		if ((NUM_REGISTERS%5) != 0) cout << "/n";

		cout << "PC: " << getPC() << "\t";
		cout << "M[PC]: " << getCurrentInstruction() << "\n\n";
		
	}


};

int main() {

	int numInstr, tmpInstr;
	cout << "Datapath Simulator"  << endl;
	cout << "Implements Stop->Mult" << endl << endl;
	
	DataPath* cpu = new DataPath();
	
	cout << "Instruction Loading..."  << endl;
	
	cout << "Enter in # of Instructions to Load: ";
	cin >> numInstr;
	
	cout << "Enter in 3-digit instructions, one per line: ";
	
	for (int i=0; i<numInstr; i++) {
		cin >> tmpInstr;
		cpu->loadMemory(i, tmpInstr);
	}
	
	cout << "Initializing Datapath...." << endl;
	cout << "Datapath initial state:" << endl;
	cpu->print();
	cout << endl << endl;
	
	while (!cpu->isHalted()) {
		cpu->step();
		cout << "Issuing Step Command:" << endl;
		cpu->print();
	}
	
	return 0;
}