#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
setlocale(LC_ALL,"Turkish");
int a,b,c;
float f;
a=8;
b=5;
c=0;
/*
matematiksel i�le�ler
mant�ksal do�ru yanl��
mant�ksal i�le�ler
*/


/*
matematiksel i�le�ler
+ toplama
- ��karma
* �arpma
/ b�lme
% mod (tamsay� b�lmeden sonra kalan k�s�m)
! << bit sola kayd�rma
! >> bit sa�a kayd�rma
& and (bit olarak ve i�lemi)
| or (bit olarak ve i�lemi)
^ xor (bit olarak xor i�lemi)
*/

c=a+b;
c=a+10;
c=a+b+c+13+a+3+b+b+b+12;
c=12+234;

//��karma

c=a-b;
c=b-a;
c=(a+10)-(b+5);
c=10-30;

//�arpma
c=a*b;

//b�lme
//b�lme i�lemi yaparken de�i�ken tiplerine g�re alabilece�iniz sonu�lar de�i�ir.
//tamsay� de�erler ile yap�lan i�lemlerde sonu� da tamsay�d�r.
c=a/b; //a=8 b=5 c=1  tamsay� olarak 8/5=1

//% mod i�lemi
c=a%b;//c de�eri a/b i�leminin kalan de�eri 8/5=1  8-(8/5)=3

//<< ve >> i�lemleri ikili say� sisteminde basamak kayd�rmad�r. kayd�rma i�leminden sonra bo�alan basamaklara 0 konur
//biz on tabanl� say� sisteminde say�n�n sonuna 0 ekledi�imizde 10 ile �arpm�� oluyoruz.
//Ayn� �ekilde 2 tabanl� say� sisteminde say�n�n sonuna 0 ekledi�imizde 2 ile �arpm�� oluruz
c=1<<5;//1 say�s�n� 5 bit sola kayd�r.
c=1<<0;//1<<0 = 1 (1 say�s�n� 0 kere sola kayd�r. yani bi bok yapma)
c=1<<1;//1<<1 = 2
c=1<<2;//1<<2 = 4
c=1<<3;//1<<3 = 8
c=1<<4;//1<<4 = 16
c=1<<5;//1<<5 = 32

c=a<<1; //a de�i�kenini 1 bit sola kayd�r, (yani 1 tane s�f�r ekle. yani 2 ile �arp.)
c=b<<2; //b de�i�kenini 2 bit sola kayd�r, (yani 2 tane s�f�r ekle. yani 4 ile �arp.)
c=b>>1; //b de�i�kenini 1 bit sa�a kayd�r, (yani 2 ye b�l. 00000101 -> 00000010)


//& and iki say�n�n ikili say� sisteminde 1 olan bitleri kar��la�t�r�l�p ikiside 1 olan bitler sonuca aktar�l�r (ikisi de 1 olmak zorunda)
c=a&b;
/*
a=8(00001000)
b=5(00000101)
c=0(00000000)  a ve b say�lar�nda ayn� basamaklarda 1 olmad��� i�in sonu� s�f�r
�rnek olmas� i�in b de�i�keninin  3.bitini (en sa�dan sola 0 1 2 3 diye gider) 1 yapsayd�k sonu� ne olurdu
a=8 (00001000)
b=13(00001101)
c=8 (00001000)
*/


//| or iki say�n�n bitlerinin 1 olanlar� birle�tirilir (bir tanesi 1 olsa yeter)
c=a|b;
/*
a=8 (00001000)
b=5 (00000101)
c=13(00001101)
*/


c=0;
//^ xor  ilk say�n�n bitlerini tersler, hangi bitlerin terslenecini ikinci say� belirler
/*
b de�i�keninin de�eri 5 ikili tabanda g�sterimi 00000101 biz bu say�n�n 2.bitini terslemek istiyoruz diyelim
c=b^4; yazmam�z gerekli.
a�arsak
b=5   (00000101)
4     (00000100) 3.bit 1  (1 2 4)
b^4=1 (00000001)

mesela led display s�r�cez ama bizim s�r�c�m�z 1 de�il 0 olunca ledleri yak�yor. Bu durumda elimizde yanacak ledlerin
s�ras� b de�i�keninde olsun b'nin b�t�n bitlerini terslememiz laz�m. �imdilik basit olsun diye i�lemi 8 bitlik d���nelim
yazaca��m�z komut

c=b^255;
b=5   (00000101)
255   (11111111)
c=250 (11111010)
*/

c=b^255;

