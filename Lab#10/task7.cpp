#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream o;
    o.open("sensor_log.txt", ios::out);
    o << "Sensor 1: 25.5 C" << endl;
    cout << "Position After writing 1 line: " << o.tellp() << endl;
    o << "Sensor 2: 98.1 %RH" << endl;
    cout << "Position After writing 1 line: " << o.tellp();

    o.close();
}