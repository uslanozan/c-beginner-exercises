#include<stdio.h>
#include<locale.h> //? Türkçe karakter için

int main(void){
    setlocale(LC_ALL,"Turkish");

    //?
    //*
    //!

    //! ctrl+alt+m    çalýþan kodu durdurur  ????  ayný zamanda ctrl+c de durdurur terminalde
    //! ctrl+alt+n    runlar
    //! ctl+l         terminali temizler

    //* double'ýn range'i float'tan daha fazladýr.

    //* %d: Tam sayýlarý (int) yazdýrmak için.
    //* %f: Ondalýk sayýlarý (float veya double) yazdýrmak için.
    //* %c: Karakterleri yazdýrmak için (char).
    //* %s: Karakter dizilerini (string) yazdýrmak için.
    //* %p: Pointer için yani hafýzadaki memory address'ini yazdýrýr.

    /*
    int c;
    printf("sayý gir: \n");
    scanf("sayý gir: %d",c);
    printf("Hello world \n");
    printf("Hello world 2\n");
    printf("Hello world 3 \n");
    */
    
    // Türkçe karakter içeren bir string
    const char *turkceMetin = "Merhaba, Dünya! Türkçe karakter: çðýöþü";

    // UTF-8 karakter setini kullanarak ekrana yazdýrma
    printf("%s\n", turkceMetin);

    return 0;


}