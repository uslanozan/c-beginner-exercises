//?�dev olarak a�a��da dosyada tan�m� yap�lm�� fonksiyonu yaz�n�z.
//?Fonksiyon verilen say� tek ise 1 �ift ise 2 d�nd�recek �ekilde olmal�d�r.
//?Fonksiyon 0'dan k���k veya 50'den b�y�k say�lar verilirse 0 de�eri d�nd�rmelidir.
//?�devi dosya olarak teslim edin








#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//-----------------------------------------------------------------------------
//------ fonksiyonu yaz�n -----------------------------------------------------



int cift_sayi(int sayi)
{
    if (sayi<0 || sayi>50)
    {
        return 0;
    }
    else if(sayi%2==0){
        return 2;
    }
    else if(sayi%2==1){
        return 1;
    }
}
//-----------------------------------------------------------------------------








//----------- a�a��daki test kodunda de�i�iklik yapmay�n ----------------------
//-----------------------------------------------------------------------------
int test_dizi[]={-10,-5,0,1,2,5,10,15,20,25,30,35,40,45,50,55,2000};
int main()
{
int i;
int giden;
int sonuc;

setlocale(LC_ALL,"Turkish"); // t�rk�e karakterler i�in

i=0;
while (test_dizi[i] != 2000) //test_dizisinin son eleman�na geldik mi?
      {
      giden=test_dizi[i]; //fonksiyona g�nderece�imiz de�er giden de�i�keninde
      sonuc=cift_sayi(giden); //fonkisyona giden'i g�nderdik, gelen de�eri sonuc'a kaydettik
      printf("fonksiyona giden de�er %d  d�nen de�er=%d ",giden,sonuc); // gideni geleni yazal�m
      
      if (giden>50)  // sonu� de�erlendirmesi
         printf("giden de�er 0-50 aras�nda de�il\r\n");
      
      if (giden<0)  // sonu� de�erlendirmesi
         printf("giden de�er 0-50 aras�nda de�il\r\n");
         else
         if (sonuc==1)
            printf(" tek sayi \r\n");
            else
            if (sonuc==0)
               printf(" �ift sayi \r\n");
               else// fonksiyondan gelen 0,1,2 d���nda bir de�er olmamal�d�r
               printf(" **** HATALI DE�ER ****\r\n");

      i=i+1;
      }

return 0;
}