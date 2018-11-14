#include <iostream>
#include <fstream>
using namespace std;

const int FMAP_x = 11;
const int FMAP_y = 11;
char map_b[50][50];
char map_k[FMAP_y][FMAP_x];
//save file lebih dari satu
//setiap save file berisi 1 orang saja

void LOAD(/*code disini*/)
{
    ifstream data_load;
    data_load.open("save.txt");
    if (data_load.is_open())
    {
        //code disini
        data_load.close();
    }
    else
    {
        //code disini
    }
}

void SAVE()
{
    ofstream data_save;
    data_save.open("save.txt");
    if (data_save.is_open())
    {
        //code disini
    }
    else
    {
        //code disini
    }
}
void MAIN_MENU()
{
    int pilihan;
    do
    {
        cout << "1. New Game";
        cout << "2. Load Game";
        cin >> pilihan;

    } while (pilihan != 2);
}

int main()
{
    MAIN_MENU();


    int i,j;

    for (i=0;i<FMAP_y;i++)
    {
        for (j=0;j<FMAP_x;j++)
        {
            if (i==0||i==FMAP_y-1||j==0||j==FMAP_x-1)
            {
                map_k[i][j]='*';
            }
            else

            {
                map_k[i][j]=' ';
            }
        }
    }


    for(i=0;i<FMAP_y;i++){
        for(j=0;j<FMAP_x;j++){
            cout<<map_k[i][j];
        }cout<<endl;
    }



    return 0;
}
