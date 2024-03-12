#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Turkish");

    int height=0;
    
    printf("height: ");
    scanf("%d",&height);

    int weight=0;
    printf("weight: ");
    scanf("%d", &weight);

    //*  || or    &&  and

    if (height > 150 || weight > 50) printf("Good to ride!\n");
    else printf("Not good to ride!\n");
    
}
