#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string name;

void SAVE(string name)
{
    ofstream save;
    save.open(name.c_str());
    if(save.is_open())
    {

    }
    else
    {

    }
}

void LOAD(string name)
{
    ifstream load;
    load.open(name.c_str());
    if(load.is_open())
    {

    }
    else
    {

    }
}


int main()
{
    cout << "Masukkan Nama : ";
    cin >> name;
    name = name + ".txt";
    SAVE(name);
    LOAD(name);

    return 0;
}
