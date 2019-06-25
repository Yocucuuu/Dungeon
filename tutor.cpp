#include <iostream>
#include <fstream>

using namespace std;

int main()
{
//    ofstream ofile("test.txt");
//    ofile << "test";
//    ofile.close();

    string arrkata[4];
    arrkata[0]="a";
    arrkata[1]="b";
    arrkata[2]="c";
    arrkata[3]="d";
    ofstream outfile("tes.txt",ios::app);
    for (int i=0;i<4;i++){
        outfile << arrkata[i] << endl;
    }
    outfile.close();

    string lane,line;
    ifstream ifile("test.txt");
    if (ifile.is_open()){
        while(!ifile.eof()){
            getline(ifile,line);
            lane+=line+"\n";
        }
    }
    else{
        cout << "File tidak ditemukan!";
    }

    string kalimat;
    cin >> kalimat;
    lane+=kalimat;

    ofstream myfile("test.txt");
    myfile << lane;
    myfile.close();

    return 0;
}
