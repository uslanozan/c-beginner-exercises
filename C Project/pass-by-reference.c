#include<stdio.h>

/* pass*by-pointer diye de bilinir */

void add_one(int *a);
void add_one2(int *a,int *b,int *c);


int main(){

    int b=5;
    printf("&b: %p\n", &b);
    add_one(&b);
    printf("b: %d\n",b);

    printf("\n--------------------\n");

    int x1=1,x2=2,x3=3;
    add_one2(&x1,&x2,&x3);
    printf("x1: %d\n",x1);
    printf("x2: %d\n",x2);
    printf("x3: %d\n",x3);

    return 0;
}

//?
//?     Variables      Address     Value
//?       b(int)           72        5
//?       a(pointer)       73       72           
//?


void add_one(int *a){
    printf(" a: %p\n",a);
    *a=*a+1;
}

void add_one2(int *a,int *b,int *c){
    *a = *a + 1;
    *b = *b + 1;
    *c = *c + 1;

}
