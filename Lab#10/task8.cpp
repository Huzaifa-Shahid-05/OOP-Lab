#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream o;
    o.open("config.txt", ios::out);

    o << "AAAAABBBBBCCCCC" << endl;
    o.close();

    fstream f;
    f.open("config.txt", ios::in | ios::out);
    f.seekp(5);
    f << "XXXXX";
    f.close();

    ifstream i;
    i.open("config.txt", ios::in);

    string line;
    while(getline(i, line)){
        cout << line << endl;
    }
}