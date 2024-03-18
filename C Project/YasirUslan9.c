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
    C nin g�zelliklerinden birine geldik. Bu #define tan�m� program derlenirken kullan�l�r.
G�zelli�i �urada derleyiciye ben �unu yazarsam sen asl�nda bunu anlayacaks�n diyoruz. Bunun
bir s�n�r� yok. Her �eyi tan�mlayabiliriz. Nerede i�e yarar dersek kodun genelinde �ok s�k kullan�lan,
ve sabit olan �eylerin kolayca de�i�tirilmesine yarar. Bazen de kodun ba�ka bir sisteme transferini
kolayla�t�rmak i�in kullan�l�r.//!Program derlenirken kullan�ld�� i�in program derlendikten sonra
!de�i�tirme �ans�m�z yoktur. Yani de�i�kenler gibi de�il. Ekrana yazd�rmak i�in text olarak verdi�imiz
mesajlarda dikkate al�nmaz. Zaten oraya ne istersek yaz�yoruz derleyici orala kar��maz.

�rnekle anlatal�m:
1.Led yak�p s�nd�ren bir kodda ledi hangi ��k��a ba�lad���m�z� ak�lda tutmamak ve ba�ka bir ��k��a
  ba�lamak istedi�imizde b�t�n program� elden ge�irmemek i�in tan�mlama yapaca��z. ledyak ve ledsondur
  diye 2 tane fonksiyonumuz olsun. Bu fonksiyonlara ledlerin bagl� oldu ��k��lar�n numaras�n� verdi�imizde
  ledi yak�p s�nd�r�yor olsun. 3 tane de ledimiz olsun. neyse koda bak�nca anla��l�r zaten fazla uzatmayay�m
  */
  #define LED_POWER 4
  #define LED_OK 1
  #define LED_SIGNAL 9

  ledyak(LED_POWER);
  ledyak(LED_OK);
  ledsondur(LED_SIGNAL);
  /*
  *bir s�re sonra ledlerin tak�ld��� de�i�tirmek istersek tan�m� de�i�tirmek yeterli. Hem ne g�zel neyi
  *nere takt�yd�k, onun numaras� neydi diye d���nmek yerine daha �nemli �eylere kafa yorabiliriz.

2.�rne�imizde ses kayd� yapan bir program yazd�k onu tan�tmak i�in bele� da��tmak istiyoruz. Ama
  para kazanabilmek i�in bu bele� versiyonda 20 saniyeden uzun kay�t yap�lmas�n istiyoruz. Program�
  yazd�ktan sonra ba�tan sona elden ge�irip b�t�n kritik yerleri de�i�tirerek demo versiyonu
  haz�rlamak, bunu ayr� bir kopya olarak tutmak zorunday�z. Onun yerine kodun kritik yerlerinde
  bir if komutu ile program�n demo oldu�una dair bir de�i�kenin de�erini kontrol edip, ona g�re
  i�lem yapmak daha mant�kl�. ��yle 1 tan�m yapal�m

  #define PROGRAM_TURU 1

  *burada derleyiciye kodu derlerken PROGRAM_TURU yazd���mda sen onu 1 olarak anlayacaks�n diyoruz.
  kodun i�inde de �u �ekilde kullan�yoruz

  if (PROGRAM_TURU == 1)
     {//demo modu
     ...
     ...
     }
     else
     {//full s�r�m
     ...
     ...
     }


3.Program yazarken tembelli�imiz tuttu de�i�ken tan�mlarken her seferinde unsigned char yazmak yerine
  onu uchar diye tan�mlayal�m. Yapaca��m�z i� gayet basit
  */
  #define uchar unsigned char

  uchar c;
  c=')';
  printf("unsigned char i uchar olarak tanimladik ya la c :%c \r\n",c);
  /*
  Ya�as�n programc�lar�n tembelli�i.
  !Bu program� derlerken derleyici uchar diye bir �eye rastlarsa onu unsigned char olarak de�erlendirecek.






//-------------------------------------------------------------------------------
- #ifdef #if #else #endif
  Bu arkada�lar ile bir tan�mlama yap�lm�� m� yap�lmam�� m� diye kontrol yapar�z.
Kullan�ma �rnek :
?1.Program yazarken kritik yerlerde hata yapmad���m�zdan emin olmak i�in asl�nda gerekli olmayan, hatay�
?  bulabilmek i�in baz� i�ler yapt�k diyelim. En son i� bitti�inde buralar� silmek yerine tekrar laz�m
?  olabilir diye silmeden iptal etmek i�in ne yapar�z.
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
  Yukar�da #define DEBUG sat�r�n� // ile kapat�rsan�z derleyicinin hangi sat�rlar� derleyece�ini g�rebilirsiniz.
  #burada #ifdef kulland�k. Bu o tan�m�n yap�l�p yap�lmad���na bakar. #if ile tan�m�n de�erine bakabiliriz.
  Ayn� �rne�i kullanal�m.
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
  yukar�daki debug tan�m�n yap�ld��� sat�rdaki 0 de�erini 1 ile de�i�tirip sonucu g�r�n�z.

2.Yukar�da verdi�im led �rne�inden devam edelim. Diyelim ki ayn� karttan 2 ayr� model �rettik. �kisinde de
  ayn� ledler var, kodlar da ayn� ama ledler farkl� ��k��lara ba�l�. Hangi kart i�in derleme yapacaksak b�t�n
  ledlerin tan�mlar�n� de�i�tirmemiz gerekli. Hemen kolaya ka��yoruz ve:
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
  #ifdef ve #if fark�na dikkat ediniz.
  #ifdef tan�m yap�lm�� m� diye bakar, de�eri �nemli de�il
  #if tan�m�n de�erine bakar

*/

return;
}