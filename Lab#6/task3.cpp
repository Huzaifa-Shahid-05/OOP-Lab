#include<iostream>
using namespace std;

class Person{
    public:
        string name;
        int age;

        Person(string n, int a):name(n),age(a){}

        void displayDetails(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

class Teacher: virtual public Person{
    public:
        string subject;

        Teacher(string n, int a,string s):Person(n,a),subject(s){}

        void displayDetails(){
            Person::displayDetails();
            cout << "Subject: " << subject << endl;
        }
};

class Researcher: virtual public Person{
    public:
        string reasearchArea;

        Researcher(string n, int a,string r):Person(n,a),reasearchArea(r){}

        void displayDetails(){
            Person::displayDetails();
            cout << "Research Area: " << reasearchArea << endl;
        }
};

class Professor: public Teacher, public Researcher{
    public:
        int publications;

        Professor(string n, int a,string s,string r,int p):Person(n,a), Researcher(n,a,r),Teacher(n,a,s),publications(p){}

        void displayDetails(){
            Person::displayDetails();
            cout << "Subject: " << subject << endl;
            cout << "Research Area: " << reasearchArea << endl;
            cout << "Publications: " << publications << endl;
        }
};

int main(){
    Professor p("Leonard",30,"Calculus","Area of 4d surfaces",20);
    p.displayDetails();
}