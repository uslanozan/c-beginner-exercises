#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
konular
- switch/case
- döngü kontrol komutlarý
- ++ --
*/

/*
    switch komutu bir sayýnýn bir çok deðer alabileceði durumlarda her deðer için
ayrý bir kod yazmak için kullanýlýr. Bu iþi bir çok if komutu ile de yapabiliriz.
switch kullanmak daha kolay ve tarafýmýzdan okunmasý daha kolaydýr.

yazýmý þu þekilde :
switch (sayý)
       {
       case 0: //sayý o ise
            ...
            ...
            ...
            break;
       case 1: //sayý 1 ise
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
       }// switch komutu burada biter. Eðer break komutuna denk geldiysek akýþ buradan devam eder

sayý olarak verdiðimiz deðer ne ise ona uyan case satýrýndan itibaren program çalýþmaya devam eder.
!eðer verdiðimiz deðer case deðerlerinin hiç birine uymuyorsa akýþ default'a gider oradan devam eder.
break komutu switch den çýkar. switch'den sonraki komuta atlar.

þimdi iki tane ayný iþi yapan fonksiyon yazalým. Birisi if ile diðeri switch ile çalýþsýn
fonksiyona giden deðer olarak 0-1-2-3-4 verelim.
Fonksiyonda 0 için 1 , 1 için 10 ... þeklinde deðer üretelim. Gelen deðer 0-4 aralýðýnýn dýþýnda
ise 0 döndürelim.

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
               else // deðer 0-4 aralýðýnda deðil;
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
iki fonksiyonda ayný iþi yapýyorlar. switch ile yazýlaný anlamak daha kolay.
Daha sade bir görünümü var.

özet
- switch'e verilen deðer uygun case satýrýnýn altýndan devam eder.
?- break kullanýlmaz ise akýþ aþaðý doðru devam eder. diðer case'ler de çalýþýr.
- case'de deðiþken kullanýlmaz sayýsal deðer istenir.
- case'ler sýralý olmak zorunda deðildir. karýþýk sýrada yazýlabilir.

yukarýda yazdýðým kodda deðiþiklik yaparak yukarýdaki özet listedeki verilen bilgileri
test ediniz kendiniz görünüz.


þimdi gelelim döngü kontrol komutlarýna. þöyle 1 döngümüz olsun. þart olarak verdiðim 1 deðeri
bool true (mantýksal doðru) olduðu için bu döngü sürekli döner.

while (1)
      {
      ...
      ...
      ...
      break;
      }

iki yeni komut continue - break

- continue komutu döngünün iþleyiþini baþa döndürür. þart kontrol edilir döngü devam eder
- break komutu döngüyü kýrar while dan sonraki komuttan devam eder.

örnek yapalým
*/

//-----------------------------------------------------------------------------
int main()
{
int a,b;
int i;

setlocale(LC_ALL,"Turkish"); // türkçe karakterler için

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


a=b=0;//hepsine bi seferde ayný deðeri veriyoruz
printf("*****************\r\n");
while (1)
      {
      b=0;
      while (b<4)
            {
            if (a==1) // a deðeri 1 ise b döngüsü iptal
               break;// b döngüsü kýrýlýr
            if (b==2) //b nin deðeri 2 ise
               {
               b=b+1; //b nin deðerini arttýr
               continue;  // b döngüsüne baþtan devam et
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
örneði adým adým çalýþtýrýp a ve b deðiþkenlerinin deðerlerini gözleyin.
continue ve break komutunun döngüyü nasýl etkilediðini görün.

burada while ile verdiðimiz örnek for komutunda da aynen bu þekilde çalýþýr
ona da bir örnek yapalým

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
++ bir deðiþkenin deðerini arttýrmak için kullanýlýr. deðiþkenin baþýna veya sonuna konulabilir.
aþaðýdaki örnek de ++'nýn deðiþkenin önünde ve sonunda olmasýna göre nasýl iþlem yapýldýðýný görünüz

daha önceki örneklerde a=a+1; yazdýðýmýz yerlere a++; yazabiliriz.
*/

a=0;
printf("\r\n a nýn deðeri=%d\r\n",a++); // a'nýn deðerini yaz , sonra deðerini arttýr

a=0;
printf("\r\n a nýn deðeri=%d\r\n",++a); // a'nýn deðerini arttýr, sonra deðerini yaz

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