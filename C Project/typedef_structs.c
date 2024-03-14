#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int inches;  //! yeni bir type olu�turuyorum:inches (int olu�tururak)

struct Point   //! asl�nda yeni bir type olu�turuyoruz ve bu ba�ka type'larda de�erler i�eriyor
{
    int x;    //* member denir
    int y;
};

//! typedef struct, bir yap� tan�mlarken ayn� zamanda yeni bir t�r ad� tan�mlar ve bu t�r ad�n� kullanarak yap� de�i�kenleri olu�turman�z� sa�lar; 
//! struct ise sadece bir yap� tan�mlar ve yap� de�i�kenleri olu�turmak i�in her seferinde struct anahtar kelimesini kullanman�z� gerektirir.
//? struct ile yeni bir yap� olu�turursun hemen de�i�ken tan�mlar kullan�rs�n 
//? typedef ile bunu bir type olarak tan�mlars�n daha sonra ayn� type'tan birka� tane struct olu�turabilirsin
typedef struct{
    int x;
    int y;

}Point2;



typedef struct 
{
    char first_name[50];
    char last_name[50];
    int age;
}Student;

typedef struct 
{
    int data1;
    int *array;
}Info;

void print_student(Student s);
void age_students(Student *s);

/*---------------------------------------------------------------------------------------------------*/
int main(){

    inches person1=181;
    inches person2=179;


    printf("person1: %d\n",person1 );  //* inches'�n type'� int oldu�u i�in %d kullan�labilir
    printf("person2: %d\n",person2 );


    struct Point p1;  //* Point type'�nda p1 olu�turup ona da int type'�nda 2 de�er atad�k
    p1.x=5;
    p1.y=3;
    printf("(%d,%d)\n",p1.x,p1.y);

    struct Point p2;
    p2.x=10,p2.y=4;
    printf("(%d,%d)\n",p2.x,p2.y);

    struct Point p3={1,2};   //? b�yle de tan�mlanabilir
    printf("(%d,%d)\n",p3.x,p3.y);

    struct Point p4={    //? b�yle de tan�mlanabilir
        .y=7,
        .x=6
    };
    printf("(%d,%d)\n",p4.x,p4.y);


    Point2 newp2={.x=6,.y=9};  //? b�yle de tan�mlanabilir
    printf("(%d,%d)\n",newp2.x,newp2.y);

    Student s1;
    s1.age=21;
    strcpy(s1.first_name,"Ozan");  //? strcpy() sa�daki parametreyi soldakine kopyalar
    strcpy(s1.last_name,"Uslan");

    print_student(s1);

    printf("\n------------------------------------\n\n");



    Student *news1;

    news1=calloc(1,sizeof(Student));
    news1->age=21;  //? news1->age ile (*news1).age ayn�d�r 
    printf("Age: %d\n",news1->age);  //? -> ise bir heap'te bulunan struct pointer'�n elemeanlar�na eri�mek i�in kullan�l�r. �rne�in ogrenci bir struct'� global olarak kullanmak istiyorsun:
    age_students(news1);
    printf("Age: %d\n",news1->age);

    Info a;
    a.data1=7;
    a.array=malloc(sizeof(int)*5);
    for (int i = 0; i < 5; i++)
    {
        a.array[i] = i+1;
    }
    Info b=a;  //! bu durumdan ka��nmam�z laz�m ��nk� pointer'�n� kopyal�yor ve b'yi de�i�tirirsek a da de�i�iyor
    printf("b.data1: %d\n",b.data1);
    for (int i = 0; i < 5; i++)
    {
        printf("b.array[%d] = %d\n",i,b.array[i]);
    }
    printf("a.array: %p\n",a.array);    
    printf("b.array: %p\n",b.array);    

    b.array[0]=10;  //? b[0]'� de�i�tirdik ama a[0] da de�i�ti
    for (int i = 0; i < 5; i++)
    {
        printf("a.array[%d] = %d\n",i,a.array[i]);
    }




    //?  Info
    //?              Values
    //?  a.data1      7
    //?  a.array     0x12345
    //?
    //?  b.data1     7
    //?  b.array    0x12345
    //?
    //?



    free(a.array);




    return 0;
}


/*-----------------------------------------------------------------------------------------------*/


void print_student(Student s){
    printf("%s %s\n",s.first_name,s.last_name);
    printf("Age: %d\n",s.age);
}

void age_students(Student *s){
    s->age +=1;
}