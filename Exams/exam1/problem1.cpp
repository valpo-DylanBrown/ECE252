#include <iostream>
using namespace std;

int ninePow(int n){
  if(n == 0){
    return 1;
  }
  return 9*ninePow(n-1);
}

int main(){
  cout << "welcome: " << endl << endl;
  int n;
  n = 20;
  cout << "9^" << n << "= " << ninePow(n) << endl;

}
