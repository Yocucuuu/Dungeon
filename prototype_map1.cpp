#include <iostream>

using namespace std;

const int FMAP_x = 11;
const int FMAP_y = 11;
char map_b[50][50];

int main()
{
    int i,j;
    char map_k[FMAP_y][FMAP_x];
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
