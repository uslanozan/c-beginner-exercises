#include <stdio.h>
#include <stdlib.h>

int main()
{
    // bu sat�rlar a��klama sat�rlar�d�r. derleyici buralar� i�lemez

    //------------- de�i�ken tan�mlama
    //! i�aretli tamsay�lar ve kapasiteleri
    char a;     //* 8 bit
    short b;    //* 16 bit
    int c;      //* 32 bit
    long long d; //* 64 bit

    //! i�aretsiz tamsay�lar ve kapasiteleri
    unsigned char e;     //* 8 bit
    unsigned short f;    //* 16 bit
    unsigned int g;      //* 32 bit
    unsigned long long h; //* 64 bit


    //! kayan noktal� ondal�kl� de�i�kenler
    float i;     //* 32 bit
    double j;     //* 64 bit


    //de�i�kenlere de�er atama �rnek
    a=1; //a char(8bit) tipinde
    b=a; // b short(16bit) tipinde oldu�u i�in 8 bitlik a de�i�keninin de�erini alabilir. tersi durum sak�ncal�d�r. b�y�k de�er varsa k���k de�i�kene s��mayabilir.
    c=a+b+5; // ayn� �ekilde c int(32bit) oldu�u i�in hepsinin toplam�n� tutabilir.
    i=3.14; // ondal�kl� say�lar yaz�l�rken nokta i�areti kullan�l�r
    j=i/2.3344; //double tipi float'dan daha b�y�k ve hassast�r.


    //de�i�kenlerin tutabilece�i minimum ve maksimum de�erler
    e = 0;  // unsigned char min
    e = 255; // unsigned char max

    a = -128; //char min
    a = 127;  //char max

    //?i�aretli say�lar da 1 bit say�n�n negatif/pozitif oldu�unu belirlemek i�in kullan�ld���ndan, ayn� tipin i�aretsizinin yar�s� kadar b�y�k say�larla �al��abilir.

    /*
    
    De�i�kenler ve veri tipleri


Bilgisayarda programlama yaparken de�i�ken dedi�imiz veri par�alar� kullan�r�z.
Bu veriler �zerinde �al��t���m�z, bir sonu� elde etmemiz gereken veriler oldu�u gibi,
bu i�leri yaparken kulland���m�z i�lem basamaklar�nda bize yard�mc� olacak k���k notlar gibidir.
    
    Ger�ek d�nyadan �rnek verecek olursak bir binaya giren-��kan ki�ileri saymak istesek,
kap�da durup her giren ve ��kan� sayar�z. Bir s�re sonra kafam�z kar��mas�n diye ka��da
gireni ��kan� ve saati not ald���m�z� d���nelim. �� bitti�inde bir excel sayfas�na ilk
s�tuna tarih saat, sonra giren ve ��kan ki�i say�s�n�, son s�tuna da binadaki mevcut ki�i
say�s�n� hesaplatt�k diyelim. ��te programlamada da buna benzer bir mant�kla program
i�erisinde bilgileri saklamak, �st�nde i�lem yapmak i�in de�i�kenleri kullan�r�z. Excel
�rne�inden devam edersek, olu�turdu�umuz tablonun s�tunlar� bizim de�i�kenlerimiz oluyor.
Her sat�rda de�i�kenlerin de�erinin de�i�mesini de �al��an programda de�i�kenlerin de�erinin
de�i�mesi olarak g�rebiliriz.

    C de de�i�ik tipte verilerle �al��mak i�in de�i�ik veri tipleri vard�r. Az �nceki excel
�rne�imizde ilk s�tuna zaman bilgisini koyduk. Bu h�crenin saklad��� de�er zaman� g�steriyor.
Yani verinin tipi zaman g�sterecek tip oluyor. Sonraki h�cremiz giren ki�i say�s�. Bu h�cre de
giren ki�ileri g�steriyor. Bu say�sal bir de�er ve pozitif olmak zorunda. -3 ki�i girdi demeyiz.
Onu ��kanlar s�tununa 3 ki�i ��kt� olarak yazar�z. Yani giren ve ��kan ki�i say�s� pozitif
tam say� olmak zorunda. 3.5 ki�i girdi diyemeyiz. Son s�tunda ise binadaki mevcut ki�i say�s�.
Bu veri de tam say� olmak zorunda. Yar�m insan girdi diyemeyiz. Ama sonucu negatif ��kabilir.
��nk� bu s�tunun de�erini giren ve ��kan ki�i say�s�na g�re hesap yap�p buluyoruz. ��eriye bizi
kand�rmak i�in arka pencereden giren muzip arkada�lar�m�z�n �n kap�dan ��kt���n� d���nelim.
Dolays�yla buradaki veri tipimiz hem negatif hem pozitif say�lar� g�sterebilecek i�aretli bir
say� tipi olmal�d�r.
    
    Programlama dilleri bize bu t�r de�i�ik veri tipleri ile �al��ma imkan� verirler. C de veri
tipleri 4 ana ba�l�kta toplanabilir.
Bunlar:
1-i�aretli tamsay�lar  : char,short,int
2-i�aretsiz tamsay�lar : unsigned char, unsigned short, unsigned int
3-��aretli kayan noktal� veya ondal�kl� say�lar : float,double
4-Kendi tan�mlad���m�z veri tipleridir.

Bilgisayarlar verileri haf�zalarda saklarlar. �e�itli haf�za tipleri olsa da hepsi ayn� mant�kla
ifade edilirler. Bilgisayarlarda en k���k bilgi par�as�na bit denir ve 0 veya 1 de�eri al�rlar.
Bilgisayar haf�zalar� 8 tane bitin yan yana getirilmesi ile olu�an byte'lar dizisi halinde tutulur.
8 bit -> 1byte
1024 byte -> 1KB kilo byte
1024 KB -> 1MB mega byte
1024 MB -> 1GB giga byte
1024 GB -> 1TB tera byte
�eklinde devam eder gider.


    Bir byte'�n b�t�n bitleri 0 ise o byt�n say�sal de�eri 0 d�r. B�t�n bitleri 1 ise 255 dir.
Burada �ok az bu 0-1 ile ifade edilen ikili say� sisteminden bahsedelim.
0 ve 1 kullanarak her seferinde 1 artan ikili say� sistemi ve kar��l�k ondal�k say� sistemi de�erleri:

�kili Say� Sistemi   Onlu Say� Sistemi
 (binary)               (decimal)
00000000                    0
00000001                    1
00000010                    2
00000011                    3
00000100                    4
00000101                    5
00000110                    6
00000111                    7
00001000                    8
00001001                    9
00001010                    10
00001011                    11
00001100                    12
00001101                    13
00001110                    14
00001111                    15
00010000                    16
   ...                        ..
   ...                        ..
11111111                    255
   
��te sadece 8 tane 0/1 den olu�an bir byte'l�k bilgisayar haf�zas� verileri bu �ekilde saklar.


    ��aretli ve i�aretsiz veri tipleri de ifade edebilecekleri en b�y�k ve en k���k say�lara g�re de�i�iklik
g�sterirler. �imdi bunlar� ka� bitlik kapasitesi oldu�una g�re s�ral�yal�m.

char tipi 1 byte
short tipi 2 byte
int tipi 4/8 byte
float 4 byte
double 8 byte

Bu de�erlerde int tipi genelde derleyicinin ve �al��t��� makinan�n �zellikleri ile alakal� olup 32bit/64bit
sistemlere g�re de�i�ir. �imdilik �ok �nemli de�il.

    ��aretli tiplerde en y�ksek bit basama�� say�n�n i�aretidir. 0 ise pozitif 1 ise negatifdir. 1biti i�arete
ayr�ld��� i�in bu tiplerin ifade etti�i maksimum ve minimum de�erleri ayn� tipin i�aretsizinden farkl�d�r.
*/


    return 0;
}