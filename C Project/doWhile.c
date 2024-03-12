#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL,"Turkish");

    //?  Do-While loop döngüyü en az 1 kere çalýþtýrmayý garanti eder

    int i=25;

    do
    {
        printf("i: %d\n",i);
        i++;
    } while (i<5);  //! ; koyulur
                    //!  25 do yüzünden yazýldý ama sonra while þartý saðlanmadýðý için döngü devam etmedi


    int number=0;
    do
    {
        printf("Enter number (>0): ");
        scanf("%d",&number);
        if (number <=0)
            printf("Number must be greater than 0!\n");
    } while (number <= 0);
    

    return 0;
}