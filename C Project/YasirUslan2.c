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
matematiksel iþleçler
mantýksal doðru yanlýþ
mantýksal iþleçler
*/


/*
matematiksel iþleçler
+ toplama
- çýkarma
* çarpma
/ bölme
% mod (tamsayý bölmeden sonra kalan kýsým)
! << bit sola kaydýrma
! >> bit saða kaydýrma
& and (bit olarak ve iþlemi)
| or (bit olarak ve iþlemi)
^ xor (bit olarak xor iþlemi)
*/

c=a+b;
c=a+10;
c=a+b+c+13+a+3+b+b+b+12;
c=12+234;

//çýkarma

c=a-b;
c=b-a;
c=(a+10)-(b+5);
c=10-30;

//çarpma
c=a*b;

//bölme
//bölme iþlemi yaparken deðiþken tiplerine göre alabileceðiniz sonuçlar deðiþir.
//tamsayý deðerler ile yapýlan iþlemlerde sonuç da tamsayýdýr.
c=a/b; //a=8 b=5 c=1  tamsayý olarak 8/5=1

//% mod iþlemi
c=a%b;//c deðeri a/b iþleminin kalan deðeri 8/5=1  8-(8/5)=3

//<< ve >> iþlemleri ikili sayý sisteminde basamak kaydýrmadýr. kaydýrma iþleminden sonra boþalan basamaklara 0 konur
//biz on tabanlý sayý sisteminde sayýnýn sonuna 0 eklediðimizde 10 ile çarpmýþ oluyoruz.
//Ayný þekilde 2 tabanlý sayý sisteminde sayýnýn sonuna 0 eklediðimizde 2 ile çarpmýþ oluruz
c=1<<5;//1 sayýsýný 5 bit sola kaydýr.
c=1<<0;//1<<0 = 1 (1 sayýsýný 0 kere sola kaydýr. yani bi bok yapma)
c=1<<1;//1<<1 = 2
c=1<<2;//1<<2 = 4
c=1<<3;//1<<3 = 8
c=1<<4;//1<<4 = 16
c=1<<5;//1<<5 = 32

c=a<<1; //a deðiþkenini 1 bit sola kaydýr, (yani 1 tane sýfýr ekle. yani 2 ile çarp.)
c=b<<2; //b deðiþkenini 2 bit sola kaydýr, (yani 2 tane sýfýr ekle. yani 4 ile çarp.)
c=b>>1; //b deðiþkenini 1 bit saða kaydýr, (yani 2 ye böl. 00000101 -> 00000010)


//& and iki sayýnýn ikili sayý sisteminde 1 olan bitleri karþýlaþtýrýlýp ikiside 1 olan bitler sonuca aktarýlýr (ikisi de 1 olmak zorunda)
c=a&b;
/*
a=8(00001000)
b=5(00000101)
c=0(00000000)  a ve b sayýlarýnda ayný basamaklarda 1 olmadýðý için sonuç sýfýr
örnek olmasý için b deðiþkeninin  3.bitini (en saðdan sola 0 1 2 3 diye gider) 1 yapsaydýk sonuç ne olurdu
a=8 (00001000)
b=13(00001101)
c=8 (00001000)
*/


//| or iki sayýnýn bitlerinin 1 olanlarý birleþtirilir (bir tanesi 1 olsa yeter)
c=a|b;
/*
a=8 (00001000)
b=5 (00000101)
c=13(00001101)
*/


c=0;
//^ xor  ilk sayýnýn bitlerini tersler, hangi bitlerin terslenecini ikinci sayý belirler
/*
b deðiþkeninin deðeri 5 ikili tabanda gösterimi 00000101 biz bu sayýnýn 2.bitini terslemek istiyoruz diyelim
c=b^4; yazmamýz gerekli.
açarsak
b=5   (00000101)
4     (00000100) 3.bit 1  (1 2 4)
b^4=1 (00000001)

mesela led display sürücez ama bizim sürücümüz 1 deðil 0 olunca ledleri yakýyor. Bu durumda elimizde yanacak ledlerin
sýrasý b deðiþkeninde olsun b'nin bütün bitlerini terslememiz lazým. þimdilik basit olsun diye iþlemi 8 bitlik düþünelim
yazacaðýmýz komut

c=b^255;
b=5   (00000101)
255   (11111111)
c=250 (11111010)
*/

c=b^255;

