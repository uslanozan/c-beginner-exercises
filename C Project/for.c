#include<stdio.h>

int main (){

    for (int i = 0; i < 10; i++)
        printf("i: %d\n",i);
    
    double initial =0, step=0, stop=0;

    //! hepsi girilen initial value'dan, stop value'ya kadar, step value'lara bölünmüþ bir þekilde metreyi feete çeviren program
    
    do
    {
        printf("Initial (m): ");
        scanf("%lf", &initial);
        if (initial < 0) printf("Must be >=0!\n");
        
    } while (initial < 0);
    
    do
    {
        printf("Step (m): ");
        scanf("%lf", &step);
        if (step <= 0) printf("Must be >=0!\n");
        
    } while (step <= 0);

    do
    {
        printf("Stop (m): ");
        scanf("%lf", &stop);
        if (stop < 0) printf("Must be >=0!\n");
        
    } while (stop < 0);



    printf("\n");
    printf("Meters      Feet\n");
    printf("*******************\n");
    
    for (double conv = initial; conv <= stop; conv += step)
    {
        printf("%-10.2f %-10.2f\n",conv,conv*3.28084);  //? 10. yaparak noktanýn solunda 10 basamak oldu ama sað tarafa dayalý gözüktü
    }                                                   //? - yaparak da sol tarafa dayadýk 
    printf("\n");




    return 0;
}