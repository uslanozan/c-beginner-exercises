Konular
-Balýk tutmak
-Çeþitli fonksiyonlar

Artýk bir fonksiyon tanýmýný gördüðümüzde onun nasýl kullanýlacaðýný anlýyor olmamýz lazým.
Çeþitli kaynaklardan yardým alýrken fonksiyonun prototipi denilen fonksiyonun tanýmý verilir.
Bu prototipe bakýp fonksiyona varsa eðer gönderdiðimiz deðerlerin anlamý, fonksiyondan
dönen deðer ve anlamlarý gibi bilgiler verilir. Burada size balýk tutmayý öðreteceðim.
þimdi aþaðýdaki satýrda kelimenin üstüne týklayýp F1 tuþuna basýn.

getch()

Help ekraný açýlacak. Ve arama yerinde getch yazacak. Entere basýp getch fonksiyonun
açýklamasýný görelim.

Açýlan yardým sayfasýna bakýp neler olduðunu görelim.

Header File : burada getch fonksiyonunun hangi .h dosyasýnda tanýmlandýðýný yazýyor.
bu fonksiyonu kullanabilmek için kodumuzun baþýna
#include<conio.h>
satýrýný eklememiz lazýmmýþ.

Category :
Console I/O Routines

Bu fonksiyonun hangi kategoride olduðunu belirtiyor.

Prototype
int getch(void);

Hah iþte bahsettiðim prototip olayý. Buna göre bu fonksiyonu çaðýrýrken bir
parametre vermiyoruz. Fonksiyon geri dönerken int deðer döndürüyormuþ.


Description:
Gets character from keyboard, does not echo to screen.
getch reads a single character directly from the keyboard, without echoing to the screen.
Note: Do not use this function in Win32 GUI applications.

Bu bölümde fonksiyona ait açýklama var. Yazdýðýna göre klavyeden bir karakter alýp
getirirmiþ. Fakat basýlan tuþu ekrana yazdýrmazmýþ. Son olarak da bir uyarý veriyor.
Bu fonksiyonu Win32 GUI uygulamalarýnda kullanmayýn diyor.


Return Value:
getch returns the character read from the keyboard.

Yukarýda fonksiyonun dönüþ deðerinin int olduðunu yazmýþtý. Burada da dönendeðerin
açýklamasý. getch klavyeden okunan deðeri döndürür diyor.


Example:
Fonksiyonu bir örnekle açýklýyor. Aferim ona.


Portability:
Bu kýsýmda taþýnabilirlik diyebiliriz. Bu fonksiyon hangi ortamlarda kullanýlabilir
onu belirtiyor.


eveeet az biraz ingiliççe lazým olduðunu görüyoruz.
Ýngilizce dökümanlarý anlamaya çalýþýn gerekirse translate/sözlük felan ne lazýmsa
kullanýn. Orcinal bilgi kaynaðýndan beslenmek çok faydalýdýr. Türkçe kaynak bulucam
diye uðraþmayýn ingilizce kaynaðý anlamaya öðrenmeye çalýþýn.


Þimdi öðrenmeyi öðrendiðimize göre bilinmesi gereken fonksiyonlarý ben sadece adýný
ve gerekirse kýsa açýklamasýný vericem. Gerisini F1 yardýmýyla veya internetten arayarak
kendiniz bulabilirsiniz. Verdiðim listede bulunan bütün fonksiyonlarý öðrenin. Verilen örnekleri
mutlaka çalýþtýrýp inceleyin. Ezberlemeyin, sadece lazým olduðunda hatýrlayacak kadar her fonksiyona
ilgi alaka gösterin.
Anlamadýðýnýz þeyler olursa sorunuz.
Geçelim listemize:

-clrscr ekraný siler
-gotoxy cursoru/imleci/ekranda yazýlacak yeri ayarlar
-wherex cursorun yatay konumunu verir
-wherey cursorun dikey konumunu verir
-textcolor yazýnýn rengini deðiþtirir
-cprintf renkli þekilli þukullu printf
-getch klavyeden bir karakter okur, tuþa basýlmasýný bekler
-putch bi karakteri ekrana basar
-scanf klavyeden formatlý bilgi giriþi

-sprintf printf'in yazýlarý ekrana deðil de bir hafýza bölgesine yazaný
-isalnum verilen karakter alphanumeric(A..Z a..z 0..9) mi sorusuna cevap arar
-isalpha verilen karakter alphabetic mi? (A..Z a..z)
-isdigit verilen karakter rakam mý? (0..9)
-atoi string'i integer'a çevir
-atof string', float'a çevir
-strcpy bir string'i baþka bir string'e kopyalar
-strcat iki string'i birleþtirir
-strlen string'in uzunluðunu verir
-strcmp iki string'i karþýlaþtýrýr
-strstr bir string'in içinde baþka bir string'i arar
-strchr bir string'in içinde bir karakter arar, aramaya baþtan baþlar
-strrchr bir string'in içinde bir karakter arar, aramaya sondan baþlar

-memcmp iki hafýza bölgesini karþýlaþtýrýr
-memset bir hafýza bölgesini bir sayý ile doldurur
-memcpy bir hafýza bölgesini baþka bir hafýza bölgesine kopyalar
-malloc bir hafýza bölgesini bize ayýrýr