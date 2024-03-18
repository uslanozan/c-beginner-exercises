#include <stdio.h>
#include <stdlib.h>
/*
konular
- c de yazým stilleri
- c de dosya yapýsý
- c de program akýþý
- if komutu ve code block
- deðiþken tanýmý, local, global
- goto komutu
- while komutu
- for komutu
*/
int main()
{
/*
--------------------------------------------------------------------------------------------------------------------------------
- c de yazým stilleri: c de program yazarken tanýmlarýn,komutlarýn arasýna bir boþluk koymak yeterlidir. komutlar ";" ile biter.
bundan gerisi tamamen bize kalmýþ. kodumuzu istediðimiz gibi satýrlara paragraflara bölüp satýr baþlarýna istediðimiz kadar
boþluk atabiliriz. c derleyicisi bunlarý takmaz. Ýstersen bütün programý tek satýrda yaz derleyicinin üreteceði sonuç aynýdýr.
Ama bu yazdýðýmýz programýn anlaþýlýrlýðýný zorlaþtýrmaktan baþka bir fayda saðlamaz. Onun için program yazmaya baþlarken ilk
dikkat etmeniz gereken þey düzgün okunaklý yazým þekline kendinizi alýþtýrmanýzdýr. Tecrübelerime göre uzun zaman önce yazdýðým
programlarý tekrar elden geçirmem gerektiðinde bunun çok iþe yaradýðýný biliyorum. Verdiðim örneklerde sürekli ayný yazým
kurallarýný kullanýyorum. Kullandýðým stile alýþýn ve kullanmaya çalýþýn. Yýllarýn deneyimleri ile þekillenmiþ iþe yarar,
pratik bir stil olduðunu düþünüyorum.

--------------------------------------------------------------------------------------------------------------------------------
- c de dosya yapýsý : Bir c programý en basit hali ile içinde "main" fonksiyonu olan tek bir dosyadýr. Bunu derleyiciye vererek
çalýþabilir bir program dosyasý oluþturabiliriz. Dosyanýn içine yazdýðýmýz kodun büyüklüðü önemli deðildir. Tek dosya içine
binlerce satýr yazýp çalýþabiliriz. Fakat iþler büyüdükce tek bir dosyanýn içinde yüzbinlerce satýr içinde çalýþmak, aradýðýmýz
yeri arayýp bulmak zorlaþýyor. Onun için programýmýzý yapýlan iþlere göre parçalayýp farklý dosyalara bölmek onlara anlamlý
isimler vermek çok büyük kolaylýk saðlamaktadýr. Bunun bir faydasý da yazdýðýmýz kodlarý baþka bir projede kullanmak istersek
basitce dosyalarý kopyalayýp diðer projeye ekleme imkaný vermesi. Kullandýðýmýz editör üstünde çalýþtýðýmýz dosyalarý takip
etmekle sorumlu olduðu için kendisi ayrýca bir proje dosyasý oluþturur. Bu dosyada kullandýðýmýz kod dosyalarý açýklama/yardým
dosyalarý gibi þeylerin diskte nerede kayýtlý olduðu, hangi fontu kullandýðýmýz gibi yazdýðýmýz kod ile alakasý olmayan
þeylerin kaydýný tutar. C derleyicisinin bunlarla alakasý yoktur. Örnek olarak bu projeyi kaydettiðiniz klasörü açýp, oluþan
dosyalara bakabilirsiniz.

--------------------------------------------------------------------------------------------------------------------------------
- c de program akýþý : C dilinde yazýlan programlar "main" fonksiyonundan baþlar, main fonksiyonundan çýkýnca program bitmiþtir.
bizim yapacaðýmýz her þey "main" fonksiyonun içinde olup biter. Her adýmda bir komut iþlenir. komut bitince diðer
komuta geçilir. Sýralý doðrusal bir akýþý vardýr. Kullandýðýmýz komutlar ile bu akýþý deðiþik satýrlara yönlendirir, akýþý
yönetiriz. Bu sýrada kendi kafamýzda kurduðumuz mantýk ile yapmak istediðimiz iþleri bilgisayara yaptýrmýþ oluruz. Dolaysý ile
her programcýnýn programý eþsizdir. Kendi mantýðýna bilgisine zevkine göre þekillenir. Bilgisayar ne yaptýðýný bilmez, sadece
ona verdiðimiz basit komutlar ile karmaþýk iþleri yapabilmesini saðladýðýmýz aptal bir araçtýr. Dolaysý ile onun yaptýðý bütün
iþi bizim planlamamýz yönetmemiz gerekir. Burada bazý hatalar yapýlmasý doðaldýr. Biz de mükemmel deðiliz.
Kafamýzda yazacaðýmýz programý tasarlayýp, oturup bi solukta yazýp çalýþtýrmak gibi bir þey yoktur. Bu durumda program
yazma iþi genelde þöyle olur:
    Yapýlacak iþin/problemin tanýmlanmasý, kabaca mantýksal bir çözüm düþünülmesi, bu mantýksal çözümün
kafada veya kaðýt üstünde irdelenmesi. Yapýlacak iþin kaba bölümlere ayrýlmasý. En zor veya kritik bölümlerin düþünülmesi.
Program yazmaya baþlama. Önce kritik/zor yerlerin yazýlmasý, test edilmesi. Diðer parçalarýn yazýlmasý, test edilmesi.
Parçalarýn birleþtirilmesi, test edilmesi.

görüldüðü üzere karmaþýk iþler bütün olarak baþtan baþlayýp deðil küçük parçalara ayýrýp parça parça yazýlýr. Bu durumda
program yazmanýn en önemli kýsmýna geliyoruz.
    DEBUG. ilk yapýlan antik bilgisayarda oluþan bir arýzanýn bilgisayarýn içine giren bir böcek tarafýndan oluþturulmasýndan
dolayý bir espri yapýlmýþ ,bu esprinin çok tutmasýndan dolayý bilgisayar programlarýndaki hatalara böcek anlamýna gelen BUG
denmiþtir, denmektedir. Programda hata bulma iþine de DEBUG yani böceksizleþtirme denmektedir. Bu iþi yapmamýza yardýmcý
olmasý için hazýrlanmýþ araçlara da DEBUGGER denir. Program yazarken, yazmak sorun deðildir. Asýl önemli olan hatalarý
bulabilmektir. þimdi basitce program yazarken oluþabilecek hatalarý gruplandýrýp kabaca bir göz atalým.

    Yazým hatalarý : Eðer bir yazým hatasý yaptýysak mesela "if" yazacaðýmýza yanlýþlýkla "ig" yazdýysak ilk hatayý
derleyici verir. Bu ne la anlamadým ben bunu der. Bunlarý bulmak kolaydýr. Zaten derleyici hata yapýlan satýrý bize bildirir.
Doðrusunu yazar tekrar derleriz.

    Yanlýþ tanýmlar : Yazdýðýmýz c ifadeleri doðrudur, ama alakasýz yerlerde veya yanlýþ þekilde kullanýlmýþtýr. Bunlarý da
derleyici yerini gösterir. Verdiðimiz deðiþken tanýmlanmamýþ olabilir veya tanýmlandýðý tip uygun olmayabilir, Açtýðýmýz bir
parantezi kapatmayý unutmuþuzdur gibi. Düzeltir devam ederiz.

    Mantýk hatalarý : Buraya kadar olan hatalarda derleyici bize hatayý bariz biçimde iþaret eder. Düzeltmek basittir.
Ama eðer bizim mantýðýmýzda hata varsa bunlarý bulabilmek daha zordur. Mesela toplama iþlemi yaparken "+" yerine "-"
yazmýþsak program hata vermez. Ama doðal olarak program istediðimiz sonuçlarý üretmez. Bunun gibi hatalarý bulabilmek için
debugger'a hakim olmamýz gerekir. Debugger bize program akýþýný istediðimiz yerde durdurma imkaný verir, tanýmlanmýþ
deðiþkenlerin deðerlerini gösterir. bir satýrý çalýþtýrýp tekrar durdurabilir. Bunlar  hata canavarýna karþý en güçlü
silahýmýzdýr. Aptal bilgisayarýn yapmasýný istediðimiz þeyin yaptýðý þey ile ayný olup olmadýðýný kontrol etmek gerekir.
Hatasýz kod yazmak imkansýzdýr. Hatalarý bulabilmek yazmakdan çok daha önemlidir. Bunun için önceki verdiðim örneklerde
debugger kullanýmýný basitce gösterdim. Ýsterseniz geriye dönüp önceki örnekleri birde bu gözle tekrar inceleyin.
Debugger en önemli yardýmcýnýzdýr. Onu sevin. :)

    Donaným hatalarý : Bunlar genelde hata sayýlmaz. Doðal olarak zamanýnda düþünülmesi gereken þeylerdir. Ama pratikde
gözden kaçabiliyor örnek olarak bilgisayara bir ses dosyasýný çalmasýný söylediniz. Ama bilgisayarda ses çalacak donaným
yok. Veya seri porttan baþka bir cihaza veri göndereceðiz ama usb seri port zýmbýrtýsýný takmayý unuttuk gibi. Bunun
çözümü doðal olarak kullanmadan önce "donaným var mý?" diye bakmak.

evet hatalar ve debugger konusu bu kadar. Program akýþý ile hala anlatacaklarým var ama sonraki konularýn içinde yavaþ
yavaþ anlatmayý düþünüyorum.

--------------------------------------------------------------------------------------------------------------------------------
- if komutu ve code block : "if" komutu ile bir þeylerin durumuna bakar ona göre sýralý akýþý kesip baþka iþler yapabiliriz.
Zaten detaylý kullanýmýný önceden vermiþtim.

Ben bunu biliyorum deyip geçmeyin anlatacaðým baþka þeyler var.

kullanýmý þu þekilde.
if (þart)
   þart doðru ise yapýlacak iþ.

eðer þart mantýksal doðru ise alttaki satýr iþlenir. Deðilse iþlenmez.
"if" komutunun bir de kankisi vardýr o da "else". Kullanýmý mecburi deðildir. Lazýmsa kullanýrýz. verdiðimiz þart doðru
olduðunda yapýlacak bir iþ yanlýþ ise yapýlacak baþka bir iþ varsa kullanýrýz.

hemen bir örnek verelim

int sayi1,sayi2,fark;

if (sayi1 > sayi2)
   fark = sayi1 - sayi2;
   else
   fark=sayi2-sayi1;

burada iki sayý arasýndaki farký bulmak istedim ama sonucun negatif çýkmamasý için büyük sayýdan küçük sayýyý çýkarmak istedim.
görüldüðü üzere burada "else" kullandým. bu iþ farklý þekilde de yapýlabilirdi ama bu þekilde yapmýþ olalým.
"else" den önce ve sonraki satýrlara dikkat edelim. ilkinde aralara boþluk attým, ama "else" den sonraki satýrda boþluk kullanmadým.
bu önceden söylediðim gibi tamamen görsel. ikisininde derleyici açýsýndan farký yok. "else" yazdýktan sonra ";" kullanmadýðýmýza
dikkat edin. toparlarsak "if" in kullanýmý:

if (þart)
   komut ;

else ile beraber

if (þart)
   komut1 ;
   else
   komut2 ;


    Þimdi kafayý boþaltýp sakince devam edin. Ya "if" komutunda yapýlacak bir kaç iþ daha varsa ne yapacaz ??? yani :

if (þart)
   komut1;
   komut2;
   komut3;

Bu þekilde eðer þart yanlýþ ise komut1 iþlenmez ama komut2 ve komut3 iþlenir. Yani bir mantýk hatasý yaptýk. Derleyiciye
istediðimizi düzgün anlatamadýk. þu þekilde yazarsam daha anlaþýlýr olur sanýrým.

if (þart)
   komut1;
komut2;
komut3;

komut1 if e baðlý ama komut2 ve komut3
her durumda çalýþýr if ile alakasý yoktur. bu gibi durumlarda code block dediðimiz þeye geldik. Çok afilli gibi görünse de
aslýnda basit bir süslü parantezdir kendisi "{" ile baþlar "}" ile biter. C de her komut yazdýðýmýz yere code block açýp
bir çok komut yazabiliriz. C komutlarý "if" de olduðu gibi genelde tek komutluktur. Bunlarý geniþletmek için code block
kullanýrýz. þimdi yukarýda yapmayý düþünüp de yapamadýðým þeyi yapalým.
Þart doðru ise komut1 komut2 komut3 iþlensin.

if (þart)
   {
   komut1;
   komut2;
   komut3;
   }

bu þekilde amacýmýza ulaþmýþ olduk. Dikkat ettiyseniz "main" de bir code block ile çalýþýyor.

    Code block konusunda anlatýlmasý gereken önemli þeyler var yeri geldikçe lazým oldukça anlatýrým. Þimdilik þunu bilelim
bir komut yazdýðýmýz her yere code block açýp çok komutlar yazabiliriz. Bir code block içinde baþka code blocklar olabilir.
Her code block içinde tekrar deðiþken tanýmlayabiliriz. O deðiþkenler sadece o code block içinde ve alt bloklarda geçerlidir.

--------------------------------------------------------------------------------------------------------------------------------
- deðiþken tanýmý, local, global

C de deðiþkenleri kullanmak için ilk önce tanýmlanmasý gerektiðini söyledik. Fakat nerede tanýmlanmasý gerektiðini söylemedik.
Code block olayýný anladýðýmýza göre artýk bu konuya gelelim. Deðiþkenler code block baþlangýcýnda tanýmlanýr. Daha sonraki
satýrlarda tanýmlama yaparsak derleyici büyük ihtimalle bize kýzar. büyük ihtimalle diyorum çünkü bazý derleyiciler buna izin
verebilir, herkes kafasýna iþ yapýyor anasýný satayým. Siz yine de bu kurala uyun. Yazdýðýnýz kodlarý baþka bir derleyicede
kullanmak isterseniz bütün kodu elden geçirmeniz gerekmesin.
Hemen örnek vereyim.
*/
{
int a;
a=123;
int b;
b=456;
printf("%d - %d",a,b);
}
/*
!burada derleyici "b" deðiþkeninin tanýmlandýðý yerde maraz çýkarýr. olmaz bu der. sebebide "a=123;" satýrý çalýþtýrýlabilir
bir komut olduðu için o satýrdan sonra deðiþken tanýmlanmasýna izin vermez. önce deðiþken tanýmla sonra kullan.

doðrusu þu þekilde

{
int a;
int b;
a=123;
b=456;
}

þu þekilde de olabilir. virgülle ayýrýp bir çok deðiþken tanýmlama olayý.

{
int a,b;
a=123;
b=456;
}

bu blok içinde "a" ve "b" deðiþkenleri kullanýlýr ama bloðun bittiði yerde o deðiþkenler yok edilir. sonrasýnda kullanmak
isterseniz hata oluþur. Bu þekilde tanýmlanmýþ deðiþkenlere local (yerel) deðiþkenler denir.

bloklarýn iç içe tanýmlanabileceðini söylemiþtik. Bir blok içinde tanýmlanmýþ local deðiþkenler üst blokda tanýmsýzdýr.
Ama alttaki bloklarda kullanýlabilir. Hemen örnek yapalým


doðrusu
*/
{
int a,b;
a=123;
b=456;
  {//burasý yeni blok yukarýdaki local deðiþkenler buranýn globali gibi
  int fark;
  fark=a-b;//fark local, a b deðil
  printf("fark = %d\r\n",fark);
  }
}
/*
yanlýþý
*/
{
int a,b;
a=123;
b=456;
  {//burasý yeni blok yukarýdaki local deðiþkenler buranýn globali gibi
  int fark;
  fark=a-b;
  printf("fark = %d\r\n",fark);
  }
//printf("fark = %d\r\n",fark); bu satýrý sonraki örnekler derlenebilsin diye kapattým. lazým olunca açýn
}
/*
sebep : çünkü farkýn tanýmlandýðý blok kapatýldýktan sonra fark yok edilir. artýk öyle bir deðiþken yoktur sonraki
satýr cortlar.


local deðiþkenler tanýmlanýrken eðer üst blokda ayný isimde bir deðiþken varsa bizim kafamýz karýþabilir ama derleyici
yeni deðiþkeni kullanýr ayný isimde iki tane deðiþken vardýr ama artýk üst blokdaki deðiþkene ulaþamayýz. localde
tanýmlanmýþ deðiþken geçerli olur. Buna dikkat edelim. Böyle bir hatayý bulmak zor olabilir.
örnek
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
görüldüðü üzere ekrana önce 20 sonra 10 yazdý. ikinci blokda da a deðiþkeni var ama aslýnda bunlar farklý deðiþkenler.




þimdi gelelim her yerde her zaman geçerli olacak deðiþken lazým olursa. Aslýnda local deðiþken anlatýrken mantýðý verdik.
"main"den önce tanýmlanmýþ deðiþkenler "main"de geçerlidir. O zaman programýn her yerinde geçerlidir. Bu arkadaþlara global
deðiþkenler denir.

Ne gerek var: her deðiþken hafýzada yer tutar. Local deðiþkenler yok edildikten sonra kullandýðý hafýza bölgesi geri
dönüþüme gider, baþka iþler için kullanýlýr. Ekonomiye kazandýrýlýr. asla kaybolmamasý gereken sürekli kullandýðýmýz
deðiþkenler ise global tanýmlanýr. Lazým olduðunda orada olacaðýný bilir mutlu oluruz.

Çok kafa karýþtýrmasýn zaman içinde kullandýkça hata yapýp debug ettikçe alýþýrsýnýz.
Debugger'ý sevin.
--------------------------------------------------------------------------------------------------------------------------------
?- goto komutu : Bu komutla yukarýdan aþaðý akýp gelen programý baþka bir satýra yönlendirebiliriz. gideceði yeri iþaret etmek
?için label (etiket) kullanýlýr. etiket tanýmý þu þekilde "isim:"
?hemen bir örnek verelim. debugger ile satýr satýr ilerleyerek inceleyin.
*/
{ //burada main altýnda yeni bir code block açýyoruz
int a,b,c; //bunlar bu code block'un local deðiþkenleri

a=10;
b=0;
c=0;
//!-------------------------------
donbaba: //döngü baþlangýcý olarak label tanýmladýk

if (b>a)//hedefe ulaþtýk mý?
   goto bitti;
c=c+b;//toplam deðer c de tutuluyor
b=b+1;// b yi 1 arttýr
goto donbaba;// haydi baþa git

bitti: // buraya geldiyse yukardaki döngüden çýktýk demektir
printf("0 - %d arasý sayýlarýn toplamý = %d\r\n",a,c);//sonuçlarý yazalým

} // bloðu kapatýyoruz. burada yaþananlar burada kalýr

/*

gayet basit en temel C komutu olarak goto böyle.
yapýlmamasý gerekenler goto ile gidilecek yerin alakasýz bir yer olmamasý.

goto komutu en az kullanýlan C komutudur. Blocklar ve fonksiyonlar iþ bitirici olduðu için genelde pek gerek kalmaz.
Ama lazým olduðu yerlerde olur. aaaa goto kullanmýþ diye dalga geçenler bile olabilir, aldýrmayýn.


--------------------------------------------------------------------------------------------------------------------------------
- while komutu : Ýtiraf ediyorum bu komutu anlatabilmek için yukarýda "goto" komutunu anlattým :D //*(çok ayýp baba :D)
bu komut "if" e benzer ama ýsrarcýdýr. "if" þarta bakar doðruysa iþini yapar sonraki komuttan devam eder. "while" komutu da þarta
bakar doðruysa iþi yapar ama sonraki komuttan devam etmez , tekrar þarta bakar yine iþi yapar. þart doðru olduðu sürece "while"
ayný iþi yapar. yanlýþlýkla programýn sonsuz döngüye düþmesinin en önemli sebebi bu arkadaþtýr :)

while (þart)
      komut;

while (þart)
      {
      komut1;
      komut2;
      komut3;
      }

goto örneðini while ile yapalým.
*/

{ //burada main altýnda yeni bir code block açýyoruz
int a,b,c; //bunlar bu code block'un local deðiþkenleri

a=10;
b=0;
c=0;

while ( (a+1) > b)
      {
      c=c+b;//toplam deðer c de tutuluyor
      b=b+1;// b yi 1 arttýr
      }

printf("0 - %d arasý sayýlarýn toplamý = %d\r\n",a,c);//sonuçlarý yazalým

} // bloðu kapatýyoruz. burada yaþananlar burada kalýr

/*
--------------------------------------------------------------------------------------------------------------------------------
- for komutu : Bu arkadaþ while komutunun az biraz geliþmiþidir.
Kýsaca þart saðlandýðý sürece while'da olduðu gibi komut çalýþtýrmaya yarar.

for (komut1;þart;komut3)
    komut2;
tekrardan hatýrlatayým C de komutun çalýþtýðý her yerde blok açýp bir sürü komut daha yazabilirsiniz

evet detaylandýralým.
1.adým- ilk önce tek seferlik komut1 çalýþtýrýlýr. Bu komut bir daha çalýþtýrýlmaz
2.adým- Sonra þart kontrol edilir.
3.adým- þart doðru ise komut2 çalýþýr, deðilse "for" bitmiþtir akýþ komut2 nin altýndaki satýrdan devam eder.
4.adým- komut2 çalýþtýysa komut3 çalýþtýrýlýr.
5.adým- 2.adýma geri dönülür.

görüldüðü üzere whilenin az geliþmiþi.
hemen ayný örneði for ile yapalým

*/

{ //burada main altýnda yeni bir code block açýyoruz
int a,b,c; //bunlar bu code block'un local deðiþkenleri

a=10;
c=0;

for ( b=0; (a+1)>b; b=b+1 )
    c=c+b;//toplam deðer c de tutuluyor

printf("0 - %d arasý sayýlarýn toplamý = %d\r\n",a,c);//sonuçlarý yazalým

} // bloðu kapatýyoruz. burada yaþananlar burada kalýr
/*

görüldüðü üzere ayný iþi yapan çok farklý komutlar kullandýk. ama harcadýðýmýz satýr sayýsý sürekli azaldý :D
þimdilik bu kadar. konuyu okuyun, örnekleri çalýþtýrýn. F7 ile adým adým çalýþtýrýp sonuçlarý görün.
internetten C'de yazýlmýþ deðiþik programlar bulup inceleyin. Bulduðunuz kodlarýn yarýsýndan fazlasýný anlar
hale gelmiþ olmanýz lazým.
--------------------------------------------------------------------------------------------------------------------------------

*/
return 0;
}