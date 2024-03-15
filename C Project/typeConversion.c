#include<stdio.h>

int main(int argc, char const *argv[])
{
    
    //? (type) expression
    //?
    
    int a=5;
    int b=2;

    double c=(double)a /b;

    printf("%d/%d=%d\n",a,b,a/b);
    printf("%d/%d=%.2f\n",a,b,(double)((double)a /b));
    printf("%d/%d=%.2f\n",a,b,c);






    return 0;
}
