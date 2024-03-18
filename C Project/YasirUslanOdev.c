#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
// 0 ile 255 arasýndaki sayýlarýn toplamýný bulan program
int sayi=0;
int toplam;

setlocale(LC_ALL,"Turkish"); // türkçe karakterler için



while (sayi < 256)
{
toplam = toplam + sayi;
sayi = sayi +1;
}

printf("0 ile 255 arasýndaki sayýlarýn toplamý = %d\r\n", toplam );

return 0;
}