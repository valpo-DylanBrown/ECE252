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
	int registers[NUM_REGISTERS];
	int pc;
	int ram[MAX_MEMORY];
	//define inner variables for opcode, arg1, arg2
	//int instruction;
	int opcode;
	int arg1;
	int arg2;


	//********PRIVATE FUNCTION THAT I FOUND HELPFUL
	//updates the opcode, arg1, and arg2 based on the instruction
	// located at the current program counter
	// Note: constants here are hard-wired to be 3 digits
	void instructionDecode() {
		int tmp;
		int count = 0;
		int digit[3];
		tmp = ram[pc];
		if(tmp != 0){
			while(tmp > 0){
				digit[count] = tmp % 10;
				tmp/=10;
				count++;
			}
			opcode = digit[2];
			arg1 = digit[1];
			arg2 = digit[0];
		}
		else{
			opcode = 0;
			arg1 = 0;
			arg2 = 0;
		}



		cout << "OP: " << opcode << endl;
		cout << "Arg1: " << arg1 << endl;
		cout << "Arg2: " << arg2 << endl;
	}
	//******************************

	public:

	DataPath() {
		//initialize all values to zero
	for(int i =0; i<NUM_REGISTERS; i++){
		registers[i] = 0;
	}
	pc = 0;
	for(int i =0; i<MAX_MEMORY; i++){
		registers[i] = 0;
	}

	}
	void execute(){
		switch(opcode){
			case 0:
				cout << "HALT" << endl;
				break;
			case 1: //done
				cout << "GOTO" << endl;

				pc = arg1;
				break;
			case 2: // done
				cout << "LDI" << endl;
				registers[arg1] = arg2;
				pc++;
				break;
			case 3:
				cout << "ADD" << endl;
				registers[arg1] = registers[arg1] + registers[arg2];
				if(registers[arg1] >= MAX_VALUE){
					registers[arg1] = registers[arg1] % MAX_VALUE;
				}
				pc++;
				break;
			case 4:
				cout << "MULT" << endl;
				registers[arg1] = registers[arg1] * registers[arg2];
				if(registers[arg1] >= MAX_VALUE){
					registers[arg1] = registers[arg1] % MAX_VALUE;
				}
				pc++;
				break;
			case 5:
				cout << "LOAD" << endl;
				registers[arg1] = ram[arg2];
				if(registers[arg1] >= MAX_VALUE){
					registers[arg1] = registers[arg1] % MAX_VALUE;
				}
				pc++;
				break;
			case 6:
				cout << "STORE" << endl;
				ram[arg1] = registers[arg2];
				if(ram[arg1] >= MAX_VALUE){
					ram[arg1] = ram[arg1] % MAX_VALUE;
				}
				pc++;
				break;
			default:
				cout << "ERROR" << endl;
				pc++;
				break;
		}
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
		getMemory(pc);
		instructionDecode();

		// if the program has halted, do nothing
		execute();

	}


	// Returns the current value of the program counter
	int getPC() {
		return pc;
	}

	// Returns the code for the current instruction
	int getCurrentInstruction() { //need to make sure this doesnt loop over 1k
		if(pc >= MAX_MEMORY){
			pc = pc % MAX_MEMORY;
		}
		return ram[pc-1];
	}

	// Returns the value stored at Rx
	//  if x is not within range, x mod (number of registers)
	//  is returned
	int getRegister(int x) {
		if(x < NUM_REGISTERS){
			return registers[x];
		}
		else{
			return registers[x % NUM_REGISTERS];
		}
	}

	//returns the value stored at M[address]
	// if address is not in range, address mod (memory size) is
	// assumed
	int getMemory( int address) {
		if(address < MAX_MEMORY){
			return ram[address];
		}
		else{
			return ram[address % MAX_MEMORY];
		}
	}

	// stores value at M[address]
    // if address is not in range, address mod (memory size) is
    // assumed
    void loadMemory( int address, int data) {
			/*if(address < MAX_MEMORY){
				ram[address] = data;
			}
			else{
				ram[address % MAX_MEMORY] = data;
			}*/
			if(address >= MAX_MEMORY){
				address = address % MAX_MEMORY;
			}
			if(data >= MAX_VALUE){
				data = data % MAX_VALUE;
			}
			ram[address] = data;
	}


	// Returns true of the program has halted.
	bool isHalted() {
	if(pc !=0){
		if(opcode == 0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
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
	cpu->print();
	cout << endl << endl;


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
		//cout << "Halt status: " << cpu->isHalted() << endl;
		cpu->step();
		cout << "Issuing Step Command:" << endl;
		cpu->print();
	}

	return 0;
}
