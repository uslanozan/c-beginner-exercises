#include<stdio.h>

//! Pointer dedi�imiz �ey, bir de�i�kenin haf�za adresindeki yeridir (RAM adresi)
//! ��in komik k�sm�, pointer'lar�n da bir adresi vard�r

int main(){

    int a=5;
    int b=10;
    int *p;  
    p=&b;   //* p=b'nin haf�za adresi (memory address)
            //* &operat�r� memory address'i verir (statement'lardaki ve ile alakas� yok burada)

//?  Variables     Address       Values
//?  a(int)        55(mesela)     5
//?  b(int)        56             10
//?  p(pointer)    57             56   b'nin adresini g�sterdi�i i�in 

    printf("%d\n",*p);  //! *p ifadesi, p pointer'�n g�sterdi�i bellek adresindeki de�eri al�r. 
                        //! Bu durumda, p b'nin bellek adresini g�sterdi�i i�in *p ifadesi b'nin de�erini alacakt�r. Yani, *p ifadesi 10 olacakt�r.
    
    printf("p: %d\n",p);  //! p direkt b'nin adresi oldu�u i�in a�a��dakiyle ayn� sonucu verdi
    printf("&b: %d\n",&b);
    printf("&a: %d\n",&a);

    p=&a;
    printf("p: %d\n",p);

    *p=*p+1;  //! *p a'n�n adresi oldu�u i�in ve o da 5 oldu�undan, *p+1 a'y� 6 yapt�
    printf("a: %d\n",a);
    printf("p: %d\n",*p);

    return 0;
}