//mant�ksal do�ru yanl�� (bool)
/*
mant�ksal i�lemleri anlatmak i�in C deki do�ru yanl�� olay�n� anlamak laz�m.
C de bir de�eri ba�ka bir de�erle kar��la�t�r�p e�itmi de�ilmi, b�y�k m� k���k m� di�e bakar�z.
bunun sonucunda da de�i�ik i�lemler yapt�r�r�z. �rnek olarak a de�i�kenin de�erinin 99 olup olmad���n� ��renmek istiyoruz
kullanmam�z gereken yaz�m a==99 �eklinde. bunun sonucunda bize mant�ksal bir de�er �retilir. mant�ksal de�eri C nin bir �ok komutunda kullan�r�z.
bu mant�ksal de�erler asl�nda yine rakamsal olup asl�nda tek 1 durumu g�re de�er al�r. O da s�f�r olup olmad���d�r.

!0 olan de�er yanl��t�r
!0 olmayan her de�er do�rudur

yukar�daki 2 sat�r �okomelli en temel bilinmesi gereken �ey. bu do�ru/yanl�� olay�n� iyice benimsemeden di�er konulara ilerlemeyin.

�imdi �rnekler yapal�m.

a=0;
a->yanl��

a=8;
a->do�ru

a=a-8;
a->yanl�� ��nk� de�eri 0 oldu

a=a-8
a->do�ru ��nk� de�eri -8 oldu

C de do�ru yanl�� kullanan komutlar olmas�na ra�men do�ru/yanl�� de�erlerini saklamak i�in �zel bir de�i�ken tipi yoktur.
b�t�n de�i�kenlerde mant�k ayn�d�r. 0 ise yanl��, 0 de�ilse do�ru

bundan sonra do�ru yanl�� tipi olarak bool diycez kendisine. �rnekleri daha anla��l�r g�stermek i�in ilk C komutumuzu ��reniyoruz

if komutu:

bu komut gayet basit olup verdi�imiz bool (mant�ksal do�ru/yanl��) de�ere g�re i�lem yapar

kullan�m� �u �ekilde dir:

if (X)
   {
   .... x do�ru ise yap�lacak i�ler
   .... x do�ru ise yap�lacak i�ler
   .... x do�ru ise yap�lacak i�ler
   }
   else
   {
   .... x yanl�� is yap�lacak i�ler
   .... x yanl�� is yap�lacak i�ler
   .... x yanl�� is yap�lacak i�ler
   }

mesela a de�i�keninde 8 de�eri var. a'n�n do�ru olup olmad���na bakal�m.
!!! verilen �rneklerde konu ile ilgili yerlere odaklan�n konuyla alakas�z o parantez niye var? , o printf ne i�e yarar, \n de ne olaki  gibi
gereksiz yerlere tak�lmay�n, oda��n�z� kayd�rmay�n.
*/

if (a)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

c=0;
if (c)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

c=100;
if (c)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

c=-100;
if (c)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

//sadece tamsay�lar de�il float de�erlerde de ayn� mant�k

f=0.00001;

if (f)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

f=0.0;

if (f)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

/*
evet hayat�n anlam�n� ��zd���m�ze g�re kullanabilece�imiz mant�ksal i�le�leri tan�yal�m.

== e�it mi?
> b�y�k m�?
< k���k m�?
<= k���k veya e�it mi?
>= b�y�k veya e�it mi
&& ve and
|| veya or
! de�il
burada ! i�areti mant�ksal durumu terslemek i�in kullan�l�r.

�rnekler �rnekler

*/

if (a==8)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if (a>4)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if (a<4)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if (a>=8)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if (a)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }
if (!a)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if ( a>0 && b>0)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if (a==8 || b==8)
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if ( !(a==99) )
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if ( (a<0) )
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

if ( !(a<0))
   {
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }
/*
karma��k ifadeler kullan�lacak ise yanl�� yapmamak ve kolay anla��labilmesi i�in parantezler kullanmak gereklidir. sonu�ta ne kadar karma��k olursa olsun
derleyici onu anlar ama �nemli olan bizim bak�nca anlamam�z, ve derleyiciye do�ru anlatabilmemiz hata yapt�ysak g�rebilmemiz.
mesela
*/


if ( ((a==8) && (b==5)) || ((a+b)>100) )
   {
   // buraya geldiyse ya a'n�n de�eri 8 ve b'nin de�eri 5dir, ve ya a ile b'nin toplam� 100 den b�y�kt�r.
   printf("do�ru\n");
   }
   else
   {
   printf("yanl��\n");
   }

/*
�imdilik bu kadar. anlat�lanlar ile ilgili al��t�rmalar yap�n�z.
mant�ksal do�ru yanl�� kavram� �nemli bunu iyice hazmedin.
internetten �e�itli C kodlar� bulun inceleyin. Orada yaz�lanlardan konuyla alakal� noktalar� anlamaya �al���n.

*/

return 0;
}