//?Ödev olarak aþaðýda dosyada tanýmý yapýlmýþ fonksiyonu yazýnýz.
//?Fonksiyon verilen sayý tek ise 1 çift ise 2 döndürecek þekilde olmalýdýr.
//?Fonksiyon 0'dan küçük veya 50'den büyük sayýlar verilirse 0 deðeri döndürmelidir.
//?ödevi dosya olarak teslim edin








#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//-----------------------------------------------------------------------------
//------ fonksiyonu yazýn -----------------------------------------------------



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








//----------- aþaðýdaki test kodunda deðiþiklik yapmayýn ----------------------
//-----------------------------------------------------------------------------
int test_dizi[]={-10,-5,0,1,2,5,10,15,20,25,30,35,40,45,50,55,2000};
int main()
{
int i;
int giden;
int sonuc;

setlocale(LC_ALL,"Turkish"); // türkçe karakterler için

i=0;
while (test_dizi[i] != 2000) //test_dizisinin son elemanýna geldik mi?
      {
      giden=test_dizi[i]; //fonksiyona göndereceðimiz deðer giden deðiþkeninde
      sonuc=cift_sayi(giden); //fonkisyona giden'i gönderdik, gelen deðeri sonuc'a kaydettik
      printf("fonksiyona giden deðer %d  dönen deðer=%d ",giden,sonuc); // gideni geleni yazalým
      
      if (giden>50)  // sonuç deðerlendirmesi
         printf("giden deðer 0-50 arasýnda deðil\r\n");
      
      if (giden<0)  // sonuç deðerlendirmesi
         printf("giden deðer 0-50 arasýnda deðil\r\n");
         else
         if (sonuc==1)
            printf(" tek sayi \r\n");
            else
            if (sonuc==0)
               printf(" çift sayi \r\n");
               else// fonksiyondan gelen 0,1,2 dýþýnda bir deðer olmamalýdýr
               printf(" **** HATALI DEÐER ****\r\n");

      i=i+1;
      }

return 0;
}