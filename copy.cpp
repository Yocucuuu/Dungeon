#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int x[5];
    int y[5];


    for (int i=0;i<5;i++)
    {
        x[i]=1 + rand() % 10;
        y[i]=1 + rand() % 10;
    }

    for (int i=0;i</*Map*/;i++)
    {
        for (int j=0;j</*Map*/;j++)
        {
            //Map[x[i]][y[j]] = 'M';
        }
    }

    return 0;
}
