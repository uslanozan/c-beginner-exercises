#include<stdio.h>

int main(){

    int number;

    printf("Enter 1 or 0!\n");
    scanf("&d",&number);

    switch (number)  //* Switch k�sm�na de�i�ken verilir, case'ler ise de�i�kene g�re komut �al��t�r�r
    {
    case 0:
        printf("Case is 0!\n");
        break;  //! break olmazsa di�er case'lerin i�i de �al���r
    case 1:
        printf("Case is 1!\n");
    default:  //! e�er hi�bir case e�le�mezse default �al���r
        printf("It's default case!\n");
    }



    return 0;
}