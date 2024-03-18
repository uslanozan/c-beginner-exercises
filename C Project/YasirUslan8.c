#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*
konular

1- struct ve struct pointer
*/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(void)
{
/*
�imdiye kadar ki konularda de�i�kenler kulland�k. Bunlar basit ihtiya�lar�m�z
i�in kulland���m�z de�i�kenlerdi. �imdi bahsedece�imiz konuda de�i�kenlerin
nas�l birle�tirilip bir yap� olu�turulaca��n�, ve hayat� nas�l kolayla�t�raca��ndan
bahsedicez.

*Birbiriyle alakal� verileri bir arada, tek bir isim alt�nda tutmak i�in kullan�l�r.
Hiyerar�ik yap� kurulabilir, b�ylece kafa kar��t�rmadan b�y�k kar���k veri y���nlar�
tek bir �at� alt�nda birle�tirilebilir. Hemen basit bir struct tan�mlay�p geli�tirelim.
*/
struct kisi
       {
       char isim[40];
       char soyIsim[40];
       char cinsiyet;
       char dogumTarihi[12];
       int numara;
       };
struct sinif
       {
       int yil;
       char sube;
       int ogrenciSayisi;
       struct kisi ogrenciler[40];
       };
struct okul
       {
       char ad[40];
       int tip;
       int sinifSayisi;
       struct sinif siniflar[20];
       };
/*
Verdi�im �rnekte 3 adet struct tan�mlad�k. �lk �nce kisi diye bir insan�n �zelliklerini
tutan yap� tan�mlad�m. Bu tan�mlamada bir kisiyi tan�mlayan �zellikler de�i�ken olarak
tan�mland� ve kisi yap�s� alt�nda birle�tirildi. �kinci tan�mda ��rencilerin ders yapacaklar�
bir s�n�f� tan�mlayan �zelliklerle s�n�f yap�s� tan�mland�. Bu s�n�f tan�m�nda 40 tane kisi
tipinde ��renci tan�mland�. Son olarak okul tan�m�nda 20 tane s�n�f tan�mland�. Her s�n�fta 40
��renci.

buraya kadar yapt�klar�m�z tan�mlama idi �imdi bu kurdu�umuz yap�dan bir tane de�i�ken
olu�turup �st�nde �al��maya ba�layal�m.
*/
struct okul eml;
// okul tipinde struct olu�turduk
int i,q;

//-----veri giri�i
eml.tip=3;
eml.sinifSayisi=1;

strcpy(eml.ad,"Mugla Endustri Meslek Lisesi");

eml.siniflar[0].yil=9;
eml.siniflar[0].sube='A';
eml.siniflar[0].ogrenciSayisi=2;

strcpy(eml.siniflar[0].ogrenciler[0].isim,"Yasir");
strcpy(eml.siniflar[0].ogrenciler[0].soyIsim,"Uslan");
eml.siniflar[0].ogrenciler[0].cinsiyet='E';
strcpy(eml.siniflar[0].ogrenciler[0].dogumTarihi,"01.01.2005");
eml.siniflar[0].ogrenciler[0].numara=494;

strcpy(eml.siniflar[0].ogrenciler[1].isim,"Hede");
strcpy(eml.siniflar[0].ogrenciler[1].soyIsim,"Hodo");
eml.siniflar[0].ogrenciler[1].cinsiyet='E';
strcpy(eml.siniflar[0].ogrenciler[1].dogumTarihi,"02.02.2005");
eml.siniflar[0].ogrenciler[1].numara=604;
//-----  veri yazd�rma
printf("Okul : %s \r\n",eml.ad);
printf("Okul Tip : ");

switch (eml.tip)
       {
       case 0:
            printf("ilk");
            break;
       case 1:
            printf("orta");
            break;
       case 2:
            printf("lise");
            break;
       case 3:
            printf("meslek Lisesi");
            break;
       default:
            printf("gizli bilimler :)");
       }
printf("\r\nSinif sayisi: %d\r\n\n",eml.sinifSayisi);

for (i=0;i<eml.sinifSayisi;i++)
    {
    printf("Sinif: %d%c\r\n",eml.siniflar[i].yil,eml.siniflar[i].sube);
    printf("Mevcut: %d\r\n",eml.siniflar[i].ogrenciSayisi);
    printf("Ogrenci listesi\r\n");
    printf("Numara\t\tSoyadi\t\tAdi \r\n");
    for (q=0;q<eml.siniflar[i].ogrenciSayisi;q++)
        {
        printf("%d\t\t%s\t\t%s\r\n",eml.siniflar[i].ogrenciler[q].numara,
                                eml.siniflar[i].ogrenciler[q].soyIsim,
                                eml.siniflar[i].ogrenciler[q].isim);
        }
    }
/*
��endi�im i�in bu kadar veri girebildim ama olay� anlad�n�z. B�t�n bu veriler
gayet d�zg�n ve mant�kl� bir bi�imde �ekillendi, bu veriler �zerinde �al��mak
art�k �ok kolay, hatta eml de�i�kenini direk diske yazabilir tek seferde b�t�n
okulun bilgilerini kaydedip, daha sonra geri y�kleyebiliriz.
�rnekle oynay�p yeni bir s�n�f kayd� yap�p,s�n�fa ��renciler ekleyip listede
g�z�kmesini sa�lay�n.

�imdi ba�ka bir �rnek yapal�m. Bu �rnekde seri porttan gelen veri blo�unu
struct pointer ile kolayca i�leyelim.

gelen verimiz �u �ekilde olsun
:10 01 00 00 21 46 01 36 01 21 47 01 36 00 7E FE 09 D2 19 01 40
format� da �u �ekilde
uzunluk     a��klama
1           paket ba�lang�c karakteri ':'
1           paketteki veri uzunlu�u, hexadecimal g�sterimde 1 byte'l�k say�
2           Adres, verinin yaz�laca�� haf�za adresi ba�lang�c�, hex 2byte
1           kayit tipi, hex 1byte, 0=data,1=endOfFile
1*uzunluk   as�l veri, uzunluk kadar, max 16byte
1           checksum kontrol toplam�

�imdi yukardaki tabloya g�re paketi par�alayal�m ve isim verelim
:       ba�lang�� karakteri (start)
10      veri uzunlugu (len)
0100    yazilacak adres (adr) 2byte
00      kayit tipi (tip)
214601360121470136007EFE09D21901 veri (data) 16byte
40      kontrol toplam� (chk)

kontrol toplam� denen �ey �u �ekilde hesaplan�yor. Paketin en ba�taki : haricindeki
b�t�n de�erleri unsigned char olarak toplad���m�zda elimizdeki say� 0 olmas� gerekiyor.

burada son olarak s�yleyece�im struct de�i�kenler ile �al���rken alt elemanlara
eri�irken '.' nokta kullan�l�r. Pointer struct ise nokta yerine -> kullan�l�r.
yukar�daki �rnekde de�i�ken, a�a��dakinde pointer kulland�m. �nceleyiniz.


�imdi buna uygun bir struct tan�mlayal�m
*/
struct paketFormat
       {
       unsigned char start;
       unsigned char len;
       unsigned char adrH;
       unsigned char adrL;
       unsigned char tip;
       unsigned char data[16];
       unsigned char chk;
       };
/*
yani bu kadar yapt�ktan sonra bunu i�leyecek kodu da yazal�m bari.
*/
unsigned char gelenVeri[]={':',0x10 ,0x01 ,0x00 ,0x00 ,0x21 ,0x46 ,0x01 ,0x36 ,0x01 ,0x21 ,0x47 ,0x01 ,0x36 ,0x00 ,0x7E,
                     0xFE ,0x09 ,0xD2 ,0x19 ,0x01 ,0x40 };

struct paketFormat *paket;//paketFormat tipinden bir pointer olu�turduk
unsigned int chksum; // veri toplam kontrol� i�in gerekli


paket=gelenVeri;//pointere gelenVeri'nin adresini yazd�k *** hat�rlayal�m her dizi pointerdir
//***** paket ':' ile ba�lamas� gerekiyor kontrol edelim
if (paket->start != ':')
   {
   printf("paket : ile baslamiyor\r\n");
   return 1;
   }
//******  veri paketinde ':' dan sonra gelen b�t�n verilerin toplam�n�n son byte'� 0 olmas� gerekli
chksum=0;
for (i=1;i < paket->len+6;i++)
    chksum += (unsigned char)gelenVeri[i];

if (chksum&0xff != 0)
   {
   printf("\r\nveri bozulmasi tespit edildi. Paket checksum uyusmuyor checksum: %02X\r\n",chksum);
   return 2;
   }
//****  paket do�ru iletilmi� ekrana yazd�ral�m
printf("\nveri paketi detaylari\r\n");
printf("paket guvenligi dogrulandi\r\n");
printf("Tip : ");
if (paket->tip==0)
   printf("VeriPaketi\r\n");
   else
   if (paket->tip==1)
      printf("EndOfFile\r\n");
      else
      printf("BilinmeyenTip\r\n");

printf("Hafiza Adresi : 0x%02X%02X \r\n",paket->adrH,paket->adrL);
printf("Veri uzunlugu : %d byte\r\n",paket->len);
printf("Veriler : ");

for (i=0;i < paket->len;i++)
    printf("0x%02X ",paket->data[i]);

printf("\r\nPaket chksum degeri : 0x%02X \r\n",paket->chk);

//---------------------
return 0; // main bitti
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------