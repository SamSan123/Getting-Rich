/*  Computer Science Project
	 GETTING RICH!
      By:
      Sanyam Agrawal    XI G
      Pranshu Malik     XI G
      Aparimit Chandra  XI G
*/

//Including the header files
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<constrea.h>

//Declaring global variables
int y,a,b,point,x,lives,i,j,v;
char c;
char w[]="Welcome! This is GETTING RICH!";
char g[]="GAME OVER!";
char e[]="[Getting Rich]";

//Function to welcome user and display rules
void info()
{
 constream cout;
 cout<<setclr(14);

 gotoxy(13,12);
 int l=strlen(w);
 for(int k=0;k<l;k++)
  {
   cout<<w[k];
   delay(50);
  }
  delay(400);
  gotoxy(13,12);
  for(k=0;k<l;k++)
   cout<<" ";

  gotoxy(52,13);
  cout<<"The rules are as follows:";
  gotoxy(52,15);
  cout<<"You have to move the bar ";
  gotoxy(52,16);
  cout<<"with the arrow keys.";
  gotoxy(52,17);
  cout<<"Collect as much money as ";
  gotoxy(52,18);
  cout<<"you can. You have 3 lives.";
  delay(3000);

  textcolor(12);
  gotoxy(24,11);
  cout<<"3";
  delay(800);
  gotoxy(24,11);
  cout<<"2";
  delay(800);
  gotoxy(24,11);
  cout<<"1";
  delay(800);
  gotoxy(24,11);
  cout<<" ";
 }

//Function to form the gameplay box
void box()
{
 constream cout;
 textcolor(9);
 gotoxy(0,0);
 cprintf("É");
 for(i=1;i<49;i++)
 {
  gotoxy(i,0);
  cprintf("Í");
  delay(10);
 }
 cprintf("»");

 for(j=2;j<22;j++)
 {
  gotoxy(50,j);
  cprintf("º");
  delay(20);
 }
 gotoxy(50,22);
 cprintf("¼");

 for(i=49;i>=2;i--)
 {
  gotoxy(i,22);
  cprintf("Í");
  delay(10);
 }
 gotoxy(1,22);
 cprintf("È");

 for(j=21;j>1;j--)
 {
  gotoxy(1,j);
  cprintf("º");
  delay(20);
 }
 cout<<setclr(10);
 gotoxy(19,1);
 for(int p=0;p<strlen(e);p++)
 {
  cout<<e[p];
  delay(30);
 }
}

//Function to display and move the money-collecting bar
void bar()
{
 if(kbhit())
  {
   c=getch();
   if(c==(char)77)
    {
     a+=4;
     gotoxy(a-4,b);
     cout<<"    ";
    }
   else if(c==(char)75)
    {
     a-=4;
     gotoxy(a+9,b);
     cout<<"    ";
    }

   if(a<=1)
    {
     gotoxy(1,20);
     cout<<(char)186;
     a=2;
    }
   if(a>41)
    {
     gotoxy(50,20);
     cout<<(char)186;
     a=41;
    }
 gotoxy(a,b);
 cprintf("_________");
  }
}

//Function to drop the money from random positions
//Also to check and display game statistics
void drop()
{
 constream cout;
 randomize();
 int d=120;
 while(lives>0)
 {
  v=random(15)+1;
  cout<<setclr(v);
  x=random(50);
  if(x<2)
   x=2;

  gotoxy(52,8);
  cout<<"Your Money :";
  gotoxy(52,10);
  cout<<point<<" $";

  gotoxy(52,4);
  cout<<"Lives remaining";
  gotoxy(52,6);
  cout<<lives;

  y=3;
  while(y<=21)
  {
   gotoxy(x,y);
   cprintf("$");
   gotoxy(x,y-1);
   cout<<" ";
   delay(d);
   bar();
   if(y==20)
   {
    if(x==a||x==a+1||x==a+2||x==a+3||x==a+4||x==a+5||x==a+6||x==a+7||x==a+8)
      {
       point+=100;
       y+=100;
       gotoxy(x,20);
       cout<<"_";
      }
    else
      lives--;
   }
   y++;
  }

    d-=10;
    if(d<55)
     d=55;
    if(lives==0)
     {
      gotoxy(52,6);
      cout<<lives;
      textcolor(11+BLINK);
      gotoxy(21,12);
      for(int l=0;l<strlen(g);l++)
       {
	cout<<g[l];
	delay(100);
       }
      delay(300);
      gotoxy(19,14);
      textcolor(11);
      cout<<"Your money: "<<point<<" $";
      delay(1000);
     }
  }
 }



//Main Function
 void main()
 {
  clrscr();
  //Intialising the variables
  a=21,b=20,point=0,lives=3;
  box();
  info();
  gotoxy(21,20);
  cout<<"_________";
  drop();
  getch();
  }
