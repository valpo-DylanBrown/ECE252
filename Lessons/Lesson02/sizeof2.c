#include <stdio.h>
int main()
{
    

    // Sizeof operator is used to evaluate the size of a variable
    printf("Size of short: %ld bytes\n",sizeof(short));
	printf("Size of int: %ld bytes\n",sizeof(int));
    printf("Size of float: %ld bytes\n",sizeof(float));
    printf("Size of double: %ld bytes\n",sizeof(double));
    printf("Size of char: %ld byte\n",sizeof(char));
    printf("Size of long: %ld bytes\n",sizeof(long));
	printf("Size of long long: %ld bytes\n",sizeof(long long));
	
    return 0;
}