#include<stdio.h>

                            //? burada fonksiyonu tanýmlýyoruz
int find_max(int a,int b){  //? baþtaki int,fonksiyonun döndüreceði türü belirler
                            //? içeridekiler de parametredir
    if (a>b) return a;
    else return b;

}

//! Çok fazla bu þekilde fonksiyon tanýmlarsak bir süre sonra main'in çok aþaðýda kalýr
//! Ve bu bazý sorunlara yol açabilir. Bu yüzden fonksiyon oluþturulurken genelde 2 bölüme ayýrýlýr
//! Üst tarafa fonksiyonun tanýmýný (Definition) yapýp, altta içi doldurulur

int find_min(int a,int b);
double add(double x,double y);
double power(double x,int n);
double multiplication(double x, double y);
void print_values(float a,float b);


int main(){

    int max=find_max(10,5);
    printf("Max is:%d\n",max);

    int min=find_min(20,3);
    printf("Min is:%d\n",min);

    printf("%.2f\n",add(10.5,4.3));
    printf("%.2f\n",power(2.2,3));
    

    return 0;
}




//*Tanýmý yapýlan fonksiyonun body'si buradadýr
int find_min(int a,int b){
    if (a>b) return b;
    else return a;
}

double add(double x, double y){
    double result=x+y;  //*result local deðiþkendir ve scope dýþýnda kullanýlamaz ayný döngülerdeki gibi
    return result;
}

double multiplication(double x, double y){ return x*y;}

double power(double x,int n){
    double result=x;

    for (int i = 1; i < n; i++)
    {
        result=multiplication(result,x);  //! burada daha önceki oluþturduðumuz multiplication methodunu kullandýk
    }
    return result;
}

void print_values(float a,float b){  //! void demek herhangi bir return kullanýlmayacak, deðer dönmeyecek
    printf("%f\n%f\n",a,b);          //! genelde printf ile falan doldurulur, methoda göre deðiþir
}