#include<stdio.h>
#include<stdlib.h>

//! malloc, calloc, realloc ve free dinamik bellek yönetimini saðlayan fonksiyonlardýr ve #include<stdlib.h> ile gelir


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

    a=malloc( sizeof(int)*5);  //? dinamik bellek tahsis etmek için kullanýlýr. Ýstenen bellek boyutu kadan alan byte olarak
    //? malloc() fonksiyonu tahsis edilmiþ belleðin BAÞLANGICINI gösteren bir pointer geri verir.
    //? a=calloc(5,sizeof(int));  ile de ayný þeyi yapabilirdik 
    //? calloc() eleman sayýsýný ve eleman boyutunu parametre olarak vermemiz lazým
    //? Buradaki önemli fark malloc ile ayýrdýðýmýzda bellekte farklý deðerler olabilir (üstte yazdýðým a[0] value'larý gibi)
    //? Ama calloc ile ayýrdýðýmýzda içindeki deðerleri 0 yapar yani atanmamýþ deðer olur
    a[0]=1;
    a[1]=5;
    a[2]=7;
    a[3]=9;
    a[4]=11;

    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    
    free(a);  //? Önceden ayrýlmýþ bir alaný boþa çýkarýrsýn
              //? C'de garbage collector olmadýðýndan memory control önemlidir

    printf("\n---------------------------\n");

    int *numbers;
    int size=2;  //* Baþlangýçta tahsis edilen bellek boyutu
    numbers=malloc(sizeof(int)*size);
    int input=0,i=0;

    do
    {   
        if (i==size)  //* Bellek boyutu dolarsa
        {
            size +=2;  //* Bellek boyutunu 2 artýr
            numbers = realloc(numbers,sizeof(int)*size);  //* Belleði yeniden boyutlandýrýr
            printf("Realloc for %d ints\n",size);
        }             //? realloc bütün deðerleri kopyalayýp yeni bir memory'e atar, memory'i geniþletir
        

        printf("Enter (-1 to quit):");
        scanf("%d",&input);
        if (input != -1)   
        {                       //* -1 girmediðimiz sürece deðerleri array'e ekler
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
    
    printf("average: %d\n",total / num_elements);  //* Girdiðimiz sayýlarýn ortalamasýný alýr

    free(numbers);  //* Belleði serbest býrak

    //! printf("%p\n",*numbers);  herhangi bir þekilde numbers'taki valuelara eriþemiyoruz ama adresini gösterir doðal olarak

    

    return 0;
}


