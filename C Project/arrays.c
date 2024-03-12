#include<stdio.h>
#include<string.h>  //? stringle �al��an baz� fonksiyonlar� ekler
#include<ctype.h>  //? lowercase,uppercase gibi char analizi yapabilir


int main(){

    int grade[5]={92,85,72,73,95};
    //! grade[5]=100;  bu �al��maz ��nk� tan�mlad���m bir dizinin uzunlu�unu artturanan

    int grade_length= sizeof(grade)/sizeof(grade[0]);
    //! C'de direkt olarak array uzunlu�unu veren bir komut yoktur
    //! Bunun i�in array'in size'�n� herhangi bir index'in size'�na b�leriz 
    //! ��nk� ayn� tip oldu�undan t�m de�erlerin size'� byte olarak ayn�d�r

    int total=0;
    
    /*
    grade[0]=92;
    grade[1]=85;
    grade[2]=72;
    grade[3]=73;
    grade[4]=95;
    */

    for (int i = 0; i < grade_length ; i++){
        printf("grade[%d]=%d\n",i,grade[i]);
        total += grade[i];
    }
    
    printf("\naverage: %d\n",total/5);
    printf("\n");

    /*-----------------------------STRING------------------------------------------------------------------*/

    char mydata[5];
    mydata[0]='a';
    mydata[1]='b';
    mydata[2]='c';
    mydata[3]='d';
    mydata[4]='\0';  //* bunu yazmazsak string'te liste sonuna \ koyar yani: abcd\  o y�zden \0 onu kald�r�r
                     //* yani listelerin sonu null ile biter

    printf("mydata[2] = %c\n", mydata[2]);
    printf("\n%s\n\n", mydata);   //? b�t�n array'i yazarken charlar'�n birle�imi string olaca��ndan %s yapt�k

    char s1[]="This is my string.";  //? array uzunlu�u 18

    for (int i = 0; i < 19; i++){  //! uzunlu�unu 1 fazla verdik array d���nda ne yazd�r�cak g�rmek i�in
        if (s1[i]=='\0')           //! \0 yazd�rd�p yazd�rmad���na bakt�k sadece
            printf("s1[%d] =\\0 \t \n",i);
        else
            printf("s1[%d] =%c\n",i, s1[i]);

    }


    char s2[20];

    printf("\nEnter: ");
    scanf("%s",s2);

    for (int i = 0; i < 19; i++)    //????? 19'u artt�r�rsak tekrdan s1'i yaz�yor ??
    {
        printf("s2[%d] = %c\n",i,s2[i]);
    }
    

    printf("s2: %s\n",s2);
    printf("\n------------------------\n");

    char s3[]="This is the way.";  // 16 indexi var

    int length=strlen(s1);  //*  #include<string.h> ile beraber gelen bir fonksiyon
    int num_is=0;

    for (int i = 0; i < length; i++)
        if(s3[i]=='h') num_is++;  //i�erideki h say�s�n� bulucak
    
    printf("length: %d\n",length);
    printf("Number of 'h' is: %d\n",num_is);


    char sent1[]="THiS IS tHE  WaY.";

    sent1[1]=tolower(sent1[1]);   //? bu k�t�phane sayesinde harfleri b�y�k ya da k���k yapabiliriz

    int length_sent1= strlen(sent1);

    for (int i = 0; i < length_sent1; i++)
    {
        printf("%c ",sent1[i]);

        if (isupper(sent1[i])) 
            printf("upper\n");

        else if (islower(sent1[i])) 
            printf("lower\n");

        else
            printf("\n\0");
        
        
    }
    




    return 0;
}