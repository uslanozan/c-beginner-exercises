#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main ( void ){

    bool b;
    char c;
    int i;
    double r;
    int arr[10];


    printf("The size of int is:%ld\n",sizeof(i));
    printf("The size of bool is:%ld\n",sizeof(b));
    printf("The size of char is:%ld\n",sizeof(c));
    printf("The size of double is:%ld\n",sizeof(r));

    /* for more info, https://en.wikipedia.org/wiki/Data_structure_alignment*/
    return 0;

    printf("The address of the bool is:%ld\n",&b);
    printf("The address of the char is:%ld\n",&c);
    printf("The address of the int is:%ld\n",&i);
    printf("The address of the arr is:%ld\n",&arr);
    printf("The address of the arr[1] is:%ld\n",&arr[1]);

}