#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//- Programda kullanacağımız bazı tanımlamalar ---------------------------------
#define evet 101
#define hayir 104
#define cik 27
#define dogru 100
//------------------------------------------------------------------------------
int sor_eh(void)
{
int key;
while (1)
      {
      printf("tekrar oynamak ister misin? (e/h)\r\n");
	   key = getch();
      if ( (key == hayir) || (key==evet) )
         return key;
      }
}
//------------------------------------------------------------------------------
void ben_tuttum_sen_bul(int alt, int ust)
{
int key;
int alt_limit;
int ust_limit;
int orta;
int bitti;
int tekrar_oyna;
//e 101  e karakterinin sayısal karşılığı
//h 104
key=0;
tekrar_oyna=1;

while (tekrar_oyna)
      {
      alt_limit = alt;
	   ust_limit = ust;
      while (key!=13)
			   {
            printf("%d ile %d arasi bir sayi tut. Sonra entere bas.\r\n",alt_limit,ust_limit);
            key = getch();
            }
      bitti=0;
      while (!bitti)
            {
            orta=(ust_limit+alt_limit)/2;
            printf("tuttugun sayi %d 'den buyuk mu? (e/h) Tuttugun sayi buysa d ye bas\r\n",orta);
            key = getch();
            switch (key)
                   {
                   case cik:
                        bitti=1;
                        tekrar_oyna=0;
                        break;
                   case evet:
                        alt_limit=orta;
                        break;
                   case hayir:
						      ust_limit=orta;
                        break;
                   case dogru:
                        bitti=1;
                        printf("nasil bildim ama xD \r\n");
                        key=sor_eh();
                        if (key == hayir)
                           tekrar_oyna=0;
                        break;
                   }
            }
	  }
printf("iyi mademli\r\n");
getch();
}
//------------------------------------------------------------------------------
void sen_tuttun_ben_buldu(int alt, int ust)
{
int sayi;
int tahmin;
int deneme;
int key;

sayi=(rand()% (ust-1) )+1+alt;
printf("%d ile %d arasi bir sayi tuttum.\r\n",alt,ust);
deneme=1;
while (1)
      {
      printf("Tahmin et bakalim.   %d.denemen\r\n",deneme++);
      scanf("%d",&tahmin);
      getchar();
      if (tahmin==sayi)
         {
         printf("aferim len, bildin\r\n");
         key = sor_eh();
         if (key == hayir)
            break;
            else
            {
            sayi=(rand()% (ust-1) )+1+alt;
            deneme=1;
            printf("%d ile %d arasi bir sayi tuttum.\r\n",alt,ust);
            }
         }
         else
         if (tahmin<sayi)
            printf("benim sayi bundan buyuk\r\n");
            else
            printf("benim sayi bundan kucuk\r\n");
      }
getch();
}
//------------------------------------------------------------------------------
int oyun (void)
{
int key;
printf ("Ben tuttum sen bul oyununu mu oynamak istersiniz(E) yoksa,\r\nSen tuttun ben buldu(H) oyununu mu oynamak istersiniz?\r\n------------------------\r\n" );
key = getch();
switch (key)
	    {
       case evet:
			   ben_tuttum_sen_bul(0,100);
			   break;
       case hayir:
			   sen_tuttun_ben_buldu(0,100);
			   break;
       }
}
//------------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL,"Turkish");
//ben_tuttum_sen_bul(0,100);
//sen_tuttun_ben_buldu(0,100);
oyun();
return 0;
}
//------------------------------------------------------------------------------