#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
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

        if(Type == "AutonomousCar"){
            size_t index = ExtraData.find(':');
            if(index != string::npos){
                string e = ExtraData.substr(index+1);
                float extract = stof(e);
                cout << "ID: " << ID << ", Numerical value of ExtractData: " << extract << endl;
            }
        }
        else if(Type == "ElectricVehicle"){
            size_t index = ExtraData.find(':');
            if(index != string::npos){
                string e = ExtraData.substr(index+1);
                int extract = stoi(e);
                cout << "ID: " << ID << ", Numerical value of ExtractData: " << extract << endl;
            }
        }
    }

    in.close();
}