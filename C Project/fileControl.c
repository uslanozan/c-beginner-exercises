#include<stdio.h>
#include<stdlib.h>

#define LINE_BUFFER 100
#define NUM_BUFFER 1000



int main(int argc, char const *argv[])
{
    FILE *fh_write;

    fh_write=fopen("write.txt","w");  //? w(write) yazmak için ama silip üstüne yazar
                                      //? a(append) yine yazmak için ama sona ekleyerek yazar
    if (fh_write==NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }else{
        for (int i = 0; i < 5; i++)
        {
            fprintf(fh_write,"%d\n",(i+1));
        }
        

        //int x=100;
        //fprintf(fh_write,"Val: %d!\n",x);  //* Printf'in txt için olaný
        fclose(fh_write);  //* açtýðýmýz file'ý kapatýyoruz
    }

    FILE *fh_read;

    fh_read=fopen("write.txt","r");  //? r(read) okumak için

    if (fh_read==NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }else{
        char buffer[LINE_BUFFER];
        int data[NUM_BUFFER];
        int i=0;
        while (fgets(buffer,100,fh_read)!=NULL)  //! fgets() txt'deki her satýrý sýrayla okur
        {                                        //? ilk parametresi okunan satýrý saklanýcak buffer(array)'i belirtir
            printf("%s",buffer);                 //? ikinci parametresi LINE_BUFFER'ýn boyutuyla eþleþmesi gereken okunacak maksimum veri ???, 3. parametre txt ismi
            data[i]=atoi(buffer);   //! atoi() string'ten inte dönüþtürmek için
            i++;
        }
        
        fclose(fh_read);
        
        int numlines=i;
        int total=0;
        for (int j = 0; j < numlines; j++)
        {
            printf("data[%d]=%d\n",j,data[j]);
            total +=data[j];
        }
        printf("average: %d\n", total/numlines);

    }
    

    

    return 0;
}