#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool pindah = 0;

const int map_x = 11;
const int map_y = 11;

const int map_B_x = 50;
const int map_B_y = 50;

char Map[map_y][map_x];
char Map_B[map_B_y][map_B_x];

void initmap(int &y,int &x)
{
    int a=0,b=0;
    if (x==11||x==1||y==1||y==11)
    {
        a += y;
        b += x;
    }
    for (int i=0;i<map_y;i++)
    {
        for (int j=0;j<map_x;j++)
        {
            if (x==9)
            {
                Map[i][j] = Map_B[i][11+j];
            }
            else
            {
                Map[i][j] = Map_B[i][j];
            }
        }
    }
}

void printmap()
{
    for (int i=0;i<map_y;i++)
    {
        for (int j=0;j<map_x;j++)
        {
            cout << Map[i][j];
        }
        cout << "\n";
    }
}

void cek(int &y,int &x)
{
    char c;
    if (kbhit())
    {
        c = getch();
        if (c=='w'/*&&y!=0*/)
        {
            y -= 1;
            if (y==-1)
            {
                y=5;
            }
        }
        else if (c=='s'/*&&y!=10*/)
        {
            y += 1;
            if (y==11)
            {
                y=5;
            }
        }
        else if (c=='a'/*&&x!=0*/)
        {
            x -= 1;
            if (x==-1)
            {
                x=5;
            }
        }
        else if (c=='d'/*&&x!=10*/)
        {
            x += 1;
            if (x==11)
            {
                x=5;
            }
        }
    }
}

int main()
{
    int px=5,py=5;
    for(int i=0;i<50;i++)
    {
        for (int j=0;j<40;j++)
        {
            Map_B[i][j] = ' ';
        }
    }
    Map_B[0][0] = '+';

    do
    {
        initmap(py,px);
        Map[py][px] = '+';
        cek(py,px);
        printmap();
        system("cls");
    } while (true);

    return 0;
}
