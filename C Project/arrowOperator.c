#include<stdio.h>
#include<stdlib.h>


/*                     
struct Point
{
    int x;
    int y;
}; */
//? struct ise sadece bir yapý tanýmlar ve yapý deðiþkenleri oluþturmak için her seferinde struct anahtar kelimesini kullanmanýzý gerektirir.
//? struct ile yeni bir yapý oluþturursun hemen deðiþken tanýmlar kullanýrsýn 



typedef struct X_Y_Coordinates  //! X_Y_Coordinates yazmasak da olur, Bu kod okunurluðu için yazýlan opsiyonlu bir þeydir
{
    int x;
    int y;
}Point;
//* typedef struct, bir yapý tanýmlarken ayný zamanda yeni bir tür adý tanýmlar ve bu tür adýný kullanarak yapý deðiþkenleri oluþturmanýzý saðlar; 
//* typedef ile bunu bir type olarak tanýmlarsýn daha sonra ayný type'tan birkaç tane struct oluþturabilirsin




int main(){

    Point p1;  //? p1 adýnda Point deðiþkeni oluþturduk
    p1.x=3;
    p1.y=2;

    printf("p1:(%d,%d)\n",p1.x,p1.y);

    Point *p2;  //? sturct'ýn memory address'ini tutan bir pointer oluþturduk
    p2=&p1;     //? p2=p1'in memory address'i

    p2->x=5;   //? -> p2'nin gösterdiði deðiþkene eriþir, x ve ye deðiþkenlerini deðiþtiriyoruz
    p2->y=4;  

    printf("p1:(%d,%d)\n",p1.x,p1.y);
    printf("p2:(%d,%d)\n",p2->x,p2->y);

    Point *p3;
    p3=malloc(sizeof(Point));

    p3->x=5;
    p3->y=10;

    printf("p3:(%d,%d)\n",p3->x,p3->y);

    (*p3).x=2;  //! p3->x=2 'yi bu þekilde yazabiliriz
    (*p3).y=4;  //! ama *p3.x=2 þeklinde yazamayýz parantez kullanmamýz lazým

    printf("p3:(%d,%d)\n",(*p3).x,(*p3).y);
    printf("p3:(%d,%d)\n",p3->x,p3->y);

    return 0;
}