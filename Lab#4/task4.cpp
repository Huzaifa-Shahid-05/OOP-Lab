#include<iostream>
using namespace std;

class battery{
    private:
        string brand;
        int mah;
    public:
        battery(string b, int m) : brand(b), mah(m){}

        void Display(){
            cout << "Battery specs: " << endl;
            cout << "Brand: " << brand << endl;
            cout << "Mah: " << mah << endl;
        }      
};

class Smartphone{
    private:
        string model;
        string display;
        battery b1;
    public:
        Smartphone(string m, string d, string b, int a): model(m),display(d), b1(b,a){}

        void Display(){
            cout << "Smartphone details: " << endl << endl;

            cout << "Model: " << model << endl;
            cout << "Display: " << display << endl << endl;
            b1.Display();
        }
};

int main(){
    Smartphone s1("Galaxy S24 Ultra", "Super Amoled", "Samsung", 5000);

    s1.Display();
}