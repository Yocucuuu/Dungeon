#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;

int x;
int y;
int Px;
int Py;
char map_b[100][50];
int Ym[3];
int Xm[3];
int Ysave;
int Xsave;
int Yk[3];
int Xk[3];

int Ybendera[3];
int Xbendera[3];
int YBatasFlag[3][8];
int XBatasFlag[3][8];



char Flag[3];
char Key[3];

bool FlagCek[3];
bool KeyCek[3];


int Xgold[10];
int Ygold[10];
bool CEKgold[10];

vector<int>Ymark;
vector<int>Xmark;
vector<bool>Xflag;
struct inventory{

    int Gold=0;
    int Zen=0;
    bool key1=false;
    bool key2=false;
    bool key3=false;
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;


};
inventory player;
void InitPosisiAwal(){
 x=rand()%44;
y=rand()%44+25;
 Px=x+5;
 Py=y+5;

}



void InitBatasFlag()
{
    for (int i=0;i<3;i++){
        YBatasFlag[i][0]=Ybendera[i];
        YBatasFlag[i][1]=Ybendera[i];
        YBatasFlag[i][2]=Ybendera[i]+1;
        YBatasFlag[i][3]=Ybendera[i]+1;
        YBatasFlag[i][4]=Ybendera[i]+1;
        YBatasFlag[i][5]=Ybendera[i]-1;
        YBatasFlag[i][6]=Ybendera[i]-1;
        YBatasFlag[i][7]=Ybendera[i]-1;

        XBatasFlag[i][0]=Xbendera[i]-1;
        XBatasFlag[i][1]=Xbendera[i]+1;
        XBatasFlag[i][2]=Xbendera[i];
        XBatasFlag[i][3]=Xbendera[i]+1;
        XBatasFlag[i][4]=Xbendera[i]-1;
        XBatasFlag[i][5]=Xbendera[i];
        XBatasFlag[i][6]=Xbendera[i]+1;
        XBatasFlag[i][7]=Xbendera[i]-1;

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
void CetakMap(string nama)
{

    for (int i=y;i<y+11;i++){
        for(int j=x;j<x+11;j++){
            cout<<map_b[i][j];
        }cout<<endl;

}
cout<<Py<<" "<<Px<<endl;
cout<<"Player Name :"<<nama<<endl;
cout<<"Gold : "<<player.Gold<<endl;
cout<<"Zen  : "<<player.Zen<<endl;
cout<<"===  KEY  ==="<<endl;
cout<<"Key1  :"<<player.key1<<endl;
cout<<"Key2  :"<<player.key2<<endl;
cout<<"Key3  :"<<player.key3<<endl;
cout<<endl;
cout<<"=== Flags ==="<<endl;
cout<<"Flag1 :"<<player.flag1<<endl;
cout<<"Flag2 :"<<player.flag2<<endl;
cout<<"Flag3 :"<<player.flag3<<endl;
}
void Move(char key,string nama)
{
    if(key=='d'&& (map_b[Py][Px+1]==' '||map_b[Py][Px+1]=='*'||map_b[Py][Px+1]=='X') ){
        if(x==0&&Px<5){
            Px++;
        }else if(x+11==49&&Px<48){
            Px++;
        }else if (x+11<49) {
            Px++;
            x++;
        }

    }else if (key=='a'&&(map_b[Py][Px-1]==' '||map_b[Py][Px-1]=='*'||map_b[Py][Px-1]=='X')){

        if(x+11==49&&Px>43){
            Px--;
        }else if (x==0&&Px>0){
            Px--;
        }else if (x>0){

            Px--;
            x--;
        }

    }else if (key=='w'&&(map_b[Py-1][Px]==' '||map_b[Py-1][Px]=='*'||map_b[Py-1][Px]=='X')){
        if(y+11==74&&Py>68){
            Py--;
        }
        else if (y==25&&Py>25){
            Py--;
        }else if(y>25){
            y--;
            Py--;
        }
    }else if (key=='s'&&(map_b[Py+1][Px]==' '||map_b[Py+1][Px]=='*'||map_b[Py+1][Px]=='X')){
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
        if (map_b[Py][Px+1]=='M'||map_b[Py][Px-1]=='M'||map_b[Py+1][Px]=='M'||map_b[Py-1][Px]=='M'){

            cout<<"Mau tukar semua gold ke zeny ??"<<endl;
            cout<<"1. Yes"<<endl;
            cout<<"2. next time"<<endl;
            cout<<"Select :";cin>>menu;
                if(menu=='1'){
                    if (player.Gold!=0){
                    player.Zen+=player.Gold*50;
                    player.Gold=0;
                    }else if(player.Gold==0){
                        cout<<"ups nggak punya gold"<<endl;
                        Sleep(500);
                    }
                }


        }else if (map_b[Py][Px+1]=='S'||map_b[Py][Px-1]=='S'||map_b[Py+1][Px]=='S'||map_b[Py-1][Px]=='S'){
            ofstream New (nama.c_str());

    if (New.is_open()){

        New<<y<<endl;
        New<<x<<endl;
        New<<Py<<endl;
        New<<Px<<endl;
        New<<Ysave<<endl;
        New<<Xsave<<endl;
        New<<player.Gold<<endl;
        New<<player.Zen<<endl;
        New<<player.key1<<endl;
        New<<player.key2<<endl;
        New<<player.key3<<endl;
        New<<player.flag1<<endl;
        New<<player.flag2<<endl;
        New<<player.flag3<<endl;
        for (int i=0;i<3;i++){
            New<<Ym[i]<<endl;
        }
        for (int i=0;i<3;i++){
            New<<Xm[i]<<endl;
        }


        for (int i=0;i<3;i++){
            New<<Yk[i]<<endl;
        }

        for (int i=0;i<3;i++){
            New<<Xk[i]<<endl;
        }

        for (int i=0;i<3;i++){
            New<<Ybendera[i]<<endl;
        }

        for (int i=0;i<3;i++){
            New<<Xbendera[i]<<endl;
        }



    }
    cout<<"Save Berhasil"<<endl;
    Sleep(500);
    New.close();

        }else if (map_b[Py][Px+1]=='K'||map_b[Py][Px-1]=='K'||map_b[Py+1][Px]=='K'||map_b[Py-1][Px]=='K'){
            if ( (Px+1==Xk[0]||Px-1==Xk[0]||Py+1==Yk[0]||Py-1==Yk[0])&&player.key1==false ){
                cout<<"Mau beli  kunci 1?? (300Zen)"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. Nah"<<endl;
                cout<<"Select :";cin>>menu;

                    if (menu=='1'&&player.Zen>=300){
                        player.key1=true;
                        player.Zen-=300;
                    }else if(player.Zen<300&&menu=='1'){
                        cout<<"Zeny Kurang"<<endl;
                        Sleep(1000);
                    }

            }else if ( (Px+1==Xk[1]||Px-1==Xk[1]||Py+1==Yk[1]||Py-1==Yk[1])&&player.key2==false ){
                cout<<"Mau beli  kunci 2?? (500Zen)"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. Nah"<<endl;
                cout<<"Select :";cin>>menu;

                    if (menu=='1'&&player.Zen>=500){
                        player.key2=true;
                        player.Zen-=500;
                    }else if(player.Zen<500&&menu=='1'){
                        cout<<"Zeny Kurang"<<endl;
                        Sleep(1000);
                    }

            }else if ( (Px+1==Xk[2]||Px-1==Xk[2]||Py+1==Yk[2]||Py-1==Yk[2])&&player.key3==false ){
                cout<<"Mau beli  kunci 3?? (800Zen)"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. Nah"<<endl;
                cout<<"Select :";cin>>menu;

                    if (menu=='1'&&player.Zen>=800){
                        player.key3=true;
                        player.Zen-=800;
                    }else if(player.Zen<800&&menu=='1'){
                        cout<<"Zeny Kurang"<<endl;
                        Sleep(1000);
                    }

            }

        }else if (map_b[Py][Px+1]=='1'||map_b[Py][Px-1]=='1'||map_b[Py+1][Px]=='1'||map_b[Py-1][Px]=='1'){
            player.flag1=true;
            cout<<"Flag 1 Claimedd"<<endl;
            Sleep(1000);

        }else if (map_b[Py][Px+1]=='2'||map_b[Py][Px-1]=='2'||map_b[Py+1][Px]=='2'||map_b[Py-1][Px]=='2'){
            player.flag2=true;
            cout<<"Flag 2 Claimedd"<<endl;
            Sleep(1000);
        }else if (map_b[Py][Px+1]=='3'||map_b[Py][Px-1]=='3'||map_b[Py+1][Px]=='3'||map_b[Py-1][Px]=='3'){
            player.flag3=true;
            cout<<"Flag 3 Claimedd"<<endl;
            Sleep(1000);
        }







}else if (key=='x'){



        Ymark.push_back(Py);
        Xmark.push_back(Px);
        Xflag.push_back(true);
        for (int i=0;i<10;i++){
            if (Ygold[i]==Py&&Xgold[i]==Px&&CEKgold[i]==false){
                player.Gold+=10;
                CEKgold[i]=true;
            }

        }






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
void ViewBendera()
{
    for (int i=0;i<3;i++){
            if (i==0&&player.key1==false){
            for(int j=0;j<8;j++){

        if (YBatasFlag[i][j]==Py){   // Y ==0
                if (XBatasFlag[i][j]>Px){
                    if (XBatasFlag[i][j]-Px<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (XBatasFlag[i][j]-Px>4){
                        map_b[YBatasFlag[i][j] ][XBatasFlag[i][j] ]=' ';
                    }
                }else if (XBatasFlag[i][j]<Px){
                    if (Px-XBatasFlag[i][j]<4){
                           map_b[YBatasFlag[i][j] ][XBatasFlag[i][j]]='@';
                    }else if (Px-XBatasFlag[i][j]>4){
                         map_b[YBatasFlag[i][j] ][XBatasFlag[i][j] ]=' ';
                    }

                }

            }else if (XBatasFlag[i][j]==Px){  //X==0
                if (YBatasFlag[i][j]>Py){
                    if (YBatasFlag[i][j]-Py<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (YBatasFlag[i][j]-Py>4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                    }
                }else if (YBatasFlag[i][j]<Py ){
                    if (Py-YBatasFlag[i][j]<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (Py-YBatasFlag[i][j]>4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                    }
                }

            }else if (XBatasFlag[i][j]>Px&&YBatasFlag[i][j]<Py){   // kuadron 1
                if (XBatasFlag[i][j]-Px<4&&Py-YBatasFlag[i][j]<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }

            }else if (XBatasFlag[i][j]>Px&&YBatasFlag[i][j]>Py){    //kuadron 4
                if (XBatasFlag[i][j]-Px<4&&YBatasFlag[i][j]-Py<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }else if (XBatasFlag[i][j]<Px&&YBatasFlag[i][j]<Py){  // kuadron 2
                if (Px-XBatasFlag[i][j]<4 && Py-YBatasFlag[i][j]<4 ){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                     map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }else if (XBatasFlag[i][j]<Px&&YBatasFlag[i][j]>Py){
                if (Px-XBatasFlag[i][j]<4&&YBatasFlag[i][j]-Py<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                     map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }
        }//
        }else if (player.key1==true){
            for (int j=0;j<8;j++){
                map_b[YBatasFlag[0][j]][XBatasFlag[0][j]]=' ';
            }

        }



        if (i==1&&player.key2==false){
            for(int j=0;j<8;j++){

        if (YBatasFlag[i][j]==Py){   // Y ==0
                if (XBatasFlag[i][j]>Px){
                    if (XBatasFlag[i][j]-Px<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (XBatasFlag[i][j]-Px>4){
                        map_b[YBatasFlag[i][j] ][XBatasFlag[i][j] ]=' ';
                    }
                }else if (XBatasFlag[i][j]<Px){
                    if (Px-XBatasFlag[i][j]<4){
                           map_b[YBatasFlag[i][j] ][XBatasFlag[i][j]]='@';
                    }else if (Px-XBatasFlag[i][j]>4){
                         map_b[YBatasFlag[i][j] ][XBatasFlag[i][j] ]=' ';
                    }

                }

            }else if (XBatasFlag[i][j]==Px){  //X==0
                if (YBatasFlag[i][j]>Py){
                    if (YBatasFlag[i][j]-Py<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (YBatasFlag[i][j]-Py>4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                    }
                }else if (YBatasFlag[i][j]<Py ){
                    if (Py-YBatasFlag[i][j]<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (Py-YBatasFlag[i][j]>4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                    }
                }

            }else if (XBatasFlag[i][j]>Px&&YBatasFlag[i][j]<Py){   // kuadron 1
                if (XBatasFlag[i][j]-Px<4&&Py-YBatasFlag[i][j]<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }

            }else if (XBatasFlag[i][j]>Px&&YBatasFlag[i][j]>Py){    //kuadron 4
                if (XBatasFlag[i][j]-Px<4&&YBatasFlag[i][j]-Py<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }else if (XBatasFlag[i][j]<Px&&YBatasFlag[i][j]<Py){  // kuadron 2
                if (Px-XBatasFlag[i][j]<4 && Py-YBatasFlag[i][j]<4 ){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                     map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }else if (XBatasFlag[i][j]<Px&&YBatasFlag[i][j]>Py){
                if (Px-XBatasFlag[i][j]<4&&YBatasFlag[i][j]-Py<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                     map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }
        }//
        }else if (player.key2==true){
            for (int j=0;j<8;j++){
                map_b[YBatasFlag[1][j]][XBatasFlag[1][j]]=' ';
            }

        }


        if (i==2&&player.key3==false){
            for(int j=0;j<8;j++){

        if (YBatasFlag[i][j]==Py){   // Y ==0
                if (XBatasFlag[i][j]>Px){
                    if (XBatasFlag[i][j]-Px<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (XBatasFlag[i][j]-Px>4){
                        map_b[YBatasFlag[i][j] ][XBatasFlag[i][j] ]=' ';
                    }
                }else if (XBatasFlag[i][j]<Px){
                    if (Px-XBatasFlag[i][j]<4){
                           map_b[YBatasFlag[i][j] ][XBatasFlag[i][j]]='@';
                    }else if (Px-XBatasFlag[i][j]>4){
                         map_b[YBatasFlag[i][j] ][XBatasFlag[i][j] ]=' ';
                    }

                }

            }else if (XBatasFlag[i][j]==Px){  //X==0
                if (YBatasFlag[i][j]>Py){
                    if (YBatasFlag[i][j]-Py<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (YBatasFlag[i][j]-Py>4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                    }
                }else if (YBatasFlag[i][j]<Py ){
                    if (Py-YBatasFlag[i][j]<4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                    }else if (Py-YBatasFlag[i][j]>4){
                        map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                    }
                }

            }else if (XBatasFlag[i][j]>Px&&YBatasFlag[i][j]<Py){   // kuadron 1
                if (XBatasFlag[i][j]-Px<4&&Py-YBatasFlag[i][j]<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }

            }else if (XBatasFlag[i][j]>Px&&YBatasFlag[i][j]>Py){    //kuadron 4
                if (XBatasFlag[i][j]-Px<4&&YBatasFlag[i][j]-Py<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }else if (XBatasFlag[i][j]<Px&&YBatasFlag[i][j]<Py){  // kuadron 2
                if (Px-XBatasFlag[i][j]<4 && Py-YBatasFlag[i][j]<4 ){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                     map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }else if (XBatasFlag[i][j]<Px&&YBatasFlag[i][j]>Py){
                if (Px-XBatasFlag[i][j]<4&&YBatasFlag[i][j]-Py<4){
                    map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]='@';
                }else {
                     map_b[YBatasFlag[i][j]][XBatasFlag[i][j]]=' ';
                }
            }
        }//
        }else if (player.key3==true){
            for (int j=0;j<8;j++){
                map_b[YBatasFlag[2][j]][XBatasFlag[2][j]]=' ';
            }

        }



















    }
}
void Viewrange()
{
    if (player.flag1==true){
        Flag[0]=' ';
    }
    if (player.flag2==true){
        Flag[1]=' ';
    }

    if (player.flag3==true){
        Flag[2]=' ';

    }


    for (int i=0;i<3;i++){

            if (Ybendera[i]==Py){   // Y ==0
                if (Xbendera[i]>Px){
                    if (Xbendera[i]-Px<4){
                        map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                    }else if (Xbendera[i]-Px>4){
                        map_b[Ybendera[i]][Xbendera[i]]=' ';
                    }
                }else if (Xbendera[i]<Px){
                    if (Px-Xbendera[i]<4){
                           map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                    }else if (Px-Xbendera[i]>4){
                         map_b[Ybendera[i]][Xbendera[i]]=' ';
                    }

                }

            }else if (Xbendera[i]==Px){  //X==0
                if (Ybendera[i]>Py){
                    if (Ybendera[i]-Py<4){
                        map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                    }else if (Ybendera[i]-Py>4){
                        map_b[Ybendera[i]][Xbendera[i]]=' ';
                    }
                }else if (Ybendera[i]<Py ){
                    if (Py-Ybendera[i]<4){
                        map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                    }else if (Py-Ybendera[i]>4){
                        map_b[Ybendera[i]][Xbendera[i]]=' ';
                    }
                }

            }else if (Xbendera[i]>Px&&Ybendera[i]<Py){   // kuadron 1
                if (Xbendera[i]-Px<4&&Py-Ybendera[i]<4){
                    map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                }else {
                    map_b[Ybendera[i]][Xbendera[i]]=' ';
                }

            }else if (Xbendera[i]>Px&&Ybendera[i]>Py){    //kuadron 4
                if (Xbendera[i]-Px<4&&Ybendera[i]-Py<4){
                    map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                }else {
                    map_b[Ybendera[i]][Xbendera[i]]=' ';
                }
            }else if (Xbendera[i]<Px&&Ybendera[i]<Py){  // kuadron 2
                if (Px-Xbendera[i]<4 && Py-Ybendera[i]<4 ){
                    map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                }else {
                     map_b[Ybendera[i]][Xbendera[i]]=' ';
                }
            }else if (Xbendera[i]<Px&&Ybendera[i]>Py){
                if (Px-Xbendera[i]<4&&Ybendera[i]-Py<4){
                    map_b[Ybendera[i]][Xbendera[i]]=Flag[i];
                }else {
                     map_b[Ybendera[i]][Xbendera[i]]=' ';
                }
            }

            //////////////////////////////
             if (Yk[i]==Py){   // Y ==0
                if (Xk[i]>Px){
                    if (Xk[i]-Px<4){
                        map_b[Yk[i]][Xk[i]]='K';
                    }else if (Xk[i]-Px>4){
                        map_b[Yk[i]][Xk[i]]=' ';
                    }
                }else if (Xk[i]<Px){
                    if (Px-Xk[i]<4){
                           map_b[Yk[i]][Xk[i]]='K';
                    }else if (Px-Xk[i]>4){
                         map_b[Yk[i]][Xk[i]]=' ';
                    }

                }

            }else if (Xk[i]==Px){  //X==0
                if (Yk[i]>Py){
                    if (Yk[i]-Py<4){
                        map_b[Yk[i]][Xk[i]]='K';
                    }else if (Yk[i]-Py>4){
                        map_b[Yk[i]][Xk[i]]=' ';
                    }
                }else if (Yk[i]<Py ){
                    if (Py-Yk[i]<4){
                        map_b[Yk[i]][Xk[i]]='K';
                    }else if (Py-Yk[i]>4){
                        map_b[Yk[i]][Xk[i]]=' ';
                    }
                }

            }else if (Xk[i]>Px&&Yk[i]<Py){   // kuadron 1
                if (Xk[i]-Px<4&&Py-Yk[i]<4){
                    map_b[Yk[i]][Xk[i]]='K';
                }else {
                    map_b[Yk[i]][Xk[i]]=' ';
                }

            }else if (Xk[i]>Px&&Yk[i]>Py){    //kuadron 4
                if (Xk[i]-Px<4&&Yk[i]-Py<4){
                    map_b[Yk[i]][Xk[i]]='K';
                }else {
                    map_b[Yk[i]][Xk[i]]=' ';
                }
            }else if (Xk[i]<Px&&Yk[i]<Py){  // kuadron 2
                if (Px-Xk[i]<4 && Py-Yk[i]<4 ){
                    map_b[Yk[i]][Xk[i]]='K';
                }else {
                     map_b[Yk[i]][Xk[i]]=' ';
                }
            }else if (Xk[i]<Px&&Yk[i]>Py){
                if (Px-Xk[i]<4&&Yk[i]-Py<4){
                    map_b[Yk[i]][Xk[i]]='K';
                }else {
                     map_b[Yk[i]][Xk[i]]=' ';
                }
            }


            //////////////////////////////////////////////////////
             if (Ym[i]==Py){   // Y ==0
                if (Xm[i]>Px){
                    if (Xm[i]-Px<4){
                        map_b[Ym[i]][Xm[i]]='M';
                    }else if (Xm[i]-Px>4){
                        map_b[Ym[i]][Xm[i]]=' ';
                    }
                }else if (Xm[i]<Px){
                    if (Px-Xm[i]<4){
                           map_b[Ym[i]][Xm[i]]='M';
                    }else if (Px-Xm[i]>4){
                         map_b[Ym[i]][Xm[i]]=' ';
                    }

                }

            }else if (Xm[i]==Px){  //X==0
                if (Ym[i]>Py){
                    if (Ym[i]-Py<4){
                        map_b[Ym[i]][Xm[i]]='M';
                    }else if (Ym[i]-Py>4){
                        map_b[Ym[i]][Xm[i]]=' ';
                    }
                }else if (Ym[i]<Py ){
                    if (Py-Ym[i]<4){
                        map_b[Ym[i]][Xm[i]]='M';
                    }else if (Py-Ym[i]>4){
                        map_b[Ym[i]][Xm[i]]=' ';
                    }
                }

            }else if (Xm[i]>Px&&Ym[i]<Py){   // kuadron 1
                if (Xm[i]-Px<4&&Py-Ym[i]<4){
                    map_b[Ym[i]][Xm[i]]='M';
                }else {
                    map_b[Ym[i]][Xm[i]]=' ';

                }

            }else if (Xm[i]>Px&&Ym[i]>Py){    //kuadron 4
                if (Xm[i]-Px<4&&Ym[i]-Py<4){
                    map_b[Ym[i]][Xm[i]]='M';
                }else {
                    map_b[Ym[i]][Xm[i]]=' ';
                }
            }else if (Xm[i]<Px&&Ym[i]<Py){  // kuadron 2
                if (Px-Xm[i]<4 && Py-Ym[i]<4 ){
                    map_b[Ym[i]][Xm[i]]='M';
                }else {
                     map_b[Ym[i]][Xm[i]]=' ';
                }
            }else if (Xm[i]<Px&&Ym[i]>Py){
                if (Px-Xm[i]<4&&Ym[i]-Py<4){
                    map_b[Ym[i]][Xm[i]]='M';
                }else {
                     map_b[Ym[i]][Xm[i]]=' ';
                }
            }





        }


         if (Ysave==Py){   // Y ==0
                if (Xsave>Px){
                    if (Xsave-Px<4){
                        map_b[Ysave][Xsave]='S';
                    }else if (Xsave-Px>4){
                        map_b[Ysave][Xsave]=' ';
                    }
                }else if (Xsave<Px){
                    if (Px-Xsave<4){
                           map_b[Ysave][Xsave]='S';
                    }else if (Px-Xsave>4){
                         map_b[Ysave][Xsave]=' ';
                    }

                }

            }else if (Xsave==Px){  //X==0
                if (Ysave>Py){
                    if (Ysave-Py<4){
                        map_b[Ysave][Xsave]='S';
                    }else if (Ysave-Py>4){
                        map_b[Ysave][Xsave]=' ';
                    }
                }else if (Ysave<Py ){
                    if (Py-Ysave<4){

                        map_b[Ysave][Xsave]='S';
                    }else if (Py-Ysave>4){
                        map_b[Ysave][Xsave]=' ';
                    }
                }

            }else if (Xsave>Px&&Ysave<Py){   // kuadron 1
                if (Xsave-Px<4&&Py-Ysave<4){
                    map_b[Ysave][Xsave]='S';
                }else {
                    map_b[Ysave][Xsave]=' ';

                }

            }else if (Xsave>Px&&Ysave>Py){    //kuadron 4
                if (Xsave-Px<4&&Ysave-Py<4){
                    map_b[Ysave][Xsave]='S';
                }else {
                    map_b[Ysave][Xsave]=' ';
                }
            }else if (Xsave<Px&&Ysave<Py){  // kuadron 2
                if (Px-Xsave<4 && Py-Ysave<4 ){
                    map_b[Ysave][Xsave]='S';
                }else {
                     map_b[Ysave][Xsave]=' ';
                }
            }else if (Xsave<Px&&Ysave>Py){
                if (Px-Xsave<4&&Ysave-Py<4){
                    map_b[Ysave][Xsave]='S';
                }else {
                     map_b[Ysave][Xsave]=' ';
                }
            }












}
void CekKey()
{
    for (int i=0;i<3;i++) {

                if (Xk[i]>Px){
                    if (Xk[i]-Px<2){
                        KeyCek[i]=true;
                    }else if (Xk[i]-Px>=2){
                        KeyCek[i]=false;
                    }
                }else if (Xk[i]<Px){
                    if (Px-Xk[i]<2){
                          KeyCek[i]=true;
                    }else if (Px-Xk[i]>=2){
                         KeyCek[i]=false;
                    }

                }else if (Xk[i]==Px){  //X==0
                if (Yk[i]>Py){
                    if (Yk[i]-Py<2){
                        KeyCek[i]=true;
                    }else if (Yk[i]-Py>=2){
                        KeyCek[i]=false;
                    }
                }else if (Yk[i]<Py ){
                    if (Py-Yk[i]<2){
                        KeyCek[i]=true;
                    }else if (Py-Yk[i]>=2){
                        KeyCek[i]=false;
                    }
                }

          } else if (Xk[i]>Px&&Yk[i]<Py){   // kuadron 1
                if (Xk[i]-Px<2&&Py-Yk[i]<2){
                    KeyCek[i]=true;
                }else {
                    KeyCek[i]=false;

                }

            }else if (Xk[i]>Px&&Yk[i]>Py){    //kuadron 2
                if (Xk[i]-Px<2&&Yk[i]-Py<2){
                    KeyCek[i]=true;
                }else {
                    KeyCek[i]=false;
                }
            }else if (Xk[i]<Px&&Yk[i]<Py){  // kuadron 2
                if (Px-Xk[i]<2 && Py-Yk[i]<2 ){
                    KeyCek[i]=true;
                }else {
                     KeyCek[i]=false;
                }
            }else if (Xk[i]<Px&&Yk[i]>Py){
                if (Px-Xk[i]<2&&Yk[i]-Py<2){
                    KeyCek[i]=true;
                }else {
                     KeyCek[i]=false;
                }

        }



    }
}
void InitKoorNPC()
{
for(int i=0;i<3;i++){
    do{
    Ym[i]=rand()%49+25;
    Xm[i]=rand()%49;
    }while(map_b [Ym[i]][Xm[i]]!=' ');

    do{
    Xk[i]=rand()%49;
    Yk[i]=rand()%49+25;
    }while(map_b [Yk[i]][Xk[i]]!=' ');

    do {
    Xbendera[i]=rand()%49;
    Ybendera[i]=rand()%49+25;
    }while(map_b [Ybendera[i]][Xbendera[i]]!=' ');


    if (i==0){
        Flag[i]='1';
    }else if (i==1){
        Flag[i]='2';
    }else if (i==2){
        Flag[i]='3';
    }


    FlagCek[i]=false;
    KeyCek[i]=false;
}
Ysave=rand()%49+25;
Xsave=rand()%49;


}
void CetakGold()
{
    for (int i=0;i<10;i++){


        if (Ygold[i]<Py){
            if (Ygold[i]<y){
                Ygold[i]=Py+5;
                Xgold[i]=rand()%11+x;
                CEKgold[i]=false;

            }
        }else if (Ygold[i]>Py){
            if (Ygold[i]>y+11){
                Ygold[i]=Py-5;
                Xgold[i]=rand()%11+x;
                CEKgold[i]=false;
            }
        }

            if (Xgold[i]<Px){
                if (Xgold[i]<x){
                    Xgold[i]=Px+5;
                    Ygold[i]=rand()%11+y;
                    CEKgold[i]=false;

                }

            }else if (Xgold[i]>Px){
                if (Xgold[i]>x+11){
                    Xgold[i]=Px-5;
                    Ygold[i]=rand()%11+y;
                    CEKgold[i]=false;

                }
            }






    }




}

int main()
{
char game;
do{

srand(time(0));
for (int i=0;i<10;i++){
    Xgold[i]=rand()%12+x;
    Ygold[i]=rand()%12+y;
    CEKgold[i]=false;
}
InitPosisiAwal();
InitAwal();
InitXmark();
InitBatasFlag();
ViewBendera();
Viewrange();
BatasView();
InitKoorNPC();



bool ok=false;
string nama;
string pemain;
do {
char menuawal;
cout<<"1. NewGame"<<endl;
cout<<"2. LoadGame"<<endl;
cout<<"3. Annonymous"<<endl;
cout<<"Select :";cin>>menuawal;

if (menuawal=='1'){

    bool cekbaru=false;
    do {
    cout<<"Masukan nama user baru :";
    cin.ignore();
    getline(cin,nama);
    pemain=nama;
    nama+=".txt";
    fstream CekPlayer(nama.c_str());
    if (CekPlayer.is_open()){
        char inputcek;
        cout<<"Player Sudah ada"<<endl;
        CekPlayer.close();
        cout<<"Input Lagi(Y/N) ??";cin>>inputcek;
        if(inputcek=='Y'||inputcek=='y'){
            cekbaru=false;
        }else if (inputcek=='n'||inputcek=='N'){
            cekbaru=true;
        }



    }else {
    cekbaru=true;
    ok=true;
    ofstream New (nama.c_str());
    if (New.is_open()){


        New<<y<<endl;
        New<<x<<endl;
        New<<Py<<endl;
        New<<Px<<endl;
        New<<Ysave<<endl;
        New<<Xsave<<endl;
        New<<player.Gold<<endl;
        New<<player.Zen<<endl;
        New<<player.key1<<endl;
        New<<player.key2<<endl;
        New<<player.key3<<endl;
        New<<player.flag1<<endl;
        New<<player.flag2<<endl;
        New<<player.flag3<<endl;
        for (int i=0;i<3;i++){
            New<<Ym[i]<<endl;
        }
        for (int i=0;i<3;i++){
            New<<Xm[i]<<endl;
        }


        for (int i=0;i<3;i++){
            New<<Yk[i]<<endl;
        }

        for (int i=0;i<3;i++){
            New<<Xk[i]<<endl;
        }

        for (int i=0;i<3;i++){
            New<<Ybendera[i]<<endl;
        }

        for (int i=0;i<3;i++){
            New<<Xbendera[i]<<endl;
        }



    }
    New.close();
     }

    }while(cekbaru==false);




}else if(menuawal=='2'){// loqd


    cin.ignore();
    cout<<"Input User :";
    getline(cin,nama);
    pemain=nama;
    nama+=".txt";



    ifstream Load (nama.c_str());
    string Data;
    if (Load.is_open()){
        ok=true;
        getline(Load,Data);stringstream (Data)>>y;
        getline(Load,Data);stringstream (Data)>>x;
        getline(Load,Data);stringstream (Data)>>Py;
        getline(Load,Data);stringstream (Data)>>Px;
        getline(Load,Data);stringstream (Data)>>Ysave;
        getline(Load,Data);stringstream (Data)>>Xsave;
        getline(Load,Data);stringstream (Data)>>player.Gold;
        getline(Load,Data);stringstream (Data)>>player.Zen;
        getline(Load,Data);stringstream (Data)>>player.key1;
        getline(Load,Data);stringstream (Data)>>player.key2;
        getline(Load,Data);stringstream (Data)>>player.key3;
        getline(Load,Data);stringstream (Data)>>player.flag1;
        getline(Load,Data);stringstream (Data)>>player.flag2;
        getline(Load,Data);stringstream (Data)>>player.flag3;
        getline(Load,Data);stringstream (Data)>>Ym[0];
        getline(Load,Data);stringstream (Data)>>Ym[1];
        getline(Load,Data);stringstream (Data)>>Ym[2];
        getline(Load,Data);stringstream (Data)>>Xm[0];
        getline(Load,Data);stringstream (Data)>>Xm[1];
        getline(Load,Data);stringstream (Data)>>Xm[2];
        getline(Load,Data);stringstream (Data)>>Yk[0];
        getline(Load,Data);stringstream (Data)>>Yk[1];
        getline(Load,Data);stringstream (Data)>>Yk[2];
        getline(Load,Data);stringstream (Data)>>Xk[0];
        getline(Load,Data);stringstream (Data)>>Xk[1];
        getline(Load,Data);stringstream (Data)>>Xk[2];
        getline(Load,Data);stringstream (Data)>>Ybendera[0];
        getline(Load,Data);stringstream (Data)>>Ybendera[1];
        getline(Load,Data);stringstream (Data)>>Ybendera[2];
        getline(Load,Data);stringstream (Data)>>Xbendera[0];
        getline(Load,Data);stringstream (Data)>>Xbendera[1];
        getline(Load,Data);stringstream (Data)>>Xbendera[2];



        }

    else {
        system("cls");
        cout<<"File tidak ada"<<endl;
        return main();
    }













}else {

}
}while (ok==false);


map_b[Py][Px]='P';
int time=0;

    while(player.flag1==false||player.flag2==false||player.flag3==false){

        CetakMap(pemain);
        cout<<time<<endl;
    if (kbhit()){
        char key=getch();
        Move(key,nama);
    }
        InitAwal();

        if (time<100){
        for (int i=0;i<10;i++){
        map_b[Ygold[i]][Xgold[i]]=' ';
        }
        }else if (time<=150){
         for (int i=0;i<10;i++){
            map_b[Ygold[i]][Xgold[i]]='*';
        }
            if (time==150){
                time=0;
            }


        }

        CetakGold();
        InitXmark();
        InitBatasFlag();
        ViewBendera();
        Viewrange();
        BatasView();
        map_b[Py][Px]='P';
        time++;
        system("cls");



    }

    cout<<"You win"<<endl;
    cout<<"Play again??? (Y/N) :";cin>>game;


}while(game=='y'||game=='Y');
    cout<<"bye bye"<<endl;









    return 0;
}
