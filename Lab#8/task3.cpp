#include<iostream>
using namespace std;

class Teacher;

class Student{
    private:
        string name;
        char* grades;
    public:
        Student(string n, char g[3]): name(n), grades(g) {}

        friend class Teacher;

        friend void CalculateAvgGrade(Student s);
};

class Teacher{
    public:
        void DisplayGrades(Student s){
            cout << "Name: " << s.name << endl;
            cout << "Grades: " << endl;
            for(int i = 0; i < 3; i++){
                cout << s.grades[i] << endl;
            }
            cout << endl;
        }

        void ModifyGrades(Student& s, char* g){
            cout << "Grades updated." << endl << endl;
            s.grades = g;
        }
};

void CalculateAvgGrade(Student s){
    int countA = 0, countB = 0, countC = 0, other = 0;

    for(int i = 0; i < 3; i++){
        if(s.grades[i] == 'A'){
            countA++;
        }
        else if(s.grades[i] =='B'){
            countB++;
        }
        else if(s.grades[i] == 'C'){
            countC++;
        }
        else{
            other++;
        }
    }
    cout << "Average Grade: ";
    if(countA >= 2){
        cout << 'A' << endl;
    }
    else if(countB >= 2){
        cout << 'B' << endl;
    }
    else if(countC >= 2){
        cout << 'C' << endl;
    }
    else{
        cout << "F" << endl;
    }
}

int main(){
    char grades[3] = {'A', 'A', 'B'};
    char g2[3] = {'C', 'B', 'B'};
    Student s("Huzaifa", grades);

    Teacher t;
    t.DisplayGrades(s);
    t.ModifyGrades(s, g2);
    t.DisplayGrades(s);

    CalculateAvgGrade(s);
}