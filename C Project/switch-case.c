#include<stdio.h>

int main(){

    int number;

    printf("Enter 1 or 0!\n");
    scanf("&d",&number);

    switch (number)  //* Switch kýsmýna deðiþken verilir, case'ler ise deðiþkene göre komut çalýþtýrýr
    {
    case 0:
        printf("Case is 0!\n");
        break;  //! break olmazsa diðer case'lerin içi de çalýþýr
    case 1:
        printf("Case is 1!\n");
    default:  //! eðer hiçbir case eþleþmezse default çalýþýr
        printf("It's default case!\n");
    }



    return 0;
}