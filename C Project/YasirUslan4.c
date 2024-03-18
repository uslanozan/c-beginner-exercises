#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//--------------------------- fonksiyonlar ---------------------------
int cikar(int sayi1,int sayi2);
void globali_sil(void);
//--------------------------- global deðiþkenler ---------------------
int globalim_benim;
//--------------------------------------------------------------------


/*
konular

1- dizi deðiþkenler
2- printf fonksiyonu
3- fonksiyon tanýmlarý ve void
*/


int main()
{
globalim_benim=0;
setlocale(LC_ALL,"Turkish");

/*
//-----------------------------------------------------------------------------
1- dizi deðiþkenler : Deðiþken tanýmlarken tek deðiþken tanýmladýk. Tek baþýna
bir deðiþken kullanýrken bazý iþleri yapmak zordur. Bazý durumlarda bir döngü
içinde rutin tekrarlayan iþler yapýlýrken dizi kullanmak çok iþe yarar.
dizi tanýmlamak için normal deðiþken tanýmý yaparken deðiþken adýnýn sonuna
köþeli parantez içinde kaç elemanlýk dizi istiyorsak onu belirtiriz.
Kullanýrken deðiþken adýnýn arkasýndan köþeli parantez içinde index numarasýný
vererek o deðiþkene ulaþýrýz.
Dizinin ilk elemanýnýn index numarasý 0 dýr. Aþaðýdaki örnekte 10 elemanlý dizi
tanýmladýk bu dizinin elemanlarý 0-9 arasýnda olmak üzere 10 tanedir.
örnekler vererek dizi olayýný inceleyelim.
*/
{
int a[10];//10 elemanlý dizi tanýmlýyoruz
int i; // index olarak kullanacaðýmýz deðiþken.

for (i=0; i<10 ;i=i+1) // i'nin deðeri 0'dan baþlayýp 9'a kadar gidecek
    a[i]=0; //a dizisinin elemanlarýný sýfýrlayalým. indeks olarak i deðiþkenini kullanýyoruz.


// deðiþkenlere tek tek deðer veriyoruz
a[0]=2; // a[0] ilk eleman. Deðiþkene 2 deðerini koyuyoruz
a[1]=5;
a[2]=1;
a[3]=0;
a[4]=22;
a[5]=23;
a[6]=6;
a[7]=72;
a[8]=26;
a[9]=18; // a[9] son eleman


for (i=0; i<10 ;i=i+1) // i'nin deðeri 0'dan baþlayýp 9'a kadar gidecek
    printf("a[%d] = %d \r\n", i, a[i] ); //a dizisinin bütün elemanlarýnýn deðerini ekrana yazalým.

}
/*
görüldüðü gibi diziler ve döngüler beraber çok iyi giderler.
deðiþik veri tiplerinde de mantýk ayný.
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
dizilerde dizinin ilk elemaný 0 dan baþlar bu önemli.

char diziler C de text (yazý karakteri dizileri) saklamak için kullanýlýr.
ama bu konuyu sonraya býrakalým. Kafa karýþtýrmasýn.

//-----------------------------------------------------------------------------
2- printf fonksiyonu : Örneklerde sýk sýk kullandýðýmýz printf fonksiyonunu
detaylý inceleme zamaný geldi sanýrým. printf ekrana bilgi basmak için
kullandýðýmýz en temel fonksiyon. Þimdiye kadar kullandýðýmýz örneklerden aþaðý
yukarý ne iþe yaradýðýný anlamýþsýnýzdýr.

taným olarak

printf(format, ... );

þeklinde özetleyebiliriz. Format dediðimiz kýsým ekrana yazýlacak þeyleri
tanýmlamak ve þekillendirmek için kullanýlýr. formattan sonra varsa yazdýrmak
istediðimiz deðiþkenleri virgül ile ayýrarak veririz. Eðer sadece ekrana bir
mesaj yazacaksak deðiþken vermeye gerek yoktur. Deðiþken kullanacaksak
deðiþkenin nasýl görüneceði ve ne tipte olacaðýný belirtmemiz gerekir. Tanýmlarý
düzgün anlatabilmek için bir örnek vereyim.
Aþaðýda int tipinde tanýmlanmýþ bir deðiþkenin deðerini ekrana yazýyoruz.
*/
{
int a;
a=123;



printf("sadece mesaj deðiþken yok. Yeni satýr için \r\n kullanýyoruz \r\n");
printf("a deðiþkeninin deðeri %d \r\n burasý yeni satýr" , a );

}

/*

þimdi printf satýrýnda bulunun þeyleri adlandýralým.

!printf("a deðiþkeninin deðeri %d \r\n burasý yeni satýr" , a );
!|      |----------------------|------------------------    |
!|      |                      |                            |
!|      |                      |                            \->deðiþken
!|      |                      \->parametre
!|      |
!|      \-> format string
!\->fonksiyonun adý

format string içinde ekrana yazacaðýmýz þeylerin tanýmý var. deðiþken yazacaksak
bu deðiþkenlerin nasýl görüneceðini belirttiðimiz parametreler var. ve enson
tabiki yazdýrmak istediðimiz deðiþkenleri virgülle ayrýlmýþ þekilde veriyoruz.

parametreler % iþareti ile baþlar. %'den sonra baya detaylý seçeneklerimiz
mevcut olup ben sadece temel bilinmesi gerekenlerden bahsedicem.

sýk kullandýðýmýz parametreler ve açýklamalarý
*%d : decimal, iþaretli tam sayý
*%u : unsigned decimal, iþaretsiz tam sayý
*%f : float ,double
*%c : tek karakter, a=97,b=98, ... A=65,B=66 olmak üzere ascii kodlarý yazdýrmak için
*%s : string, text yazdýrmak için.

bu parametrelerin de detaylarý var ama þimdilik girmeyelim merak edenler þu adresten
bakabilirler.
http://www.cplusplus.com/reference/cstdio/printf/

ascii tablo için
http://www.asciitable.com/

evet örnekler örnekler
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

// þimdi yazdýralým

printf("\r\n-----------------------------------------------");
printf("\r\n decimal i=%d",i);
printf("\r\n unsigned decimal ui=%u",ui);
printf("\r\n float f=%f",f);
printf("\r\n char c=%c   decimal c=%d",c,c);
printf("\r\n Benim adým %s ...  Adýmýn ilk harfi %c",str,str[0]);

}
/*
str deðiþkeni 100 elemanlý char tipinde deðiþken
karakter dizileri tutmak için kullanýyoruz. Debugger ile detaylý inceleyin.

//-----------------------------------------------------------------------------
3- fonksiyon tanýmlarý ve void : Evet yukarýda C nin bir fonksiyonunu kullandýk.
Artýk kendi fonksiyonlarýmýzý yazmanýn zamaný geldi. Fonksiyon ne iþe yarar diye
baþlayalým. Fonksiyon, ulan ne güzel program yazdým ben bunu saklayayým ilerde
çok yerde kullanýrým dediðimiz güzide kod parçalarýnýn asýl yapý içinden ayrýlýp
bir çok yerde kullanýlabilir ayrý bir parça haline getirilmesidir. Daha önce de
söylediðim gibi bir program yazarken iþi küçük parçalara bölmek çok önemli avantajlar
saðlar.

    Evet nasýl yapýyoruz. Fonksiyon aslýnda bizim sürekli kullandýðýmýz kod bloklarýnýn
isim verilmiþ halidir. Kod bloklarda yapamadýðýmýz bazý güzellikleri de vardýr.
Mesela printf fonksiyonunda da gördüðümüz gibi fonksiyona bazý bilgiler göndeririz
o bilgilere göre birþeyler yapmasýný bekleriz. Hatta fonksiyondan bilgi de alýrýz.
öyle ya belki beklediðimiz iþ yapýlamadý, bir hata oluþtu. Onun için fonksiyonlar
geriye deðer döndürebilirler.

Taným olarak fonksiyon þöyledir.

dönüþ_deðeri_tipi fonksiyon_adý(fonksiyona_gidecek_deðerler)

Þimdi verdiðimiz iki int deðeri toplayýp geri döndüren fonksiyon yazalým
*/
int topla(int sayi1,int sayi2) //fonksiyon tanýmlanýyor
{//fonksiyonun kod bloðu
int toplam; //dýþarýdan gelecek iki sayýnýn toplamýný tutmak için local deðiþken açýyoruz
toplam = sayi1 + sayi2; // toplama iþlemi. Sonuç local deðiþkende
return toplam;// fonksiyonun dönüþ deðeri, çaðýrýldýðý yere geri dönecek ve toplam deðiþkenin deðerini iletecek
}
/*
evet yukarýdaki fonksiyon tam olarak verdiðimiz iki int sayýyý toplayýp int olarak geri döndürüyor.

kullanma þekli ise þu þekilde
*/
{
int birinci_sayi;
int ikinci_sayi;
int donen_deger;

birinci_sayi=100;
ikinci_sayi=200;

donen_deger = topla(birinci_sayi,ikinci_sayi);

//deðerleri yazalým
printf("\r\n\n\nbirinci_sayi=%d  ikinci_sayi=%d  fonksiyondan dönen deðer=%d\r\n",birinci_sayi,ikinci_sayi,donen_deger);
}
/*
olay bu kadar.
- Fonksiyonlara çok sayýda ve her tipte deðer gönderebiliriz.
- Fonksiyonlardan sadece bir deðer döndürebiliriz.
- Fonksiyonlar kullanýlmadan önce derleyiciye bildirilmelidir.

son maddeyi açalým. Bir fonksiyon kullanýlmadan önce derleyiciye ben böyle bir
fonksiyon yazdým sonra kullanýcam demek lazýmdýr. Bunu üç farklý þekilde yapabiliriz.

- birinci yöntem yukarýda yaptýðýmýz gibi önce fonksiyonu yazýp, daha sonraki satýrlarda
  kullanmak. Bu her zaman mümkün olmaz, özellikle fonksiyon baþka bir dosyada ise

- ikinci yöntem fonksiyon tanýmýný önceden derleyiciye bildirmek.
  Fonksiyon tanýmý yaptýðýmýz þekilde kod bloðu olmadan <dönüþ deðeri, adý, ve parametrelerinin olduðu satýrý> alýp
  üst taraflara bir yere koymak.

?- üçüncü yöntem ise fonksiyon tanýmlarýnýn hepsini bir yere toplayýp ayrý bir
?  dosyaya yazmak, ve programýn baþýnda bu dosyalarý #include ile programa eklemek.
?  bu dosyanýn en baþýndaki satýrlarý nihayet anladýk. hemen gidip bu gözle bir daha bakýn.
?  hatta bahsi geçen dosyalarý mouse sað tuþ týklayýp açýp içinde tanýmlanmýþ bi
?  ton abuk sabuk þeyleri görün. :) çoðunu ben bile anlamasam da kullandýðýmýz
?  printf gibi fonksiyonlarýn tanýmlarý oralarda yapýlýyor.

evet bir kaç örnek fonksiyon yazmadan evvel void mevzusuna girelim

void tanýmsýz demektir. Türkçedeki þey gibi biþi.

fonksiyon tanýmlarken eðer deðer döndürmeyeceksek tipini void olarak tanýmlarýz.

mesela
*/
void deger_dondurmeyen_fonksiyon(int fonksiyona_giden_deger)
{
printf("\r\n ben sadece ekrana bunu yazarým. \r\n %d \r\n",fonksiyona_giden_deger);
//return; // olmasa da olur.
}
/*
geri deðer dönmeyeceði için fonksiyonun sonunda return kullanmadým. Zaten blok kapandýðý için
fonksiyon bitmiþtir. geri dönecektir.

ayný þekilde eðer fonksiyona deðer göndermeyeceksek tanýmlarken bunu da void olarak belirtiriz
örnek hiç parametre almayan ve geri deðer döndürmeyen fonksiyon.
kullanýmý aþaðýda
*/
void almam_vermem(void)
{
printf("ben kendi kafama göre takýlýrým ama globalleride oynarým\r\n");
globalim_benim = globalim_benim + 1; //main den önce tanýmlanmýþ global deðiþken
printf("Bu fonksiyon %d kere çalýþtý\r\n",globalim_benim);
}
/*
fonksiyonlardan çýkmak için illede bloðun sonuna ulaþmak þart deðildir.
bir döngünün içindeyken return ile çýkýlabilir. geri deðer döndüren fonksiyon ise
return den sonra dönecek deðeri belirtmemiz lazýmdýr.

//-----------------------------------------------------------------------------

evet fazla uzatmadan burada bitirelim. aþaðýya bir fonksiyon daha yazacaðým.
onun tanýmýný en üste yazdým çünkü fonksiyonu programýn en sonunda yazacaðým,
ama þimdi kullanacaðým için yukarýda tanýmlamam gerek. örnek olmasý için gidip
yukarýdaki tanýmlandýðý yeri // ile kapatýp derleyicinin nasýl mýzýldadýðýný görün.
çalýþýn ,debugger ile nasýl çalýþtýðýný inceleyin. satýr satýr çalýþtýrýrken
program akýþýnýn fonksiyonlara nasýl dallanýp geri geldiðine dikkat edin.
Debuggerdeki StepInto ile fonksiyona dallanmayý görün.

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