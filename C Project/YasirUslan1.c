#include <stdio.h>
#include <stdlib.h>

int main()
{
    // bu satýrlar açýklama satýrlarýdýr. derleyici buralarý iþlemez

    //------------- deðiþken tanýmlama
    //! iþaretli tamsayýlar ve kapasiteleri
    char a;     //* 8 bit
    short b;    //* 16 bit
    int c;      //* 32 bit
    long long d; //* 64 bit

    //! iþaretsiz tamsayýlar ve kapasiteleri
    unsigned char e;     //* 8 bit
    unsigned short f;    //* 16 bit
    unsigned int g;      //* 32 bit
    unsigned long long h; //* 64 bit


    //! kayan noktalý ondalýklý deðiþkenler
    float i;     //* 32 bit
    double j;     //* 64 bit


    //deðiþkenlere deðer atama örnek
    a=1; //a char(8bit) tipinde
    b=a; // b short(16bit) tipinde olduðu için 8 bitlik a deðiþkeninin deðerini alabilir. tersi durum sakýncalýdýr. büyük deðer varsa küçük deðiþkene sýðmayabilir.
    c=a+b+5; // ayný þekilde c int(32bit) olduðu için hepsinin toplamýný tutabilir.
    i=3.14; // ondalýklý sayýlar yazýlýrken nokta iþareti kullanýlýr
    j=i/2.3344; //double tipi float'dan daha büyük ve hassastýr.


    //deðiþkenlerin tutabileceði minimum ve maksimum deðerler
    e = 0;  // unsigned char min
    e = 255; // unsigned char max

    a = -128; //char min
    a = 127;  //char max

    //?iþaretli sayýlar da 1 bit sayýnýn negatif/pozitif olduðunu belirlemek için kullanýldýðýndan, ayný tipin iþaretsizinin yarýsý kadar büyük sayýlarla çalýþabilir.

    /*
    
    Deðiþkenler ve veri tipleri


Bilgisayarda programlama yaparken deðiþken dediðimiz veri parçalarý kullanýrýz.
Bu veriler üzerinde çalýþtýðýmýz, bir sonuç elde etmemiz gereken veriler olduðu gibi,
bu iþleri yaparken kullandýðýmýz iþlem basamaklarýnda bize yardýmcý olacak küçük notlar gibidir.
    
    Gerçek dünyadan örnek verecek olursak bir binaya giren-çýkan kiþileri saymak istesek,
kapýda durup her giren ve çýkaný sayarýz. Bir süre sonra kafamýz karýþmasýn diye kaðýda
gireni çýkaný ve saati not aldýðýmýzý düþünelim. Ýþ bittiðinde bir excel sayfasýna ilk
sütuna tarih saat, sonra giren ve çýkan kiþi sayýsýný, son sütuna da binadaki mevcut kiþi
sayýsýný hesaplattýk diyelim. Ýþte programlamada da buna benzer bir mantýkla program
içerisinde bilgileri saklamak, üstünde iþlem yapmak için deðiþkenleri kullanýrýz. Excel
örneðinden devam edersek, oluþturduðumuz tablonun sütunlarý bizim deðiþkenlerimiz oluyor.
Her satýrda deðiþkenlerin deðerinin deðiþmesini de çalýþan programda deðiþkenlerin deðerinin
deðiþmesi olarak görebiliriz.

    C de deðiþik tipte verilerle çalýþmak için deðiþik veri tipleri vardýr. Az önceki excel
örneðimizde ilk sütuna zaman bilgisini koyduk. Bu hücrenin sakladýðý deðer zamaný gösteriyor.
Yani verinin tipi zaman gösterecek tip oluyor. Sonraki hücremiz giren kiþi sayýsý. Bu hücre de
giren kiþileri gösteriyor. Bu sayýsal bir deðer ve pozitif olmak zorunda. -3 kiþi girdi demeyiz.
Onu çýkanlar sütununa 3 kiþi çýktý olarak yazarýz. Yani giren ve çýkan kiþi sayýsý pozitif
tam sayý olmak zorunda. 3.5 kiþi girdi diyemeyiz. Son sütunda ise binadaki mevcut kiþi sayýsý.
Bu veri de tam sayý olmak zorunda. Yarým insan girdi diyemeyiz. Ama sonucu negatif çýkabilir.
Çünkü bu sütunun deðerini giren ve çýkan kiþi sayýsýna göre hesap yapýp buluyoruz. Ýçeriye bizi
kandýrmak için arka pencereden giren muzip arkadaþlarýmýzýn ön kapýdan çýktýðýný düþünelim.
Dolaysýyla buradaki veri tipimiz hem negatif hem pozitif sayýlarý gösterebilecek iþaretli bir
sayý tipi olmalýdýr.
    
    Programlama dilleri bize bu tür deðiþik veri tipleri ile çalýþma imkaný verirler. C de veri
tipleri 4 ana baþlýkta toplanabilir.
Bunlar:
1-iþaretli tamsayýlar  : char,short,int
2-iþaretsiz tamsayýlar : unsigned char, unsigned short, unsigned int
3-Ýþaretli kayan noktalý veya ondalýklý sayýlar : float,double
4-Kendi tanýmladýðýmýz veri tipleridir.

Bilgisayarlar verileri hafýzalarda saklarlar. Çeþitli hafýza tipleri olsa da hepsi ayný mantýkla
ifade edilirler. Bilgisayarlarda en küçük bilgi parçasýna bit denir ve 0 veya 1 deðeri alýrlar.
Bilgisayar hafýzalarý 8 tane bitin yan yana getirilmesi ile oluþan byte'lar dizisi halinde tutulur.
8 bit -> 1byte
1024 byte -> 1KB kilo byte
1024 KB -> 1MB mega byte
1024 MB -> 1GB giga byte
1024 GB -> 1TB tera byte
þeklinde devam eder gider.


    Bir byte'ýn bütün bitleri 0 ise o bytýn sayýsal deðeri 0 dýr. Bütün bitleri 1 ise 255 dir.
Burada çok az bu 0-1 ile ifade edilen ikili sayý sisteminden bahsedelim.
0 ve 1 kullanarak her seferinde 1 artan ikili sayý sistemi ve karþýlýk ondalýk sayý sistemi deðerleri:

Ýkili Sayý Sistemi   Onlu Sayý Sistemi
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
   
Ýþte sadece 8 tane 0/1 den oluþan bir byte'lýk bilgisayar hafýzasý verileri bu þekilde saklar.


    Ýþaretli ve iþaretsiz veri tipleri de ifade edebilecekleri en büyük ve en küçük sayýlara göre deðiþiklik
gösterirler. Þimdi bunlarý kaç bitlik kapasitesi olduðuna göre sýralýyalým.

char tipi 1 byte
short tipi 2 byte
int tipi 4/8 byte
float 4 byte
double 8 byte

Bu deðerlerde int tipi genelde derleyicinin ve çalýþtýðý makinanýn özellikleri ile alakalý olup 32bit/64bit
sistemlere göre deðiþir. Þimdilik çok önemli deðil.

    Ýþaretli tiplerde en yüksek bit basamaðý sayýnýn iþaretidir. 0 ise pozitif 1 ise negatifdir. 1biti iþarete
ayrýldýðý için bu tiplerin ifade ettiði maksimum ve minimum deðerleri ayný tipin iþaretsizinden farklýdýr.
*/


    return 0;
}