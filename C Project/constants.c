#include<stdio.h>
#include<stdlib.h>

//* #define NAME 5

int x=10;
//! Bu þekilde global variable tanýmlamak çok risklidir çünkü eðer bunu deðiþtirirsek program saçmalayabilir


void func();

int main(int argc, char const *argv[])
{
    
    //? const int x=5;
    //? x=3; yapamayýz
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