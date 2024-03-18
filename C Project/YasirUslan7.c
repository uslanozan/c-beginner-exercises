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
    char tipindeki dizilere string denir. String programlarda ekrana bastýðýmýz mesajlar,
    ve düz yazý þeklinde sakladýðýmýz veriler için kullanýlýr.
    bu zamana kadar printf ile kullandýðýmýz ekrana bastýðýmýz yazýlar mesela.
    printf("merhaba dünya") gibi.
    burada çift týrnak(") içinde kalan bölüm bahsettiðim þey. C bu stringleri hafýzada
    ard arda sýralar ve sonuna bir 0 koyar. Bu sondaki 0 string'in bittiðini ifade eder.
    C'nin standart fonksiyonlarý bu stringi iþlerken 0'ý görünce dizinin bittiðini anlar.

    hemen bir örnek yapalým.
    bu örnekte bir string tanýmlýyoruz. Stringin uzunluðunu öðrenmek için yeni bir fonksiyon
    !kullandým, strlen adlý bu fonksiyon verilen char* pointerinin gösterdiði adreste bulunan
    !char dizisinin uzunluðunu int olarak döndürüyor.

    Örnekte str dizisinin sonundaki 0 deðerinin varlýðýný ispat ediyoruz.
    Uzunluðunu görmek için kullandýðýmýz strlen, yazýlabilir karakterlerin sayýsýný verirken
    ?sizeof tanýmlanmýþ olan deðiþkenin toplam büyüklüðünü veriyor. Yani ayrýlmýþ olan hafýza
    ?alaný çok büyük de olsa strlen dizinin baþýndan, sondaki sýfýra kadar olan karakterlerin
    ?sayýsýný verir. 100 bytelýk bir hafýza ayýrýp içine 3 karakter yazýp 4. karaktere 0 yazarsak
    ?elimizde 3 karakterlik bir string olur. geri kalan 96byte kullanýlmaz.
    Bu durumu str dizisinin 6.karakteri olan boþluðu 0 ile deðiþtirerek gösterelim.
    Böylece stringin uzunluðunu deðiþtirmiþ olduk. Stringin Uslan kýsmý hala hafýzada duruyor ama
    artýk printf orayý yazdýrmýyor.
    */
            {
            char str[] = "Yasir Uslan";

            printf(str);//stringi yazdýralým
            printf("\r\nString uzunlugu: %d \r\n", strlen(str));
            printf("Stringin hafizada kapladigi alan: %d \r\n", sizeof(str));

            str[5] = 0; // boþluðun olduðu yere 0 yazýyoruz
            printf(str);//stringi yazdýralým
            printf("\r\nString uzunlugu: %d \r\n", strlen(str));
            printf("Stringin hafizada kapladigi alan: %d \r\n", sizeof(str));
            }
            /*
            stringlerin ve dizilerin kullanýmýnda belki dikkatinizi çekmiþtir, dizileri tanýmlayan deðiþkenler
            aslýnda birer pointer. Printf fonksiyonuna verdiðimiz deðerler, char tipinde pointerler.
            Bu konuyu biraz daha açalým, daha bariz hale getirelim.
            bu örnekte 100 karakterlik bir char deðiþken dizi tanýmlýyoruz. Ve bu diziye bir stringi kopyalýyoruz.
            Bu iþ için yazýlmýþ strcpy fonksiyonu kullanýyoruz.

            !strcpy fonksiyonu 1 diziyi baþka 1 yere kopyalamak için kullanýlýr. Kaynak ve hedef olarak iki pointer alýr.
            Kaynak pointerin gösterdiði adresdeki dizinin byte'larý hedef pointerinin gösterdiði adrese kopyalanýr. 
            Bu kopyalama iþlemi kaynak dizinin sonu olduðu anlaþýlan 0 deðeri içeren byte ulaþýncaya kadar devam eder. 
            Eðer diznin sonunda 0 yoksa buluncaya kadar kopyalamaya devam eder. O yüzden tehlikeli bi fonksiyondur. 
            Bu arada hedef dizinin boyu kaynaktan küçükse yine kopyalamaya devam eder, hafýzada büyük karmaþa yaratýr. 
            Ellemememiz gereken yerlere ulaþýrsa program çöker. Eskiden iþletim sistemi bile çökerdi :) þimdilerde onun önlemini aldýlar, 
            en azýndan iþletim sistemi saðlam kalýyor.
            Bu gibi tehlikeli sonu belli olmayan dizilerle uðraþmak için yeni fonksiyonlar yazýldý. 
            Biz burada eski strcpy ve yeni strcpy_s fonksiyonunu kullanacaðýz. 

            ***********   visual studio da strcpy arýza çýkarttýðý için strcpy_s  kullanacaðýz  ****************
            
            strcpy_s 2 þekilde kullanýlýr
            derleyici hedef dizinin büyüklüðünü bilmek ister. Eðer dizi tanýmlanýrken dizinin boyutu belirtilmiþse 1. þekilde kullanýlabilir.
            Eðer hedef dizinin boyutu belli deðil ise 2. þekilde kullanýlýr. yani dizinin boyutunu bizden ister ki hedefi taþýrmasýn alakasýz 
            yerlere yazmasýn.

            1- strcpy_s(hedefDizi/Pointer, kaynakDizi/Pointer)
            2- strcpy_s(hedefDizi/Pointer, maxKopyalanacakChr, kaynakDizi/Pointer)
            */
            {
            char str[100];
            int i, q;

            strcpy_s(str, "Yasir Uslan"); //derleyici str dizisinin 100 karakter uzunluðunda olduðunu biliyor.
            strcpy_s(str, sizeof(str), "Yasir Uslan"); //böyle de yazýlabilir ama gerek yok yukarýdaki daha iyi

            printf("%s \r\n", str);

            i = 1 + strlen(str);//stringin sonundaki 0'ý da yazdýrmak için strlen'in döndürdüðü deðer+1 yaptýk
            q = 0;
            while (q < i)
                {
                printf("%d - '%c'  %d \r\n", q, str[q], str[q]); // diziyi karakter karakter yazdýralým
                q++;
                }
            }
            /*
            char* pointer kullanýmýna örnek olmasý için biraz deðiþtirelim.

            */
            {
            char str1[100];//100 karakterlik char dizi, str1 aslýnda char* pointer, 100byte lýk hafýzayý gösteriyor
            char str2[100];//100 karakterlik char dizi, str2 aslýnda char* pointer, 100byte lýk hafýzayý gösteriyor
            char* p1, * p2; //iki tane char* pointer tanýmladýk

            p1 = str1;//pointer1 str1 dizisini gösteriyor
            p2 = str2;

            //strcpy(p1, "Yasir Uslan");//pointerin(p1) gösterdiði adrese þu stringi kopyala **** vs vc++ da çalýþmýyor
            strcpy_s(p1, sizeof(str1), "Yasir Uslan");//pointerin(p1) gösterdiði adrese þu stringi kopyala

            //strcpy(p2, p1);//pointerin(p2) gösterdiði adrese þu pointerin(p1) gösterdiði stringi kopyala
            strcpy_s(p2, sizeof(str2), p1);//pointerin(p2) gösterdiði adrese þu pointerin(p1) gösterdiði stringi kopyala

            printf("\r\n----------p1 pointeri str1------------\r\n");
            printf(p1);
            printf("\r\n----------p2 pointeri str2------------\r\n");
            printf(p2);
            printf("\r\n--------------------------------------\r\n");

            }
            /*
            ne iþimize yarar bu pointer, ne gerek var. zaten deðiþken orada niye adresi ile uðraþýyoruz ???
            þu iþimize yarar : üstünde çalýþtýðýmýz veriyi elleyip mýncýklarken, sürekli ayný þeyleri yapýyorsak
            bunlarý fonksiyon haline getirip (strlen ve printf gibi) her yerde kullanabiliriz. Fakat bu fonksiyonlarý
            çaðýrýrken üstünde çalýþacaðýmýz verilerin nerede olduðunu fonksiyona göndermemiz gerekir. Ýþte bu þekilde
            verinin adresini göndeririz, fonksiyon da gelen bu adresi pointer olarak kullanýp veriye eriþir.
            Bu yöntem sayesinde hafýza oldukça verimli bir þekilde kullanýlýr. Pointer kullanmadan da iþleri halledebiliriz.
            fakat bu sefer üstünde çalýþtýðýmýz verinin bir kopyasýný oluþturup fonksiyona göndermemiz,
            üstünde çalýþýp sonucun bir kopyasýný oluþturup geri göndermemiz gerekir. ne kadar verimsiz ve zor
            yöntem olduðunu farkettiniz mi?

            Yani elimde bir veri var. Bu veri üstünde bir iþlem yapmak istiyorum. Fonksiyona verinin adresini gönderip
            þu iþi yap diyorum. Gayet pratik. Hafýzanýn sýnýrlý olduðu gömülü sistemlerde bu yöntem acayip iþ bitirir.

            örnek olarak verdiðimiz stringin içinde kaç karakter olduðunu bulan bir fonksiyon yazalým. Hazýr yazýlmýþý
            var(strlen) ama olsun. Örnek örnektir.

            fonksiyonun ismi kackarakter olsun.
            geriye karakter sayýsý döndüreceði için dönüþ tipini int yapalým.
            Fonksiyonumuza pointer(char*) olarak stringimizin adresini gönderelim.
            toparlarsak fonksiyon tanýmýmýz þu þekilde olacak
            *int kackarakter(char *str)
            buraya bir deneme kodu yazýp fonksiyonu çalýþtýralým. Fonksiyonun kendini dosyanýn sonuna ekliycem.
            ...
            Fonksiyonu yazarken aklýma geldi. Ýyi ve kötü diye iki fonksiyon yazayým. Ayný iþi yapacaklar ama
            kötü olan mevzu anlaþýlsýn diye gereksiz uzun yazýldý
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

    dizipointeri = str;//fonksiyona gönderilmiþ olan pointer'ý local pointer'a kopyaladýk
    karaktersayisi = 0;

tekrar://goto için label
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