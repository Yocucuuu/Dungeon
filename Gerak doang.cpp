#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;



int main()
{


char map_b[50][50];
for (int i=0;i<50;i++){
    for(int j=0;j<50;j++)
    {
        map_b[i][j]=' ';
    }
}



int x=0;
int y=0;
int Px=5;
int Py=5;
map_b[Py][Px]='P';


while(true){

cout<<"*************"<<endl;
for (int i=y;i<y+11;i++){
    cout<<"*";
    for(int j=x;j<x+11;j++){
        cout<<map_b[i][j];
    }cout<<"*"<<endl;
}
cout<<"*************\n"<<endl;


cout<<"Px :"<<Px<<endl;
cout<<"Py :"<<Py<<endl;
cout<<"x  :"<<x<<endl;
cout<<"y  :"<<y<<endl;
cout<<"x+11  :"<<x+11<<endl;
cout<<"y+11  :"<<y+11<<endl;



char key=getch();
    if(key=='d'){
        if(x==0&&Px<5){
            Px++;
        }else if(x+11==49&&Px<48){
            Px++;
        }else if (x+11<49) {
            Px++;
            x++;
        }

    }else if (key=='a'){

        if(x+11==49&&Px>43){
            Px--;
        }else if (x==0&&Px>0){
            Px--;
        }else if (x>0){

            Px--;
            x--;
        }

    }else if (key=='w'){
        if(y+11==49&&Py>43){
            Py--;
        }
        else if (y==0&&Py>0){
            Py--;
        }else if(y>0){
            y--;
            Py--;
        }
    }else if (key=='s'){
        if(y==0&&Py<5){
            Py++;
        }
        else if(y+11==49&&Py<48){
            Py++;
        }else if(y+11<49){
            y++;
            Py++;
        }

    }




for (int i=0;i<50;i++){
    for(int j=0;j<49;j++)
    {
        map_b[i][j]=' ';
    }
}


map_b[0][20]='0';

map_b[Py][Px]='P';
system("cls");
}








































    return 0;
}
