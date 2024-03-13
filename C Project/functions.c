#include<stdio.h>

                            //? burada fonksiyonu tan�ml�yoruz
int find_max(int a,int b){  //? ba�taki int,fonksiyonun d�nd�rece�i t�r� belirler
                            //? i�eridekiler de parametredir
    if (a>b) return a;
    else return b;

}

//! �ok fazla bu �ekilde fonksiyon tan�mlarsak bir s�re sonra main'in �ok a�a��da kal�r
//! Ve bu baz� sorunlara yol a�abilir. Bu y�zden fonksiyon olu�turulurken genelde 2 b�l�me ay�r�l�r
//! �st tarafa fonksiyonun tan�m�n� (Definition) yap�p, altta i�i doldurulur

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




//*Tan�m� yap�lan fonksiyonun body'si buradad�r
int find_min(int a,int b){
    if (a>b) return b;
    else return a;
}

double add(double x, double y){
    double result=x+y;  //*result local de�i�kendir ve scope d���nda kullan�lamaz ayn� d�ng�lerdeki gibi
    return result;
}

double multiplication(double x, double y){ return x*y;}

double power(double x,int n){
    double result=x;

    for (int i = 1; i < n; i++)
    {
        result=multiplication(result,x);  //! burada daha �nceki olu�turdu�umuz multiplication methodunu kulland�k
    }
    return result;
}

void print_values(float a,float b){  //! void demek herhangi bir return kullan�lmayacak, de�er d�nmeyecek
    printf("%f\n%f\n",a,b);          //! genelde printf ile falan doldurulur, methoda g�re de�i�ir
}