#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------------------
/*
Konular
- #define
- #ifdef #else #endif
- #undef
*/
//-----------------------------------------------------------------------------------------
void ledyak(int led)
{
printf("led yandi %d \r\n",led);
}
//-----------------------------------------------------------------------------------------
void ledsondur(int led)
{
printf("led sondu :%d \r\n",led);
}
//-----------------------------------------------------------------------------------------
void main()
{
/*
    C nin güzelliklerinden birine geldik. Bu #define tanýmý program derlenirken kullanýlýr.
Güzelliði þurada derleyiciye ben þunu yazarsam sen aslýnda bunu anlayacaksýn diyoruz. Bunun
bir sýnýrý yok. Her þeyi tanýmlayabiliriz. Nerede iþe yarar dersek kodun genelinde çok sýk kullanýlan,
ve sabit olan þeylerin kolayca deðiþtirilmesine yarar. Bazen de kodun baþka bir sisteme transferini
kolaylaþtýrmak için kullanýlýr.//!Program derlenirken kullanýldðý için program derlendikten sonra
!deðiþtirme þansýmýz yoktur. Yani deðiþkenler gibi deðil. Ekrana yazdýrmak için text olarak verdiðimiz
mesajlarda dikkate alýnmaz. Zaten oraya ne istersek yazýyoruz derleyici orala karýþmaz.

Örnekle anlatalým:
1.Led yakýp söndüren bir kodda ledi hangi çýkýþa baðladýðýmýzý akýlda tutmamak ve baþka bir çýkýþa
  baðlamak istediðimizde bütün programý elden geçirmemek için tanýmlama yapacaðýz. ledyak ve ledsondur
  diye 2 tane fonksiyonumuz olsun. Bu fonksiyonlara ledlerin baglý oldu çýkýþlarýn numarasýný verdiðimizde
  ledi yakýp söndürüyor olsun. 3 tane de ledimiz olsun. neyse koda bakýnca anlaþýlýr zaten fazla uzatmayayým
  */
  #define LED_POWER 4
  #define LED_OK 1
  #define LED_SIGNAL 9

  ledyak(LED_POWER);
  ledyak(LED_OK);
  ledsondur(LED_SIGNAL);
  /*
  *bir süre sonra ledlerin takýldýðý deðiþtirmek istersek tanýmý deðiþtirmek yeterli. Hem ne güzel neyi
  *nere taktýydýk, onun numarasý neydi diye düþünmek yerine daha önemli þeylere kafa yorabiliriz.

2.Örneðimizde ses kaydý yapan bir program yazdýk onu tanýtmak için beleþ daðýtmak istiyoruz. Ama
  para kazanabilmek için bu beleþ versiyonda 20 saniyeden uzun kayýt yapýlmasýn istiyoruz. Programý
  yazdýktan sonra baþtan sona elden geçirip bütün kritik yerleri deðiþtirerek demo versiyonu
  hazýrlamak, bunu ayrý bir kopya olarak tutmak zorundayýz. Onun yerine kodun kritik yerlerinde
  bir if komutu ile programýn demo olduðuna dair bir deðiþkenin deðerini kontrol edip, ona göre
  iþlem yapmak daha mantýklý. þöyle 1 taným yapalým

  #define PROGRAM_TURU 1

  *burada derleyiciye kodu derlerken PROGRAM_TURU yazdýðýmda sen onu 1 olarak anlayacaksýn diyoruz.
  kodun içinde de þu þekilde kullanýyoruz

  if (PROGRAM_TURU == 1)
     {//demo modu
     ...
     ...
     }
     else
     {//full sürüm
     ...
     ...
     }


3.Program yazarken tembelliðimiz tuttu deðiþken tanýmlarken her seferinde unsigned char yazmak yerine
  onu uchar diye tanýmlayalým. Yapacaðýmýz iþ gayet basit
  */
  #define uchar unsigned char

  uchar c;
  c=')';
  printf("unsigned char i uchar olarak tanimladik ya la c :%c \r\n",c);
  /*
  Yaþasýn programcýlarýn tembelliði.
  !Bu programý derlerken derleyici uchar diye bir þeye rastlarsa onu unsigned char olarak deðerlendirecek.






//-------------------------------------------------------------------------------
- #ifdef #if #else #endif
  Bu arkadaþlar ile bir tanýmlama yapýlmýþ mý yapýlmamýþ mý diye kontrol yaparýz.
Kullanýma örnek :
?1.Program yazarken kritik yerlerde hata yapmadýðýmýzdan emin olmak için aslýnda gerekli olmayan, hatayý
?  bulabilmek için bazý iþler yaptýk diyelim. En son iþ bittiðinde buralarý silmek yerine tekrar lazým
?  olabilir diye silmeden iptal etmek için ne yaparýz.
  */
  #define DEBUG
  //...
  //...
  #ifdef DEBUG
  printf("debug modu: bu satir sadece debug modunda derlenir \r\n");
  #else
  printf("normal mod: bu satir debug modunda derlenmez \r\n");
  #endif
  /*
  Yukarýda #define DEBUG satýrýný // ile kapatýrsanýz derleyicinin hangi satýrlarý derleyeceðini görebilirsiniz.
  #burada #ifdef kullandýk. Bu o tanýmýn yapýlýp yapýlmadýðýna bakar. #if ile tanýmýn deðerine bakabiliriz.
  Ayný örneði kullanalým.
  */
  #define DEBUG_MODE 0
  //...
  //...
  #if DEBUG_MODE == 1
  printf("debug modu: bu satir sadece debug modunda derlenir \r\n");
  #else
  printf("normal mod: bu satir debug modunda derlenmez \r\n");
  #endif
  /*
  yukarýdaki debug tanýmýn yapýldýðý satýrdaki 0 deðerini 1 ile deðiþtirip sonucu görünüz.

2.Yukarýda verdiðim led örneðinden devam edelim. Diyelim ki ayný karttan 2 ayrý model ürettik. Ýkisinde de
  ayný ledler var, kodlar da ayný ama ledler farklý çýkýþlara baðlý. Hangi kart için derleme yapacaksak bütün
  ledlerin tanýmlarýný deðiþtirmemiz gerekli. Hemen kolaya kaçýyoruz ve:
  */
  #define KART_VERS 2


  #if KART_VERS == 1
      #define LED_POWER 4
      #define LED_OK 1
      #define LED_SIGNAL 9
      #elif KART_VERS == 2
            #define LED_POWER 2
            #define LED_OK 3
            #define LED_SIGNAL 1
            #endif

  ledyak(LED_POWER);
  ledyak(LED_OK);
  ledsondur(LED_SIGNAL);
/*
  #ifdef ve #if farkýna dikkat ediniz.
  #ifdef taným yapýlmýþ mý diye bakar, deðeri önemli deðil
  #if tanýmýn deðerine bakar

*/

return;
}