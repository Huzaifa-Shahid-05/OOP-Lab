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
        else if(Type == "HybridTruck"){
            size_t index1 = ExtraData.find(':');
            size_t index2 = ExtraData.find(':', index1 + 1);
            
            if(index1 != string::npos && index2 != string::npos){
                string e1 = ExtraData.substr(index1+1, index2 - index1 - 1);
                string e2 = ExtraData.substr(index2+1);
                int extract1 = stoi(e1);
                int extract2 = stoi(e2);

                cout << "ID: " << ID << ", Numerical value of ExtractData1: " << extract1 << ", Numerical value of ExtractData2: " << extract2 << endl;
            }
        }
        else{
            cout << "Error" << endl;
        }
    }

    in.close();
}