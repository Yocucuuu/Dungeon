#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int map_x=50;
const int map_y=50;

char Map_B[map_y][map_x];

int player_x, player_y;

int merchan_gold_x[3],merchant_gold_y[3];

int merchan_key_x[3],merchant_key_y[3];

int flag_x[3],flag_y[3];


struct Inventory
{
    int Gold=0;
    int Zen=0;
    bool key1=false;
    bool key2=false;
    bool key3=false;
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;
};
//void debug_map()
//{
//    for (int i=0;i<map_y;i++)
//    {
//        for (int j=0;j<map_x;j++)
//        {
//            cout << Map_B[i][j];
//        }
//        cout<< "\n";
//    }
//}

void SAVE(string name)
{
    ofstream save;
    save.open(name.c_str());
    if(save.is_open())
    {

    }
    save.close();
}

void LOAD(string name)
{
    ifstream load;
    load.open(name.c_str());
    if(load.is_open())
    {

    }
    load.close();
}

int main()
{
    char menu_awal;
    do
    {
    cout << "1. New Game";
    cout << endl;
    cout << "2. Load Game";
    cout << endl;
    cin >> menu_awal;
    }while(menu_awal!='1'&&menu_awal!='2');

    string name;

    if (menu_awal=='1')    // INI NEW GAME
    {
        cout << "Masukkan Nama : ";
        cin >> name;
        name = name + ".txt";
        SAVE(name);
    }

    else if (menu_awal=='2') // INI LOAD GAME
    {
        cout << "Masukkan Nama : ";
        cin >> name;
        name = name + ".txt";
        LOAD(name);
    }

    Inventory player;

    while (player.flag1==0&&player.flag2==0&&player.flag3==0)
    {
        //ISI DENGAN GAME
    }


    return 0;
}
