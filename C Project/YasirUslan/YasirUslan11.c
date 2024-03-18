Konular
-Bal�k tutmak
-�e�itli fonksiyonlar

Art�k bir fonksiyon tan�m�n� g�rd���m�zde onun nas�l kullan�laca��n� anl�yor olmam�z laz�m.
�e�itli kaynaklardan yard�m al�rken fonksiyonun prototipi denilen fonksiyonun tan�m� verilir.
Bu prototipe bak�p fonksiyona varsa e�er g�nderdi�imiz de�erlerin anlam�, fonksiyondan
d�nen de�er ve anlamlar� gibi bilgiler verilir. Burada size bal�k tutmay� ��retece�im.
�imdi a�a��daki sat�rda kelimenin �st�ne t�klay�p F1 tu�una bas�n.

getch()

Help ekran� a��lacak. Ve arama yerinde getch yazacak. Entere bas�p getch fonksiyonun
a��klamas�n� g�relim.

A��lan yard�m sayfas�na bak�p neler oldu�unu g�relim.

Header File : burada getch fonksiyonunun hangi .h dosyas�nda tan�mland���n� yaz�yor.
bu fonksiyonu kullanabilmek i�in kodumuzun ba��na
#include<conio.h>
sat�r�n� eklememiz laz�mm��.

Category :
Console I/O Routines

Bu fonksiyonun hangi kategoride oldu�unu belirtiyor.

Prototype
int getch(void);

Hah i�te bahsetti�im prototip olay�. Buna g�re bu fonksiyonu �a��r�rken bir
parametre vermiyoruz. Fonksiyon geri d�nerken int de�er d�nd�r�yormu�.


Description:
Gets character from keyboard, does not echo to screen.
getch reads a single character directly from the keyboard, without echoing to the screen.
Note: Do not use this function in Win32 GUI applications.

Bu b�l�mde fonksiyona ait a��klama var. Yazd���na g�re klavyeden bir karakter al�p
getirirmi�. Fakat bas�lan tu�u ekrana yazd�rmazm��. Son olarak da bir uyar� veriyor.
Bu fonksiyonu Win32 GUI uygulamalar�nda kullanmay�n diyor.


Return Value:
getch returns the character read from the keyboard.

Yukar�da fonksiyonun d�n�� de�erinin int oldu�unu yazm��t�. Burada da d�nende�erin
a��klamas�. getch klavyeden okunan de�eri d�nd�r�r diyor.


Example:
Fonksiyonu bir �rnekle a��kl�yor. Aferim ona.


Portability:
Bu k�s�mda ta��nabilirlik diyebiliriz. Bu fonksiyon hangi ortamlarda kullan�labilir
onu belirtiyor.


eveeet az biraz ingili��e laz�m oldu�unu g�r�yoruz.
�ngilizce d�k�manlar� anlamaya �al���n gerekirse translate/s�zl�k felan ne laz�msa
kullan�n. Orcinal bilgi kayna��ndan beslenmek �ok faydal�d�r. T�rk�e kaynak bulucam
diye u�ra�may�n ingilizce kayna�� anlamaya ��renmeye �al���n.


�imdi ��renmeyi ��rendi�imize g�re bilinmesi gereken fonksiyonlar� ben sadece ad�n�
ve gerekirse k�sa a��klamas�n� vericem. Gerisini F1 yard�m�yla veya internetten arayarak
kendiniz bulabilirsiniz. Verdi�im listede bulunan b�t�n fonksiyonlar� ��renin. Verilen �rnekleri
mutlaka �al��t�r�p inceleyin. Ezberlemeyin, sadece laz�m oldu�unda hat�rlayacak kadar her fonksiyona
ilgi alaka g�sterin.
Anlamad���n�z �eyler olursa sorunuz.
Ge�elim listemize:

-clrscr ekran� siler
-gotoxy cursoru/imleci/ekranda yaz�lacak yeri ayarlar
-wherex cursorun yatay konumunu verir
-wherey cursorun dikey konumunu verir
-textcolor yaz�n�n rengini de�i�tirir
-cprintf renkli �ekilli �ukullu printf
-getch klavyeden bir karakter okur, tu�a bas�lmas�n� bekler
-putch bi karakteri ekrana basar
-scanf klavyeden formatl� bilgi giri�i

-sprintf printf'in yaz�lar� ekrana de�il de bir haf�za b�lgesine yazan�
-isalnum verilen karakter alphanumeric(A..Z a..z 0..9) mi sorusuna cevap arar
-isalpha verilen karakter alphabetic mi? (A..Z a..z)
-isdigit verilen karakter rakam m�? (0..9)
-atoi string'i integer'a �evir
-atof string', float'a �evir
-strcpy bir string'i ba�ka bir string'e kopyalar
-strcat iki string'i birle�tirir
-strlen string'in uzunlu�unu verir
-strcmp iki string'i kar��la�t�r�r
-strstr bir string'in i�inde ba�ka bir string'i arar
-strchr bir string'in i�inde bir karakter arar, aramaya ba�tan ba�lar
-strrchr bir string'in i�inde bir karakter arar, aramaya sondan ba�lar

-memcmp iki haf�za b�lgesini kar��la�t�r�r
-memset bir haf�za b�lgesini bir say� ile doldurur
-memcpy bir haf�za b�lgesini ba�ka bir haf�za b�lgesine kopyalar
-malloc bir haf�za b�lgesini bize ay�r�r