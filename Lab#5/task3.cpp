#include<iostream>
using namespace std;

class Professor{
    private:
        string name;
        string department;
    public:
        Professor(string n, string d){
            name = n;
            department = d;
        }
        void Display(){
            cout << "Professor name: " << name << endl;
            cout << "Department: " << department <<endl;
            cout << endl;
        }
};

class University{
    private:
        string name;
        Professor** p;
        int numP;
    public:
        University(string n){
            name = n;
            numP = 0;
            p = new Professor*[10];
        }

        void addProfessor(string n, string d){
            p[numP] = new Professor(n,d);
            numP++;
        }
        void display(){
            cout << "University: " << name << endl << endl;
            cout << "Professor list: " << endl;
            for(int i = 0; i < numP; i++){
                p[i]->Display();
            }
        }

        ~University(){
            for(int i = 0; i < numP; i++){
                delete[] p;
            }
            delete[] p;
        }
};

int main(){
    University f("Fast Nuces");
    f.addProfessor("Talha Shahid", "CS");
    f.addProfessor("Muhammad Hasham", "AI");
    f.addProfessor("Fahad Hussain", "DS");

    f.display();
}