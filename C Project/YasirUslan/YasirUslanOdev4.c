#include<stdio.h>
#include<locale.h>

int main(){
setlocale(LC_ALL,"Turkish");

struct RGB{
    int red;
    int green;
    int blue;
    char isim[40];
};
    struct RGB renk1;

    printf("K�rm�z� tonu i�in 0-255 aras�nda say� girin:");
    scanf("%d",&renk1.red);

    printf("Ye�il tonu i�in 0-255 aras�nda say� girin:");
    scanf("%d",&renk1.green);

    printf("Mavi tonu i�in 0-255 aras�nda say� girin:");
    scanf("%d",&renk1.blue);

    printf("Renk kodunuz i�te budur: (%d,%d,%d)",renk1.red,renk1.green,renk1.blue);

    //! �leride girilen renk koduna g�re ismini s�ylemesini ekleyebilirim ama �uan bi t�k uykum var :)

}