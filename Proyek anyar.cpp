#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;
int x=0;
int y=25;
int Px=5;
int Py=30;
char map_b[100][50];
int Ym[3];
int Xm[3];

int Yk[3];
int Xk[3];

int Ysave;
int Xsave;
vector<int>Ymark;
vector<int>Xmark;
vector<bool>Xflag;
struct iventory{

    int Gold=0;
    int Zen=0;
    bool key1=false;
    bool key2=false;
    bool key3=false;
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;


}player;

void SAVE(string name)
{
    ofstream save;
    save.open(name.c_str());
    if(save.is_open())
    {
        save << name;
        save << endl;
        save << player.gold;
        save << endl;
        save << x;
        save << y;
    }   
    save.close();
}

void LOAD(string name)
{
    ifstream load;
    load.open(name.c_str());
    if(load.is_open())
    {
        stringstream ss;
        int number;
        ss >> number;
    }
    else
    {
        cout << "File Tidak Ditemukan" << endl;
    }
}

void InitAwal()
{
    for (int i=0;i<100;i++){
        for(int j=0;j<50;j++)
        {
        map_b[i][j]=' ';
        }
    }
}

void BatasView()
{
     map_b[Py][Px-3]  ='|';
    map_b[Py-1][Px-3]='|';
    map_b[Py+1][Px-3]='|';
    map_b[Py+2][Px-3]='|';
    map_b[Py-2][Px-3]='|';

     map_b[Py][Px+3] ='|';
    map_b[Py-1][Px+3]='|';
    map_b[Py+1][Px+3]='|';
    map_b[Py+2][Px+3]='|';
    map_b[Py-2][Px+3]='|';

    map_b[Py-3][Px-3]='+';
    map_b[Py+3][Px+3]='+';
    map_b[Py+3][Px-3]='+';
    map_b[Py-3][Px+3]='+';

    map_b[Py+3][Px+2]='-';
    map_b[Py+3][Px+1]='-';
    map_b[Py+3][Px]='-';
    map_b[Py+3][Px-1]='-';
    map_b[Py+3][Px-2]='-';

    map_b[Py-3][Px+2]='-';
    map_b[Py-3][Px+1]='-';
    map_b[Py-3][Px]='-';
    map_b[Py-3][Px-1]='-';
    map_b[Py-3][Px-2]='-';
}

void CetakMap()
{

    for (int i=y;i<y+11;i++){
        for(int j=x;j<x+11;j++){
            cout<<map_b[i][j];
        }cout<<endl;

}

cout<<"------------"<<endl;

cout<<endl;
    cout<<" Y : "<<y<<endl;
    cout<<" Y+11 :"<< y+11<<endl;
    cout<<" X : "<<x<<endl;
    cout<<" X+11 :"<< x+11<<endl;
    cout<<" Py :" <<Py<<endl;
    cout<<" Px :" <<Px<<endl;
    cout<<endl;

    for (int i=0;i<3;i++){
        cout<<Ym[i]<<" "<<Xm[i]<<endl;
        cout<<Yk[i]<<" "<<Xk[i]<<endl;
    }

//cout<<"Gold  :"<<player.Gold<<endl;
//cout<<"Zen   :"<<player.Zen<<endl;
//cout<<"===  KEY  ==="<<endl;
//cout<<"Key1  :"<<player.key1<<endl;
//cout<<"Key2  :"<<player.key2<<endl;
//cout<<"Key3  :"<<player.key3<<endl;
//cout<<endl;
//cout<<"=== Flags ==="<<endl;
//cout<<"Flag1 :"<<player.flag1<<endl;
//cout<<"Flag2 :"<<player.flag2<<endl;
//cout<<"Flag3 :"<<player.flag3<<endl;
}
void Move(char key)
{
    if(key=='d'&& (map_b[Py][Px+1]==' '||map_b[Py][Px+1]=='+'||map_b[Py][Px+1]=='X') ){
        if(x==0&&Px<5){
            Px++;
        }else if(x+11==49&&Px<48){
            Px++;
        }else if (x+11<49) {
            Px++;
            x++;
        }

    }else if (key=='a'&&(map_b[Py][Px-1]==' '||map_b[Py][Px-1]=='+'||map_b[Py][Px-1]=='X')){

        if(x+11==49&&Px>43){
            Px--;
        }else if (x==0&&Px>0){
            Px--;
        }else if (x>0){

            Px--;
            x--;
        }

    }else if (key=='w'&&(map_b[Py-1][Px]==' '||map_b[Py-1][Px]=='+'||map_b[Py-1][Px]=='X')){
        if(y+11==74&&Py>68){
            Py--;
        }
        else if (y==25&&Py>25){
            Py--;
        }else if(y>25){
            y--;
            Py--;
        }
    }else if (key=='s'&&(map_b[Py+1][Px]==' '||map_b[Py+1][Px]=='+'||map_b[Py+1][Px]=='X')){
        if(y==25&&Py<30){
            Py++;
        }
        else if(y+11==74&&Py<73){
            Py++;
        }else if(y+11<74){
            y++;
            Py++;
        }
    }

    // Key
    if (key==' '){
        char menu;
      if (map_b[Py][Px+1]=='M'||map_b[Py][Px-1]=='M'||map_b[Py-1][Px]=='M'||map_b[Py+1][Px]=='M'){//Merchant
            cout<<"Merchant"<<endl;
            cout<<"1.Tukar Zeny"<<endl;
            cout<<"2.Exit "<<endl;
            cout<<"Pilih :";cin>>menu;
        }else if (map_b[Py][Px+1]=='K'||map_b[Py][Px-1]=='K'||map_b[Py-1][Px]=='K'||map_b[Py+1][Px]=='K'){
            cout<<"Kunci"<<endl;
            cout<<"1.Beli Kunci"<<endl;
            cout<<"2.Exit"<<endl;
            cout<<"Pilih :";cin>>menu;
        }else if (map_b[Py][Px+1]=='S'||map_b[Py][Px-1]=='S'||map_b[Py-1][Px]=='S'||map_b[Py+1][Px]=='S'){
            cout<<"Save Game....??"<<endl;
            cout<<"1.Yes"<<endl;
            cout<<"2.No"<<endl;
            cout<<"Pilih :";cin>>menu;

        }

    }



   else if (key=='x'){
        Ymark.push_back(Py);
        Xmark.push_back(Px);
        Xflag.push_back(true);





    }

}

