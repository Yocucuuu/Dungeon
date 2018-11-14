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
        cout << "File Tidak Ditemukan Mau buat File baru ?" << endl;
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
        cout << "File Tidak Ditemukan Mau buat File baru ?" << endl;
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
