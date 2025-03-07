#include<iostream>
using namespace std;

class Employee{
    public:
        string name;
        float salary;

        Employee(string n, float s){
            name = n;
            salary = s;
        }
        void displayDetails(){
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl << endl;
        }
};

class Manager: public Employee{
    public:
        float bonus;
        Manager(string n, float s, float b):Employee(n,s),bonus(b){}

        void displayDetails(){
            Employee::displayDetails();
            cout << "Bonus: " << bonus << endl << endl;
        }
};

int main(){
    Manager m("Ali", 500000, 100000);
    m.displayDetails();
}