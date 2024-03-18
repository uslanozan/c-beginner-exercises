#include <stdio.h>
#include <stdlib.h>
/*
konular
- c de yaz�m stilleri
- c de dosya yap�s�
- c de program ak���
- if komutu ve code block
- de�i�ken tan�m�, local, global
- goto komutu
- while komutu
- for komutu
*/
int main()
{
/*
--------------------------------------------------------------------------------------------------------------------------------
- c de yaz�m stilleri: c de program yazarken tan�mlar�n,komutlar�n aras�na bir bo�luk koymak yeterlidir. komutlar ";" ile biter.
bundan gerisi tamamen bize kalm��. kodumuzu istedi�imiz gibi sat�rlara paragraflara b�l�p sat�r ba�lar�na istedi�imiz kadar
bo�luk atabiliriz. c derleyicisi bunlar� takmaz. �stersen b�t�n program� tek sat�rda yaz derleyicinin �retece�i sonu� ayn�d�r.
Ama bu yazd���m�z program�n anla��l�rl���n� zorla�t�rmaktan ba�ka bir fayda sa�lamaz. Onun i�in program yazmaya ba�larken ilk
dikkat etmeniz gereken �ey d�zg�n okunakl� yaz�m �ekline kendinizi al��t�rman�zd�r. Tecr�belerime g�re uzun zaman �nce yazd���m
programlar� tekrar elden ge�irmem gerekti�inde bunun �ok i�e yarad���n� biliyorum. Verdi�im �rneklerde s�rekli ayn� yaz�m
kurallar�n� kullan�yorum. Kulland���m stile al���n ve kullanmaya �al���n. Y�llar�n deneyimleri ile �ekillenmi� i�e yarar,
pratik bir stil oldu�unu d���n�yorum.

--------------------------------------------------------------------------------------------------------------------------------
- c de dosya yap�s� : Bir c program� en basit hali ile i�inde "main" fonksiyonu olan tek bir dosyad�r. Bunu derleyiciye vererek
�al��abilir bir program dosyas� olu�turabiliriz. Dosyan�n i�ine yazd���m�z kodun b�y�kl��� �nemli de�ildir. Tek dosya i�ine
binlerce sat�r yaz�p �al��abiliriz. Fakat i�ler b�y�d�kce tek bir dosyan�n i�inde y�zbinlerce sat�r i�inde �al��mak, arad���m�z
yeri aray�p bulmak zorla��yor. Onun i�in program�m�z� yap�lan i�lere g�re par�alay�p farkl� dosyalara b�lmek onlara anlaml�
isimler vermek �ok b�y�k kolayl�k sa�lamaktad�r. Bunun bir faydas� da yazd���m�z kodlar� ba�ka bir projede kullanmak istersek
basitce dosyalar� kopyalay�p di�er projeye ekleme imkan� vermesi. Kulland���m�z edit�r �st�nde �al��t���m�z dosyalar� takip
etmekle sorumlu oldu�u i�in kendisi ayr�ca bir proje dosyas� olu�turur. Bu dosyada kulland���m�z kod dosyalar� a��klama/yard�m
dosyalar� gibi �eylerin diskte nerede kay�tl� oldu�u, hangi fontu kulland���m�z gibi yazd���m�z kod ile alakas� olmayan
�eylerin kayd�n� tutar. C derleyicisinin bunlarla alakas� yoktur. �rnek olarak bu projeyi kaydetti�iniz klas�r� a��p, olu�an
dosyalara bakabilirsiniz.

--------------------------------------------------------------------------------------------------------------------------------
- c de program ak��� : C dilinde yaz�lan programlar "main" fonksiyonundan ba�lar, main fonksiyonundan ��k�nca program bitmi�tir.
bizim yapaca��m�z her �ey "main" fonksiyonun i�inde olup biter. Her ad�mda bir komut i�lenir. komut bitince di�er
komuta ge�ilir. S�ral� do�rusal bir ak��� vard�r. Kulland���m�z komutlar ile bu ak��� de�i�ik sat�rlara y�nlendirir, ak���
y�netiriz. Bu s�rada kendi kafam�zda kurdu�umuz mant�k ile yapmak istedi�imiz i�leri bilgisayara yapt�rm�� oluruz. Dolays� ile
her programc�n�n program� e�sizdir. Kendi mant���na bilgisine zevkine g�re �ekillenir. Bilgisayar ne yapt���n� bilmez, sadece
ona verdi�imiz basit komutlar ile karma��k i�leri yapabilmesini sa�lad���m�z aptal bir ara�t�r. Dolays� ile onun yapt��� b�t�n
i�i bizim planlamam�z y�netmemiz gerekir. Burada baz� hatalar yap�lmas� do�ald�r. Biz de m�kemmel de�iliz.
Kafam�zda yazaca��m�z program� tasarlay�p, oturup bi solukta yaz�p �al��t�rmak gibi bir �ey yoktur. Bu durumda program
yazma i�i genelde ��yle olur:
    Yap�lacak i�in/problemin tan�mlanmas�, kabaca mant�ksal bir ��z�m d���n�lmesi, bu mant�ksal ��z�m�n
kafada veya ka��t �st�nde irdelenmesi. Yap�lacak i�in kaba b�l�mlere ayr�lmas�. En zor veya kritik b�l�mlerin d���n�lmesi.
Program yazmaya ba�lama. �nce kritik/zor yerlerin yaz�lmas�, test edilmesi. Di�er par�alar�n yaz�lmas�, test edilmesi.
Par�alar�n birle�tirilmesi, test edilmesi.

g�r�ld��� �zere karma��k i�ler b�t�n olarak ba�tan ba�lay�p de�il k���k par�alara ay�r�p par�a par�a yaz�l�r. Bu durumda
program yazman�n en �nemli k�sm�na geliyoruz.
    DEBUG. ilk yap�lan antik bilgisayarda olu�an bir ar�zan�n bilgisayar�n i�ine giren bir b�cek taraf�ndan olu�turulmas�ndan
dolay� bir espri yap�lm�� ,bu esprinin �ok tutmas�ndan dolay� bilgisayar programlar�ndaki hatalara b�cek anlam�na gelen BUG
denmi�tir, denmektedir. Programda hata bulma i�ine de DEBUG yani b�ceksizle�tirme denmektedir. Bu i�i yapmam�za yard�mc�
olmas� i�in haz�rlanm�� ara�lara da DEBUGGER denir. Program yazarken, yazmak sorun de�ildir. As�l �nemli olan hatalar�
bulabilmektir. �imdi basitce program yazarken olu�abilecek hatalar� grupland�r�p kabaca bir g�z atal�m.

    Yaz�m hatalar� : E�er bir yaz�m hatas� yapt�ysak mesela "if" yazaca��m�za yanl��l�kla "ig" yazd�ysak ilk hatay�
derleyici verir. Bu ne la anlamad�m ben bunu der. Bunlar� bulmak kolayd�r. Zaten derleyici hata yap�lan sat�r� bize bildirir.
Do�rusunu yazar tekrar derleriz.

    Yanl�� tan�mlar : Yazd���m�z c ifadeleri do�rudur, ama alakas�z yerlerde veya yanl�� �ekilde kullan�lm��t�r. Bunlar� da
derleyici yerini g�sterir. Verdi�imiz de�i�ken tan�mlanmam�� olabilir veya tan�mland��� tip uygun olmayabilir, A�t���m�z bir
parantezi kapatmay� unutmu�uzdur gibi. D�zeltir devam ederiz.

    Mant�k hatalar� : Buraya kadar olan hatalarda derleyici bize hatay� bariz bi�imde i�aret eder. D�zeltmek basittir.
Ama e�er bizim mant���m�zda hata varsa bunlar� bulabilmek daha zordur. Mesela toplama i�lemi yaparken "+" yerine "-"
yazm��sak program hata vermez. Ama do�al olarak program istedi�imiz sonu�lar� �retmez. Bunun gibi hatalar� bulabilmek i�in
debugger'a hakim olmam�z gerekir. Debugger bize program ak���n� istedi�imiz yerde durdurma imkan� verir, tan�mlanm��
de�i�kenlerin de�erlerini g�sterir. bir sat�r� �al��t�r�p tekrar durdurabilir. Bunlar  hata canavar�na kar�� en g��l�
silah�m�zd�r. Aptal bilgisayar�n yapmas�n� istedi�imiz �eyin yapt��� �ey ile ayn� olup olmad���n� kontrol etmek gerekir.
Hatas�z kod yazmak imkans�zd�r. Hatalar� bulabilmek yazmakdan �ok daha �nemlidir. Bunun i�in �nceki verdi�im �rneklerde
debugger kullan�m�n� basitce g�sterdim. �sterseniz geriye d�n�p �nceki �rnekleri birde bu g�zle tekrar inceleyin.
Debugger en �nemli yard�mc�n�zd�r. Onu sevin. :)

    Donan�m hatalar� : Bunlar genelde hata say�lmaz. Do�al olarak zaman�nda d���n�lmesi gereken �eylerdir. Ama pratikde
g�zden ka�abiliyor �rnek olarak bilgisayara bir ses dosyas�n� �almas�n� s�ylediniz. Ama bilgisayarda ses �alacak donan�m
yok. Veya seri porttan ba�ka bir cihaza veri g�nderece�iz ama usb seri port z�mb�rt�s�n� takmay� unuttuk gibi. Bunun
��z�m� do�al olarak kullanmadan �nce "donan�m var m�?" diye bakmak.

evet hatalar ve debugger konusu bu kadar. Program ak��� ile hala anlatacaklar�m var ama sonraki konular�n i�inde yava�
yava� anlatmay� d���n�yorum.

--------------------------------------------------------------------------------------------------------------------------------
- if komutu ve code block : "if" komutu ile bir �eylerin durumuna bakar ona g�re s�ral� ak��� kesip ba�ka i�ler yapabiliriz.
Zaten detayl� kullan�m�n� �nceden vermi�tim.

Ben bunu biliyorum deyip ge�meyin anlataca��m ba�ka �eyler var.

kullan�m� �u �ekilde.
if (�art)
   �art do�ru ise yap�lacak i�.

e�er �art mant�ksal do�ru ise alttaki sat�r i�lenir. De�ilse i�lenmez.
"if" komutunun bir de kankisi vard�r o da "else". Kullan�m� mecburi de�ildir. Laz�msa kullan�r�z. verdi�imiz �art do�ru
oldu�unda yap�lacak bir i� yanl�� ise yap�lacak ba�ka bir i� varsa kullan�r�z.

hemen bir �rnek verelim

int sayi1,sayi2,fark;

if (sayi1 > sayi2)
   fark = sayi1 - sayi2;
   else
   fark=sayi2-sayi1;

burada iki say� aras�ndaki fark� bulmak istedim ama sonucun negatif ��kmamas� i�in b�y�k say�dan k���k say�y� ��karmak istedim.
g�r�ld��� �zere burada "else" kulland�m. bu i� farkl� �ekilde de yap�labilirdi ama bu �ekilde yapm�� olal�m.
"else" den �nce ve sonraki sat�rlara dikkat edelim. ilkinde aralara bo�luk att�m, ama "else" den sonraki sat�rda bo�luk kullanmad�m.
bu �nceden s�yledi�im gibi tamamen g�rsel. ikisininde derleyici a��s�ndan fark� yok. "else" yazd�ktan sonra ";" kullanmad���m�za
dikkat edin. toparlarsak "if" in kullan�m�:

if (�art)
   komut ;

else ile beraber

if (�art)
   komut1 ;
   else
   komut2 ;


    �imdi kafay� bo�alt�p sakince devam edin. Ya "if" komutunda yap�lacak bir ka� i� daha varsa ne yapacaz ??? yani :

if (�art)
   komut1;
   komut2;
   komut3;

Bu �ekilde e�er �art yanl�� ise komut1 i�lenmez ama komut2 ve komut3 i�lenir. Yani bir mant�k hatas� yapt�k. Derleyiciye
istedi�imizi d�zg�n anlatamad�k. �u �ekilde yazarsam daha anla��l�r olur san�r�m.

if (�art)
   komut1;
komut2;
komut3;

komut1 if e ba�l� ama komut2 ve komut3
her durumda �al���r if ile alakas� yoktur. bu gibi durumlarda code block dedi�imiz �eye geldik. �ok afilli gibi g�r�nse de
asl�nda basit bir s�sl� parantezdir kendisi "{" ile ba�lar "}" ile biter. C de her komut yazd���m�z yere code block a��p
bir �ok komut yazabiliriz. C komutlar� "if" de oldu�u gibi genelde tek komutluktur. Bunlar� geni�letmek i�in code block
kullan�r�z. �imdi yukar�da yapmay� d���n�p de yapamad���m �eyi yapal�m.
�art do�ru ise komut1 komut2 komut3 i�lensin.

if (�art)
   {
   komut1;
   komut2;
   komut3;
   }

bu �ekilde amac�m�za ula�m�� olduk. Dikkat ettiyseniz "main" de bir code block ile �al���yor.

    Code block konusunda anlat�lmas� gereken �nemli �eyler var yeri geldik�e laz�m olduk�a anlat�r�m. �imdilik �unu bilelim
bir komut yazd���m�z her yere code block a��p �ok komutlar yazabiliriz. Bir code block i�inde ba�ka code blocklar olabilir.
Her code block i�inde tekrar de�i�ken tan�mlayabiliriz. O de�i�kenler sadece o code block i�inde ve alt bloklarda ge�erlidir.

--------------------------------------------------------------------------------------------------------------------------------
- de�i�ken tan�m�, local, global

C de de�i�kenleri kullanmak i�in ilk �nce tan�mlanmas� gerekti�ini s�yledik. Fakat nerede tan�mlanmas� gerekti�ini s�ylemedik.
Code block olay�n� anlad���m�za g�re art�k bu konuya gelelim. De�i�kenler code block ba�lang�c�nda tan�mlan�r. Daha sonraki
sat�rlarda tan�mlama yaparsak derleyici b�y�k ihtimalle bize k�zar. b�y�k ihtimalle diyorum ��nk� baz� derleyiciler buna izin
verebilir, herkes kafas�na i� yap�yor anas�n� satay�m. Siz yine de bu kurala uyun. Yazd���n�z kodlar� ba�ka bir derleyicede
kullanmak isterseniz b�t�n kodu elden ge�irmeniz gerekmesin.
Hemen �rnek vereyim.
*/
{
int a;
a=123;
int b;
b=456;
printf("%d - %d",a,b);
}
/*
!burada derleyici "b" de�i�keninin tan�mland��� yerde maraz ��kar�r. olmaz bu der. sebebide "a=123;" sat�r� �al��t�r�labilir
bir komut oldu�u i�in o sat�rdan sonra de�i�ken tan�mlanmas�na izin vermez. �nce de�i�ken tan�mla sonra kullan.

do�rusu �u �ekilde

{
int a;
int b;
a=123;
b=456;
}

�u �ekilde de olabilir. virg�lle ay�r�p bir �ok de�i�ken tan�mlama olay�.

{
int a,b;
a=123;
b=456;
}

bu blok i�inde "a" ve "b" de�i�kenleri kullan�l�r ama blo�un bitti�i yerde o de�i�kenler yok edilir. sonras�nda kullanmak
isterseniz hata olu�ur. Bu �ekilde tan�mlanm�� de�i�kenlere local (yerel) de�i�kenler denir.

bloklar�n i� i�e tan�mlanabilece�ini s�ylemi�tik. Bir blok i�inde tan�mlanm�� local de�i�kenler �st blokda tan�ms�zd�r.
Ama alttaki bloklarda kullan�labilir. Hemen �rnek yapal�m


do�rusu
*/
{
int a,b;
a=123;
b=456;
  {//buras� yeni blok yukar�daki local de�i�kenler buran�n globali gibi
  int fark;
  fark=a-b;//fark local, a b de�il
  printf("fark = %d\r\n",fark);
  }
}
/*
yanl���
*/
{
int a,b;
a=123;
b=456;
  {//buras� yeni blok yukar�daki local de�i�kenler buran�n globali gibi
  int fark;
  fark=a-b;
  printf("fark = %d\r\n",fark);
  }
//printf("fark = %d\r\n",fark); bu sat�r� sonraki �rnekler derlenebilsin diye kapatt�m. laz�m olunca a��n
}
/*
sebep : ��nk� fark�n tan�mland��� blok kapat�ld�ktan sonra fark yok edilir. art�k �yle bir de�i�ken yoktur sonraki
sat�r cortlar.


local de�i�kenler tan�mlan�rken e�er �st blokda ayn� isimde bir de�i�ken varsa bizim kafam�z kar��abilir ama derleyici
yeni de�i�keni kullan�r ayn� isimde iki tane de�i�ken vard�r ama art�k �st blokdaki de�i�kene ula�amay�z. localde
tan�mlanm�� de�i�ken ge�erli olur. Buna dikkat edelim. B�yle bir hatay� bulmak zor olabilir.
�rnek
*/

{
int a;
a=10;
   {
   int a;
   a=20;
   printf("a=%d\r\n",a);
   }
printf("a=%d\r\n",a);
}

/*
g�r�ld��� �zere ekrana �nce 20 sonra 10 yazd�. ikinci blokda da a de�i�keni var ama asl�nda bunlar farkl� de�i�kenler.




�imdi gelelim her yerde her zaman ge�erli olacak de�i�ken laz�m olursa. Asl�nda local de�i�ken anlat�rken mant��� verdik.
"main"den �nce tan�mlanm�� de�i�kenler "main"de ge�erlidir. O zaman program�n her yerinde ge�erlidir. Bu arkada�lara global
de�i�kenler denir.

Ne gerek var: her de�i�ken haf�zada yer tutar. Local de�i�kenler yok edildikten sonra kulland��� haf�za b�lgesi geri
d�n���me gider, ba�ka i�ler i�in kullan�l�r. Ekonomiye kazand�r�l�r. asla kaybolmamas� gereken s�rekli kulland���m�z
de�i�kenler ise global tan�mlan�r. Laz�m oldu�unda orada olaca��n� bilir mutlu oluruz.

�ok kafa kar��t�rmas�n zaman i�inde kulland�k�a hata yap�p debug ettik�e al���rs�n�z.
Debugger'� sevin.
--------------------------------------------------------------------------------------------------------------------------------
?- goto komutu : Bu komutla yukar�dan a�a�� ak�p gelen program� ba�ka bir sat�ra y�nlendirebiliriz. gidece�i yeri i�aret etmek
?i�in label (etiket) kullan�l�r. etiket tan�m� �u �ekilde "isim:"
?hemen bir �rnek verelim. debugger ile sat�r sat�r ilerleyerek inceleyin.
*/
{ //burada main alt�nda yeni bir code block a��yoruz
int a,b,c; //bunlar bu code block'un local de�i�kenleri

a=10;
b=0;
c=0;
//!-------------------------------
donbaba: //d�ng� ba�lang�c� olarak label tan�mlad�k

if (b>a)//hedefe ula�t�k m�?
   goto bitti;
c=c+b;//toplam de�er c de tutuluyor
b=b+1;// b yi 1 artt�r
goto donbaba;// haydi ba�a git

bitti: // buraya geldiyse yukardaki d�ng�den ��kt�k demektir
printf("0 - %d aras� say�lar�n toplam� = %d\r\n",a,c);//sonu�lar� yazal�m

} // blo�u kapat�yoruz. burada ya�ananlar burada kal�r

/*

gayet basit en temel C komutu olarak goto b�yle.
yap�lmamas� gerekenler goto ile gidilecek yerin alakas�z bir yer olmamas�.

goto komutu en az kullan�lan C komutudur. Blocklar ve fonksiyonlar i� bitirici oldu�u i�in genelde pek gerek kalmaz.
Ama laz�m oldu�u yerlerde olur. aaaa goto kullanm�� diye dalga ge�enler bile olabilir, ald�rmay�n.


--------------------------------------------------------------------------------------------------------------------------------
- while komutu : �tiraf ediyorum bu komutu anlatabilmek i�in yukar�da "goto" komutunu anlatt�m :D //*(�ok ay�p baba :D)
bu komut "if" e benzer ama �srarc�d�r. "if" �arta bakar do�ruysa i�ini yapar sonraki komuttan devam eder. "while" komutu da �arta
bakar do�ruysa i�i yapar ama sonraki komuttan devam etmez , tekrar �arta bakar yine i�i yapar. �art do�ru oldu�u s�rece "while"
ayn� i�i yapar. yanl��l�kla program�n sonsuz d�ng�ye d��mesinin en �nemli sebebi bu arkada�t�r :)

while (�art)
      komut;

while (�art)
      {
      komut1;
      komut2;
      komut3;
      }

goto �rne�ini while ile yapal�m.
*/

{ //burada main alt�nda yeni bir code block a��yoruz
int a,b,c; //bunlar bu code block'un local de�i�kenleri

a=10;
b=0;
c=0;

while ( (a+1) > b)
      {
      c=c+b;//toplam de�er c de tutuluyor
      b=b+1;// b yi 1 artt�r
      }

printf("0 - %d aras� say�lar�n toplam� = %d\r\n",a,c);//sonu�lar� yazal�m

} // blo�u kapat�yoruz. burada ya�ananlar burada kal�r

/*
--------------------------------------------------------------------------------------------------------------------------------
- for komutu : Bu arkada� while komutunun az biraz geli�mi�idir.
K�saca �art sa�land��� s�rece while'da oldu�u gibi komut �al��t�rmaya yarar.

for (komut1;�art;komut3)
    komut2;
tekrardan hat�rlatay�m C de komutun �al��t��� her yerde blok a��p bir s�r� komut daha yazabilirsiniz

evet detayland�ral�m.
1.ad�m- ilk �nce tek seferlik komut1 �al��t�r�l�r. Bu komut bir daha �al��t�r�lmaz
2.ad�m- Sonra �art kontrol edilir.
3.ad�m- �art do�ru ise komut2 �al���r, de�ilse "for" bitmi�tir ak�� komut2 nin alt�ndaki sat�rdan devam eder.
4.ad�m- komut2 �al��t�ysa komut3 �al��t�r�l�r.
5.ad�m- 2.ad�ma geri d�n�l�r.

g�r�ld��� �zere whilenin az geli�mi�i.
hemen ayn� �rne�i for ile yapal�m

*/

{ //burada main alt�nda yeni bir code block a��yoruz
int a,b,c; //bunlar bu code block'un local de�i�kenleri

a=10;
c=0;

for ( b=0; (a+1)>b; b=b+1 )
    c=c+b;//toplam de�er c de tutuluyor

printf("0 - %d aras� say�lar�n toplam� = %d\r\n",a,c);//sonu�lar� yazal�m

} // blo�u kapat�yoruz. burada ya�ananlar burada kal�r
/*

g�r�ld��� �zere ayn� i�i yapan �ok farkl� komutlar kulland�k. ama harcad���m�z sat�r say�s� s�rekli azald� :D
�imdilik bu kadar. konuyu okuyun, �rnekleri �al��t�r�n. F7 ile ad�m ad�m �al��t�r�p sonu�lar� g�r�n.
internetten C'de yaz�lm�� de�i�ik programlar bulup inceleyin. Buldu�unuz kodlar�n yar�s�ndan fazlas�n� anlar
hale gelmi� olman�z laz�m.
--------------------------------------------------------------------------------------------------------------------------------

*/
return 0;
}