#include<iostream> 
using namespace std;

class Vehicle{
    public:
        string brand;
        int speed;

        Vehicle(string b, int s): brand(b), speed(s){}

        void displayDetails(){
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
        }
};

class Car: public Vehicle{
    public:
        int seats;

        Car(string b, int s, int i): Vehicle(b,s),seats(i){}

        void displayDetails(){
            Vehicle::displayDetails();
            cout << "Seats: " << seats << endl;
        }
};

class ElectricCar: public Car{
    public:
        int batteryLife;

        ElectricCar(string b, int s, int i, int a):Car(b,s,i), batteryLife(a){}

        void displayDetails(){
            Car::displayDetails();
            cout << "Battery Life: " << batteryLife << endl;
        }
};

int main(){
    ElectricCar e("Tesla", 240, 5, 100);
    e.displayDetails();
}