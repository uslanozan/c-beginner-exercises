#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
// 0 ile 255 aras�ndaki say�lar�n toplam�n� bulan program
int sayi=0;
int toplam;

setlocale(LC_ALL,"Turkish"); // t�rk�e karakterler i�in



while (sayi < 256)
{
toplam = toplam + sayi;
sayi = sayi +1;
}

printf("0 ile 255 aras�ndaki say�lar�n toplam� = %d\r\n", toplam );

return 0;
}