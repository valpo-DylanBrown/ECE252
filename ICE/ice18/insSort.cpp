#include <iostream>
#define LENGTH 12
using namespace std;


void swap(int &x, int &y){
  int tmp = x;
  x = y;
  y = tmp;
}
void printArray(int array[LENGTH]){
  for(int i =0; i<LENGTH; i++){
      cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[LENGTH], int length){
  int count = 0;
  for(int i=1; i < length; i++){
    //count++;
    //if(count%10 == 0){
      printArray(array);
    //}
    for(int j=i; j>0 && array[j] < array[j-1];  j--){
      swap(array[j], array[j-1]);
    }
  }
}

void fillRandom(int array[LENGTH]){
  for(int i=0; i<100; i++){
    array[i] = rand() % 1000;
  }
}

int main(){
  srand(20);
  /*int dataRand[LENGTH];
  fillRandom(data);
  int data[LENGTH] = {3, 9, 10, 2, 18, 29, 1, 9, 11, 20};*/
  //printArray(data);
  int data1[LENGTH];
  for(int i=0; i<LENGTH; i++){
    data1[i] = i+1;
  }
  int data2[LENGTH];
  for(int i=LENGTH; i>0; i--){
    data2[LENGTH-i] = i;
  }
  insertionSort(data1, LENGTH);
  printArray(data1);
  cout << endl;
  insertionSort(data2, LENGTH);
  printArray(data2);

}



/* OUTPUT

* 10-Array | Insertion sort
3 9 10 2 18 29 1 9 11 20
3 9 10 2 18 29 1 9 11 20
3 9 10 2 18 29 1 9 11 20
2 3 9 10 18 29 1 9 11 20
2 3 9 10 18 29 1 9 11 20
2 3 9 10 18 29 1 9 11 20
1 2 3 9 10 18 29 9 11 20
1 2 3 9 9 10 18 29 11 20
1 2 3 9 9 10 11 18 29 20
1 2 3 9 9 10 11 18 20 29

* 100-Array | Insertion Sort
4c-32-75-9c-9c-29:ice18 dylan$ ./a.out
49 130 140 149 337 534 686 755 852 880 271 830 488 840 93 590 129 580 271 593 884 969 63 494 848 190 333 149 144 642 294 815 5 340 142 778 816 275 287 891 752 147 802 15 289 253 796 821 645 964 315 237 572 645 831 859 657 921 954 413 794 850 510 598 727 237 305 513 914 13 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
49 93 129 130 140 149 271 271 337 488 534 580 590 593 686 755 830 840 852 880 884 969 63 494 848 190 333 149 144 642 294 815 5 340 142 778 816 275 287 891 752 147 802 15 289 253 796 821 645 964 315 237 572 645 831 859 657 921 954 413 794 850 510 598 727 237 305 513 914 13 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
49 63 93 129 130 140 144 149 149 190 271 271 333 337 488 494 534 580 590 593 642 686 755 830 840 848 852 880 884 969 294 815 5 340 142 778 816 275 287 891 752 147 802 15 289 253 796 821 645 964 315 237 572 645 831 859 657 921 954 413 794 850 510 598 727 237 305 513 914 13 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
5 49 63 93 129 130 140 142 144 149 149 190 271 271 275 287 294 333 337 340 488 494 534 580 590 593 642 686 755 778 815 816 830 840 848 852 880 884 891 969 752 147 802 15 289 253 796 821 645 964 315 237 572 645 831 859 657 921 954 413 794 850 510 598 727 237 305 513 914 13 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
5 15 49 63 93 129 130 140 142 144 147 149 149 190 253 271 271 275 287 289 294 333 337 340 488 494 534 580 590 593 642 645 686 752 755 778 796 802 815 816 821 830 840 848 852 880 884 891 964 969 315 237 572 645 831 859 657 921 954 413 794 850 510 598 727 237 305 513 914 13 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
5 15 49 63 93 129 130 140 142 144 147 149 149 190 237 253 271 271 275 287 289 294 315 333 337 340 413 488 494 534 572 580 590 593 642 645 645 657 686 752 755 778 796 802 815 816 821 830 831 840 848 852 859 880 884 891 921 954 964 969 794 850 510 598 727 237 305 513 914 13 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
5 13 15 49 63 93 129 130 140 142 144 147 149 149 190 237 237 253 271 271 275 287 289 294 305 315 333 337 340 413 488 494 510 513 534 572 580 590 593 598 642 645 645 657 686 727 752 755 778 794 796 802 815 816 821 830 831 840 848 850 852 859 880 884 891 914 921 954 964 969 490 91 465 614 830 457 614 73 795 675 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
5 13 15 49 63 73 91 93 129 130 140 142 144 147 149 149 190 237 237 253 271 271 275 287 289 294 305 315 333 337 340 413 457 465 488 490 494 510 513 534 572 580 590 593 598 614 614 642 645 645 657 675 686 727 752 755 778 794 795 796 802 815 816 821 830 830 831 840 848 850 852 859 880 884 891 914 921 954 964 969 948 586 580 609 341 136 42 22 727 961 172 578 571 170 923 968 144 388 525 704
5 13 15 22 42 49 63 73 91 93 129 130 136 140 142 144 147 149 149 190 237 237 253 271 271 275 287 289 294 305 315 333 337 340 341 413 457 465 488 490 494 510 513 534 572 580 580 586 590 593 598 609 614 614 642 645 645 657 675 686 727 727 752 755 778 794 795 796 802 815 816 821 830 830 831 840 848 850 852 859 880 884 891 914 921 948 954 961 964 969 172 578 571 170 923 968 144 388 525 704
5 13 15 22 42 49 63 73 91 93 129 130 136 140 142 144 144 147 149 149 170 172 190 237 237 253 271 271 275 287 289 294 305 315 333 337 340 341 388 413 457 465 488 490 494 510 513 525 534 571 572 578 580 580 586 590 593 598 609 614 614 642 645 645 657 675 686 704 727 727 752 755 778 794 795 796 802 815 816 821 830 830 831 840 848 850 852 859 880 884 891 914 921 923 948 954 961 964 968 969

* 12's | Insertion sort
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6 7 8 9 10 11 12

12 11 10 9 8 7 6 5 4 3 2 1
11 12 10 9 8 7 6 5 4 3 2 1
10 11 12 9 8 7 6 5 4 3 2 1
9 10 11 12 8 7 6 5 4 3 2 1
8 9 10 11 12 7 6 5 4 3 2 1
7 8 9 10 11 12 6 5 4 3 2 1
6 7 8 9 10 11 12 5 4 3 2 1
5 6 7 8 9 10 11 12 4 3 2 1
4 5 6 7 8 9 10 11 12 3 2 1
3 4 5 6 7 8 9 10 11 12 2 1
2 3 4 5 6 7 8 9 10 11 12 1
1 2 3 4 5 6 7 8 9 10 11 12
*/
