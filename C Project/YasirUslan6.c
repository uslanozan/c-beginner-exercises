#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
/*
konular

1- pointer
2- sizeof
*/
//-----------------------------------------------------------------------------
void pointerGoster(char* x);
int diziGoster(void* x, int diziBoyutu, int elemanUzunlugu);
//-----------------------------------------------------------------------------
char charDizi[] = "Yasir Uslan";
int intDizi[] = {11,22,33,44,55,66,77,88,99,-1};
short shortDizi[] = {11,22,33,44,55,66,77,88,99,-1};


/*
//-----------------------------------------------------------------------------
C dilinde en �ok kafa kar��t�ran olaylardan birine giriyoruz. Pointer.
Pointer konusuna girmeden �nce bilgisayarlarda haf�za yap�s�n� az biraz anlatmak istiyorum.
B�t�n bilgisayarlar de�i�ik tipte haf�zalara sahiptir. ��lemciler bu haf�za b�lgelerine eri�mek i�in
bir adresleme sistemi kullan�rlar.//! Bu sistemde her bir byte'�n bir adresi vard�r. Bu haf�za b�lgeleri
donan�m�n �zelliklerine g�re sadece okunabilir, sadece yaz�labilir veya hem okunup hem yaz�labilir olabilir.
�imdilik bizim programlar�m�zda de�i�kenlerin tutuldu�u haf�za b�lgelerine yak�ndan bakal�m.
Bu b�lge ram dedi�imiz b�lge. Hem okunur hem yaz�l�r b�lge. C de bir de�i�ken tan�mlad���m�zda bu haf�zan�n
bir yeri tan�mlad���m�z de�i�kene ayr�l�r. Bu de�i�kene bir de�er yazd���m�zda o adresdeki haf�za b�lgesine
verdi�imiz de�er yaz�l�r. o de�i�kenin de�eri laz�m oldu�unda bulundu�u adresdeki haf�za okunur.
Olay� basitle�tirerek anlatmak i�in 5 byte'l�k haf�zas� olan bir bilgisayar d���nelim. �lk haf�za b�lgesinin
adresi de s�f�rdan ba�las�n. Her bir adresde 8bit'lik 1byte'l�k ram haf�za bulunsun. B�t�n haf�za
b�lgelerinin i�eriklerinin s�f�r oldu�unu kabul edelim.

Kafan�zda canland�rabilmeniz i�in g�rsel olarak �u �ekilde yazal�m.
adres  i�erik
 0       0
 1       0
 2       0
 3       0
 4       0

 bu �ekilde 5 byte'l�k bir haf�zam�z�n oldu�unu d���n�nerek sanal bir program yazal�m.
 char a;
 char b;
 char c;
diyerek 3 tane char tipinde de�i�ken tan�mlayal�m. �lk tan�mlanan de�i�ken 0 adresine di�erleride s�rayla 1 ve 2 ye
yerle�sin. son durum �u �ekilde olacakt�r.

adres  i�erik a��klama
 0       0    a de�i�keni (char)
 1       0    b de�i�keni (char)
 2       0    c de�i�keni (char)
 3       0
 4       0

 �imdi a de�i�kenine 10, b de�i�kenine 20 de�erini yazal�m.
 a=10;
 b=20;

 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2       0    c de�i�keni (char)
 3       0
 4       0

a ve b de�i�kenlerinin de�erinin toplam�n� c ye yazal�m
c=a+b;

 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2      30    c de�i�keni (char)
 3       0
 4       0

evet 3 numaral� haf�za adresindeki c de�i�kenin de�eri 30 oldu.
Program yazarken bu de�i�kenlerin haf�zan�n neresine yaz�laca�� bizi ilgilendirmez. O i� i�letim sistemi
ile c derleyicisinin sorunu.//* Ama istersek de�i�kenlerin adreslerini sorup ��renebiliriz. Hatta �u adrese bunu
*yaz diyerek kendimiz haf�za b�lgelerine de eri�ebilir oralar� okuyup yazabiliriz.

?Bir de�i�kenin adresini kullanmak istersek de�i�ken ad�n�n �n�ne & i�areti koyar�z. �rnek olarak a de�i�keninin
de�eri 10 adresi 0.
�imdi a de�i�keninin adresini ve i�eri�ini ekrana yazd�ral�m

printf("adres : %d   i�erik : %d \r\n", &a , a);

ekran ��kt�m�z �u �ekilde olur
adres : 0   i�erik : 10

evet son noktay� koyma zaman� geldi. Pointer dedi�imiz �ey ba�ka bir de�i�kenin adres de�erini tutan de�i�kendir.
Yani kendisi de bir de�i�kendir ama i�eri�i ba�ka bir de�i�kenin adresidir.

Pointer arkada��m�z madem ki ba�ka bir de�i�kenin adresini g�sterecek, g�sterdi�i adresde hangi tip de�i�ken oldu�unu
derleyiciye s�ylememiz gerekir. ��nk� de�i�kenlerimiz haf�zada ayn� miktarda yer kaplamazlar. Ayn� miktarda yer kaplasa
bile i�aretli mi de�il mi int mi float m� gibi de�i�ik muamele isteyen de�i�kenlerin kar��mamas� i�in pointer de ayn�
de�i�ken gibi tan�mlan�r.

�imdi 5 byt'l�k ram'� olan, dandik sanal bilgisayar�m�za d�n�p, bir pointer tan�mlayal�m. Haf�zada bo� olan ilk adrese
yerle�ecek olan bu pointerimize p ad�n� verelim. char tipli de�i�kenlerin adresini tutmak i�in tipi char olsun.

char *p;

 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2      30    c de�i�keni (char)
 3       0    p pointeri  (char*)
 4       0

!Bu p ad�ndaki pointerimizi tan�mlarken ad�n�n �n�ndeki * i�aretinden ba�ka bir yenilik yok. B�t�n tiplerde, tan�mlan�rken
!ad�n�n �n�nde * olunca o arkada� pointer olur.
Devam edelim, pointerimize b de�i�kenin adresini yazal�m.

p=&b;

 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2      30    c de�i�keni (char)
 3       1    p pointeri  (char*) (b de�i�keninin adresi var)
 4       0

evet g�r�ld��� �zere p bir de�i�kendir. 3 numaral� haf�za adresindedir. Saklad��� de�er yani i�eri�i 1 dir. 1 de�eri b
de�i�keninin adresidir.

Bu durumu iyice anlay�ncaya kadar ilerlemeyin ba�a d�n�p anlaya anlaya tekrar okuyun. Gerekirse sorun.

Elimizde bir tane pointerimiz var. �imdi bu pointeri kullanarak i�lemler yapal�m.

// pointere de�er atamak
p=&a; // p pointerine a de�i�keninin adresini(0) yaz
 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2      30    c de�i�keni (char)
 3       0    p pointeri  (char*)
 4       0


// pointerin g�sterdi�i de�i�keni okumak
!c=*p; //c de�i�kenine, p pointerinin g�sterdi�i adresdeki(0) de�i�kenin(a) i�eri�ini yaz
 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2      10    c de�i�keni (char)
 3       0    p pointeri  (char*)
 4       0

// pointerin g�sterdi�i de�i�kene yazmak
p=&c; // p pointerine c de�i�keninin adresini(2) yaz
*p=40;// p pointerinin g�sterdi�i adrese(2) 40 de�erini yaz
 haf�zam�z :
adres  i�erik a��klama
 0      10    a de�i�keni (char)
 1      20    b de�i�keni (char)
 2      40    c de�i�keni (char)
 3       2    p pointeri  (char*)
 4       0

Son �rnekte g�r�ld��� �zere pointer ile �al���rken (dikkat: pointer tan�mlarken de�il) pointerin ba��nda * varsa
i�lemler pointerin g�sterdi�i adrese yap�l�r. * yoksa i�lemler pointerin kendine yap�l�r.

Pointerlere de de�i�kenlerde oldu�u gibi matematiksel i�lemler uygulanabilir. Toplama, ��karma, �arpma, b�lme,++,-- ...

Dikkat : pointerlerin i�eri�i ile u�ra��rken pointerin tipi �nemlidir.
char   tipli bir pointerin de�erini ++ ile artt�r�rsak de�eri 1 artar ��nk� haf�zada char  1 byte'l�k yer kaplar.
Short  tipli bir pointerin de�erini ++ ile artt�r�rsak de�eri 2 artar ��nk� haf�zada short 2 byte'l�k bir kaplar.
float  tipli bir pointerin de�erini ++ ile artt�r�rsak de�eri 4 artar ��nk� haf�zada float 4 byte'l�k bir kaplar.
double tipli bir pointerin de�erini ++ ile artt�r�rsak de�eri 8 artar ��nk� haf�zada float 8 byte'l�k bir kaplar.
ayn� mant�k di�er matematiksel i�lemlerde de ge�erlidir.
int tipi derleyiciye g�re de�i�ir 32bit i�in 4 byte, 64 bit i�in 8 byte.

de�i�kenlerin, dizilerin haf�zada ne kadar yer kaplad���n� ��renmek i�in sizeof(x) kullan�l�r. x yerine bu
sayd�klar�m�n herhangi birini kullanabilirsiniz.
�rnek olarak a�a��da yazd�m.

evet son olarak tipsiz bir pointer tan�m� var ondan bahsedelim :) void * olarak tan�mlanan pointerler sadece adres
tutarlar, ++ , -- i�lemlerinde de�erleri 1 de�i�ir. Genelde tipi bilinmeyen veya tipi �nemli olmayan i�ler i�in
kullan�l�rlar. Bunun d���nda �ok bir i�e yaramazlar bir �zellikleri yoktur. Genel maksat pointeri de denebilir. :)

pointer kullanarak baz� �rnekler yapal�m
*/
int main()
    {
    char a, b, c, * p;
    short s;
    int i;
    float f;
    double d;

    a = 10;
    b = 20;
    c = 0;

    p = &c;//p pointerine c de�i�keninin adresini yaz
    *p = a + b;//p pointerinin g�sterdi�i adrese a+b yi yaz;
    printf("c nin degeri :%d \r\n", c);
    //bir de�i�kenin haf�zada ne kadar yer kaplad���n� bulmak i�in sizeof kullan�l�r
    printf("c char degiskeninin hafizada kapladigi byte  : %d \r\n", sizeof(c));
    printf("s short degiskeninin hafizada kapladigi byte : %d \r\n", sizeof(s));
    printf("i int degiskeninin hafizada kapladigi byte   : %d \r\n", sizeof(i));
    printf("f float degiskeninin hafizada kapladigi byte : %d \r\n", sizeof(f));
    printf("d double degiskeninin hafizada kapladigi byte: %d \r\n", sizeof(d));


    // bir fonksiyona parametre olarak pointer g�nderme olay�
    pointerGoster(p);

    p = 0;
    pointerGoster(p);

    p = charDizi;
    printf("\r\n Adres        icerik   karakter \r\n");
    for (i = sizeof(charDizi); i; i--)
        {
        printf("%d \t %d \t %c\r\n", p, *p, *p);
        p++;
        }

    pointerGoster((char*)shortDizi);
    pointerGoster((char*)intDizi);

    printf("\n\nintDizi'nin toplam kapladigi alan        : %d byte \r\n", sizeof(intDizi));
    printf("intDizi'nin bir elemaninin kapladigi alan: %d byte \r\n", sizeof(intDizi[0]));
    printf("intDizi'nin eleman sayisi                : %d \r\n", sizeof(intDizi) / sizeof(intDizi[0]));


    return 0;
    }
//------------------------------------------------------------------------------
void pointerGoster(char* x)
    {
    int i;
    //gelen pointerle bi�iler yapal�m

    printf("---------------------------------------------\r\n");
    printf("Pointerin hafizadaki adresi         : %d \r\n", &x);
    printf("Pointerin icerigi                   : %d \r\n", x);
    if (x == 0)
        {
        printf("Gelen pointer degeri 0 olmasin isletim sistemi KIZIYOR\r\n");
        return;
        }
    printf("Pointerin gosterdigi adresin icerigi: %d \r\n", *x);
    printf("pointerin hafizada kapladigi byte   : %d \r\n", sizeof(x));
    //bir de�i�kenin haf�zada ne kadar yer kaplad���n� bulmak i�in sizeof kullan�l�r

    //pointerin g�sterdi�i yerin ilerisinde neler var bir g�z atal�m
    //buralarda olan verilerin ne oldu�unu bi derleyici bi de Allah bilir.
    printf(" Adres      icerik \r\n");
    for (i = 10; i; i--)
        {
        printf(" %d    %d \r\n", x, *x);
        x++;
        }
    }
//------------------------------------------------------------------------------