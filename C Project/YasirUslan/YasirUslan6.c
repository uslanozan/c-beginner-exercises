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
C dilinde en çok kafa karýþtýran olaylardan birine giriyoruz. Pointer.
Pointer konusuna girmeden önce bilgisayarlarda hafýza yapýsýný az biraz anlatmak istiyorum.
Bütün bilgisayarlar deðiþik tipte hafýzalara sahiptir. Ýþlemciler bu hafýza bölgelerine eriþmek için
bir adresleme sistemi kullanýrlar.//! Bu sistemde her bir byte'ýn bir adresi vardýr. Bu hafýza bölgeleri
donanýmýn özelliklerine göre sadece okunabilir, sadece yazýlabilir veya hem okunup hem yazýlabilir olabilir.
Þimdilik bizim programlarýmýzda deðiþkenlerin tutulduðu hafýza bölgelerine yakýndan bakalým.
Bu bölge ram dediðimiz bölge. Hem okunur hem yazýlýr bölge. C de bir deðiþken tanýmladýðýmýzda bu hafýzanýn
bir yeri tanýmladýðýmýz deðiþkene ayrýlýr. Bu deðiþkene bir deðer yazdýðýmýzda o adresdeki hafýza bölgesine
verdiðimiz deðer yazýlýr. o deðiþkenin deðeri lazým olduðunda bulunduðu adresdeki hafýza okunur.
Olayý basitleþtirerek anlatmak için 5 byte'lýk hafýzasý olan bir bilgisayar düþünelim. Ýlk hafýza bölgesinin
adresi de sýfýrdan baþlasýn. Her bir adresde 8bit'lik 1byte'lýk ram hafýza bulunsun. Bütün hafýza
bölgelerinin içeriklerinin sýfýr olduðunu kabul edelim.

Kafanýzda canlandýrabilmeniz için görsel olarak þu þekilde yazalým.
adres  içerik
 0       0
 1       0
 2       0
 3       0
 4       0

 bu þekilde 5 byte'lýk bir hafýzamýzýn olduðunu düþününerek sanal bir program yazalým.
 char a;
 char b;
 char c;
diyerek 3 tane char tipinde deðiþken tanýmlayalým. Ýlk tanýmlanan deðiþken 0 adresine diðerleride sýrayla 1 ve 2 ye
yerleþsin. son durum þu þekilde olacaktýr.

adres  içerik açýklama
 0       0    a deðiþkeni (char)
 1       0    b deðiþkeni (char)
 2       0    c deðiþkeni (char)
 3       0
 4       0

 þimdi a deðiþkenine 10, b deðiþkenine 20 deðerini yazalým.
 a=10;
 b=20;

 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2       0    c deðiþkeni (char)
 3       0
 4       0

a ve b deðiþkenlerinin deðerinin toplamýný c ye yazalým
c=a+b;

 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2      30    c deðiþkeni (char)
 3       0
 4       0

evet 3 numaralý hafýza adresindeki c deðiþkenin deðeri 30 oldu.
Program yazarken bu deðiþkenlerin hafýzanýn neresine yazýlacaðý bizi ilgilendirmez. O iþ iþletim sistemi
ile c derleyicisinin sorunu.//* Ama istersek deðiþkenlerin adreslerini sorup öðrenebiliriz. Hatta þu adrese bunu
*yaz diyerek kendimiz hafýza bölgelerine de eriþebilir oralarý okuyup yazabiliriz.

?Bir deðiþkenin adresini kullanmak istersek deðiþken adýnýn önüne & iþareti koyarýz. Örnek olarak a deðiþkeninin
deðeri 10 adresi 0.
þimdi a deðiþkeninin adresini ve içeriðini ekrana yazdýralým

printf("adres : %d   içerik : %d \r\n", &a , a);

ekran çýktýmýz þu þekilde olur
adres : 0   içerik : 10

evet son noktayý koyma zamaný geldi. Pointer dediðimiz þey baþka bir deðiþkenin adres deðerini tutan deðiþkendir.
Yani kendisi de bir deðiþkendir ama içeriði baþka bir deðiþkenin adresidir.

Pointer arkadaþýmýz madem ki baþka bir deðiþkenin adresini gösterecek, gösterdiði adresde hangi tip deðiþken olduðunu
derleyiciye söylememiz gerekir. Çünkü deðiþkenlerimiz hafýzada ayný miktarda yer kaplamazlar. Ayný miktarda yer kaplasa
bile iþaretli mi deðil mi int mi float mý gibi deðiþik muamele isteyen deðiþkenlerin karýþmamasý için pointer de ayný
deðiþken gibi tanýmlanýr.

þimdi 5 byt'lýk ram'ý olan, dandik sanal bilgisayarýmýza dönüp, bir pointer tanýmlayalým. Hafýzada boþ olan ilk adrese
yerleþecek olan bu pointerimize p adýný verelim. char tipli deðiþkenlerin adresini tutmak için tipi char olsun.

char *p;

 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2      30    c deðiþkeni (char)
 3       0    p pointeri  (char*)
 4       0

!Bu p adýndaki pointerimizi tanýmlarken adýnýn önündeki * iþaretinden baþka bir yenilik yok. Bütün tiplerde, tanýmlanýrken
!adýnýn önünde * olunca o arkadaþ pointer olur.
Devam edelim, pointerimize b deðiþkenin adresini yazalým.

