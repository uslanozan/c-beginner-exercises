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


void add_one(int array[],int length){  //* bu method array içindeki sayýlarý 1 arttýrarak a'yý modifiye eder

    printf("array: %p\n",array);       //? output'ta a array'inin adresinin deðiþmediðini görüyoruz. Array'e ayrýlan
    for (int i = 0; i < length; i++)   //? alandaki adres deðiþmez içi deðiþse de.
    {
        array[i] +=1;
    }
    

}