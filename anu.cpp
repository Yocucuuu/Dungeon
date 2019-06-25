#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

char Map[22][22];
string kata;

void PRINTMAP()
{
    for (int i=0;i<22;i++)
    {
        for (int j=0;j<22;j++)
        {
            cout << Map[i][j];
        }
        cout << "\n";
    }
}

void INIT_MAP()
{
    for (int i=0;i<22;i++)
    {
        for (int j=0;j<22;j++)
        {
            if (i==0||i==21||j==0||j==21)
                Map[i][j] = '#';
            else
                Map[i][j] = ' ';
        }
    }
}

void RANDOM_TEMPAT(int x[], int y[])
{
    for (int i=0;i<kata.size();i++)
    {
        x[i] = 1 + rand() % 19;
        y[i] = 1 + rand() % 19;
    }
}

void MINTA_KATA()
{
    cout << "KATA : ";
    cin >> kata;
    cout << endl;
}

void PECAH_KATA(int x[], int y[])
{
    for (int i=0;i<kata.size();i++)
    {
        Map[y[i]][x[i]] = kata[i];
    }
}

int main()
{
    srand(time(NULL));
    int x[100],y[100];
    INIT_MAP();
    MINTA_KATA();
    RANDOM_TEMPAT(x,y);
    PECAH_KATA(x,y);
    PRINTMAP();

    return 0;
}
