#include<windows.h>
#include<iostream>
#include<conio.h>

#define BARS 26
using namespace std;
int BAR_HEIGHTS[BARS]={};
char* BAR="||";

void Gotoxy(int x, int y)
{
    COORD c;
    c.X=x; c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void PrintBase(int y)
{
    for(int i=1; i<79; i++)
    {
        Gotoxy(i, y);   cout<<"=";
        Gotoxy(i, y+1); cout<<"=";
    }
    Gotoxy(33, 23);
    cout<<"MUSICAL BARS";
}

void RandomizeBarHeights(int A[], int n, int m)
{
    int t=0;
    {
        srand(GetTickCount());
        for(int i=0; i<n; i++)
        {
            t=rand()%m+1;
            if(t>A[i])
                A[i]=t;
            else
                A[i]--;
        }
    }
}

void PrintBars(int A[], int n, int b)
{
    int bx=40-(n/2)*3, ex=40+(n/2)*3+4, i=0;
    for(int x=bx; x<=ex; x+=3)
    {
        for(int y=b; y>b-A[i]; y--)
        {
            Gotoxy(x, y);
            cout<<BAR;
        }
        ++i;
    }
}
void ClearView(int x1, int y1, int x2, int y2)
{
    for(int y=y1; y<=y2; y++)
    {
        for(int x=x1; x<=x2; x++)
        {
            Gotoxy(x, y);
            cout<<" ";
        }
    }
}
int main()
{
    PrintBase(20);
    while(!kbhit())
    {
        ClearView(0, 0, 79, 19);
        RandomizeBarHeights(BAR_HEIGHTS, BARS, 15);
        PrintBars(BAR_HEIGHTS, BARS, 19);
        Sleep(1);
    }
}
