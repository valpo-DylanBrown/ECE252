#include <iostream>
using namespace std;
int main( int argc, char *argv[]) {
  int n, i, first =0, second =1, nextTerm;

  cout << "Enter number of terms: ";
  cin >> n;

  for (i=1; i<n; i++){
//    if(i<=1){nextTerm = i;}
    nextTerm = first + second;
    first = second;
    second = nextTerm;
    //cout << nextTerm << endl;
  }
  cout << "Answer: " << nextTerm << endl;

}