void InitXmark()
{
    for(int i=0;i<Ymark.size();i++){
            if (Xflag[i]==true){
            map_b[Ymark[i]][Xmark[i]]='X';
            }else if (Xflag[i]==false){
            map_b[Ymark[i]][Xmark[i]]=' ';
            }

        }

        for (int i=0;i<Xflag.size();i++){
            if (Px-Xmark[i]>5||Xmark[i]-Px>5||Py-Ymark[i]>5||Ymark[i]-Py>5){
                Xflag[i]=false;
            }

        }

        for (int i=0;i<Ymark.size();i++){
        if(Xflag[i]==true){
            if (Ymark[i]==Py){   // Y ==0
                if (Xmark[i]>Px){
                    if (Xmark[i]-Px<3){
                        map_b[Ymark[i]][Xmark[i]]='X';
                    }else if (Xmark[i]-Px>3){
                        map_b[Ymark[i]][Xmark[i]]=' ';
                    }
                }else if (Xmark[i]<Px){
                    if (Px-Xmark[i]<3){
                           map_b[Ymark[i]][Xmark[i]]='X';
                    }else if (Px-Xmark[i]>3){
                         map_b[Ymark[i]][Xmark[i]]=' ';
                    }

                }

            }else if (Xmark[i]==Px){  //X==0
                if (Ymark[i]>Py){
                    if (Ymark[i]-Py<3){
                        map_b[Ymark[i]][Xmark[i]]='X';
                    }else if (Ymark[i]-Py>3){
                        map_b[Ymark[i]][Xmark[i]]=' ';
                    }
                }else if (Ymark[i]<Py ){
                    if (Py-Ymark[i]<3){
                        map_b[Ymark[i]][Xmark[i]]='X';
                    }else if (Py-Ymark[i]>3){
                        map_b[Ymark[i]][Xmark[i]]=' ';
                    }
                }

            }else if (Xmark[i]>Px&&Ymark[i]<Py){   // kuadron 1
                if (Xmark[i]-Px<4&&Py-Ymark[i]<4){
                    map_b[Ymark[i]][Xmark[i]]='X';
                }else {
                    map_b[Ymark[i]][Xmark[i]]=' ';
                }

            }else if (Xmark[i]>Px&&Ymark[i]>Py){    //kuadron 4
                if (Xmark[i]-Px<4&&Ymark[i]-Py<4){
                    map_b[Ymark[i]][Xmark[i]]='X';
                }else {
                    map_b[Ymark[i]][Xmark[i]]=' ';
                }
            }else if (Xmark[i]<Px&&Ymark[i]<Py){  // kuadron 2
                if (Px-Xmark[i]<4 && Py-Ymark[i]<4 ){
                    map_b[Ymark[i]][Xmark[i]]='X';
                }else {
                     map_b[Ymark[i]][Xmark[i]]=' ';
                }
            }else if (Xmark[i]<Px&&Ymark[i]>Py){
                if (Px-Xmark[i]<4&&Ymark[i]-Py<4){
                    map_b[Ymark[i]][Xmark[i]]='X';
                }else {
                     map_b[Ymark[i]][Xmark[i]]=' ';
                }
            }
        }
        }
}

int main()
{
srand(time(0));
cout << "Masukkan Nama : ";
cin >> name;
name = name + ".txt";
cin.ignore();
SAVE(name);
LOAD(name);
InitAwal();

for(int i=0;i<3;i++)
{
    Ym[i]=rand()%49+25;
    Xm[i]=rand()%49;
    Xk[i]=rand()%49;
    Yk[i]=rand()%49+25;
}

Ysave=rand()%50+25;
Xsave=rand()%50;


map_b[Py][Px]='P';

    while(true){

        CetakMap();

        char key=getch();
        Move(key);

        InitAwal();
        InitXmark();
        BatasView();

        for(int i=0;i<3;i++){
            map_b[Ym[i]][Xm[i]]='M';
            map_b[Yk[i]][Xk[i]]='K';
        }


        map_b[51][20]='0';
        map_b[Ysave][Xsave]='S';
        map_b[Py][Px]='P';
        system("cls");
}








































    return 0;
}
