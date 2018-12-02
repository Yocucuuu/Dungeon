#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
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

int Ybendera[3];
int Xbendera[3];
int YBatasFlag[3][8];
int XBatasFlag[3][8];

int Ysave;
int Xsave;

char Flag[3];
char Key[3];

bool FlagCek[3];
bool KeyCek[3];

vector<int>Ymark;
vector<int>Xmark;
vector<bool>Xflag;
struct inventory{

    int Gold=5000;
    int Zen=0;
    bool key1=false;
    bool key2=false;
    bool key3=false;
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;


};
inventory player;
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

void CetakMap()
{

    for (int i=y;i<y+11;i++){
        for(int j=x;j<x+11;j++){
            cout<<map_b[i][j];
        }cout<<endl;

}


   cout<<player.Gold<<endl;
    cout<<"Py   :" <<Py<<endl;
    cout<<"Px   :" <<Px<<endl;

    for (int i=0;i<3;i++){
        cout<<Yk[i]<<" "<<Xk[i]<<endl;
//        cout<<Ym[i]<<" "<<Xm[i]<<endl;
//
//        cout<<Ybendera[i]<<" "<<Xbendera[i]<<endl;
//        cout<<endl;
    }
    for (int i=0;i<3;i++){
        cout<<KeyCek[i]<<endl;
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
        for (int i=0;i<3;i++){

        if (i==0){
            if (KeyCek[i]==true&&player.key1==false){
                do {
                cout<<"Welcome to Key "<<i+1<<endl;
                cout<<"Buy key for 1000"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. exit"<<endl;
                cout<<"Select :";cin>>menu;
                }while(menu!='1'&&menu!='2');

                if (menu=='1'){
                    player.Gold-=1000;
                    player.key1=true;

                }
            }else if (player.key1==true){
                cout<<"sudah beli Kunci 1 "<<endl;
                Sleep(1000);
            }
        }else if(i==1){

           if (KeyCek[i]==true&&player.key2==false){
            do {
                cout<<"Welcome to Key "<<i+1<<endl;
                cout<<"Buy key for 1000"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. exit"<<endl;
                cout<<"Select ";cin>>menu;
                }while(menu!='1'&&menu!='2');

                if (menu=='1'){
                    player.Gold-=1000;
                    player.key2=true;

                }
        }else if (player.key2==true) {
            cout<<"sudah beli key 2"<<endl;
            Sleep(1000);
        }
        }else if(i==2){

            if (KeyCek[i]==true){
            do {
                cout<<"Welcome to Key "<<i+1<<endl;
                cout<<"Buy key for 1000"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. exit"<<endl;
                cout<<"Select ";cin>>menu;
                }while(menu!='1'&&menu!='2');

                if (menu=='1'){
                    player.Gold-=1000;
                    player.key3=true;

                }
        }else if (player.key3==true) {
            cout<<"sudah beli key 3"<<endl;
            Sleep(1000);
        }
        }

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




int main()
{
srand(time(0));
InitAwal();
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

Ysave=rand()%50+25;
Xsave=rand()%50;



int Xgold[10];
int Ygold[10];


for (int i=0;i<10;i++){
    Xgold[i]=rand()%11+x;
    Ygold[i]=rand()%11+y;
}


map_b[Py][Px]='P';


    while(true){

        CetakMap();

        char key=getch();
        Move(key);

        InitAwal();

        for (int i=0;i<10;i++){
            map_b[Ygold[i]][Xgold[i]]='*';
        }


        InitXmark();
        InitBatasFlag();
        ViewBendera();
        Viewrange();
        BatasView();
        CekKey();




        map_b[Ysave][Xsave]='S';
        map_b[Py][Px]='P';
        system("cls");



    }
    return 0;
}
