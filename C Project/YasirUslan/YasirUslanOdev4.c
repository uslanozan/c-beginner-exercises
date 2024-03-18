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

    printf("Kýrmýzý tonu için 0-255 arasýnda sayý girin:");
    scanf("%d",&renk1.red);

    printf("Yeþil tonu için 0-255 arasýnda sayý girin:");
    scanf("%d",&renk1.green);

    printf("Mavi tonu için 0-255 arasýnda sayý girin:");
    scanf("%d",&renk1.blue);

    printf("Renk kodunuz iþte budur: (%d,%d,%d)",renk1.red,renk1.green,renk1.blue);

    //! Ýleride girilen renk koduna göre ismini söylemesini ekleyebilirim ama þuan bi týk uykum var :)

}