p=&b;

 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2      30    c deðiþkeni (char)
 3       1    p pointeri  (char*) (b deðiþkeninin adresi var)
 4       0

evet görüldüðü üzere p bir deðiþkendir. 3 numaralý hafýza adresindedir. Sakladýðý deðer yani içeriði 1 dir. 1 deðeri b
deðiþkeninin adresidir.

Bu durumu iyice anlayýncaya kadar ilerlemeyin baþa dönüp anlaya anlaya tekrar okuyun. Gerekirse sorun.

Elimizde bir tane pointerimiz var. Þimdi bu pointeri kullanarak iþlemler yapalým.

// pointere deðer atamak
p=&a; // p pointerine a deðiþkeninin adresini(0) yaz
 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2      30    c deðiþkeni (char)
 3       0    p pointeri  (char*)
 4       0


// pointerin gösterdiði deðiþkeni okumak
!c=*p; //c deðiþkenine, p pointerinin gösterdiði adresdeki(0) deðiþkenin(a) içeriðini yaz
 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2      10    c deðiþkeni (char)
 3       0    p pointeri  (char*)
 4       0

// pointerin gösterdiði deðiþkene yazmak
p=&c; // p pointerine c deðiþkeninin adresini(2) yaz
*p=40;// p pointerinin gösterdiði adrese(2) 40 deðerini yaz
 hafýzamýz :
adres  içerik açýklama
 0      10    a deðiþkeni (char)
 1      20    b deðiþkeni (char)
 2      40    c deðiþkeni (char)
 3       2    p pointeri  (char*)
 4       0

Son örnekte görüldüðü üzere pointer ile çalýþýrken (dikkat: pointer tanýmlarken deðil) pointerin baþýnda * varsa
iþlemler pointerin gösterdiði adrese yapýlýr. * yoksa iþlemler pointerin kendine yapýlýr.

Pointerlere de deðiþkenlerde olduðu gibi matematiksel iþlemler uygulanabilir. Toplama, çýkarma, çarpma, bölme,++,-- ...

Dikkat : pointerlerin içeriði ile uðraþýrken pointerin tipi önemlidir.
char   tipli bir pointerin deðerini ++ ile arttýrýrsak deðeri 1 artar çünkü hafýzada char  1 byte'lýk yer kaplar.
Short  tipli bir pointerin deðerini ++ ile arttýrýrsak deðeri 2 artar çünkü hafýzada short 2 byte'lýk bir kaplar.
float  tipli bir pointerin deðerini ++ ile arttýrýrsak deðeri 4 artar çünkü hafýzada float 4 byte'lýk bir kaplar.
double tipli bir pointerin deðerini ++ ile arttýrýrsak deðeri 8 artar çünkü hafýzada float 8 byte'lýk bir kaplar.
ayný mantýk diðer matematiksel iþlemlerde de geçerlidir.
int tipi derleyiciye göre deðiþir 32bit için 4 byte, 64 bit için 8 byte.

deðiþkenlerin, dizilerin hafýzada ne kadar yer kapladýðýný öðrenmek için sizeof(x) kullanýlýr. x yerine bu
saydýklarýmýn herhangi birini kullanabilirsiniz.
örnek olarak aþaðýda yazdým.

evet son olarak tipsiz bir pointer tanýmý var ondan bahsedelim :) void * olarak tanýmlanan pointerler sadece adres
tutarlar, ++ , -- iþlemlerinde deðerleri 1 deðiþir. Genelde tipi bilinmeyen veya tipi önemli olmayan iþler için
kullanýlýrlar. Bunun dýþýnda çok bir iþe yaramazlar bir özellikleri yoktur. Genel maksat pointeri de denebilir. :)

pointer kullanarak bazý örnekler yapalým
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

    p = &c;//p pointerine c deðiþkeninin adresini yaz
    *p = a + b;//p pointerinin gösterdiði adrese a+b yi yaz;
    printf("c nin degeri :%d \r\n", c);
    //bir deðiþkenin hafýzada ne kadar yer kapladýðýný bulmak için sizeof kullanýlýr
    printf("c char degiskeninin hafizada kapladigi byte  : %d \r\n", sizeof(c));
    printf("s short degiskeninin hafizada kapladigi byte : %d \r\n", sizeof(s));
    printf("i int degiskeninin hafizada kapladigi byte   : %d \r\n", sizeof(i));
    printf("f float degiskeninin hafizada kapladigi byte : %d \r\n", sizeof(f));
    printf("d double degiskeninin hafizada kapladigi byte: %d \r\n", sizeof(d));


    // bir fonksiyona parametre olarak pointer gönderme olayý
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
    //gelen pointerle biþiler yapalým

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
    //bir deðiþkenin hafýzada ne kadar yer kapladýðýný bulmak için sizeof kullanýlýr

    //pointerin gösterdiði yerin ilerisinde neler var bir göz atalým
    //buralarda olan verilerin ne olduðunu bi derleyici bi de Allah bilir.
    printf(" Adres      icerik \r\n");
    for (i = 10; i; i--)
        {
        printf(" %d    %d \r\n", x, *x);
        x++;
        }
    }
//------------------------------------------------------------------------------