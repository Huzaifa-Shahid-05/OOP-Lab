#include<iostream>
using namespace std;

class Vehicle{
    protected:
        string model;
        double rate;
    public:
         Vehicle(string m, double r):model(m),rate(r) {}

        virtual double getDailyRate() = 0;
        virtual void displayDetails() = 0;
        virtual ~Vehicle() {}
};

class Car: public Vehicle{
    public:
        Car(string m, double r): Vehicle(m,r) {}

        double getDailyRate()override{
            return rate;
        }
        void displayDetails()override{
            cout << "-----Car-----" << endl;
            cout << "Model: " << model << endl;
            cout << "Rate: " << rate << endl << endl;
        }
};

class Bike: public Vehicle{
    public:
        Bike(string m, double r): Vehicle(m,r) {}

        double getDailyRate()override{
            return rate;
        }

        void displayDetails()override{
            cout << "-----Bike-----" << endl;
            cout << "Model: " << model << endl;
            cout << "Rate: " << rate << endl << endl;
        }
};

int main(){
    Vehicle* v1 = new Car("Civic Turbo rs", 30000);
    Vehicle* v2 = new Bike("Yamaha 1600" , 10000);

    cout << "Car Rate: " << v1->getDailyRate() << endl;
    cout << "Bike Rate: " << v2->getDailyRate() << endl << endl;

    v1->displayDetails();
    v2->displayDetails();

    delete v1;
    delete v2;
}

