#include<stdio.h>
#include<locale.h>

int main(){

    int grade=0;
    
    printf("Grade: ");
    scanf("%d", &grade);  //? ald���m�z input grade'e e�it olucak ve double i�in %d
                         //? & koymazsak �al��maz
    if (grade >= 70)
    {
        printf("Pass\n");
        printf("Congratulations you get A!\n");
    }
    else if (grade>=50)
    {
        printf("It could be better you get B!\n");
    }
    
    else {
        printf("You have failed!\n");
        printf("Good luck next time!\n");
    }


    return 0;
}