//mantýksal doðru yanlýþ (bool)
/*
mantýksal iþlemleri anlatmak için C deki doðru yanlýþ olayýný anlamak lazým.
C de bir deðeri baþka bir deðerle karþýlaþtýrýp eþitmi deðilmi, büyük mü küçük mü diðe bakarýz.
bunun sonucunda da deðiþik iþlemler yaptýrýrýz. örnek olarak a deðiþkenin deðerinin 99 olup olmadýðýný öðrenmek istiyoruz
kullanmamýz gereken yazým a==99 þeklinde. bunun sonucunda bize mantýksal bir deðer üretilir. mantýksal deðeri C nin bir çok komutunda kullanýrýz.
bu mantýksal deðerler aslýnda yine rakamsal olup aslýnda tek 1 durumu göre deðer alýr. O da sýfýr olup olmadýðýdýr.

!0 olan deðer yanlýþtýr
!0 olmayan her deðer doðrudur

yukarýdaki 2 satýr çokomelli en temel bilinmesi gereken þey. bu doðru/yanlýþ olayýný iyice benimsemeden diðer konulara ilerlemeyin.

þimdi örnekler yapalým.

a=0;
a->yanlýþ

a=8;
a->doðru

a=a-8;
a->yanlýþ çünkü deðeri 0 oldu

a=a-8
a->doðru çünkü deðeri -8 oldu

C de doðru yanlýþ kullanan komutlar olmasýna raðmen doðru/yanlýþ deðerlerini saklamak için özel bir deðiþken tipi yoktur.
bütün deðiþkenlerde mantýk aynýdýr. 0 ise yanlýþ, 0 deðilse doðru

bundan sonra doðru yanlýþ tipi olarak bool diycez kendisine. örnekleri daha anlaþýlýr göstermek için ilk C komutumuzu öðreniyoruz

if komutu:

bu komut gayet basit olup verdiðimiz bool (mantýksal doðru/yanlýþ) deðere göre iþlem yapar

kullanýmý þu þekilde dir:

if (X)
   {
   .... x doðru ise yapýlacak iþler
   .... x doðru ise yapýlacak iþler
   .... x doðru ise yapýlacak iþler
   }
   else
   {
   .... x yanlýþ is yapýlacak iþler
   .... x yanlýþ is yapýlacak iþler
   .... x yanlýþ is yapýlacak iþler
   }

mesela a deðiþkeninde 8 deðeri var. a'nýn doðru olup olmadýðýna bakalým.
!!! verilen örneklerde konu ile ilgili yerlere odaklanýn konuyla alakasýz o parantez niye var? , o printf ne iþe yarar, \n de ne olaki  gibi
gereksiz yerlere takýlmayýn, odaðýnýzý kaydýrmayýn.
*/

if (a)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

c=0;
if (c)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

c=100;
if (c)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

c=-100;
if (c)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

//sadece tamsayýlar deðil float deðerlerde de ayný mantýk

f=0.00001;

if (f)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

f=0.0;

if (f)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

/*
evet hayatýn anlamýný çözdüðümüze göre kullanabileceðimiz mantýksal iþleçleri tanýyalým.

== eþit mi?
> büyük mü?
< küçük mü?
<= küçük veya eþit mi?
>= büyük veya eþit mi
&& ve and
|| veya or
! deðil
burada ! iþareti mantýksal durumu terslemek için kullanýlýr.

örnekler örnekler

*/

if (a==8)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if (a>4)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if (a<4)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if (a>=8)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if (a)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }
if (!a)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if ( a>0 && b>0)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if (a==8 || b==8)
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if ( !(a==99) )
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if ( (a<0) )
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

if ( !(a<0))
   {
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }
/*
karmaþýk ifadeler kullanýlacak ise yanlýþ yapmamak ve kolay anlaþýlabilmesi için parantezler kullanmak gereklidir. sonuçta ne kadar karmaþýk olursa olsun
derleyici onu anlar ama önemli olan bizim bakýnca anlamamýz, ve derleyiciye doðru anlatabilmemiz hata yaptýysak görebilmemiz.
mesela
*/


if ( ((a==8) && (b==5)) || ((a+b)>100) )
   {
   // buraya geldiyse ya a'nýn deðeri 8 ve b'nin deðeri 5dir, ve ya a ile b'nin toplamý 100 den büyüktür.
   printf("doðru\n");
   }
   else
   {
   printf("yanlýþ\n");
   }

/*
þimdilik bu kadar. anlatýlanlar ile ilgili alýþtýrmalar yapýnýz.
mantýksal doðru yanlýþ kavramý önemli bunu iyice hazmedin.
internetten çeþitli C kodlarý bulun inceleyin. Orada yazýlanlardan konuyla alakalý noktalarý anlamaya çalýþýn.

*/

return 0;
}