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
-enum ve kullan�m�na �rnekler

*/
//------------------------------------------------------------------------------
void main(void)
{
/*
!Enum ne i�e yarar: Programda kulland���m�z say�sal baz� de�erleri isimlendirmek
!i�in kullan�l�r. G�zelli�i �urada, verdi�imiz listeyi kendisi numaraland�r�r.
!K���kten b�y��e do�ru s�ralar.

Nas�l tan�mlan�r : �u �ekilde

enum tan�m_ad� {tan�m1,tan�m2,tan�m3,tan�m4......};

Tan�m ad� �ok laz�m de�ildir. Olmasa da olur.

Takvim ile ilgili bir program yazd���m�z� d���nelim. Haftan�n g�nlerini say�larla
ifade etmemiz gerekti�inde pazar 1,pazartesi 2, sal� 3... �eklinde kulland�k diyelim.
program�n her yerinde haftan�n 5. g�n� dedi�imizde onun per�embe oldu�unu bilmemiz
gerekiyor. bu �ekilde �al��mak hata yapmaya ve gereksiz kafa yormaya neden olur.
Onun yerine �u �ekilde daha �nceden ��rendi�imiz #define ile tan�mlama yapabiliriz.

#define PAZAR     1
#define PAZARTESI 2
#define SALI      3
#define CARSAMBA  4
#define PERSEMBE  5
#define CUMA      6
#define CUMARTESI 7

Ayn� i�i enum ile yapal�m

*enum {PAZAR=1,PAZARTESI,SALI,CARSAMBA,PERSEMBE,CUMA,CUMARTESI};

*bu �ekilde verdi�imiz listeyi 1 den ba�layarak artt�rarak tan�mlar. Pazar=1
*demeseydik pazar� 0 dan ba�latacakt�.

Nerelerde kullan�l�r : Genel olarak ger�ek d�nyada bulunan �eyleri ve durumlar�
say�sal olarak ifade etmek istedi�imizde hat�rlamas� kolay olsun diye kullan�l�r.
Ben buna say�sal olarak ne diyordum diye d���nece�imiz her yerde kullan�labilir.
Her t�rl� kolayl�k sa�lar.

bir ka� �rnek verelim.
enum {RC_STATUS=0,RC_WIFICONFIG,RC_CONTROL,RC_TEST,RC_SET,RC_NETWORK,RC_SCRIPT,RC_TXPOWER};
enum {P_UNINIT=0,P_OPENING,P_OPENED,P_CLOSING,P_CLOSED};
enum {HATA_YOK,ADRES_HATALI,DEGER_HATALI,PARAMETRE_HATALI,PARAMETRE_EKSIK,HABERLESME_HATASI,CIHAZ_MESGUL};


Neden buyuk harfle yaz�l�r : �art de�ildir ama genel olarak programc�lar tan�mlar�
b�y�k hafle yazarak onun tan�m oldu�u anla��ls�n isterler. Program� incelerken
anla��lmas�n� kolayla�t�r�r.

Do�al olarak enumlar kullan�ld�klar� yerlerden �nce tan�mlanm�� olmas� gerekir.
Genelde dosyan�n �st taraflar�nda tan�mlar� yapar�z ki kodun i�inde aray�p bulmak
zorunda kalmayal�m.

*****  enum ile tan�mlanan de�erler int dir.
*****  enum ile tan�mlanan �eyler sabittir de�i�ken de�ildir.

�imdi �al��an bir �rnek ile kullan�m�n� g�sterelim.


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

getch();//��k��ta bir tu�a bas�lmas�n� bekle
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