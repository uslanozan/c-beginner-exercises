#include<stdio.h>
#include<locale.h> //? T�rk�e karakter i�in

int main(void){
    setlocale(LC_ALL,"Turkish");

    //?
    //*
    //!

    //? mainde execute olur ve en sondaki return 0; asl�nda kodun oraya kadar hatas�z �al��t���n� belirtir
    //? return 0 hari� her �ey hatal� sinyalini verir

    //! caps+alt ile o sat�r� ta��r
    //! ctrl+alt+m    �al��an kodu durdurur  ????  ayn� zamanda ctrl+c de durdurur terminalde
    //! ctrl+alt+n    runlar
    //! ctl+l         terminali temizler

    //* double'�n range'i float'tan daha fazlad�r.

    //* %d: Tam say�lar� (int) yazd�rmak i�in.
    //* %f: Ondal�k say�lar� (float veya double) yazd�rmak i�in.
    //* %c: Karakterleri yazd�rmak i�in (char).
    //* %s: Karakter dizilerini (string) yazd�rmak i�in.
    //* %p: Pointer i�in yani haf�zadaki memory address'ini yazd�r�r.

    //? C'de string olay� bir t�k farkl�


    char myText[]="Hello\n";
    printf("%s",myText);

    /*
    int c;
    printf("say� gir: \n");
    scanf("say� gir: %d",c);
    printf("Hello world \n");
    printf("Hello world 2\n");
    printf("Hello world 3 \n");
    */
    
    // T�rk�e karakter i�eren bir string
    char *turkceMetin = "Merhaba, D�nya! T�rk�e karakter: ������";

    // UTF-8 karakter setini kullanarak ekrana yazd�rma
    printf("%s\n", turkceMetin);

    float my_float = 42.8f;
    printf("%d",(int)my_float);

    char buffer[100];
//    printf("Enter: ");
//    scanf("%s,buffer");
//    printf("Buffer: %s\n",buffer);

    //? bo�luk b�rakarak input almaya yarar
    printf("Enter: ");
    fgets(buffer,100,stdin);  //* standart input,
    printf("Buffer: %s\n",buffer);

    float test1=4.2;
    float test2=4.2f;

    printf("%.6f\n",test1);
    printf("%.6f",test2);

    return 0;


}