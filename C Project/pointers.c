#include<stdio.h>

//! Pointer dediðimiz þey, bir deðiþkenin hafýza adresindeki yeridir (RAM adresi)
//! Ýþin komik kýsmý, pointer'larýn da bir adresi vardýr

int main(){

    int a=5;
    int b=10;
    int *p;  
    p=&b;   //* p=b'nin hafýza adresi (memory address)
            //* &operatörü memory address'i verir (statement'lardaki ve ile alakasý yok burada)

//?  Variables     Address       Values
//?  a(int)        55(mesela)     5
//?  b(int)        56             10
//?  p(pointer)    57             56   b'nin adresini gösterdiði için 

    printf("%d\n",*p);  //! *p ifadesi, p pointer'ýn gösterdiði bellek adresindeki deðeri alýr. 
                        //! Bu durumda, p b'nin bellek adresini gösterdiði için *p ifadesi b'nin deðerini alacaktýr. Yani, *p ifadesi 10 olacaktýr.
    
    printf("p: %d\n",p);  //! p direkt b'nin adresi olduðu için aþaðýdakiyle ayný sonucu verdi
    printf("&b: %d\n",&b);
    printf("&a: %d\n",&a);

    p=&a;
    printf("p: %d\n",p);

    *p=*p+1;  //! *p a'nýn adresi olduðu için ve o da 5 olduðundan, *p+1 a'yý 6 yaptý
    printf("a: %d\n",a);
    printf("p: %d\n",*p);

    return 0;
}