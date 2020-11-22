#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
int row, col, space;

for(row=1;row<=7;row++)
     {
       cout<<endl;
       for(col=row;col<=7;col++)
	   { cout<<col;}
     }

for(row=6;row>=1;--row)
    {cout<<endl;
       for(col=row;col<=7;col++)
	 {cout<<col;}
    }

 getch();
}

