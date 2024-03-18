#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//--------------------------- fonksiyonlar ---------------------------
int cikar(int sayi1,int sayi2);
void globali_sil(void);
//--------------------------- global de�i�kenler ---------------------
int globalim_benim;
//--------------------------------------------------------------------


/*
konular

1- dizi de�i�kenler
2- printf fonksiyonu
3- fonksiyon tan�mlar� ve void
*/


int main()
{
globalim_benim=0;
setlocale(LC_ALL,"Turkish");

/*
//-----------------------------------------------------------------------------
1- dizi de�i�kenler : De�i�ken tan�mlarken tek de�i�ken tan�mlad�k. Tek ba��na
bir de�i�ken kullan�rken baz� i�leri yapmak zordur. Baz� durumlarda bir d�ng�
i�inde rutin tekrarlayan i�ler yap�l�rken dizi kullanmak �ok i�e yarar.
dizi tan�mlamak i�in normal de�i�ken tan�m� yaparken de�i�ken ad�n�n sonuna
k��eli parantez i�inde ka� elemanl�k dizi istiyorsak onu belirtiriz.
Kullan�rken de�i�ken ad�n�n arkas�ndan k��eli parantez i�inde index numaras�n�
vererek o de�i�kene ula��r�z.
Dizinin ilk eleman�n�n index numaras� 0 d�r. A�a��daki �rnekte 10 elemanl� dizi
tan�mlad�k bu dizinin elemanlar� 0-9 aras�nda olmak �zere 10 tanedir.
�rnekler vererek dizi olay�n� inceleyelim.
*/
{
int a[10];//10 elemanl� dizi tan�ml�yoruz
int i; // index olarak kullanaca��m�z de�i�ken.

for (i=0; i<10 ;i=i+1) // i'nin de�eri 0'dan ba�lay�p 9'a kadar gidecek
    a[i]=0; //a dizisinin elemanlar�n� s�f�rlayal�m. indeks olarak i de�i�kenini kullan�yoruz.


// de�i�kenlere tek tek de�er veriyoruz
a[0]=2; // a[0] ilk eleman. De�i�kene 2 de�erini koyuyoruz
a[1]=5;
a[2]=1;
a[3]=0;
a[4]=22;
a[5]=23;
a[6]=6;
a[7]=72;
a[8]=26;
a[9]=18; // a[9] son eleman


for (i=0; i<10 ;i=i+1) // i'nin de�eri 0'dan ba�lay�p 9'a kadar gidecek
    printf("a[%d] = %d \r\n", i, a[i] ); //a dizisinin b�t�n elemanlar�n�n de�erini ekrana yazal�m.

}
/*
g�r�ld��� gibi diziler ve d�ng�ler beraber �ok iyi giderler.
de�i�ik veri tiplerinde de mant�k ayn�.
*/
{
int a[20];
unsigned short deneme[100];
float f[50];
char ch[50];

a[0]=12; // ilk eleman
a[19]=22; // son eleman

deneme[0]=12; // ilk eleman
deneme[99]=22; // son eleman

f[0]=3.14; // ilk eleman
f[49]=6.28; // son eleman

ch[0]=12; // ilk eleman
ch[49]=22; // son eleman

}
/*
dizilerde dizinin ilk eleman� 0 dan ba�lar bu �nemli.

char diziler C de text (yaz� karakteri dizileri) saklamak i�in kullan�l�r.
ama bu konuyu sonraya b�rakal�m. Kafa kar��t�rmas�n.

//-----------------------------------------------------------------------------
2- printf fonksiyonu : �rneklerde s�k s�k kulland���m�z printf fonksiyonunu
detayl� inceleme zaman� geldi san�r�m. printf ekrana bilgi basmak i�in
kulland���m�z en temel fonksiyon. �imdiye kadar kulland���m�z �rneklerden a�a��
yukar� ne i�e yarad���n� anlam��s�n�zd�r.

tan�m olarak

printf(format, ... );

�eklinde �zetleyebiliriz. Format dedi�imiz k�s�m ekrana yaz�lacak �eyleri
tan�mlamak ve �ekillendirmek i�in kullan�l�r. formattan sonra varsa yazd�rmak
istedi�imiz de�i�kenleri virg�l ile ay�rarak veririz. E�er sadece ekrana bir
mesaj yazacaksak de�i�ken vermeye gerek yoktur. De�i�ken kullanacaksak
de�i�kenin nas�l g�r�nece�i ve ne tipte olaca��n� belirtmemiz gerekir. Tan�mlar�
d�zg�n anlatabilmek i�in bir �rnek vereyim.
A�a��da int tipinde tan�mlanm�� bir de�i�kenin de�erini ekrana yaz�yoruz.
*/
{
int a;
a=123;



printf("sadece mesaj de�i�ken yok. Yeni sat�r i�in \r\n kullan�yoruz \r\n");
printf("a de�i�keninin de�eri %d \r\n buras� yeni sat�r" , a );

}

/*

�imdi printf sat�r�nda bulunun �eyleri adland�ral�m.

!printf("a de�i�keninin de�eri %d \r\n buras� yeni sat�r" , a );
!|      |----------------------|------------------------    |
!|      |                      |                            |
!|      |                      |                            \->de�i�ken
!|      |                      \->parametre
!|      |
!|      \-> format string
!\->fonksiyonun ad�

format string i�inde ekrana yazaca��m�z �eylerin tan�m� var. de�i�ken yazacaksak
bu de�i�kenlerin nas�l g�r�nece�ini belirtti�imiz parametreler var. ve enson
tabiki yazd�rmak istedi�imiz de�i�kenleri virg�lle ayr�lm�� �ekilde veriyoruz.

parametreler % i�areti ile ba�lar. %'den sonra baya detayl� se�eneklerimiz
mevcut olup ben sadece temel bilinmesi gerekenlerden bahsedicem.

s�k kulland���m�z parametreler ve a��klamalar�
*%d : decimal, i�aretli tam say�
*%u : unsigned decimal, i�aretsiz tam say�
*%f : float ,double
*%c : tek karakter, a=97,b=98, ... A=65,B=66 olmak �zere ascii kodlar� yazd�rmak i�in
*%s : string, text yazd�rmak i�in.

bu parametrelerin de detaylar� var ama �imdilik girmeyelim merak edenler �u adresten
bakabilirler.
http://www.cplusplus.com/reference/cstdio/printf/

ascii tablo i�in
http://www.asciitable.com/

evet �rnekler �rnekler
*/
{
int i;
unsigned int ui;
float f;
char c;
char str[100];


i= -123;
ui= 987;
f= 3.14;
c= 65;
strcpy(str,"Yasir Uslan");// char dizisine string kopyalayan fonksiyon

// �imdi yazd�ral�m

printf("\r\n-----------------------------------------------");
printf("\r\n decimal i=%d",i);
printf("\r\n unsigned decimal ui=%u",ui);
printf("\r\n float f=%f",f);
printf("\r\n char c=%c   decimal c=%d",c,c);
printf("\r\n Benim ad�m %s ...  Ad�m�n ilk harfi %c",str,str[0]);

}
/*
str de�i�keni 100 elemanl� char tipinde de�i�ken
karakter dizileri tutmak i�in kullan�yoruz. Debugger ile detayl� inceleyin.

//-----------------------------------------------------------------------------
3- fonksiyon tan�mlar� ve void : Evet yukar�da C nin bir fonksiyonunu kulland�k.
Art�k kendi fonksiyonlar�m�z� yazman�n zaman� geldi. Fonksiyon ne i�e yarar diye
ba�layal�m. Fonksiyon, ulan ne g�zel program yazd�m ben bunu saklayay�m ilerde
�ok yerde kullan�r�m dedi�imiz g�zide kod par�alar�n�n as�l yap� i�inden ayr�l�p
bir �ok yerde kullan�labilir ayr� bir par�a haline getirilmesidir. Daha �nce de
s�yledi�im gibi bir program yazarken i�i k���k par�alara b�lmek �ok �nemli avantajlar
sa�lar.

    Evet nas�l yap�yoruz. Fonksiyon asl�nda bizim s�rekli kulland���m�z kod bloklar�n�n
isim verilmi� halidir. Kod bloklarda yapamad���m�z baz� g�zellikleri de vard�r.
Mesela printf fonksiyonunda da g�rd���m�z gibi fonksiyona baz� bilgiler g�ndeririz
o bilgilere g�re bir�eyler yapmas�n� bekleriz. Hatta fonksiyondan bilgi de al�r�z.
�yle ya belki bekledi�imiz i� yap�lamad�, bir hata olu�tu. Onun i�in fonksiyonlar
geriye de�er d�nd�rebilirler.

Tan�m olarak fonksiyon ��yledir.

d�n��_de�eri_tipi fonksiyon_ad�(fonksiyona_gidecek_de�erler)

�imdi verdi�imiz iki int de�eri toplay�p geri d�nd�ren fonksiyon yazal�m
*/
int topla(int sayi1,int sayi2) //fonksiyon tan�mlan�yor
{//fonksiyonun kod blo�u
int toplam; //d��ar�dan gelecek iki say�n�n toplam�n� tutmak i�in local de�i�ken a��yoruz
toplam = sayi1 + sayi2; // toplama i�lemi. Sonu� local de�i�kende
return toplam;// fonksiyonun d�n�� de�eri, �a��r�ld��� yere geri d�necek ve toplam de�i�kenin de�erini iletecek
}
/*
evet yukar�daki fonksiyon tam olarak verdi�imiz iki int say�y� toplay�p int olarak geri d�nd�r�yor.

kullanma �ekli ise �u �ekilde
*/
{
int birinci_sayi;
int ikinci_sayi;
int donen_deger;

birinci_sayi=100;
ikinci_sayi=200;

donen_deger = topla(birinci_sayi,ikinci_sayi);

//de�erleri yazal�m
printf("\r\n\n\nbirinci_sayi=%d  ikinci_sayi=%d  fonksiyondan d�nen de�er=%d\r\n",birinci_sayi,ikinci_sayi,donen_deger);
}
/*
olay bu kadar.
- Fonksiyonlara �ok say�da ve her tipte de�er g�nderebiliriz.
- Fonksiyonlardan sadece bir de�er d�nd�rebiliriz.
- Fonksiyonlar kullan�lmadan �nce derleyiciye bildirilmelidir.

son maddeyi a�al�m. Bir fonksiyon kullan�lmadan �nce derleyiciye ben b�yle bir
fonksiyon yazd�m sonra kullan�cam demek laz�md�r. Bunu �� farkl� �ekilde yapabiliriz.

- birinci y�ntem yukar�da yapt���m�z gibi �nce fonksiyonu yaz�p, daha sonraki sat�rlarda
  kullanmak. Bu her zaman m�mk�n olmaz, �zellikle fonksiyon ba�ka bir dosyada ise

- ikinci y�ntem fonksiyon tan�m�n� �nceden derleyiciye bildirmek.
  Fonksiyon tan�m� yapt���m�z �ekilde kod blo�u olmadan <d�n�� de�eri, ad�, ve parametrelerinin oldu�u sat�r�> al�p
  �st taraflara bir yere koymak.

?- ���nc� y�ntem ise fonksiyon tan�mlar�n�n hepsini bir yere toplay�p ayr� bir
?  dosyaya yazmak, ve program�n ba��nda bu dosyalar� #include ile programa eklemek.
?  bu dosyan�n en ba��ndaki sat�rlar� nihayet anlad�k. hemen gidip bu g�zle bir daha bak�n.
?  hatta bahsi ge�en dosyalar� mouse sa� tu� t�klay�p a��p i�inde tan�mlanm�� bi
?  ton abuk sabuk �eyleri g�r�n. :) �o�unu ben bile anlamasam da kulland���m�z
?  printf gibi fonksiyonlar�n tan�mlar� oralarda yap�l�yor.

evet bir ka� �rnek fonksiyon yazmadan evvel void mevzusuna girelim

void tan�ms�z demektir. T�rk�edeki �ey gibi bi�i.

fonksiyon tan�mlarken e�er de�er d�nd�rmeyeceksek tipini void olarak tan�mlar�z.

mesela
*/
void deger_dondurmeyen_fonksiyon(int fonksiyona_giden_deger)
{
printf("\r\n ben sadece ekrana bunu yazar�m. \r\n %d \r\n",fonksiyona_giden_deger);
//return; // olmasa da olur.
}
/*
geri de�er d�nmeyece�i i�in fonksiyonun sonunda return kullanmad�m. Zaten blok kapand��� i�in
fonksiyon bitmi�tir. geri d�necektir.

ayn� �ekilde e�er fonksiyona de�er g�ndermeyeceksek tan�mlarken bunu da void olarak belirtiriz
�rnek hi� parametre almayan ve geri de�er d�nd�rmeyen fonksiyon.
kullan�m� a�a��da
*/
void almam_vermem(void)
{
printf("ben kendi kafama g�re tak�l�r�m ama globalleride oynar�m\r\n");
globalim_benim = globalim_benim + 1; //main den �nce tan�mlanm�� global de�i�ken
printf("Bu fonksiyon %d kere �al��t�\r\n",globalim_benim);
}
/*
fonksiyonlardan ��kmak i�in illede blo�un sonuna ula�mak �art de�ildir.
bir d�ng�n�n i�indeyken return ile ��k�labilir. geri de�er d�nd�ren fonksiyon ise
return den sonra d�necek de�eri belirtmemiz laz�md�r.

//-----------------------------------------------------------------------------

evet fazla uzatmadan burada bitirelim. a�a��ya bir fonksiyon daha yazaca��m.
onun tan�m�n� en �ste yazd�m ��nk� fonksiyonu program�n en sonunda yazaca��m,
ama �imdi kullanaca��m i�in yukar�da tan�mlamam gerek. �rnek olmas� i�in gidip
yukar�daki tan�mland��� yeri // ile kapat�p derleyicinin nas�l m�z�ldad���n� g�r�n.
�al���n ,debugger ile nas�l �al��t���n� inceleyin. sat�r sat�r �al��t�r�rken
program ak���n�n fonksiyonlara nas�l dallan�p geri geldi�ine dikkat edin.
Debuggerdeki StepInto ile fonksiyona dallanmay� g�r�n.

kolay gelsin.

//-----------------------------------------------------------------------------
*/
{
int a,b,c;
a=123;
b=456;

almam_vermem();
almam_vermem();
almam_vermem();
almam_vermem();


c=cikar(a,b);
printf("a - b = %d\r\n",c);
}


//-----------------------------------------------------------------------------
return 0;
}
//------------------------------------------------------------------------------
int cikar(int sayi1,int sayi2)
{
return sayi1 - sayi2;
}
//------------------------------------------------------------------------------