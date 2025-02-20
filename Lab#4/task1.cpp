#include<iostream>
using namespace std;

class Car{
    private:
        int regNum;
        string modelName;
        string OwnerName;

    public:
        Car(int r, string m, string o){
            regNum = r;
            modelName = m;
            OwnerName = o;
        }
        Car(Car &obj, string n){
            regNum = obj.regNum;
            modelName = obj.modelName;
            OwnerName = n;
        }
        void Display(){
            cout << "Registration Number: " << regNum << endl;
            cout << "Model Name: " << modelName << endl;
            cout << "Owner Name: " << OwnerName << endl;
            cout << endl;
        }
};

int main(){
    Car c1(101, "Gli 2020", "Huzaifa");
    c1.Display();
    Car c2(c1, "Ali");
    c2.Display();
}