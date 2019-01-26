#include <iostream>
using namespace std;
 
int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of long long : " << sizeof(long long) << endl;
   return 0;
}


/* on server
Linux tesla 4.14.12-x86_64-linode92 #1 SMP Fri Jan 5 15:34:44 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux

jwill@tesla:~$ ./a.out
Size of char : 1
Size of int : 4
Size of short int : 2
Size of long int : 8
Size of float : 4
Size of double : 8
Size of long long : 8
*/

/* on MinGW32
$ ./sizeof.exe
Size of char : 1
Size of int : 4
Size of short int : 2
Size of long int : 4
Size of float : 4
Size of double : 8
Size of long long : 8
*/

// Arduino
// int -- 2 bytes (16 bits) 
// long -- 4 bytes
