#include<stdio.h>

//!  Buradaki mevzu pointerlarýn array yerine kullanýlabilmesi

void add_one(int *array,int length);

int main(){

    int a[]={1,2,3,4,5,6,7,8,9,10};
    
    add_one(a+5,5);
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("\n-------------------\n");
/*------------------------------------------------------------------------*/
    int b[]={1,2,3};
    int *p;
    p=b;   //! b array'ini gösteren bir pointer tanýmladýk
           //! b=p; gibi bir gösterim yapamayýz

//?              address    value   
//? index 0        55        1
//? index 1        56        2
//? index 2        57        3
//?
//?     p          58        55
    
    printf("%d\n",p[0]);  //* array notation ile gösterebileceðimiz bir deðeri pointer notation ile gösterdik
    
    printf("p: %p\n",p);
    printf("b: %p\n",b);

    printf("p[2]=%d\n",p[2]);
    printf("b[2]=%d\n",b[2]);

    printf("*(p+1)= %d\n",*(p+1));  //* normalde p, b arrayinin baþlangýcýyla baþladý ama +1 ile p=1 oldu
    printf("*(p+2)= %d\n",*(p+2));
    
    printf("*(b+1)= %d\n",*(b+1));
    printf("*(b+2)= %d\n",*(b+2));

    return 0;
}


void add_one(int *array,int length){
    for (int i = 0; i < length; i++)
    {
        array[i] +=1;
    }
        


}