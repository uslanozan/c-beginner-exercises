#include<stdio.h>
#include<stdlib.h>

//* #define NAME 5

int x=10;
//! Bu �ekilde global variable tan�mlamak �ok risklidir ��nk� e�er bunu de�i�tirirsek program sa�malayabilir


void func();

int main(int argc, char const *argv[])
{
    
    //? const int x=5;
    //? x=3; yapamay�z
    int x=2;
    printf("x: %d\n",x);
    x++;
    func();
    return 0;
}

void func(){
    x++;
    printf("x: %d\n",x);
}