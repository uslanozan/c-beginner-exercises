#include<stdio.h>
#include<stdlib.h>

#define ROWS 2   //! constant value'lar runtime sýrasýnda deðiþemez.
#define COLS 3   //? Bunun iyi yaný koddaki bir þeyi deðiþtirmek istediðimizde
                 //? her yerdeki deðiþkeni deðiþtirmek yerine burayý deðiþtiricez

void print_array(int data[ROWS][COLS]);
void input_array(int data[ROWS][COLS]);

/*----------------------------------------------------------------------------*/
int main(){

    int data[ROWS][COLS] ={{1,2,3},{4,5,6}};  //? row and column olarak düþünülebilir
    int data2[ROWS][COLS]={0};
    //! int data2[2][3] ={1,2,3,4,5,6};   Neden bilinmez ama bu da çalýþýyor. Yine de yapmak kafa karýþtýrýcý ve sakýncalý  

    printf("data[1][1]=%d\n",data[1][1]);
    printf("data2[1][1]=%d\n",data2[1][1]);
    printf("\n---------------------------------------------------------\n\n");

    input_array(data2);
    print_array(data2);
        


    return 0;
}
 /*----------------------------------------------------------------------------*/
 void print_array(int data[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS ; j++)
        {
            printf("data[%d][%d]=%d\n",i,j,data[i][j]);
        }
 }

void input_array(int data[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS ; j++)
        {
            printf("data[%d][%d]= ",i,j);
            scanf("%d",&data[i][j]);
        }
        
}


