#include<stdio.h>

void add_one(int array[],int length);



int main(){

    int a[]={2,4,9,1,3,5};

    printf("a: %p\n",a); 

    add_one(a,6);
    for (int i = 0; i < 6; i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
    



    return 0;
}


void add_one(int array[],int length){  //* bu method array i�indeki say�lar� 1 artt�rarak a'y� modifiye eder

    printf("array: %p\n",array);       //? output'ta a array'inin adresinin de�i�medi�ini g�r�yoruz. Array'e ayr�lan
    for (int i = 0; i < length; i++)   //? alandaki adres de�i�mez i�i de�i�se de.
    {
        array[i] +=1;
    }
    

}