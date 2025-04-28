#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream i;
    i.open("large_log.txt", ios::in);

    string s1, s2;
    i.read((char*)&s1, 10);
    cout << "Get Pointer Position After 10 char: " << i.tellg() << endl;

    i.read((char*)&s2, 10);
    cout << "Get Pointer Position After 20 char: " << i.tellg();
    i.close();
}