#include<stdio.h>

int main(){

    int toplam=0;
    for (int i = 3; i <18; i++)
    {
        toplam=toplam+i;
    }
    printf("Toplam: %d\n",toplam);
    
    int toplam2=0;
    int counter=3;
    while (counter<18)
    {
        toplam2=toplam2+counter;
        counter++;
    }
    printf("Toplam: %d\n",toplam2);

    int counter2=3;
    int toplam3=0;
    do
    {
        toplam3=toplam3+counter2;
        counter2++;
    } while (counter2<18);
    printf("Toplam: %d\n",toplam3);

    return 0;
}