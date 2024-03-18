#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
int kackarakterBad(char* str);
int kackarakterGood(char* str);
//-----------------------------------------------------------------------------
/*
konular

1- c de string (char * diziler) ve pointer
2- strlen
3- strcpy veya strcpy_s
*/
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(void)
    {
    /*
    char tipindeki dizilere string denir. String programlarda ekrana bast���m�z mesajlar,
    ve d�z yaz� �eklinde saklad���m�z veriler i�in kullan�l�r.
    bu zamana kadar printf ile kulland���m�z ekrana bast���m�z yaz�lar mesela.
    printf("merhaba d�nya") gibi.
    burada �ift t�rnak(") i�inde kalan b�l�m bahsetti�im �ey. C bu stringleri haf�zada
    ard arda s�ralar ve sonuna bir 0 koyar. Bu sondaki 0 string'in bitti�ini ifade eder.
    C'nin standart fonksiyonlar� bu stringi i�lerken 0'� g�r�nce dizinin bitti�ini anlar.

    hemen bir �rnek yapal�m.
    bu �rnekte bir string tan�ml�yoruz. Stringin uzunlu�unu ��renmek i�in yeni bir fonksiyon
    !kulland�m, strlen adl� bu fonksiyon verilen char* pointerinin g�sterdi�i adreste bulunan
    !char dizisinin uzunlu�unu int olarak d�nd�r�yor.

    �rnekte str dizisinin sonundaki 0 de�erinin varl���n� ispat ediyoruz.
    Uzunlu�unu g�rmek i�in kulland���m�z strlen, yaz�labilir karakterlerin say�s�n� verirken
    ?sizeof tan�mlanm�� olan de�i�kenin toplam b�y�kl���n� veriyor. Yani ayr�lm�� olan haf�za
    ?alan� �ok b�y�k de olsa strlen dizinin ba��ndan, sondaki s�f�ra kadar olan karakterlerin
    ?say�s�n� verir. 100 bytel�k bir haf�za ay�r�p i�ine 3 karakter yaz�p 4. karaktere 0 yazarsak
    ?elimizde 3 karakterlik bir string olur. geri kalan 96byte kullan�lmaz.
    Bu durumu str dizisinin 6.karakteri olan bo�lu�u 0 ile de�i�tirerek g�sterelim.
    B�ylece stringin uzunlu�unu de�i�tirmi� olduk. Stringin Uslan k�sm� hala haf�zada duruyor ama
    art�k printf oray� yazd�rm�yor.
    */
            {
            char str[] = "Yasir Uslan";

            printf(str);//stringi yazd�ral�m
            printf("\r\nString uzunlugu: %d \r\n", strlen(str));
            printf("Stringin hafizada kapladigi alan: %d \r\n", sizeof(str));

            str[5] = 0; // bo�lu�un oldu�u yere 0 yaz�yoruz
            printf(str);//stringi yazd�ral�m
            printf("\r\nString uzunlugu: %d \r\n", strlen(str));
            printf("Stringin hafizada kapladigi alan: %d \r\n", sizeof(str));
            }
            /*
            stringlerin ve dizilerin kullan�m�nda belki dikkatinizi �ekmi�tir, dizileri tan�mlayan de�i�kenler
            asl�nda birer pointer. Printf fonksiyonuna verdi�imiz de�erler, char tipinde pointerler.
            Bu konuyu biraz daha a�al�m, daha bariz hale getirelim.
            bu �rnekte 100 karakterlik bir char de�i�ken dizi tan�ml�yoruz. Ve bu diziye bir stringi kopyal�yoruz.
            Bu i� i�in yaz�lm�� strcpy fonksiyonu kullan�yoruz.

            !strcpy fonksiyonu 1 diziyi ba�ka 1 yere kopyalamak i�in kullan�l�r. Kaynak ve hedef olarak iki pointer al�r.
            Kaynak pointerin g�sterdi�i adresdeki dizinin byte'lar� hedef pointerinin g�sterdi�i adrese kopyalan�r. 
            Bu kopyalama i�lemi kaynak dizinin sonu oldu�u anla��lan 0 de�eri i�eren byte ula��ncaya kadar devam eder. 
            E�er diznin sonunda 0 yoksa buluncaya kadar kopyalamaya devam eder. O y�zden tehlikeli bi fonksiyondur. 
            Bu arada hedef dizinin boyu kaynaktan k���kse yine kopyalamaya devam eder, haf�zada b�y�k karma�a yarat�r. 
            Ellemememiz gereken yerlere ula��rsa program ��ker. Eskiden i�letim sistemi bile ��kerdi :) �imdilerde onun �nlemini ald�lar, 
            en az�ndan i�letim sistemi sa�lam kal�yor.
            Bu gibi tehlikeli sonu belli olmayan dizilerle u�ra�mak i�in yeni fonksiyonlar yaz�ld�. 
            Biz burada eski strcpy ve yeni strcpy_s fonksiyonunu kullanaca��z. 

            ***********   visual studio da strcpy ar�za ��kartt��� i�in strcpy_s  kullanaca��z  ****************
            
            strcpy_s 2 �ekilde kullan�l�r
            derleyici hedef dizinin b�y�kl���n� bilmek ister. E�er dizi tan�mlan�rken dizinin boyutu belirtilmi�se 1. �ekilde kullan�labilir.
            E�er hedef dizinin boyutu belli de�il ise 2. �ekilde kullan�l�r. yani dizinin boyutunu bizden ister ki hedefi ta��rmas�n alakas�z 
            yerlere yazmas�n.

            1- strcpy_s(hedefDizi/Pointer, kaynakDizi/Pointer)
            2- strcpy_s(hedefDizi/Pointer, maxKopyalanacakChr, kaynakDizi/Pointer)
            */
            {
            char str[100];
            int i, q;

            strcpy_s(str, "Yasir Uslan"); //derleyici str dizisinin 100 karakter uzunlu�unda oldu�unu biliyor.
            strcpy_s(str, sizeof(str), "Yasir Uslan"); //b�yle de yaz�labilir ama gerek yok yukar�daki daha iyi

            printf("%s \r\n", str);

            i = 1 + strlen(str);//stringin sonundaki 0'� da yazd�rmak i�in strlen'in d�nd�rd��� de�er+1 yapt�k
            q = 0;
            while (q < i)
                {
                printf("%d - '%c'  %d \r\n", q, str[q], str[q]); // diziyi karakter karakter yazd�ral�m
                q++;
                }
            }
            /*
            char* pointer kullan�m�na �rnek olmas� i�in biraz de�i�tirelim.

            */
            {
            char str1[100];//100 karakterlik char dizi, str1 asl�nda char* pointer, 100byte l�k haf�zay� g�steriyor
            char str2[100];//100 karakterlik char dizi, str2 asl�nda char* pointer, 100byte l�k haf�zay� g�steriyor
            char* p1, * p2; //iki tane char* pointer tan�mlad�k

            p1 = str1;//pointer1 str1 dizisini g�steriyor
            p2 = str2;

            //strcpy(p1, "Yasir Uslan");//pointerin(p1) g�sterdi�i adrese �u stringi kopyala **** vs vc++ da �al��m�yor
            strcpy_s(p1, sizeof(str1), "Yasir Uslan");//pointerin(p1) g�sterdi�i adrese �u stringi kopyala

            //strcpy(p2, p1);//pointerin(p2) g�sterdi�i adrese �u pointerin(p1) g�sterdi�i stringi kopyala
            strcpy_s(p2, sizeof(str2), p1);//pointerin(p2) g�sterdi�i adrese �u pointerin(p1) g�sterdi�i stringi kopyala

            printf("\r\n----------p1 pointeri str1------------\r\n");
            printf(p1);
            printf("\r\n----------p2 pointeri str2------------\r\n");
            printf(p2);
            printf("\r\n--------------------------------------\r\n");

            }
            /*
            ne i�imize yarar bu pointer, ne gerek var. zaten de�i�ken orada niye adresi ile u�ra��yoruz ???
            �u i�imize yarar : �st�nde �al��t���m�z veriyi elleyip m�nc�klarken, s�rekli ayn� �eyleri yap�yorsak
            bunlar� fonksiyon haline getirip (strlen ve printf gibi) her yerde kullanabiliriz. Fakat bu fonksiyonlar�
            �a��r�rken �st�nde �al��aca��m�z verilerin nerede oldu�unu fonksiyona g�ndermemiz gerekir. ��te bu �ekilde
            verinin adresini g�ndeririz, fonksiyon da gelen bu adresi pointer olarak kullan�p veriye eri�ir.
            Bu y�ntem sayesinde haf�za olduk�a verimli bir �ekilde kullan�l�r. Pointer kullanmadan da i�leri halledebiliriz.
            fakat bu sefer �st�nde �al��t���m�z verinin bir kopyas�n� olu�turup fonksiyona g�ndermemiz,
            �st�nde �al���p sonucun bir kopyas�n� olu�turup geri g�ndermemiz gerekir. ne kadar verimsiz ve zor
            y�ntem oldu�unu farkettiniz mi?

            Yani elimde bir veri var. Bu veri �st�nde bir i�lem yapmak istiyorum. Fonksiyona verinin adresini g�nderip
            �u i�i yap diyorum. Gayet pratik. Haf�zan�n s�n�rl� oldu�u g�m�l� sistemlerde bu y�ntem acayip i� bitirir.

            �rnek olarak verdi�imiz stringin i�inde ka� karakter oldu�unu bulan bir fonksiyon yazal�m. Haz�r yaz�lm���
            var(strlen) ama olsun. �rnek �rnektir.

            fonksiyonun ismi kackarakter olsun.
            geriye karakter say�s� d�nd�rece�i i�in d�n�� tipini int yapal�m.
            Fonksiyonumuza pointer(char*) olarak stringimizin adresini g�nderelim.
            toparlarsak fonksiyon tan�m�m�z �u �ekilde olacak
            *int kackarakter(char *str)
            buraya bir deneme kodu yaz�p fonksiyonu �al��t�ral�m. Fonksiyonun kendini dosyan�n sonuna ekliycem.
            ...
            Fonksiyonu yazarken akl�ma geldi. �yi ve k�t� diye iki fonksiyon yazay�m. Ayn� i�i yapacaklar ama
            k�t� olan mevzu anla��ls�n diye gereksiz uzun yaz�ld�
            go go go
            */

            {
            char str1[100];

            //strcpy(str1, "Ahanda bu bir string dir.");
            strcpy_s(str1, "Ahanda bu bir string dir."); //strcpy visual studio sevmiyo


            printf("Badfunc  str1 %d karakter\r\n", kackarakterBad(str1));
            printf("Goodfunc str1 %d karakter\r\n", kackarakterGood(str1));
            }
            //---------------------
            return 0; // main bitti
    }
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int kackarakterBad(char* str)
    {
    int karaktersayisi;
    char karakter;
    char* dizipointeri;

    dizipointeri = str;//fonksiyona g�nderilmi� olan pointer'� local pointer'a kopyalad�k
    karaktersayisi = 0;

tekrar://goto i�in label
    karakter = *dizipointeri;

    if (karakter == 0)
        {
        return karaktersayisi;
        }
    karaktersayisi++;
    dizipointeri++;
    goto tekrar;
    }
//-----------------------------------------------------------------------------
int kackarakterGood(char* str)
    {
    int karaktersayisi = 0;

    while (*str++ != 0)
        karaktersayisi++;

    return karaktersayisi;
    }
//-----------------------------------------------------------------------------