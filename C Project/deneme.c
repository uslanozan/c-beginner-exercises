#include<stdio.h>

int main(){

    int a[3]={1,3};

    
    printf("%d\n",&a[0]);
    printf("%d\n",&a[1]);
    printf("%d\n",&a[2]);
    printf("%d\n",&a[4]);
    printf("%d\n",&a[5]);
    printf("%d\n",&a[6]);
    printf("%d\n",&a[7]);
    printf("%d\n",&a[8]);
    printf("%d\n",&a[9]);
    printf("%d\n",&a[10]);
    printf("%d\n",&a[11]);
    printf("\n----------------------------\n");
    
    printf("%d\n",&a[0]);
    printf("%d\n",&a[1]);
    printf("%d\n",&a[2]);
    printf("%d\n",a[2]);
    printf("%d\n",&a[3]);
    printf("%d\n",&a[4]);
    printf("%d\n",&a[5]);
    printf("%d\n",a[5]*3);



    return 0;
}