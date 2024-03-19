#include <stdio.h>
#include <conio.h>
#include<windows.h>
#include<time.h>
//----------------------------------------------------------------------------------------------------------------------
char font[11][8]={  {127,65,65,65,65,65,65,127},//0
  				    {8,24,40,72,8,8,8,127},//1
  					{28,34,66,4,8,16,32,127},//2
  					{124,2,1,2,126,1,2,124},//3
  					{1,2,4,8,17,33,127,1},//4
  					{127,64,64,64,126,1,2,124},//5
  					{31,32,64,94,65,65,33,30},//6
  					{127,1,2,4,62,16,32,64},//7
  					{62,65,65,65,62,65,65,62},//8
  					{62,65,65,65,63,1,1,63},//9
  					{0,24,24,0,0,24,24,0} };//:
//----------------------------------------------------------------------------------------------------------------------
void saatYaz(void)
{
struct tm zaman;
time_t simdi;
char simdi_saat[10];
int i;
simdi = time(0);
zaman = *localtime(&simdi);
strftime(simdi_saat, sizeof(simdi_saat), "%H:%M:%S", &zaman);

ekranGitXY(50,13);

for (i=0;i<8;i++)
    printf("%c",simdi_saat[i]);

}
//----------------------------------------------------------------------------------------------------------------------
void cursoruGizle(void)
{
HANDLE hConsoleOutput;
CONSOLE_CURSOR_INFO ConsoleCursorInfo;
hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);

GetConsoleCursorInfo(hConsoleOutput,&ConsoleCursorInfo);
ConsoleCursorInfo.bVisible=0;
SetConsoleCursorInfo(hConsoleOutput,&ConsoleCursorInfo);
}
//----------------------------------------------------------------------------------------------------------------------
void ekranGitXY(int x,int y)
{
COORD pos ;
pos.X = x ;
pos.Y = y ;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//----------------------------------------------------------------------------------------------------------------------
int main()
{
cursoruGizle();
while (!kbhit())
	  {
	  saatYaz();
	  Sleep(1000);
	  }
return 0;
}
//----------------------------------------------------------------------------------------------------------------------