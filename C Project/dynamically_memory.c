#include<stdio.h>
#include<stdlib.h>

//! malloc, calloc, realloc ve free dinamik bellek y�netimini sa�layan fonksiyonlard�r ve #include<stdlib.h> ile gelir


//*  Stack
//*  
//*  Variable    Address    Value
//*  a             12         5
//*  b             13         6
//*                14
//*                15
//*                ..
//*                ..
//*                .. 
//*                ..
//*                ..
//*   a[0]         16         55
//*   a[1]         17         67
//*   a[2]         18         14
//*    ..          19         22
//*  heap


int main(){

    int *a;

    a=malloc( sizeof(int)*5);  //? dinamik bellek tahsis etmek i�in kullan�l�r. �stenen bellek boyutu kadan alan byte olarak
    //? malloc() fonksiyonu tahsis edilmi� belle�in BA�LANGICINI g�steren bir pointer geri verir.
    //? a=calloc(5,sizeof(int));  ile de ayn� �eyi yapabilirdik 
    //? calloc() eleman say�s�n� ve eleman boyutunu parametre olarak vermemiz laz�m
    //? Buradaki �nemli fark malloc ile ay�rd���m�zda bellekte farkl� de�erler olabilir (�stte yazd���m a[0] value'lar� gibi)
    //? Ama calloc ile ay�rd���m�zda i�indeki de�erleri 0 yapar yani atanmam�� de�er olur
    a[0]=1;
    a[1]=5;
    a[2]=7;
    a[3]=9;
    a[4]=11;

    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    
    free(a);  //? �nceden ayr�lm�� bir alan� bo�a ��kar�rs�n
              //? C'de garbage collector olmad���ndan memory control �nemlidir

    printf("\n---------------------------\n");

    int *numbers;
    int size=2;  //* Ba�lang��ta tahsis edilen bellek boyutu
    numbers=malloc(sizeof(int)*size);
    int input=0,i=0;

    do
    {   
        if (i==size)  //* Bellek boyutu dolarsa
        {
            size +=2;  //* Bellek boyutunu 2 art�r
            numbers = realloc(numbers,sizeof(int)*size);  //* Belle�i yeniden boyutland�r�r
            printf("Realloc for %d ints\n",size);
        }             //? realloc b�t�n de�erleri kopyalay�p yeni bir memory'e atar, memory'i geni�letir
        

        printf("Enter (-1 to quit):");
        scanf("%d",&input);
        if (input != -1)   
        {                       //* -1 girmedi�imiz s�rece de�erleri array'e ekler
            numbers[i]=input;
            i++;
        }
        
    } while (input != -1);
    
    int num_elements=i;
    int total=0;

    for (int j = 0; j < num_elements; j++)
    {
        total+=numbers[j];
    }
    
    printf("average: %d\n",total / num_elements);  //* Girdi�imiz say�lar�n ortalamas�n� al�r

    free(numbers);  //* Belle�i serbest b�rak

    //! printf("%p\n",*numbers);  herhangi bir �ekilde numbers'taki valuelara eri�emiyoruz ama adresini g�sterir do�al olarak

    

    return 0;
}


