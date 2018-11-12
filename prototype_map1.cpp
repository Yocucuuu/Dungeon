#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

void Gerak(char gerak,int &posx1, int &posy1, int &posx2 , int &posy2)
{
    if(kbhit())
    {
        gerak = getch();
        if (gerak=='w')
        {
            posy1-=1;
            posy2-=1;
            //gerak w
        }
        else if (gerak=='s')
        {
            posy1+=1;
            posy2+=1;
            //gerak s
        }
        else if (gerak=='a')
        {
            posx1-=1;
            posx2-=1;
            //gerak a
        }
        else if (gerak=='d')
        {
            posx1+=1;
            posx2+=1;
            //gerak d
        }
    }
}

int main() {
    int posx1=0,posx2=11;
    int posy1=0,posy2=11;
    char gerak; //inisialisasi char untuk gerak
    string mapping[30][30]; //inisialisasi map besar
    do
    {
    for (int i=0;i<30;i++)
    {
        for (int j=0;j<30;j++)
        {
            mapping[i][j] = " ";
        }
    }
    Gerak(gerak,posx1,posy1,posx2,posy2);
    for (int i=0;i<30;i++)
    {
        for (int j=0;j<30;j++)
        {
            if ((i==posy1||i==posy2)||(j==posx1||j==posx2))
            {
                mapping[i][j] = "%";
            }
            cout << mapping[i][j];
        }
        cout << "\n";
    }
    cout << gerak << endl;
    cout <<"posisi x atas:"<< posx1 << endl;
    cout <<"posisi x bawah:"<< posx2 << endl;
    cout <<"posisi y atas:"<< posy1 << endl;
    cout <<"posisi y bawah:"<< posy2 << endl;
    //getch();
    Sleep(100);
    system("cls");
    } while (true);
}
