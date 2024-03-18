#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
konular
- switch/case
- d�ng� kontrol komutlar�
- ++ --
*/

/*
    switch komutu bir say�n�n bir �ok de�er alabilece�i durumlarda her de�er i�in
ayr� bir kod yazmak i�in kullan�l�r. Bu i�i bir �ok if komutu ile de yapabiliriz.
switch kullanmak daha kolay ve taraf�m�zdan okunmas� daha kolayd�r.

yaz�m� �u �ekilde :
switch (say�)
       {
       case 0: //say� o ise
            ...
            ...
            ...
            break;
       case 1: //say� 1 ise
            ...
            ...
            ...
            break;
       case 2:
            ...
            ...
            break;
       case 3:
       ...
       ...
       ...
       default:
            ...
            ...
       }// switch komutu burada biter. E�er break komutuna denk geldiysek ak�� buradan devam eder

say� olarak verdi�imiz de�er ne ise ona uyan case sat�r�ndan itibaren program �al��maya devam eder.
!e�er verdi�imiz de�er case de�erlerinin hi� birine uymuyorsa ak�� default'a gider oradan devam eder.
break komutu switch den ��kar. switch'den sonraki komuta atlar.

�imdi iki tane ayn� i�i yapan fonksiyon yazal�m. Birisi if ile di�eri switch ile �al��s�n
fonksiyona giden de�er olarak 0-1-2-3-4 verelim.
Fonksiyonda 0 i�in 1 , 1 i�in 10 ... �eklinde de�er �retelim. Gelen de�er 0-4 aral���n�n d���nda
ise 0 d�nd�relim.

*/
//-----------------------------------------------------------------------------------
int ifli_func(int sayi)
{
int donen_deger;
if (sayi==0)
   donen_deger=1;
   else
   if (sayi==1)
      donen_deger=10;
      else
      if (sayi==2)
         donen_deger=100;
         else
         if (sayi==3)
            donen_deger=1000;
            else
            if (sayi==4)
               donen_deger=10000;
               else // de�er 0-4 aral���nda de�il;
               donen_deger=0;

return donen_deger;
}
//-----------------------------------------------------------------------------------
int switchli_func(int sayi)
{
int donen_deger;
switch (sayi)
       {
       case 0:
            donen_deger=1;
            break;
       case 1:
            donen_deger=10;
            break;
       case 2:
            donen_deger=100;
            break;
       case 3:
            donen_deger=1000;
            break;
       case 4:
            donen_deger=10000;
            break;
       default:
            donen_deger=0;
       }
return donen_deger;
}
//-----------------------------------------------------------------------------------
/*
iki fonksiyonda ayn� i�i yap�yorlar. switch ile yaz�lan� anlamak daha kolay.
Daha sade bir g�r�n�m� var.

�zet
- switch'e verilen de�er uygun case sat�r�n�n alt�ndan devam eder.
?- break kullan�lmaz ise ak�� a�a�� do�ru devam eder. di�er case'ler de �al���r.
- case'de de�i�ken kullan�lmaz say�sal de�er istenir.
- case'ler s�ral� olmak zorunda de�ildir. kar���k s�rada yaz�labilir.

yukar�da yazd���m kodda de�i�iklik yaparak yukar�daki �zet listedeki verilen bilgileri
test ediniz kendiniz g�r�n�z.


�imdi gelelim d�ng� kontrol komutlar�na. ��yle 1 d�ng�m�z olsun. �art olarak verdi�im 1 de�eri
bool true (mant�ksal do�ru) oldu�u i�in bu d�ng� s�rekli d�ner.

while (1)
      {
      ...
      ...
      ...
      break;
      }

iki yeni komut continue - break

- continue komutu d�ng�n�n i�leyi�ini ba�a d�nd�r�r. �art kontrol edilir d�ng� devam eder
- break komutu d�ng�y� k�rar while dan sonraki komuttan devam eder.

�rnek yapal�m
*/

//-----------------------------------------------------------------------------
int main()
{
int a,b;
int i;

setlocale(LC_ALL,"Turkish"); // t�rk�e karakterler i�in

i=ifli_func(0);
i=ifli_func(1);
i=ifli_func(2);
i=ifli_func(3);
i=ifli_func(10);

i=switchli_func(0);
i=switchli_func(1);
i=switchli_func(2);
i=switchli_func(3);
i=switchli_func(10);


a=b=0;//hepsine bi seferde ayn� de�eri veriyoruz
printf("*****************\r\n");
while (1)
      {
      b=0;
      while (b<4)
            {
            if (a==1) // a de�eri 1 ise b d�ng�s� iptal
               break;// b d�ng�s� k�r�l�r
            if (b==2) //b nin de�eri 2 ise
               {
               b=b+1; //b nin de�erini artt�r
               continue;  // b d�ng�s�ne ba�tan devam et
               }
            printf("a=%d \t b=%d\r\n",a,b);
            b=b+1;
            }
      a=a+1;
      printf("-----------------\r\n");
      if (a>3)
         break;
      }
/*
�rne�i ad�m ad�m �al��t�r�p a ve b de�i�kenlerinin de�erlerini g�zleyin.
continue ve break komutunun d�ng�y� nas�l etkiledi�ini g�r�n.

burada while ile verdi�imiz �rnek for komutunda da aynen bu �ekilde �al���r
ona da bir �rnek yapal�m

*/
printf("================\r\n");
for (a=0;a<10;a=a+1)
    {
    if (a==8)
       break;
    if (a==3)
       continue;
    printf("a=%d\r\n",a);
    }

/*
++ bir de�i�kenin de�erini artt�rmak i�in kullan�l�r. de�i�kenin ba��na veya sonuna konulabilir.
a�a��daki �rnek de ++'n�n de�i�kenin �n�nde ve sonunda olmas�na g�re nas�l i�lem yap�ld���n� g�r�n�z

daha �nceki �rneklerde a=a+1; yazd���m�z yerlere a++; yazabiliriz.
*/

a=0;
printf("\r\n a n�n de�eri=%d\r\n",a++); // a'n�n de�erini yaz , sonra de�erini artt�r

a=0;
printf("\r\n a n�n de�eri=%d\r\n",++a); // a'n�n de�erini artt�r, sonra de�erini yaz

a=0;
while (a<4)
      printf("a -> %d\r\n",a++);


printf("////////////////\r\n");
a=5;
while (a)
      printf("a -> %d\r\n",a--);


printf("================\r\n");
for (a=0;a<5;a++)
    {
    printf("a=%d\r\n",a);
    }


return 0;
}
//-----------------------------------------------------------------------------