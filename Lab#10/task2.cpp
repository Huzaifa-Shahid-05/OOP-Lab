#include<iostream>
#include<fstream>
#include<sstream>
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

    string s;
    while(getline(in, s)){
        if(s.empty() || s.find("//") == 0){
            continue;
        }
        istringstream iss(s);
        string Type, ID, Name, Year, ExtraData, Certification;

        getline(iss, Type, ',');
        getline(iss, ID, ',');
        getline(iss, Name, ',');
        getline(iss, Year, ',');
        getline(iss, ExtraData, ',');
        getline(iss, Certification, ',');
        
        cout << "Type: " << Type << ", ID: " << ID << ", Name: " << Name << ", Year: " << Year << ", Extract Data: " << ExtraData << ", Certification: " << Certification << endl << endl;
    }

    in.close();
}