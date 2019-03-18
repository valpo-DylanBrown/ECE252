#include "CharStack.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  CharStack myStack;
  myStack.push('c');
  myStack.push('a');
  myStack.push('t');

  cout << myStack.pop() << endl;
  cout << myStack.pop() << endl;
  cout << myStack.pop() << endl;
}
