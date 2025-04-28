#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream i;
    i.open("data_records.txt", ios::in);
    i.seekg(20);
    string s;
    getline(i,s);
    cout << s;
}