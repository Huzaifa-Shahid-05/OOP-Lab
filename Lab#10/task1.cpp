#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in;
    in.open("vehicles.txt");

    if(!in){
        cout << "Error in opening the file" << endl;
        return 1;
    }
    else{
        cout << "File opened successfully" << endl << endl;
    }

    char s[100];
    while(in){
        in.getline(s,100);
        cout << s << endl;
    }

    in.close();
}