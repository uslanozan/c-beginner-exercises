#include<stdio.h>
#include<stdlib.h>


/*                     
struct Point
{
    int x;
    int y;
}; */
//? struct ise sadece bir yap� tan�mlar ve yap� de�i�kenleri olu�turmak i�in her seferinde struct anahtar kelimesini kullanman�z� gerektirir.
//? struct ile yeni bir yap� olu�turursun hemen de�i�ken tan�mlar kullan�rs�n 



typedef struct X_Y_Coordinates  //! X_Y_Coordinates yazmasak da olur, Bu kod okunurlu�u i�in yaz�lan opsiyonlu bir �eydir
{
    int x;
    int y;
}Point;
//* typedef struct, bir yap� tan�mlarken ayn� zamanda yeni bir t�r ad� tan�mlar ve bu t�r ad�n� kullanarak yap� de�i�kenleri olu�turman�z� sa�lar; 
//* typedef ile bunu bir type olarak tan�mlars�n daha sonra ayn� type'tan birka� tane struct olu�turabilirsin




int main(){

    Point p1;  //? p1 ad�nda Point de�i�keni olu�turduk
    p1.x=3;
    p1.y=2;

    printf("p1:(%d,%d)\n",p1.x,p1.y);

    Point *p2;  //? sturct'�n memory address'ini tutan bir pointer olu�turduk
    p2=&p1;     //? p2=p1'in memory address'i

    p2->x=5;   //? -> p2'nin g�sterdi�i de�i�kene eri�ir, x ve ye de�i�kenlerini de�i�tiriyoruz
    p2->y=4;  

    printf("p1:(%d,%d)\n",p1.x,p1.y);
    printf("p2:(%d,%d)\n",p2->x,p2->y);

    Point *p3;
    p3=malloc(sizeof(Point));

    p3->x=5;
    p3->y=10;

    printf("p3:(%d,%d)\n",p3->x,p3->y);

    (*p3).x=2;  //! p3->x=2 'yi bu �ekilde yazabiliriz
    (*p3).y=4;  //! ama *p3.x=2 �eklinde yazamay�z parantez kullanmam�z laz�m

    printf("p3:(%d,%d)\n",(*p3).x,(*p3).y);
    printf("p3:(%d,%d)\n",p3->x,p3->y);

    return 0;
}