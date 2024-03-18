//------------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
//------------------------------------------------------------------------------
enum {PAZAR=1,PAZARTESI,SALI,CARSAMBA,PERSEMBE,CUMA,CUMARTESI};
enum {HATA_YOK,BOYLE_BIR_GUN_YOK};
int gun_yaz(int kacinci_gun);
//------------------------------------------------------------------------------

/*
Konular
-enum ve kullanýmýna örnekler

*/
//------------------------------------------------------------------------------
void main(void)
{
/*
!Enum ne iþe yarar: Programda kullandýðýmýz sayýsal bazý deðerleri isimlendirmek
!için kullanýlýr. Güzelliði þurada, verdiðimiz listeyi kendisi numaralandýrýr.
!Küçükten büyüðe doðru sýralar.

Nasýl tanýmlanýr : þu þekilde

enum taným_adý {taným1,taným2,taným3,taným4......};

Taným adý çok lazým deðildir. Olmasa da olur.

Takvim ile ilgili bir program yazdýðýmýzý düþünelim. Haftanýn günlerini sayýlarla
ifade etmemiz gerektiðinde pazar 1,pazartesi 2, salý 3... þeklinde kullandýk diyelim.
programýn her yerinde haftanýn 5. günü dediðimizde onun perþembe olduðunu bilmemiz
gerekiyor. bu þekilde çalýþmak hata yapmaya ve gereksiz kafa yormaya neden olur.
Onun yerine þu þekilde daha önceden öðrendiðimiz #define ile tanýmlama yapabiliriz.

#define PAZAR     1
#define PAZARTESI 2
#define SALI      3
#define CARSAMBA  4
#define PERSEMBE  5
#define CUMA      6
#define CUMARTESI 7

Ayný iþi enum ile yapalým

*enum {PAZAR=1,PAZARTESI,SALI,CARSAMBA,PERSEMBE,CUMA,CUMARTESI};

*bu þekilde verdiðimiz listeyi 1 den baþlayarak arttýrarak tanýmlar. Pazar=1
*demeseydik pazarý 0 dan baþlatacaktý.

Nerelerde kullanýlýr : Genel olarak gerçek dünyada bulunan þeyleri ve durumlarý
sayýsal olarak ifade etmek istediðimizde hatýrlamasý kolay olsun diye kullanýlýr.
Ben buna sayýsal olarak ne diyordum diye düþüneceðimiz her yerde kullanýlabilir.
Her türlü kolaylýk saðlar.

bir kaç örnek verelim.
enum {RC_STATUS=0,RC_WIFICONFIG,RC_CONTROL,RC_TEST,RC_SET,RC_NETWORK,RC_SCRIPT,RC_TXPOWER};
enum {P_UNINIT=0,P_OPENING,P_OPENED,P_CLOSING,P_CLOSED};
enum {HATA_YOK,ADRES_HATALI,DEGER_HATALI,PARAMETRE_HATALI,PARAMETRE_EKSIK,HABERLESME_HATASI,CIHAZ_MESGUL};


Neden buyuk harfle yazýlýr : Þart deðildir ama genel olarak programcýlar tanýmlarý
büyük hafle yazarak onun taným olduðu anlaþýlsýn isterler. Programý incelerken
anlaþýlmasýný kolaylaþtýrýr.

Doðal olarak enumlar kullanýldýklarý yerlerden önce tanýmlanmýþ olmasý gerekir.
Genelde dosyanýn üst taraflarýnda tanýmlarý yaparýz ki kodun içinde arayýp bulmak
zorunda kalmayalým.

*****  enum ile tanýmlanan deðerler int dir.
*****  enum ile tanýmlanan þeyler sabittir deðiþken deðildir.

þimdi çalýþan bir örnek ile kullanýmýný gösterelim.


*/
//------------------------------------------------------------------------------

int i;
int donusdegeri;

for (i=0;i<10;i++)
    {
    printf("\r\n%d = ",i);
    donusdegeri = gun_yaz(i);
    if (donusdegeri == BOYLE_BIR_GUN_YOK)
       printf("Hatali deger. Boyle bir gun yok");
    }

getch();//çýkýþta bir tuþa basýlmasýný bekle
return;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int gun_yaz(int kacinci_gun)
{
switch (kacinci_gun)
       {
       case PAZAR:
            printf("Pazar");
            break;
       case PAZARTESI:
            printf("Pazartesi");
            break;
       case SALI:
            printf("Sali");
            break;
       case CARSAMBA:
            printf("Carsamba");
            break;
       case PERSEMBE:
            printf("Persembe");
            break;
       case CUMA:
            printf("Cuma");
            break;
       case CUMARTESI:
            printf("Cumartesi");
            break;
       default:
            return BOYLE_BIR_GUN_YOK;
       }
return HATA_YOK;
}
//------------------------------------------------------------------------------