#include<stdio.h>
#include<locale.h> //? T�rk�e karakter i�in

int main(void){
    setlocale(LC_ALL,"Turkish");

    //?
    //*
    //!

    //! ctrl+alt+m    �al��an kodu durdurur  ????  ayn� zamanda ctrl+c de durdurur terminalde
    //! ctrl+alt+n    runlar
    //! ctl+l         terminali temizler

    //* double'�n range'i float'tan daha fazlad�r.

    //* %d: Tam say�lar� (int) yazd�rmak i�in.
    //* %f: Ondal�k say�lar� (float veya double) yazd�rmak i�in.
    //* %c: Karakterleri yazd�rmak i�in (char).
    //* %s: Karakter dizilerini (string) yazd�rmak i�in.
    //* %p: Pointer i�in yani haf�zadaki memory address'ini yazd�r�r.

    /*
    int c;
    printf("say� gir: \n");
    scanf("say� gir: %d",c);
    printf("Hello world \n");
    printf("Hello world 2\n");
    printf("Hello world 3 \n");
    */
    
    // T�rk�e karakter i�eren bir string
    const char *turkceMetin = "Merhaba, D�nya! T�rk�e karakter: ������";

    // UTF-8 karakter setini kullanarak ekrana yazd�rma
    printf("%s\n", turkceMetin);

    return 0;


}