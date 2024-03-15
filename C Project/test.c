#include<stdio.h>
#include<locale.h> //? Türkçe karakter için

int main(void){
    setlocale(LC_ALL,"Turkish");

    //?
    //*
    //!

    //? mainde execute olur ve en sondaki return 0; aslýnda kodun oraya kadar hatasýz çalýþtýðýný belirtir
    //? return 0 hariç her þey hatalý sinyalini verir

    //! caps+alt ile o satýrý taþýr
    //! ctrl+alt+m    çalýþan kodu durdurur  ????  ayný zamanda ctrl+c de durdurur terminalde
    //! ctrl+alt+n    runlar
    //! ctl+l         terminali temizler

    //* double'ýn range'i float'tan daha fazladýr.

    //* %d: Tam sayýlarý (int) yazdýrmak için.
    //* %f: Ondalýk sayýlarý (float veya double) yazdýrmak için.
    //* %c: Karakterleri yazdýrmak için (char).
    //* %s: Karakter dizilerini (string) yazdýrmak için.
    //* %p: Pointer için yani hafýzadaki memory address'ini yazdýrýr.

    //? C'de string olayý bir týk farklý


    char myText[]="Hello\n";
    printf("%s",myText);

    /*
    int c;
    printf("sayý gir: \n");
    scanf("sayý gir: %d",c);
    printf("Hello world \n");
    printf("Hello world 2\n");
    printf("Hello world 3 \n");
    */
    
    // Türkçe karakter içeren bir string
    char *turkceMetin = "Merhaba, Dünya! Türkçe karakter: çðýöþü";

    // UTF-8 karakter setini kullanarak ekrana yazdýrma
    printf("%s\n", turkceMetin);

    float my_float = 42.8f;
    printf("%d",(int)my_float);

    char buffer[100];
//    printf("Enter: ");
//    scanf("%s,buffer");
//    printf("Buffer: %s\n",buffer);

    //? boþluk býrakarak input almaya yarar
    printf("Enter: ");
    fgets(buffer,100,stdin);  //* standart input,
    printf("Buffer: %s\n",buffer);

    float test1=4.2;
    float test2=4.2f;

    printf("%.6f\n",test1);
    printf("%.6f",test2);

    return 0;


}