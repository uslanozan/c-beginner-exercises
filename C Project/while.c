#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Turkish");

    int i=0;
    int number=0;
    float total=0;
    int total_number=0;


    printf("How many numbers: ");
    scanf("%d",&total_number);

    while (i<total_number)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&number);
        total=total+number;
        i++;
    }
    
    printf("total: %f\n",total );                   //!  float/int  float yapar
    printf("average: %.2f\n",total/total_number );  //!  %a.bf  var ise a noktan�n solundaki ka� basamak g�sterilsin demek
                                                    //!                 b ise noktan�n sa��ndan ka� basamak g�sterilsin demek

    /*
    while (i<5)
    {
        printf("i: %d\n",i);
        i=i+1;
        //? i++;
        //? i+=1;  hepsi ayn�. 1 yerine farkl� bir �ey konulabilir
    }*/

    printf("--------------------------------------\n");

    int number2 = 0;
    int max = -1;


    //!!!! Infinite loop, bug var string girince 
    while (number2 != -1)
    {
        printf("Enter a number and enter -1 to quit");
        scanf("%d",&number2);
        if (number2 > max)
            max =number2;
        printf("max: %d\n",max);
    }
    printf("max: %d\n",max);
    


    return 0;
}
