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
Þimdiye kadar ki konularda deðiþkenler kullandýk. Bunlar basit ihtiyaçlarýmýz
için kullandýðýmýz deðiþkenlerdi. Þimdi bahsedeceðimiz konuda deðiþkenlerin
nasýl birleþtirilip bir yapý oluþturulacaðýný, ve hayatý nasýl kolaylaþtýracaðýndan
bahsedicez.

*Birbiriyle alakalý verileri bir arada, tek bir isim altýnda tutmak için kullanýlýr.
Hiyerarþik yapý kurulabilir, böylece kafa karýþtýrmadan büyük karýþýk veri yýðýnlarý
tek bir çatý altýnda birleþtirilebilir. Hemen basit bir struct tanýmlayýp geliþtirelim.
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
Verdiðim örnekte 3 adet struct tanýmladýk. Ýlk önce kisi diye bir insanýn özelliklerini
tutan yapý tanýmladým. Bu tanýmlamada bir kisiyi tanýmlayan özellikler deðiþken olarak
tanýmlandý ve kisi yapýsý altýnda birleþtirildi. Ýkinci tanýmda öðrencilerin ders yapacaklarý
bir sýnýfý tanýmlayan özelliklerle sýnýf yapýsý tanýmlandý. Bu sýnýf tanýmýnda 40 tane kisi
tipinde öðrenci tanýmlandý. Son olarak okul tanýmýnda 20 tane sýnýf tanýmlandý. Her sýnýfta 40
öðrenci.

buraya kadar yaptýklarýmýz tanýmlama idi þimdi bu kurduðumuz yapýdan bir tane deðiþken
oluþturup üstünde çalýþmaya baþlayalým.
*/
struct okul eml;
// okul tipinde struct oluþturduk
int i,q;

//-----veri giriþi
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
//-----  veri yazdýrma
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
üþendiðim için bu kadar veri girebildim ama olayý anladýnýz. Bütün bu veriler
gayet düzgün ve mantýklý bir biçimde þekillendi, bu veriler üzerinde çalýþmak
artýk çok kolay, hatta eml deðiþkenini direk diske yazabilir tek seferde bütün
okulun bilgilerini kaydedip, daha sonra geri yükleyebiliriz.
örnekle oynayýp yeni bir sýnýf kaydý yapýp,sýnýfa öðrenciler ekleyip listede
gözükmesini saðlayýn.

þimdi baþka bir örnek yapalým. Bu örnekde seri porttan gelen veri bloðunu
struct pointer ile kolayca iþleyelim.

gelen verimiz þu þekilde olsun
:10 01 00 00 21 46 01 36 01 21 47 01 36 00 7E FE 09 D2 19 01 40
formatý da þu þekilde
uzunluk     açýklama
1           paket baþlangýc karakteri ':'
1           paketteki veri uzunluðu, hexadecimal gösterimde 1 byte'lýk sayý
2           Adres, verinin yazýlacaðý hafýza adresi baþlangýcý, hex 2byte
1           kayit tipi, hex 1byte, 0=data,1=endOfFile
1*uzunluk   asýl veri, uzunluk kadar, max 16byte
1           checksum kontrol toplamý

þimdi yukardaki tabloya göre paketi parçalayalým ve isim verelim
:       baþlangýç karakteri (start)
10      veri uzunlugu (len)
0100    yazilacak adres (adr) 2byte
00      kayit tipi (tip)
214601360121470136007EFE09D21901 veri (data) 16byte
40      kontrol toplamý (chk)

kontrol toplamý denen þey þu þekilde hesaplanýyor. Paketin en baþtaki : haricindeki
bütün deðerleri unsigned char olarak topladýðýmýzda elimizdeki sayý 0 olmasý gerekiyor.

burada son olarak söyleyeceðim struct deðiþkenler ile çalýþýrken alt elemanlara
eriþirken '.' nokta kullanýlýr. Pointer struct ise nokta yerine -> kullanýlýr.
yukarýdaki örnekde deðiþken, aþaðýdakinde pointer kullandým. Ýnceleyiniz.


þimdi buna uygun bir struct tanýmlayalým
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
yani bu kadar yaptýktan sonra bunu iþleyecek kodu da yazalým bari.
*/
unsigned char gelenVeri[]={':',0x10 ,0x01 ,0x00 ,0x00 ,0x21 ,0x46 ,0x01 ,0x36 ,0x01 ,0x21 ,0x47 ,0x01 ,0x36 ,0x00 ,0x7E,
                     0xFE ,0x09 ,0xD2 ,0x19 ,0x01 ,0x40 };

struct paketFormat *paket;//paketFormat tipinden bir pointer oluþturduk
unsigned int chksum; // veri toplam kontrolü için gerekli


paket=gelenVeri;//pointere gelenVeri'nin adresini yazdýk *** hatýrlayalým her dizi pointerdir
//***** paket ':' ile baþlamasý gerekiyor kontrol edelim
if (paket->start != ':')
   {
   printf("paket : ile baslamiyor\r\n");
   return 1;
   }
//******  veri paketinde ':' dan sonra gelen bütün verilerin toplamýnýn son byte'ý 0 olmasý gerekli
chksum=0;
for (i=1;i < paket->len+6;i++)
    chksum += (unsigned char)gelenVeri[i];

if (chksum&0xff != 0)
   {
   printf("\r\nveri bozulmasi tespit edildi. Paket checksum uyusmuyor checksum: %02X\r\n",chksum);
   return 2;
   }
//****  paket doðru iletilmiþ ekrana yazdýralým
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